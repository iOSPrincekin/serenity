/*
 * Copyright (c) 2021, Federico Guerinoni <guerinoni.federico@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/Button.h>
#include <LibGUI/TableView.h>
#include <LibGUI/TextBox.h>
#include <LibGUI/Widget.h>

namespace HackStudio {

class ToDoEntriesWidget final : public GUI::Widget {
    C_OBJECT(ToDoEntriesWidget)
public:
    virtual ~ToDoEntriesWidget() override { }

    void refresh();

private:
    explicit ToDoEntriesWidget();

    RefPtr<GUI::TableView> m_result_view;
};

}
