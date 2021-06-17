/*
 * Copyright (c) 2018-2021, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "WindowStack.h"
#include <AK/HashMap.h>
#include <AK/HashTable.h>
#include <AK/WeakPtr.h>
#include <LibCore/ConfigFile.h>
#include <LibCore/ElapsedTimer.h>
#include <LibGfx/Color.h>
#include <LibGfx/DisjointRectSet.h>
#include <LibGfx/Painter.h>
#include <LibGfx/Palette.h>
#include <LibGfx/Rect.h>
#include <WindowServer/Cursor.h>
#include <WindowServer/Event.h>
#include <WindowServer/MenuManager.h>
#include <WindowServer/Menubar.h>
#include <WindowServer/WMClientConnection.h>
#include <WindowServer/WindowSwitcher.h>
#include <WindowServer/WindowType.h>

namespace WindowServer {

const int double_click_speed_max = 900;
const int double_click_speed_min = 100;

class Screen;
class MouseEvent;
class Window;
class ClientConnection;
class WindowSwitcher;
class Button;

enum class ResizeDirection {
    None,
    Left,
    UpLeft,
    Up,
    UpRight,
    Right,
    DownRight,
    Down,
    DownLeft
};

class WindowManager : public Core::Object {
    C_OBJECT(WindowManager)

    friend class Compositor;
    friend class WindowFrame;
    friend class WindowSwitcher;

public:
    static WindowManager& the();

    explicit WindowManager(const Gfx::PaletteImpl&);
    virtual ~WindowManager() override;

    Palette palette() const { return Palette(*m_palette); }

    RefPtr<Core::ConfigFile> config() const { return m_config; }
    void reload_config();

    void add_window(Window&);
    void remove_window(Window&);

    void notify_title_changed(Window&);
    void notify_modal_unparented(Window&);
    void notify_rect_changed(Window&, const Gfx::IntRect& oldRect, const Gfx::IntRect& newRect);
    void notify_minimization_state_changed(Window&);
    void notify_opacity_changed(Window&);
    void notify_occlusion_state_changed(Window&);
    void notify_progress_changed(Window&);
    void notify_modified_changed(Window&);

    Gfx::IntRect maximized_window_rect(const Window&) const;

    const ClientConnection* dnd_client() const { return m_dnd_client.ptr(); }
    const String& dnd_text() const { return m_dnd_text; }
    const Core::MimeData& dnd_mime_data() const { return *m_dnd_mime_data; }
    const Gfx::Bitmap* dnd_bitmap() const { return m_dnd_bitmap; }
    Gfx::IntRect dnd_rect() const;

    void start_dnd_drag(ClientConnection&, const String& text, const Gfx::Bitmap*, const Core::MimeData&);
    void end_dnd_drag();

    Window* active_window() { return m_active_window.ptr(); }
    const Window* active_window() const { return m_active_window.ptr(); }
    Window* active_input_window() { return m_active_input_window.ptr(); }
    const Window* active_input_window() const { return m_active_input_window.ptr(); }
    const ClientConnection* active_client() const;

    Window* window_with_active_menu() { return m_window_with_active_menu; }
    const Window* window_with_active_menu() const { return m_window_with_active_menu; }
    void set_window_with_active_menu(Window*);

    Window const* highlight_window() const { return m_window_stack.highlight_window(); }
    void set_highlight_window(Window*);

    void move_to_front_and_make_active(Window&);

    Gfx::IntRect desktop_rect() const;
    Gfx::IntRect arena_rect_for_type(WindowType) const;

    const Cursor& active_cursor() const;
    const Cursor& hidden_cursor() const { return *m_hidden_cursor; }
    const Cursor& arrow_cursor() const { return *m_arrow_cursor; }
    const Cursor& crosshair_cursor() const { return *m_crosshair_cursor; }
    const Cursor& hand_cursor() const { return *m_hand_cursor; }
    const Cursor& help_cursor() const { return *m_help_cursor; }
    const Cursor& resize_horizontally_cursor() const { return *m_resize_horizontally_cursor; }
    const Cursor& resize_vertically_cursor() const { return *m_resize_vertically_cursor; }
    const Cursor& resize_diagonally_tlbr_cursor() const { return *m_resize_diagonally_tlbr_cursor; }
    const Cursor& resize_diagonally_bltr_cursor() const { return *m_resize_diagonally_bltr_cursor; }
    const Cursor& resize_column_cursor() const { return *m_resize_column_cursor; }
    const Cursor& resize_row_cursor() const { return *m_resize_row_cursor; }
    const Cursor& i_beam_cursor() const { return *m_i_beam_cursor; }
    const Cursor& disallowed_cursor() const { return *m_disallowed_cursor; }
    const Cursor& move_cursor() const { return *m_move_cursor; }
    const Cursor& drag_cursor() const { return *m_drag_cursor; }
    const Cursor& wait_cursor() const { return *m_wait_cursor; }

    const Gfx::Font& font() const;
    const Gfx::Font& window_title_font() const;

    bool set_resolution(int width, int height, int scale);
    Gfx::IntSize resolution() const;
    int scale_factor() const;

    void set_acceleration_factor(double);
    void set_scroll_step_size(unsigned);
    void set_double_click_speed(int);
    int double_click_speed() const;

    Window* set_active_input_window(Window*);
    void restore_active_input_window(Window*);
    void set_active_window(Window*, bool make_input = true);
    void set_hovered_button(Button*);

    const Button* cursor_tracking_button() const { return m_cursor_tracking_button.ptr(); }
    void set_cursor_tracking_button(Button*);

    void set_resize_candidate(Window&, ResizeDirection);
    void clear_resize_candidate();
    ResizeDirection resize_direction_of_window(const Window&);

    void greet_window_manager(WMClientConnection&);
    void tell_wms_window_state_changed(Window&);
    void tell_wms_window_icon_changed(Window&);
    void tell_wms_window_rect_changed(Window&);
    void tell_wms_applet_area_size_changed(const Gfx::IntSize&);
    void tell_wms_super_key_pressed();

    bool is_active_window_or_accessory(Window&) const;

    void start_window_resize(Window&, const Gfx::IntPoint&, MouseButton);
    void start_window_resize(Window&, const MouseEvent&);
    void start_window_move(Window&, const MouseEvent&);
    void start_window_move(Window&, const Gfx::IntPoint&);

    const Window* active_fullscreen_window() const
    {
        if (m_active_window && m_active_window->is_fullscreen()) {
            return m_active_window;
        }
        return nullptr;
    };

    Window* active_fullscreen_window()
    {
        if (m_active_window && m_active_window->is_fullscreen()) {
            return m_active_window;
        }
        return nullptr;
    }

    bool update_theme(String theme_path, String theme_name);
    void invalidate_after_theme_or_font_change();

    bool set_hovered_window(Window*);
    void deliver_mouse_event(Window& window, MouseEvent& event, bool process_double_click);

    void did_popup_a_menu(Badge<Menu>);

    void start_menu_doubleclick(Window& window, const MouseEvent& event);
    bool is_menu_doubleclick(Window& window, const MouseEvent& event) const;

    void minimize_windows(Window&, bool);
    void maximize_windows(Window&, bool);

    template<typename Function>
    IterationDecision for_each_window_in_modal_stack(Window& window, Function f)
    {
        auto* blocking_modal_window = window.blocking_modal_window();
        if (blocking_modal_window || window.is_modal()) {
            Vector<Window&> modal_stack;
            auto* modal_stack_top = blocking_modal_window ? blocking_modal_window : &window;
            for (auto* parent = modal_stack_top->parent_window(); parent; parent = parent->parent_window()) {
                auto* blocked_by = parent->blocking_modal_window();
                if (!blocked_by || (blocked_by != modal_stack_top && !modal_stack_top->is_descendant_of(*blocked_by)))
                    break;
                modal_stack.append(*parent);
                if (!parent->is_modal())
                    break;
            }
            if (!modal_stack.is_empty()) {
                for (size_t i = modal_stack.size(); i > 0; i--) {
                    IterationDecision decision = f(modal_stack[i - 1], false);
                    if (decision != IterationDecision::Continue)
                        return decision;
                }
            }
            return f(*modal_stack_top, true);
        } else {
            // Not a modal window stack, just "iterate" over this window
            return f(window, true);
        }
    }

    Gfx::IntPoint get_recommended_window_position(const Gfx::IntPoint& desired);

    int compositor_icon_scale() const;
    void reload_icon_bitmaps_after_scale_change(bool allow_hidpi_icons = true);

    void reevaluate_hovered_window(Window* = nullptr);
    Window* hovered_window() const { return m_hovered_window.ptr(); }

    WindowStack& window_stack() { return m_window_stack; }

private:
    NonnullRefPtr<Cursor> get_cursor(const String& name);

    void process_mouse_event(MouseEvent&, Window*& hovered_window);
    void process_event_for_doubleclick(Window& window, MouseEvent& event);
    bool process_ongoing_window_resize(const MouseEvent&, Window*& hovered_window);
    bool process_ongoing_window_move(MouseEvent&, Window*& hovered_window);
    bool process_ongoing_drag(MouseEvent&, Window*& hovered_window);

    template<typename Callback>
    void for_each_window_manager(Callback);

    virtual void event(Core::Event&) override;
    void tell_wm_about_window(WMClientConnection& conn, Window&);
    void tell_wm_about_window_icon(WMClientConnection& conn, Window&);
    void tell_wm_about_window_rect(WMClientConnection& conn, Window&);
    bool pick_new_active_window(Window*);

    void do_move_to_front(Window&, bool, bool);

    bool m_allow_hidpi_icons { true };
    RefPtr<Cursor> m_hidden_cursor;
    RefPtr<Cursor> m_arrow_cursor;
    RefPtr<Cursor> m_hand_cursor;
    RefPtr<Cursor> m_help_cursor;
    RefPtr<Cursor> m_resize_horizontally_cursor;
    RefPtr<Cursor> m_resize_vertically_cursor;
    RefPtr<Cursor> m_resize_diagonally_tlbr_cursor;
    RefPtr<Cursor> m_resize_diagonally_bltr_cursor;
    RefPtr<Cursor> m_resize_column_cursor;
    RefPtr<Cursor> m_resize_row_cursor;
    RefPtr<Cursor> m_i_beam_cursor;
    RefPtr<Cursor> m_disallowed_cursor;
    RefPtr<Cursor> m_move_cursor;
    RefPtr<Cursor> m_drag_cursor;
    RefPtr<Cursor> m_wait_cursor;
    RefPtr<Cursor> m_crosshair_cursor;

    WindowStack m_window_stack;

    struct DoubleClickInfo {
        struct ClickMetadata {
            Core::ElapsedTimer clock;
            Gfx::IntPoint last_position;
        };

        const ClickMetadata& metadata_for_button(MouseButton) const;
        ClickMetadata& metadata_for_button(MouseButton);

        void reset()
        {
            m_left = {};
            m_right = {};
            m_middle = {};
            m_back = {};
            m_forward = {};
        }

        WeakPtr<Window> m_clicked_window;

    private:
        ClickMetadata m_left;
        ClickMetadata m_right;
        ClickMetadata m_middle;
        ClickMetadata m_back;
        ClickMetadata m_forward;
    };

    bool is_considered_doubleclick(const MouseEvent& event, const DoubleClickInfo::ClickMetadata& metadata) const;

    DoubleClickInfo m_double_click_info;
    int m_double_click_speed { 0 };
    int m_max_distance_for_double_click { 4 };
    bool m_previous_event_was_super_keydown { false };

    WeakPtr<Window> m_active_window;
    WeakPtr<Window> m_hovered_window;
    WeakPtr<Window> m_active_input_window;
    WeakPtr<Window> m_active_input_tracking_window;
    WeakPtr<Window> m_window_with_active_menu;

    WeakPtr<Window> m_move_window;
    Gfx::IntPoint m_move_origin;
    Gfx::IntPoint m_move_window_origin;

    WeakPtr<Window> m_resize_window;
    WeakPtr<Window> m_resize_candidate;
    MouseButton m_resizing_mouse_button { MouseButton::None };
    Gfx::IntRect m_resize_window_original_rect;
    Gfx::IntPoint m_resize_origin;
    ResizeDirection m_resize_direction { ResizeDirection::None };

    u8 m_keyboard_modifiers { 0 };

    WindowSwitcher m_switcher;

    WeakPtr<Button> m_cursor_tracking_button;
    WeakPtr<Button> m_hovered_button;

    NonnullRefPtr<Gfx::PaletteImpl> m_palette;

    RefPtr<Core::ConfigFile> m_config;

    WeakPtr<ClientConnection> m_dnd_client;
    String m_dnd_text;
    RefPtr<Core::MimeData> m_dnd_mime_data;
    RefPtr<Gfx::Bitmap> m_dnd_bitmap;
};

template<typename Callback>
void WindowManager::for_each_window_manager(Callback callback)
{
    auto& connections = WMClientConnection::s_connections;

    // FIXME: this isn't really ordered... does it need to be?
    for (auto it = connections.begin(); it != connections.end(); ++it) {
        if (callback(*it->value) == IterationDecision::Break)
            return;
    }
}

}
