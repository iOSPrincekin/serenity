/*
 * Copyright (c) 2019-2020, Marios Prokopakis <mariosprokopakis@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/QuickSort.h>
#include <AK/StdLibExtras.h>
#include <AK/String.h>
#include <AK/Vector.h>
#include <LibCore/ArgsParser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Range {
    size_t m_from { 1 };
    size_t m_to { SIZE_MAX };

    [[nodiscard]] bool intersects(const Range& other) const
    {
        return !(other.m_from > m_to || other.m_to < m_from);
    }

    void merge(const Range& other)
    {
        // Can't merge two ranges that are disjoint.
        VERIFY(intersects(other));

        m_from = min(m_from, other.m_from);
        m_to = max(m_to, other.m_to);
    }
};

static bool expand_list(String& list, Vector<Range>& ranges)
{
    Vector<String> tokens = list.split(',');

    for (auto& token : tokens) {
        if (token.length() == 0) {
            warnln("cut: byte/character positions are numbered from 1");
            return false;
        }

        if (token == "-") {
            warnln("cut: invalid range with no endpoint: {}", token);
            return false;
        }

        if (token[0] == '-') {
            auto index = token.substring(1, token.length() - 1).to_uint();
            if (!index.has_value()) {
                warnln("cut: invalid byte/character position '{}'", token);
                return false;
            }

            if (index.value() == 0) {
                warnln("cut: byte/character positions are numbered from 1");
                return false;
            }

            ranges.append({ 1, index.value() });
        } else if (token[token.length() - 1] == '-') {
            auto index = token.substring(0, token.length() - 1).to_uint();
            if (!index.has_value()) {
                warnln("cut: invalid byte/character position '{}'", token);
                return false;
            }

            if (index.value() == 0) {
                warnln("cut: byte/character positions are numbered from 1");
                return false;
            }

            ranges.append({ index.value(), SIZE_MAX });
        } else {
            auto range = token.split('-');
            if (range.size() == 2) {
                auto index1 = range[0].to_uint();
                if (!index1.has_value()) {
                    warnln("cut: invalid byte/character position '{}'", range[0]);
                    return false;
                }

                auto index2 = range[1].to_uint();
                if (!index2.has_value()) {
                    warnln("cut: invalid byte/character position '{}'", range[1]);
                    return false;
                }

                if (index1.value() > index2.value()) {
                    warnln("cut: invalid decreasing range");
                    return false;
                } else if (index1.value() == 0 || index2.value() == 0) {
                    warnln("cut: byte/character positions are numbered from 1");
                    return false;
                }

                ranges.append({ index1.value(), index2.value() });
            } else if (range.size() == 1) {
                auto index = range[0].to_uint();
                if (!index.has_value()) {
                    warnln("cut: invalid byte/character position '{}'", range[0]);
                    return false;
                }

                if (index.value() == 0) {
                    warnln("cut: byte/character positions are numbered from 1");
                    return false;
                }

                ranges.append({ index.value(), index.value() });
            } else {
                warnln("cut: invalid byte or character range");
                return false;
            }
        }
    }

    return true;
}

static void cut_file(const String& file, const Vector<Range>& byte_vector)
{
    FILE* fp = stdin;
    if (!file.is_null()) {
        fp = fopen(file.characters(), "r");
        if (!fp) {
            warnln("cut: Could not open file '{}'", file);
            return;
        }
    }

    char* line = nullptr;
    ssize_t line_length = 0;
    size_t line_capacity = 0;
    while ((line_length = getline(&line, &line_capacity, fp)) != -1) {
        if (line_length < 0) {
            warnln("cut: Failed to read line from file '{}'", file);
            return;
        }
        line[line_length - 1] = '\0';
        line_length--;

        for (auto& i : byte_vector) {
            if (i.m_from >= (size_t) line_length)
                continue;


            auto to = min(i.m_to, line_length);
            auto sub_string = String(line).substring(i.m_from - 1, to - i.m_from + 1);
            out("{}", sub_string);
        }
        outln();
    }

    if (line)
        free(line);

    if (!file.is_null())
        fclose(fp);
}

int main(int argc, char** argv)
{
    String byte_list = "";

    Vector<String> files;

    Core::ArgsParser args_parser;
    args_parser.add_positional_argument(files, "file(s) to cut", "file", Core::ArgsParser::Required::No);
    args_parser.add_option(byte_list, "select only these bytes", "bytes", 'b', "list");
    args_parser.parse(argc, argv);

    if (byte_list == "") {
        warnln("cut: you must specify a list of bytes");
        args_parser.print_usage(stderr, argv[0]);
        return 1;
    }

    Vector<Range> byte_vector;
    auto expansion_successful = expand_list(byte_list, byte_vector);

    if (!expansion_successful) {
        args_parser.print_usage(stderr, argv[0]);
        return 1;
    }

    quick_sort(byte_vector, [](auto& a, auto& b) { return a.m_from < b.m_from; });

    Vector<Range> disjoint_ranges;
    for (auto& range : byte_vector) {
        if (disjoint_ranges.is_empty()) {
            disjoint_ranges.append(range);
            continue;
        }

        Range& last_range = disjoint_ranges.last();

        if (!last_range.intersects(range)) {
            disjoint_ranges.append(range);
            continue;
        }

        last_range.merge(range);
    }

    if (files.is_empty())
        files.append(String());

    /* Process each file */
    for (auto& file : files)
        cut_file(file, disjoint_ranges);

    return 0;
}
