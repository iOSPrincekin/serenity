/*
 * Copyright (c) 2020, Emanuel Sprung <emanuel.sprung@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "LibRegex/RegexMatcher.h"
#include <LibTest/TestCase.h> // import first, to prevent warning of VERIFY* redefinition

#include <AK/StringBuilder.h>
#include <LibRegex/Regex.h>
#include <LibRegex/RegexDebug.h>
#include <stdio.h>

static ECMAScriptOptions match_test_api_options(const ECMAScriptOptions options)
{
    return options;
}

static PosixOptions match_test_api_options(const PosixOptions options)
{
    return options;
}

template<typename... Flags>
static constexpr ECMAScriptFlags combine_flags(Flags&&... flags) requires((IsSame<Flags, ECMAScriptFlags> && ...))
{
    return static_cast<ECMAScriptFlags>((static_cast<regex::FlagsUnderlyingType>(flags) | ...));
}

TEST_CASE(regex_options_ecmascript)
{
    ECMAScriptOptions eo;
    eo |= ECMAScriptFlags::Global;

    EXPECT(eo & ECMAScriptFlags::Global);
    EXPECT(!(eo & ECMAScriptFlags::Insensitive));

    eo = match_test_api_options(ECMAScriptFlags::Global | ECMAScriptFlags::Insensitive | ECMAScriptFlags::Sticky);
    EXPECT(eo & ECMAScriptFlags::Global);
    EXPECT(eo & ECMAScriptFlags::Insensitive);
    EXPECT(eo & ECMAScriptFlags::Sticky);
    EXPECT(!(eo & ECMAScriptFlags::Unicode));
    EXPECT(!(eo & ECMAScriptFlags::Multiline));
    EXPECT(!(eo & ECMAScriptFlags::SingleLine));

    eo &= ECMAScriptFlags::Insensitive;
    EXPECT(!(eo & ECMAScriptFlags::Global));
    EXPECT(eo & ECMAScriptFlags::Insensitive);
    EXPECT(!(eo & ECMAScriptFlags::Multiline));

    eo &= ECMAScriptFlags::Sticky;
    EXPECT(!(eo & ECMAScriptFlags::Global));
    EXPECT(!(eo & ECMAScriptFlags::Insensitive));
    EXPECT(!(eo & ECMAScriptFlags::Multiline));
    EXPECT(!(eo & ECMAScriptFlags::Sticky));

    eo = ~ECMAScriptFlags::Insensitive;
    EXPECT(eo & ECMAScriptFlags::Global);
    EXPECT(!(eo & ECMAScriptFlags::Insensitive));
    EXPECT(eo & ECMAScriptFlags::Multiline);
    EXPECT(eo & ECMAScriptFlags::Sticky);
}

TEST_CASE(regex_options_posix)
{
    PosixOptions eo;
    eo |= PosixFlags::Global;

    EXPECT(eo & PosixFlags::Global);
    EXPECT(!(eo & PosixFlags::Insensitive));

    eo = match_test_api_options(PosixFlags::Global | PosixFlags::Insensitive | PosixFlags::MatchNotBeginOfLine);
    EXPECT(eo & PosixFlags::Global);
    EXPECT(eo & PosixFlags::Insensitive);
    EXPECT(eo & PosixFlags::MatchNotBeginOfLine);
    EXPECT(!(eo & PosixFlags::Unicode));
    EXPECT(!(eo & PosixFlags::Multiline));

    eo &= PosixFlags::Insensitive;
    EXPECT(!(eo & PosixFlags::Global));
    EXPECT(eo & PosixFlags::Insensitive);
    EXPECT(!(eo & PosixFlags::Multiline));

    eo &= PosixFlags::MatchNotBeginOfLine;
    EXPECT(!(eo & PosixFlags::Global));
    EXPECT(!(eo & PosixFlags::Insensitive));
    EXPECT(!(eo & PosixFlags::Multiline));

    eo = ~PosixFlags::Insensitive;
    EXPECT(eo & PosixFlags::Global);
    EXPECT(!(eo & PosixFlags::Insensitive));
    EXPECT(eo & PosixFlags::Multiline);
}

TEST_CASE(regex_lexer)
{
    Lexer l("/[.*+?^${}()|[\\]\\\\]/g");
    EXPECT(l.next().type() == regex::TokenType::Slash);
    EXPECT(l.next().type() == regex::TokenType::LeftBracket);
    EXPECT(l.next().type() == regex::TokenType::Period);
    EXPECT(l.next().type() == regex::TokenType::Asterisk);
    EXPECT(l.next().type() == regex::TokenType::Plus);
    EXPECT(l.next().type() == regex::TokenType::Questionmark);
    EXPECT(l.next().type() == regex::TokenType::Circumflex);
    EXPECT(l.next().type() == regex::TokenType::Dollar);
    EXPECT(l.next().type() == regex::TokenType::LeftCurly);
    EXPECT(l.next().type() == regex::TokenType::RightCurly);
    EXPECT(l.next().type() == regex::TokenType::LeftParen);
    EXPECT(l.next().type() == regex::TokenType::RightParen);
    EXPECT(l.next().type() == regex::TokenType::Pipe);
    EXPECT(l.next().type() == regex::TokenType::LeftBracket);
    EXPECT(l.next().type() == regex::TokenType::EscapeSequence);
    EXPECT(l.next().type() == regex::TokenType::EscapeSequence);
    EXPECT(l.next().type() == regex::TokenType::RightBracket);
    EXPECT(l.next().type() == regex::TokenType::Slash);
    EXPECT(l.next().type() == regex::TokenType::Char);
}

TEST_CASE(parser_error_parens)
{
    String pattern = "test()test";
    Lexer l(pattern);
    PosixExtendedParser p(l);
    p.parse();
    EXPECT(p.has_error());
    EXPECT(p.error() == Error::EmptySubExpression);
}

TEST_CASE(parser_error_special_characters_used_at_wrong_place)
{
    String pattern;
    Vector<char, 5> chars = { '*', '+', '?', '{' };
    StringBuilder b;

    Lexer l;
    PosixExtended p(l);

    for (auto& ch : chars) {
        // First in ere
        b.clear();
        b.append(ch);
        pattern = b.build();
        l.set_source(pattern);
        p.parse();
        EXPECT(p.has_error());
        EXPECT(p.error() == Error::InvalidRepetitionMarker);

        // After vertical line
        b.clear();
        b.append("a|");
        b.append(ch);
        pattern = b.build();
        l.set_source(pattern);
        p.parse();
        EXPECT(p.has_error());
        EXPECT(p.error() == Error::InvalidRepetitionMarker);

        // After circumflex
        b.clear();
        b.append("^");
        b.append(ch);
        pattern = b.build();
        l.set_source(pattern);
        p.parse();
        EXPECT(p.has_error());
        EXPECT(p.error() == Error::InvalidRepetitionMarker);

        // After dollar
        b.clear();
        b.append("$");
        b.append(ch);
        pattern = b.build();
        l.set_source(pattern);
        p.parse();
        EXPECT(p.has_error());
        EXPECT(p.error() == Error::InvalidRepetitionMarker);

        // After left parens
        b.clear();
        b.append("(");
        b.append(ch);
        b.append(")");
        pattern = b.build();
        l.set_source(pattern);
        p.parse();
        EXPECT(p.has_error());
        EXPECT(p.error() == Error::InvalidRepetitionMarker);
    }
}

TEST_CASE(parser_error_vertical_line_used_at_wrong_place)
{
    Lexer l;
    PosixExtended p(l);

    // First in ere
    l.set_source("|asdf");
    p.parse();
    EXPECT(p.has_error());
    EXPECT(p.error() == Error::EmptySubExpression);

    // Last in ere
    l.set_source("asdf|");
    p.parse();
    EXPECT(p.has_error());
    EXPECT(p.error() == Error::EmptySubExpression);

    // After left parens
    l.set_source("(|asdf)");
    p.parse();
    EXPECT(p.has_error());
    EXPECT(p.error() == Error::EmptySubExpression);

    // Proceed right parens
    l.set_source("(asdf)|");
    p.parse();
    EXPECT(p.has_error());
    EXPECT(p.error() == Error::EmptySubExpression);
}

TEST_CASE(catch_all_first)
{
    Regex<PosixExtended> re("^.*$");
    RegexResult m;
    re.match("Hello World", m);
    EXPECT(m.count == 1);
    EXPECT(re.match("Hello World", m));
}

TEST_CASE(catch_all)
{
    Regex<PosixExtended> re("^.*$", PosixFlags::Global);

    EXPECT(re.has_match("Hello World"));
    EXPECT(re.match("Hello World").success);
    EXPECT(re.match("Hello World").count == 1);

    EXPECT(has_match("Hello World", re));
    auto res = match("Hello World", re);
    EXPECT(res.success);
    EXPECT(res.count == 1);
    EXPECT(res.matches.size() == 1);
    EXPECT(res.matches.first().view == "Hello World");
}

TEST_CASE(catch_all_again)
{
    Regex<PosixExtended> re("^.*$", PosixFlags::Extra);
    EXPECT_EQ(has_match("Hello World", re), true);
}

TEST_CASE(char_utf8)
{
    Regex<PosixExtended> re("😀");
    RegexResult result;

    EXPECT_EQ((result = match(Utf8View { "Привет, мир! 😀 γειά σου κόσμος 😀 こんにちは世界" }, re, PosixFlags::Global)).success, true);
    EXPECT_EQ(result.count, 2u);
}

TEST_CASE(catch_all_newline)
{
    Regex<PosixExtended> re("^.*$", PosixFlags::Multiline | PosixFlags::StringCopyMatches);
    RegexResult result;
    auto lambda = [&result, &re]() {
        String aaa = "Hello World\nTest\n1234\n";
        result = match(aaa, re);
        EXPECT_EQ(result.success, true);
    };
    lambda();
    EXPECT_EQ(result.count, 3u);
    EXPECT_EQ(result.matches.at(0).view, "Hello World");
    EXPECT_EQ(result.matches.at(1).view, "Test");
    EXPECT_EQ(result.matches.at(2).view, "1234");
}

TEST_CASE(catch_all_newline_view)
{
    Regex<PosixExtended> re("^.*$", PosixFlags::Multiline);
    RegexResult result;

    String aaa = "Hello World\nTest\n1234\n";
    result = match(aaa, re);
    EXPECT_EQ(result.success, true);
    EXPECT_EQ(result.count, 3u);
    String str = "Hello World";
    EXPECT_EQ(result.matches.at(0).view, str.view());
    EXPECT_EQ(result.matches.at(1).view, "Test");
    EXPECT_EQ(result.matches.at(2).view, "1234");
}

TEST_CASE(catch_all_newline_2)
{
    Regex<PosixExtended> re("^.*$");
    RegexResult result;
    result = match("Hello World\nTest\n1234\n", re, PosixFlags::Multiline | PosixFlags::StringCopyMatches);
    EXPECT_EQ(result.success, true);
    EXPECT_EQ(result.count, 3u);
    EXPECT_EQ(result.matches.at(0).view, "Hello World");
    EXPECT_EQ(result.matches.at(1).view, "Test");
    EXPECT_EQ(result.matches.at(2).view, "1234");

    result = match("Hello World\nTest\n1234\n", re);
    EXPECT_EQ(result.success, true);
    EXPECT_EQ(result.count, 1u);
    EXPECT_EQ(result.matches.at(0).view, "Hello World\nTest\n1234\n");
}

TEST_CASE(match_all_character_class)
{
    Regex<PosixExtended> re("[[:alpha:]]");
    String str = "[Window]\nOpacity=255\nAudibleBeep=0\n";
    RegexResult result = match(str, re, PosixFlags::Global | PosixFlags::StringCopyMatches);

    EXPECT_EQ(result.success, true);
    EXPECT_EQ(result.count, 24u);
    EXPECT_EQ(result.matches.at(0).view, "W");
    EXPECT_EQ(result.matches.at(1).view, "i");
    EXPECT_EQ(result.matches.at(2).view, "n");
}

TEST_CASE(match_character_class_with_assertion)
{
    Regex<PosixExtended> re("[[:alpha:]]+$");
    String str = "abcdef";
    RegexResult result = match(str, re);

    EXPECT_EQ(result.success, true);
    EXPECT_EQ(result.count, 1u);
}

TEST_CASE(example_for_git_commit)
{
    Regex<PosixExtended> re("^.*$");
    auto result = re.match("Well, hello friends!\nHello World!");

    EXPECT(result.success);
    EXPECT(result.count == 1);
    EXPECT(result.matches.at(0).view.starts_with("Well"));
    EXPECT(result.matches.at(0).view.length() == 33);

    EXPECT(re.has_match("Well,...."));

    result = re.match("Well, hello friends!\nHello World!", PosixFlags::Multiline);

    EXPECT(result.success);
    EXPECT(result.count == 2);
    EXPECT(result.matches.at(0).view == "Well, hello friends!");
    EXPECT(result.matches.at(1).view == "Hello World!");
}

TEST_CASE(email_address)
{
    Regex<PosixExtended> re("^[A-Z0-9a-z._%+-]{1,64}@([A-Za-z0-9-]{1,63}\\.){1,125}[A-Za-z]{2,63}$");
    EXPECT(re.has_match("hello.world@domain.tld"));
    EXPECT(re.has_match("this.is.a.very_long_email_address@world.wide.web"));
}

TEST_CASE(ini_file_entries)
{
    Regex<PosixExtended> re("[[:alpha:]]*=([[:digit:]]*)|\\[(.*)\\]");
    RegexResult result;

    if constexpr (REGEX_DEBUG) {
        RegexDebug regex_dbg(stderr);
        regex_dbg.print_raw_bytecode(re);
        regex_dbg.print_header();
        regex_dbg.print_bytecode(re);
    }

    String haystack = "[Window]\nOpacity=255\nAudibleBeep=0\n";
    EXPECT_EQ(re.search(haystack.view(), result, PosixFlags::Multiline), true);
    EXPECT_EQ(result.count, 3u);

    if constexpr (REGEX_DEBUG) {
        for (auto& v : result.matches)
            fprintf(stderr, "%s\n", v.view.to_string().characters());
    }

    EXPECT_EQ(result.matches.at(0).view, "[Window]");
    EXPECT_EQ(result.capture_group_matches.at(0).at(0).view, "Window");
    EXPECT_EQ(result.matches.at(1).view, "Opacity=255");
    EXPECT_EQ(result.matches.at(1).line, 1u);
    EXPECT_EQ(result.matches.at(1).column, 0u);
    EXPECT_EQ(result.capture_group_matches.at(1).at(0).view, "255");
    EXPECT_EQ(result.capture_group_matches.at(1).at(0).line, 1u);
    EXPECT_EQ(result.capture_group_matches.at(1).at(0).column, 8u);
    EXPECT_EQ(result.matches.at(2).view, "AudibleBeep=0");
    EXPECT_EQ(result.capture_group_matches.at(2).at(0).view, "0");
    EXPECT_EQ(result.capture_group_matches.at(2).at(0).line, 2u);
    EXPECT_EQ(result.capture_group_matches.at(2).at(0).column, 12u);
}

TEST_CASE(ini_file_entries2)
{
    Regex<PosixExtended> re("[[:alpha:]]*=([[:digit:]]*)");
    RegexResult result;

    String haystack = "ViewMode=Icon";

    EXPECT_EQ(re.match(haystack.view(), result), false);
    EXPECT_EQ(result.count, 0u);

    EXPECT_EQ(re.search(haystack.view(), result), true);
    EXPECT_EQ(result.count, 1u);
}

TEST_CASE(named_capture_group)
{
    Regex<PosixExtended> re("[[:alpha:]]*=(?<Test>[[:digit:]]*)");
    RegexResult result;

    if constexpr (REGEX_DEBUG) {
        RegexDebug regex_dbg(stderr);
        regex_dbg.print_raw_bytecode(re);
        regex_dbg.print_header();
        regex_dbg.print_bytecode(re);
    }

    String haystack = "[Window]\nOpacity=255\nAudibleBeep=0\n";
    EXPECT_EQ(re.search(haystack, result, PosixFlags::Multiline), true);
    EXPECT_EQ(result.count, 2u);
    EXPECT_EQ(result.matches.at(0).view, "Opacity=255");
    EXPECT_EQ(result.named_capture_group_matches.at(0).ensure("Test").view, "255");
    EXPECT_EQ(result.matches.at(1).view, "AudibleBeep=0");
    EXPECT_EQ(result.named_capture_group_matches.at(1).ensure("Test").view, "0");
}

TEST_CASE(ecma262_named_capture_group_with_dollar_sign)
{
    Regex<ECMA262> re("[a-zA-Z]*=(?<$Test$>[0-9]*)");
    RegexResult result;

    if constexpr (REGEX_DEBUG) {
        RegexDebug regex_dbg(stderr);
        regex_dbg.print_raw_bytecode(re);
        regex_dbg.print_header();
        regex_dbg.print_bytecode(re);
    }

    String haystack = "[Window]\nOpacity=255\nAudibleBeep=0\n";
    EXPECT_EQ(re.search(haystack, result, ECMAScriptFlags::Multiline), true);
    EXPECT_EQ(result.count, 2u);
    EXPECT_EQ(result.matches.at(0).view, "Opacity=255");
    EXPECT_EQ(result.named_capture_group_matches.at(0).ensure("$Test$").view, "255");
    EXPECT_EQ(result.matches.at(1).view, "AudibleBeep=0");
    EXPECT_EQ(result.named_capture_group_matches.at(1).ensure("$Test$").view, "0");
}

TEST_CASE(a_star)
{
    Regex<PosixExtended> re("a*");
    RegexResult result;

    if constexpr (REGEX_DEBUG) {
        RegexDebug regex_dbg(stderr);
        regex_dbg.print_raw_bytecode(re);
        regex_dbg.print_header();
        regex_dbg.print_bytecode(re);
    }

    String haystack = "[Window]\nOpacity=255\nAudibleBeep=0\n";
    EXPECT_EQ(re.search(haystack.view(), result, PosixFlags::Multiline), true);
    EXPECT_EQ(result.count, 32u);
    if (result.count == 32u) {
        EXPECT_EQ(result.matches.at(0).view.length(), 0u);
        EXPECT_EQ(result.matches.at(10).view.length(), 1u);
        EXPECT_EQ(result.matches.at(10).view, "a");
        EXPECT_EQ(result.matches.at(31).view.length(), 0u);
    }
}

TEST_CASE(simple_period_end_benchmark)
{
    Regex<PosixExtended> re("hello.$");
    RegexResult m;
    EXPECT_EQ(re.search("Hello1", m), false);
    EXPECT_EQ(re.search("hello1hello1", m), true);
    EXPECT_EQ(re.search("hello2hell", m), false);
    EXPECT_EQ(re.search("hello?", m), true);
}

TEST_CASE(ECMA262_parse)
{
    struct _test {
        StringView pattern;
        regex::Error expected_error { regex::Error::NoError };
        regex::ECMAScriptFlags flags {};
    };

    constexpr _test tests[] {
        { "^hello.$"sv },
        { "^(hello.)$"sv },
        { "^h{0,1}ello.$"sv },
        { "^hello\\W$"sv },
        { "^hell\\w.$"sv },
        { "^hell\\x6f1$"sv }, // ^hello1$
        { "^hel(?:l\\w).$"sv },
        { "^hel(?<LO>l\\w).$"sv },
        { "^[-a-zA-Z\\w\\s]+$"sv },
        { "\\bhello\\B"sv },
        { "^[\\w+/_-]+[=]{0,2}$"sv },                        // #4189
        { "^(?:[^<]*(<[\\w\\W]+>)[^>]*$|#([\\w\\-]*)$)"sv }, // #4189
        { "\\/"sv },                                         // #4189
        { ",/=-:"sv },                                       // #4243
        { "\\x"sv },                                         // Even invalid escapes are allowed if ~unicode.
        { "\\x1"sv },                                        // Even invalid escapes are allowed if ~unicode.
        { "\\x1"sv, regex::Error::InvalidPattern, regex::ECMAScriptFlags::Unicode },
        { "\\x11"sv },
        { "\\x11"sv, regex::Error::NoError, regex::ECMAScriptFlags::Unicode },
        { "\\"sv, regex::Error::InvalidTrailingEscape },
        { "(?"sv, regex::Error::InvalidCaptureGroup },
        { "\\u1234"sv, regex::Error::NoError, regex::ECMAScriptFlags::Unicode },
        { "[\\u1234]"sv, regex::Error::NoError, regex::ECMAScriptFlags::Unicode },
        { "\\u1"sv, regex::Error::InvalidPattern, regex::ECMAScriptFlags::Unicode },
        { "[\\u1]"sv, regex::Error::InvalidPattern, regex::ECMAScriptFlags::Unicode },
        { ",(?"sv, regex::Error::InvalidCaptureGroup }, // #4583
        { "{1}"sv, regex::Error::InvalidPattern },
        { "{1,2}"sv, regex::Error::InvalidPattern },
        { "\\uxxxx"sv, regex::Error::NoError },
        { "\\uxxxx"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\ud83d"sv, regex::Error::NoError, ECMAScriptFlags::Unicode },
        { "\\ud83d\\uxxxx"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\u{0}"sv, regex::Error::NoError, ECMAScriptFlags::Unicode },
        { "\\u{10ffff}"sv, regex::Error::NoError, ECMAScriptFlags::Unicode },
        { "\\u{10ffff"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\u{10ffffx"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\u{110000}"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\p"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\p{"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\p{}"sv, regex::Error::InvalidNameForProperty, ECMAScriptFlags::Unicode },
        { "\\p{AsCiI}"sv, regex::Error::InvalidNameForProperty, ECMAScriptFlags::Unicode },
        { "\\p{hello friends}"sv, regex::Error::InvalidNameForProperty, ECMAScriptFlags::Unicode },
        { "\\p{Prepended_Concatenation_Mark}"sv, regex::Error::InvalidNameForProperty, ECMAScriptFlags::Unicode },
        { "\\p{ASCII}"sv, regex::Error::NoError, ECMAScriptFlags::Unicode },
        { "\\\\p{1}"sv, regex::Error::NoError, ECMAScriptFlags::Unicode },
        { "\\\\p{AsCiI}"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\\\p{ASCII}"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\c"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "\\c"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "[\\c]"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "[\\c]"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\c`"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "\\c`"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "[\\c`]"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "[\\c`]"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\A"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "\\A"sv, regex::Error::InvalidCharacterClass, ECMAScriptFlags::Unicode },
        { "[\\A]"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "[\\A]"sv, regex::Error::InvalidPattern, ECMAScriptFlags::Unicode },
        { "\\0"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "\\0"sv, regex::Error::NoError, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
        { "\\00"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "\\00"sv, regex::Error::InvalidCharacterClass, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
        { "[\\0]"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "[\\0]"sv, regex::Error::NoError, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
        { "[\\00]"sv, regex::Error::NoError, ECMAScriptFlags::BrowserExtended },
        { "[\\00]"sv, regex::Error::InvalidPattern, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
    };

    for (auto& test : tests) {
        Regex<ECMA262> re(test.pattern, test.flags);
        EXPECT_EQ(re.parser_result.error, test.expected_error);
        if constexpr (REGEX_DEBUG) {
            dbgln("\n");
            RegexDebug regex_dbg(stderr);
            regex_dbg.print_raw_bytecode(re);
            regex_dbg.print_header();
            regex_dbg.print_bytecode(re);
            dbgln("\n");
        }
    }
}

TEST_CASE(ECMA262_match)
{
    struct _test {
        StringView pattern;
        StringView subject;
        bool matches { true };
        ECMAScriptFlags options {};
    };
    // clang-format off
    constexpr _test tests[] {
        { "^hello.$"sv, "hello1"sv },
        { "^(hello.)$"sv, "hello1"sv },
        { "^h{0,1}ello.$"sv, "ello1"sv },
        { "^hello\\W$"sv, "hello!"sv },
        { "^hell\\w.$"sv, "hellx!"sv },
        { "^hell\\x6f1$"sv, "hello1"sv },
        { "^hel(?<LO>l.)1$"sv, "hello1"sv },
        { "^hel(?<LO>l.)1*\\k<LO>.$"sv, "hello1lo1"sv },
        { "^[-a-z1-3\\s]+$"sv, "hell2 o1"sv },
        { "^[\\0-\\x1f]$"sv, "\n"sv },
        { .pattern = "\\bhello\\B"sv, .subject = "hello1"sv, .options = ECMAScriptFlags::Global },
        { "\\b.*\\b"sv, "hello1"sv },
        { "[^\\D\\S]{2}"sv, "1 "sv },
        { "bar(?=f.)foo"sv, "barfoo"sv },
        { "bar(?=foo)bar"sv, "barbar"sv, false },
        { "bar(?!foo)bar"sv, "barbar"sv, true },
        { "bar(?!bar)bar"sv, "barbar"sv, false },
        { "bar.*(?<=foo)"sv, "barbar"sv, false },
        { "bar.*(?<!foo)"sv, "barbar"sv, true },
        { "((...)X)+"sv, "fooXbarXbazX"sv, true },
        { "(?:)"sv, ""sv, true },
        { "\\^"sv, "^"sv },
        // ECMA262, B.1.4. Regular Expression Pattern extensions for browsers
        { "{"sv, "{"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\5"sv, "\5"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\05"sv, "\5"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\455"sv, "\45""5"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\314"sv, "\314"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\c"sv, "\\c"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\cf"sv, "\06"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\c1"sv, "\\c1"sv, true, ECMAScriptFlags::BrowserExtended },
        { "[\\c1]"sv, "\x11"sv, true, ECMAScriptFlags::BrowserExtended },
        { "[\\w-\\d]"sv, "-"sv, true, ECMAScriptFlags::BrowserExtended },
        { "^(?:^^\\.?|[!+-]|!=|!==|#|%|%=|&|&&|&&=|&=|\\(|\\*|\\*=|\\+=|,|-=|->|\\/|\\/=|:|::|;|<|<<|<<=|<=|=|==|===|>|>=|>>|>>=|>>>|>>>=|[?@[^]|\\^=|\\^\\^|\\^\\^=|{|\\||\\|=|\\|\\||\\|\\|=|~|break|case|continue|delete|do|else|finally|instanceof|return|throw|try|typeof)\\s*(\\/(?=[^*/])(?:[^/[\\\\]|\\\\[\\S\\s]|\\[(?:[^\\\\\\]]|\\\\[\\S\\s])*(?:]|$))+\\/)"sv,
                 "return /xx/"sv, true, ECMAScriptFlags::BrowserExtended
        }, // #5517, appears to be matching JS expressions that involve regular expressions...
        { "a{2,}"sv, "aaaa"sv }, // #5518
        { "\\0"sv, "\0"sv, true, ECMAScriptFlags::BrowserExtended },
        { "\\0"sv, "\0"sv, true, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
        { "\\01"sv, "\1"sv, true, ECMAScriptFlags::BrowserExtended },
        { "[\\0]"sv, "\0"sv, true, ECMAScriptFlags::BrowserExtended },
        { "[\\0]"sv, "\0"sv, true, combine_flags(ECMAScriptFlags::Unicode, ECMAScriptFlags::BrowserExtended) },
        { "[\\01]"sv, "\1"sv, true, ECMAScriptFlags::BrowserExtended },
    };
    // clang-format on

    for (auto& test : tests) {
        Regex<ECMA262> re(test.pattern, test.options);
        if constexpr (REGEX_DEBUG) {
            dbgln("\n");
            RegexDebug regex_dbg(stderr);
            regex_dbg.print_raw_bytecode(re);
            regex_dbg.print_header();
            regex_dbg.print_bytecode(re);
            dbgln("\n");
        }
        EXPECT_EQ(re.parser_result.error, Error::NoError);
        EXPECT_EQ(re.match(test.subject).success, test.matches);
    }
}

TEST_CASE(ECMA262_unicode_match)
{
    struct _test {
        StringView pattern;
        StringView subject;
        bool matches { true };
        ECMAScriptFlags options {};
    };
    _test tests[] {
        { "\\ud83d"sv, "😀"sv, true },
        { "\\ud83d"sv, "😀"sv, false, ECMAScriptFlags::Unicode },
        { "\\ude00"sv, "😀"sv, true },
        { "\\ude00"sv, "😀"sv, false, ECMAScriptFlags::Unicode },
        { "\\ud83d\\ude00"sv, "😀"sv, true },
        { "\\ud83d\\ude00"sv, "😀"sv, true, ECMAScriptFlags::Unicode },
        { "\\u{1f600}"sv, "😀"sv, true, ECMAScriptFlags::Unicode },
        { "\\ud83d\\ud83d"sv, "\xed\xa0\xbd\xed\xa0\xbd"sv, true },
        { "\\ud83d\\ud83d"sv, "\xed\xa0\xbd\xed\xa0\xbd"sv, true, ECMAScriptFlags::Unicode },
    };

    for (auto& test : tests) {
        Regex<ECMA262> re(test.pattern, (ECMAScriptFlags)regex::AllFlags::Global | test.options);

        auto subject = AK::utf8_to_utf16(test.subject);
        Utf16View view { subject };

        if constexpr (REGEX_DEBUG) {
            dbgln("\n");
            RegexDebug regex_dbg(stderr);
            regex_dbg.print_raw_bytecode(re);
            regex_dbg.print_header();
            regex_dbg.print_bytecode(re);
            dbgln("\n");
        }

        EXPECT_EQ(re.parser_result.error, Error::NoError);
        EXPECT_EQ(re.match(view).success, test.matches);
    }
}

TEST_CASE(ECMA262_property_match)
{
    struct _test {
        StringView pattern;
        StringView subject;
        bool matches { true };
        ECMAScriptFlags options {};
    };

    constexpr _test tests[] {
        { "\\p{ASCII}"sv, "a"sv, false },
        { "\\p{ASCII}"sv, "p{ASCII}"sv, true },
        { "\\p{ASCII}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{ASCII}"sv, "😀"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{ASCII}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{ASCII}"sv, "😀"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{ASCII_Hex_Digit}"sv, "1"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{ASCII_Hex_Digit}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{ASCII_Hex_Digit}"sv, "x"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{ASCII_Hex_Digit}"sv, "1"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{ASCII_Hex_Digit}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{ASCII_Hex_Digit}"sv, "x"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Any}"sv, "\xcd\xb8"sv, true, ECMAScriptFlags::Unicode },       // U+0378, which is an unassigned code point.
        { "\\P{Any}"sv, "\xcd\xb8"sv, false, ECMAScriptFlags::Unicode },      // U+0378, which is an unassigned code point.
        { "\\p{Assigned}"sv, "\xcd\xb8"sv, false, ECMAScriptFlags::Unicode }, // U+0378, which is an unassigned code point.
        { "\\P{Assigned}"sv, "\xcd\xb8"sv, true, ECMAScriptFlags::Unicode },  // U+0378, which is an unassigned code point.
        { "\\p{Lu}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{Lu}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Lu}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{Cased_Letter}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Cased_Letter}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Cased_Letter}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{Cased_Letter}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{Cased_Letter}"sv, "A"sv, false, ECMAScriptFlags::Unicode },
        { "\\P{Cased_Letter}"sv, "9"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{General_Category=Cased_Letter}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{General_Category=Cased_Letter}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{General_Category=Cased_Letter}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{gc=Cased_Letter}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{gc=Cased_Letter}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{gc=Cased_Letter}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{Script=Latin}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Script=Latin}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{Script=Latin}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{sc=Latin}"sv, "a"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{sc=Latin}"sv, "A"sv, true, ECMAScriptFlags::Unicode },
        { "\\p{sc=Latin}"sv, "9"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{Script_Extensions=Deva}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{Script_Extensions=Beng}"sv, "\xe1\xb3\x95"sv, true, ECMAScriptFlags::Unicode }, // U+01CD5
        { "\\p{Script_Extensions=Deva}"sv, "\xe1\xb3\x95"sv, true, ECMAScriptFlags::Unicode }, // U+01CD5
        { "\\p{scx=Deva}"sv, "a"sv, false, ECMAScriptFlags::Unicode },
        { "\\p{scx=Beng}"sv, "\xe1\xb3\x95"sv, true, ECMAScriptFlags::Unicode }, // U+01CD5
        { "\\p{scx=Deva}"sv, "\xe1\xb3\x95"sv, true, ECMAScriptFlags::Unicode }, // U+01CD5
    };

    for (auto& test : tests) {
        Regex<ECMA262> re(test.pattern, (ECMAScriptFlags)regex::AllFlags::Global | regex::ECMAScriptFlags::BrowserExtended | test.options);

        auto subject = AK::utf8_to_utf16(test.subject);
        Utf16View view { subject };

        if constexpr (REGEX_DEBUG) {
            dbgln("\n");
            RegexDebug regex_dbg(stderr);
            regex_dbg.print_raw_bytecode(re);
            regex_dbg.print_header();
            regex_dbg.print_bytecode(re);
            dbgln("\n");
        }

        EXPECT_EQ(re.parser_result.error, Error::NoError);
        EXPECT_EQ(re.match(view).success, test.matches);
    }
}

TEST_CASE(replace)
{
    struct _test {
        StringView pattern;
        StringView replacement;
        StringView subject;
        StringView expected;
        ECMAScriptFlags options {};
    };

    constexpr _test tests[] {
        { "foo(.+)"sv, "aaa"sv, "test"sv, "test"sv },
        { "foo(.+)"sv, "test\\1"sv, "foobar"sv, "testbar"sv },
        { "foo(.+)"sv, "\\2\\1"sv, "foobar"sv, "\\2bar"sv },
        { "foo(.+)"sv, "\\\\\\1"sv, "foobar"sv, "\\bar"sv },
        { "foo(.)"sv, "a\\1"sv, "fooxfooy"sv, "axay"sv, ECMAScriptFlags::Multiline },
    };

    for (auto& test : tests) {
        Regex<ECMA262> re(test.pattern, test.options);
        if constexpr (REGEX_DEBUG) {
            dbgln("\n");
            RegexDebug regex_dbg(stderr);
            regex_dbg.print_raw_bytecode(re);
            regex_dbg.print_header();
            regex_dbg.print_bytecode(re);
            dbgln("\n");
        }
        EXPECT_EQ(re.parser_result.error, Error::NoError);
        EXPECT_EQ(re.replace(test.subject, test.replacement), test.expected);
    }
}

TEST_CASE(case_insensitive_match)
{
    Regex<PosixExtended> re("cd", PosixFlags::Insensitive | PosixFlags::Global);
    auto result = re.match("AEKFCD");

    EXPECT_EQ(result.success, true);
    if (result.success) {
        EXPECT_EQ(result.matches.at(0).column, 4ul);
    }
}

TEST_CASE(extremely_long_fork_chain)
{
    Regex<ECMA262> re("(?:aa)*");
    auto result = re.match(String::repeated('a', 100'000));
    EXPECT_EQ(result.success, true);
}

static auto g_lots_of_a_s = String::repeated('a', 10'000'000);

BENCHMARK_CASE(fork_performance)
{
    Regex<ECMA262> re("(?:aa)*");
    auto result = re.match(g_lots_of_a_s);
    EXPECT_EQ(result.success, true);
}
