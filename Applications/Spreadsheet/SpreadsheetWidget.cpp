/*
 * Copyright (c) 2020, the SerenityOS developers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "SpreadsheetWidget.h"
#include "CellSyntaxHighlighter.h"
#include "HelpWindow.h"
#include <AK/JsonArray.h>
#include <AK/JsonObject.h>
#include <AK/JsonObjectSerializer.h>
#include <LibCore/File.h>
#include <LibGUI/BoxLayout.h>
#include <LibGUI/Button.h>
#include <LibGUI/Label.h>
#include <LibGUI/MessageBox.h>
#include <LibGUI/Splitter.h>
#include <LibGUI/TabWidget.h>
#include <LibGUI/TextEditor.h>
#include <string.h>

namespace Spreadsheet {

SpreadsheetWidget::SpreadsheetWidget()
{
    set_fill_with_background_color(true);
    set_layout<GUI::VerticalBoxLayout>().set_margins({ 2, 2, 2, 2 });
    auto& container = add<GUI::VerticalSplitter>();

    auto& top_bar = container.add<GUI::Frame>();
    top_bar.set_layout<GUI::HorizontalBoxLayout>().set_spacing(1);
    top_bar.set_preferred_size(0, 50);
    top_bar.set_size_policy(GUI::SizePolicy::Fill, GUI::SizePolicy::Fixed);
    auto& current_cell_label = top_bar.add<GUI::Label>("");
    current_cell_label.set_preferred_size(50, 0);
    current_cell_label.set_size_policy(GUI::SizePolicy::Fixed, GUI::SizePolicy::Fill);

    auto& help_button = top_bar.add<GUI::Button>("🛈");
    help_button.set_preferred_size(20, 20);
    help_button.set_size_policy(GUI::SizePolicy::Fixed, GUI::SizePolicy::Fixed);
    help_button.on_click = [&](auto) {
        auto docs = m_selected_view->sheet().gather_documentation();
        auto help_window = HelpWindow::the();
        help_window->set_docs(move(docs));
        help_window->show();
    };

    auto& cell_value_editor = top_bar.add<GUI::TextEditor>(GUI::TextEditor::Type::SingleLine);
    cell_value_editor.set_scrollbars_enabled(false);

    cell_value_editor.set_syntax_highlighter(make<CellSyntaxHighlighter>());
    cell_value_editor.set_enabled(false);
    current_cell_label.set_enabled(false);

    m_tab_widget = container.add<GUI::TabWidget>();
    m_tab_widget->set_tab_position(GUI::TabWidget::TabPosition::Bottom);

    m_sheets.append(Sheet::construct("Sheet 1"));
    auto& tab = m_tab_widget->add_tab<SpreadsheetView>(m_sheets.first().name(), m_sheets.first());

    auto change = [&](auto& selected_widget) {
        if (m_selected_view) {
            m_selected_view->on_selection_changed = nullptr;
            m_selected_view->on_selection_dropped = nullptr;
        };
        m_selected_view = &static_cast<SpreadsheetView&>(selected_widget);
        m_selected_view->on_selection_changed = [&](const Position& position, Cell& cell) {
            StringBuilder builder;
            builder.append(position.column);
            builder.appendf("%zu", position.row);
            current_cell_label.set_enabled(true);
            current_cell_label.set_text(builder.string_view());

            cell_value_editor.on_change = nullptr;
            cell_value_editor.set_text(cell.source());
            cell_value_editor.on_change = [&] {
                cell.set_data(cell_value_editor.text());
                m_selected_view->sheet().update();
            };
            cell_value_editor.set_enabled(true);
        };
        m_selected_view->on_selection_dropped = [&]() {
            cell_value_editor.set_enabled(false);
            cell_value_editor.set_text("");
            current_cell_label.set_enabled(false);
            current_cell_label.set_text("");
        };
    };

    change(tab);
    m_tab_widget->on_change = [change = move(change)](auto& selected_widget) {
        change(selected_widget);
    };
}

SpreadsheetWidget::~SpreadsheetWidget()
{
}

void SpreadsheetWidget::save(const StringView& filename)
{
    JsonArray array;
    m_tab_widget->for_each_child_of_type<SpreadsheetView>([&](auto& view) {
        array.append(view.sheet().to_json());
        return IterationDecision::Continue;
    });

    auto file_content = array.to_string();

    auto file = Core::File::construct(filename);
    file->open(Core::IODevice::WriteOnly);
    if (!file->is_open()) {
        StringBuilder sb;
        sb.append("Failed to open ");
        sb.append(filename);
        sb.append(" for write. Error: ");
        sb.append(file->error_string());

        GUI::MessageBox::show(window(), sb.to_string(), "Error", GUI::MessageBox::Type::Error);
        return;
    }

    bool result = file->write(file_content);
    if (!result) {
        int error_number = errno;
        StringBuilder sb;
        sb.append("Unable to save file. Error: ");
        sb.append(strerror(error_number));

        GUI::MessageBox::show(window(), sb.to_string(), "Error", GUI::MessageBox::Type::Error);
        return;
    }
}

}
