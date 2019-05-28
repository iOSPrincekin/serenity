#pragma once

#include <AK/Vector.h>
#include <LibGUI/GDirectoryModel.h>
#include <LibGUI/GItemView.h>
#include <LibGUI/GStackWidget.h>
#include <LibGUI/GTableView.h>
#include <sys/stat.h>

class DirectoryView final : public GStackWidget {
public:
    explicit DirectoryView(GWidget* parent);
    virtual ~DirectoryView() override;

    void open(const String& path);
    String path() const { return model().path(); }
    void open_parent_directory();
    void open_previous_directory();
    void open_next_directory();
    int path_history_size() const { return m_path_history.size(); }
    int path_history_position() const { return m_path_history_position; }

    void refresh();

    Function<void(const String&)> on_path_change;
    Function<void(String)> on_status_message;
    Function<void(int done, int total)> on_thumbnail_progress;

    enum ViewMode
    {
        Invalid,
        List,
        Icon
    };
    void set_view_mode(ViewMode);
    ViewMode view_mode() const { return m_view_mode; }

private:
    GDirectoryModel& model() { return *m_model; }
    const GDirectoryModel& model() const { return *m_model; }

    void handle_activation(const GModelIndex&);

    void set_status_message(const String&);

    ViewMode m_view_mode { Invalid };

    Retained<GDirectoryModel> m_model;
    int m_path_history_position { 0 };
    Vector<String> m_path_history;
    void add_path_to_history(const String& path);

    GTableView* m_table_view { nullptr };
    GItemView* m_item_view { nullptr };
};
