#pragma once
#include <LibCore/AnonymousBuffer.h>
#include <LibGfx/ShareableBitmap.h>
#include <AK/MemoryStream.h>
#include <AK/OwnPtr.h>
#include <AK/Result.h>
#include <AK/Utf8View.h>
#include <LibIPC/Connection.h>
#include <LibIPC/Decoder.h>
#include <LibIPC/Dictionary.h>
#include <LibIPC/Encoder.h>
#include <LibIPC/File.h>
#include <LibIPC/Message.h>
#include <LibIPC/Stub.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdefaulted-function-deleted"
#endif

namespace Messages::WindowServer {

enum class MessageID : i32 {
    CreateMenu = 1,
    DestroyMenu = 2,
    AddMenu = 3,
    AddMenuItem = 4,
    AddMenuSeparator = 5,
    UpdateMenuItem = 6,
    RemoveMenuItem = 7,
    FlashMenubarMenu = 8,
    CreateWindow = 9,
    DestroyWindow = 10,
    DestroyWindowResponse = 11,
    SetWindowTitle = 12,
    GetWindowTitle = 13,
    GetWindowTitleResponse = 14,
    SetWindowProgress = 15,
    SetWindowModified = 16,
    IsWindowModified = 17,
    IsWindowModifiedResponse = 18,
    SetWindowRect = 19,
    SetWindowRectResponse = 20,
    GetWindowRect = 21,
    GetWindowRectResponse = 22,
    SetWindowMinimumSize = 23,
    GetWindowMinimumSize = 24,
    GetWindowMinimumSizeResponse = 25,
    GetAppletRectOnScreen = 26,
    GetAppletRectOnScreenResponse = 27,
    StartWindowResize = 28,
    IsMaximized = 29,
    IsMaximizedResponse = 30,
    SetMaximized = 31,
    InvalidateRect = 32,
    DidFinishPainting = 33,
    SetGlobalMouseTracking = 34,
    SetWindowOpacity = 35,
    SetWindowAlphaHitThreshold = 36,
    SetWindowBackingStore = 37,
    SetWindowBackingStoreResponse = 38,
    SetWindowHasAlphaChannel = 39,
    MoveWindowToFront = 40,
    SetFullscreen = 41,
    SetFrameless = 42,
    SetForcedShadow = 43,
    PopupMenu = 44,
    DismissMenu = 45,
    SetWallpaper = 46,
    SetBackgroundColor = 47,
    SetWallpaperMode = 48,
    SetScreenLayout = 49,
    SetScreenLayoutResponse = 50,
    GetScreenLayout = 51,
    GetScreenLayoutResponse = 52,
    SaveScreenLayout = 53,
    SaveScreenLayoutResponse = 54,
    ShowScreenNumbers = 55,
    ApplyWorkspaceSettings = 56,
    ApplyWorkspaceSettingsResponse = 57,
    GetWorkspaceSettings = 58,
    GetWorkspaceSettingsResponse = 59,
    SetWindowIconBitmap = 60,
    GetWallpaper = 61,
    GetWallpaperResponse = 62,
    SetWindowCursor = 63,
    SetWindowCustomCursor = 64,
    StartDrag = 65,
    StartDragResponse = 66,
    SetSystemTheme = 67,
    SetSystemThemeResponse = 68,
    GetSystemTheme = 69,
    GetSystemThemeResponse = 70,
    RefreshSystemTheme = 71,
    ApplyCursorTheme = 72,
    GetCursorTheme = 73,
    GetCursorThemeResponse = 74,
    SetSystemFonts = 75,
    SetSystemFontsResponse = 76,
    SetWindowBaseSizeAndSizeIncrement = 77,
    SetWindowResizeAspectRatio = 78,
    EnableDisplayLink = 79,
    DisableDisplayLink = 80,
    SetGlobalCursorPosition = 81,
    GetGlobalCursorPosition = 82,
    GetGlobalCursorPositionResponse = 83,
    SetMouseAcceleration = 84,
    GetMouseAcceleration = 85,
    GetMouseAccelerationResponse = 86,
    SetScrollStepSize = 87,
    GetScrollStepSize = 88,
    GetScrollStepSizeResponse = 89,
    GetScreenBitmap = 90,
    GetScreenBitmapResponse = 91,
    GetScreenBitmapAroundCursor = 92,
    GetScreenBitmapAroundCursorResponse = 93,
    GetColorUnderCursor = 94,
    GetColorUnderCursorResponse = 95,
    Pong = 96,
    SetDoubleClickSpeed = 97,
    GetDoubleClickSpeed = 98,
    GetDoubleClickSpeedResponse = 99,
    SetButtonsSwitched = 100,
    GetButtonsSwitched = 101,
    GetButtonsSwitchedResponse = 102,
    GetDesktopDisplayScale = 103,
    GetDesktopDisplayScaleResponse = 104,
    SetFlashFlush = 105,
    SetWindowParentFromClient = 106,
    GetWindowRectFromClient = 107,
    GetWindowRectFromClientResponse = 108,
    AddWindowStealingForClient = 109,
    RemoveWindowStealingForClient = 110,
    RemoveWindowStealing = 111,
};

class CreateMenu final : public IPC::Message {
public:

    CreateMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CreateMenu(CreateMenu const&) = default;
    CreateMenu(CreateMenu&&) = default;
    CreateMenu& operator=(CreateMenu const&) = default;
    CreateMenu(i32 menu_id, String menu_title) : m_menu_id(move(menu_id)), m_menu_title(move(menu_title)) {}
    virtual ~CreateMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::CreateMenu; }
    static i32 static_message_id() { return (int)MessageID::CreateMenu; }
    virtual const char* message_name() const override { return "WindowServer::CreateMenu"; }

    static OwnPtr<CreateMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        String menu_title = {};
        if (decoder.decode(menu_title).is_error())
            return {};

        if (!Utf8View(menu_title).validate())
            return {};

        return make<CreateMenu>(move(menu_id), move(menu_title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CreateMenu;

        stream << m_menu_id;

        stream << m_menu_title;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const String& menu_title() const { return m_menu_title; }
    String take_menu_title() { return move(m_menu_title); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    String m_menu_title {};

};

class DestroyMenu final : public IPC::Message {
public:

    DestroyMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DestroyMenu(DestroyMenu const&) = default;
    DestroyMenu(DestroyMenu&&) = default;
    DestroyMenu& operator=(DestroyMenu const&) = default;
    DestroyMenu(i32 menu_id) : m_menu_id(move(menu_id)) {}
    virtual ~DestroyMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DestroyMenu; }
    static i32 static_message_id() { return (int)MessageID::DestroyMenu; }
    virtual const char* message_name() const override { return "WindowServer::DestroyMenu"; }

    static OwnPtr<DestroyMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        return make<DestroyMenu>(move(menu_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DestroyMenu;

        stream << m_menu_id;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

};

class AddMenu final : public IPC::Message {
public:

    AddMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddMenu(AddMenu const&) = default;
    AddMenu(AddMenu&&) = default;
    AddMenu& operator=(AddMenu const&) = default;
    AddMenu(i32 window_id, i32 menu_id) : m_window_id(move(window_id)), m_menu_id(move(menu_id)) {}
    virtual ~AddMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::AddMenu; }
    static i32 static_message_id() { return (int)MessageID::AddMenu; }
    virtual const char* message_name() const override { return "WindowServer::AddMenu"; }

    static OwnPtr<AddMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        return make<AddMenu>(move(window_id), move(menu_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddMenu;

        stream << m_window_id;

        stream << m_menu_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    i32 m_menu_id {};

};

class AddMenuItem final : public IPC::Message {
public:

    AddMenuItem(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddMenuItem(AddMenuItem const&) = default;
    AddMenuItem(AddMenuItem&&) = default;
    AddMenuItem& operator=(AddMenuItem const&) = default;
    AddMenuItem(i32 menu_id, i32 identifier, i32 submenu_id, String text, bool enabled, bool checkable, bool checked, bool is_default, String shortcut, Gfx::ShareableBitmap icon, bool exclusive) : m_menu_id(move(menu_id)), m_identifier(move(identifier)), m_submenu_id(move(submenu_id)), m_text(move(text)), m_enabled(move(enabled)), m_checkable(move(checkable)), m_checked(move(checked)), m_is_default(move(is_default)), m_shortcut(move(shortcut)), m_icon(move(icon)), m_exclusive(move(exclusive)) {}
    virtual ~AddMenuItem() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::AddMenuItem; }
    static i32 static_message_id() { return (int)MessageID::AddMenuItem; }
    virtual const char* message_name() const override { return "WindowServer::AddMenuItem"; }

    static OwnPtr<AddMenuItem> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        i32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        i32 submenu_id = {};
        if (decoder.decode(submenu_id).is_error())
            return {};

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        bool enabled = false;
        if (decoder.decode(enabled).is_error())
            return {};

        bool checkable = false;
        if (decoder.decode(checkable).is_error())
            return {};

        bool checked = false;
        if (decoder.decode(checked).is_error())
            return {};

        bool is_default = false;
        if (decoder.decode(is_default).is_error())
            return {};

        String shortcut = {};
        if (decoder.decode(shortcut).is_error())
            return {};

        if (!Utf8View(shortcut).validate())
            return {};

        Gfx::ShareableBitmap icon = {};
        if (decoder.decode(icon).is_error())
            return {};

        bool exclusive = false;
        if (decoder.decode(exclusive).is_error())
            return {};

        return make<AddMenuItem>(move(menu_id), move(identifier), move(submenu_id), move(text), move(enabled), move(checkable), move(checked), move(is_default), move(shortcut), move(icon), move(exclusive));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddMenuItem;

        stream << m_menu_id;

        stream << m_identifier;

        stream << m_submenu_id;

        stream << m_text;

        stream << m_enabled;

        stream << m_checkable;

        stream << m_checked;

        stream << m_is_default;

        stream << m_shortcut;

        stream << m_icon;

        stream << m_exclusive;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const i32& identifier() const { return m_identifier; }
    i32 take_identifier() { return move(m_identifier); }

    const i32& submenu_id() const { return m_submenu_id; }
    i32 take_submenu_id() { return move(m_submenu_id); }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const bool& enabled() const { return m_enabled; }
    bool take_enabled() { return move(m_enabled); }

    const bool& checkable() const { return m_checkable; }
    bool take_checkable() { return move(m_checkable); }

    const bool& checked() const { return m_checked; }
    bool take_checked() { return move(m_checked); }

    const bool& is_default() const { return m_is_default; }
    bool take_is_default() { return move(m_is_default); }

    const String& shortcut() const { return m_shortcut; }
    String take_shortcut() { return move(m_shortcut); }

    const Gfx::ShareableBitmap& icon() const { return m_icon; }
    Gfx::ShareableBitmap take_icon() { return move(m_icon); }

    const bool& exclusive() const { return m_exclusive; }
    bool take_exclusive() { return move(m_exclusive); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    i32 m_identifier {};

    i32 m_submenu_id {};

    String m_text {};

    bool m_enabled {};

    bool m_checkable {};

    bool m_checked {};

    bool m_is_default {};

    String m_shortcut {};

    Gfx::ShareableBitmap m_icon {};

    bool m_exclusive {};

};

class AddMenuSeparator final : public IPC::Message {
public:

    AddMenuSeparator(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddMenuSeparator(AddMenuSeparator const&) = default;
    AddMenuSeparator(AddMenuSeparator&&) = default;
    AddMenuSeparator& operator=(AddMenuSeparator const&) = default;
    AddMenuSeparator(i32 menu_id) : m_menu_id(move(menu_id)) {}
    virtual ~AddMenuSeparator() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::AddMenuSeparator; }
    static i32 static_message_id() { return (int)MessageID::AddMenuSeparator; }
    virtual const char* message_name() const override { return "WindowServer::AddMenuSeparator"; }

    static OwnPtr<AddMenuSeparator> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        return make<AddMenuSeparator>(move(menu_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddMenuSeparator;

        stream << m_menu_id;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

};

class UpdateMenuItem final : public IPC::Message {
public:

    UpdateMenuItem(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateMenuItem(UpdateMenuItem const&) = default;
    UpdateMenuItem(UpdateMenuItem&&) = default;
    UpdateMenuItem& operator=(UpdateMenuItem const&) = default;
    UpdateMenuItem(i32 menu_id, i32 identifier, i32 submenu_id, String text, bool enabled, bool checkable, bool checked, bool is_default, String shortcut) : m_menu_id(move(menu_id)), m_identifier(move(identifier)), m_submenu_id(move(submenu_id)), m_text(move(text)), m_enabled(move(enabled)), m_checkable(move(checkable)), m_checked(move(checked)), m_is_default(move(is_default)), m_shortcut(move(shortcut)) {}
    virtual ~UpdateMenuItem() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateMenuItem; }
    static i32 static_message_id() { return (int)MessageID::UpdateMenuItem; }
    virtual const char* message_name() const override { return "WindowServer::UpdateMenuItem"; }

    static OwnPtr<UpdateMenuItem> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        i32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        i32 submenu_id = {};
        if (decoder.decode(submenu_id).is_error())
            return {};

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        bool enabled = false;
        if (decoder.decode(enabled).is_error())
            return {};

        bool checkable = false;
        if (decoder.decode(checkable).is_error())
            return {};

        bool checked = false;
        if (decoder.decode(checked).is_error())
            return {};

        bool is_default = false;
        if (decoder.decode(is_default).is_error())
            return {};

        String shortcut = {};
        if (decoder.decode(shortcut).is_error())
            return {};

        if (!Utf8View(shortcut).validate())
            return {};

        return make<UpdateMenuItem>(move(menu_id), move(identifier), move(submenu_id), move(text), move(enabled), move(checkable), move(checked), move(is_default), move(shortcut));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateMenuItem;

        stream << m_menu_id;

        stream << m_identifier;

        stream << m_submenu_id;

        stream << m_text;

        stream << m_enabled;

        stream << m_checkable;

        stream << m_checked;

        stream << m_is_default;

        stream << m_shortcut;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const i32& identifier() const { return m_identifier; }
    i32 take_identifier() { return move(m_identifier); }

    const i32& submenu_id() const { return m_submenu_id; }
    i32 take_submenu_id() { return move(m_submenu_id); }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const bool& enabled() const { return m_enabled; }
    bool take_enabled() { return move(m_enabled); }

    const bool& checkable() const { return m_checkable; }
    bool take_checkable() { return move(m_checkable); }

    const bool& checked() const { return m_checked; }
    bool take_checked() { return move(m_checked); }

    const bool& is_default() const { return m_is_default; }
    bool take_is_default() { return move(m_is_default); }

    const String& shortcut() const { return m_shortcut; }
    String take_shortcut() { return move(m_shortcut); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    i32 m_identifier {};

    i32 m_submenu_id {};

    String m_text {};

    bool m_enabled {};

    bool m_checkable {};

    bool m_checked {};

    bool m_is_default {};

    String m_shortcut {};

};

class RemoveMenuItem final : public IPC::Message {
public:

    RemoveMenuItem(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RemoveMenuItem(RemoveMenuItem const&) = default;
    RemoveMenuItem(RemoveMenuItem&&) = default;
    RemoveMenuItem& operator=(RemoveMenuItem const&) = default;
    RemoveMenuItem(i32 menu_id, i32 identifier) : m_menu_id(move(menu_id)), m_identifier(move(identifier)) {}
    virtual ~RemoveMenuItem() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::RemoveMenuItem; }
    static i32 static_message_id() { return (int)MessageID::RemoveMenuItem; }
    virtual const char* message_name() const override { return "WindowServer::RemoveMenuItem"; }

    static OwnPtr<RemoveMenuItem> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        i32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        return make<RemoveMenuItem>(move(menu_id), move(identifier));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RemoveMenuItem;

        stream << m_menu_id;

        stream << m_identifier;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const i32& identifier() const { return m_identifier; }
    i32 take_identifier() { return move(m_identifier); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    i32 m_identifier {};

};

class FlashMenubarMenu final : public IPC::Message {
public:

    FlashMenubarMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FlashMenubarMenu(FlashMenubarMenu const&) = default;
    FlashMenubarMenu(FlashMenubarMenu&&) = default;
    FlashMenubarMenu& operator=(FlashMenubarMenu const&) = default;
    FlashMenubarMenu(i32 window_id, i32 menu_id) : m_window_id(move(window_id)), m_menu_id(move(menu_id)) {}
    virtual ~FlashMenubarMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::FlashMenubarMenu; }
    static i32 static_message_id() { return (int)MessageID::FlashMenubarMenu; }
    virtual const char* message_name() const override { return "WindowServer::FlashMenubarMenu"; }

    static OwnPtr<FlashMenubarMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        return make<FlashMenubarMenu>(move(window_id), move(menu_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FlashMenubarMenu;

        stream << m_window_id;

        stream << m_menu_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    i32 m_menu_id {};

};

class CreateWindow final : public IPC::Message {
public:

    CreateWindow(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CreateWindow(CreateWindow const&) = default;
    CreateWindow(CreateWindow&&) = default;
    CreateWindow& operator=(CreateWindow const&) = default;
    CreateWindow(i32 window_id, Gfx::IntRect rect, bool auto_position, bool has_alpha_channel, bool modal, bool minimizable, bool closeable, bool resizable, bool fullscreen, bool frameless, bool forced_shadow, bool accessory, float opacity, float alpha_hit_threshold, Gfx::IntSize base_size, Gfx::IntSize size_increment, Gfx::IntSize minimum_size, Optional<Gfx::IntSize> resize_aspect_ratio, i32 type, String title, i32 parent_window_id, Gfx::IntRect launch_origin_rect) : m_window_id(move(window_id)), m_rect(move(rect)), m_auto_position(move(auto_position)), m_has_alpha_channel(move(has_alpha_channel)), m_modal(move(modal)), m_minimizable(move(minimizable)), m_closeable(move(closeable)), m_resizable(move(resizable)), m_fullscreen(move(fullscreen)), m_frameless(move(frameless)), m_forced_shadow(move(forced_shadow)), m_accessory(move(accessory)), m_opacity(move(opacity)), m_alpha_hit_threshold(move(alpha_hit_threshold)), m_base_size(move(base_size)), m_size_increment(move(size_increment)), m_minimum_size(move(minimum_size)), m_resize_aspect_ratio(move(resize_aspect_ratio)), m_type(move(type)), m_title(move(title)), m_parent_window_id(move(parent_window_id)), m_launch_origin_rect(move(launch_origin_rect)) {}
    virtual ~CreateWindow() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::CreateWindow; }
    static i32 static_message_id() { return (int)MessageID::CreateWindow; }
    virtual const char* message_name() const override { return "WindowServer::CreateWindow"; }

    static OwnPtr<CreateWindow> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        bool auto_position = false;
        if (decoder.decode(auto_position).is_error())
            return {};

        bool has_alpha_channel = false;
        if (decoder.decode(has_alpha_channel).is_error())
            return {};

        bool modal = false;
        if (decoder.decode(modal).is_error())
            return {};

        bool minimizable = false;
        if (decoder.decode(minimizable).is_error())
            return {};

        bool closeable = false;
        if (decoder.decode(closeable).is_error())
            return {};

        bool resizable = false;
        if (decoder.decode(resizable).is_error())
            return {};

        bool fullscreen = false;
        if (decoder.decode(fullscreen).is_error())
            return {};

        bool frameless = false;
        if (decoder.decode(frameless).is_error())
            return {};

        bool forced_shadow = false;
        if (decoder.decode(forced_shadow).is_error())
            return {};

        bool accessory = false;
        if (decoder.decode(accessory).is_error())
            return {};

        float opacity = {};
        if (decoder.decode(opacity).is_error())
            return {};

        float alpha_hit_threshold = {};
        if (decoder.decode(alpha_hit_threshold).is_error())
            return {};

        Gfx::IntSize base_size = {};
        if (decoder.decode(base_size).is_error())
            return {};

        Gfx::IntSize size_increment = {};
        if (decoder.decode(size_increment).is_error())
            return {};

        Gfx::IntSize minimum_size = {};
        if (decoder.decode(minimum_size).is_error())
            return {};

        Optional<Gfx::IntSize> resize_aspect_ratio = {};
        if (decoder.decode(resize_aspect_ratio).is_error())
            return {};

        i32 type = {};
        if (decoder.decode(type).is_error())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        i32 parent_window_id = {};
        if (decoder.decode(parent_window_id).is_error())
            return {};

        Gfx::IntRect launch_origin_rect = {};
        if (decoder.decode(launch_origin_rect).is_error())
            return {};

        return make<CreateWindow>(move(window_id), move(rect), move(auto_position), move(has_alpha_channel), move(modal), move(minimizable), move(closeable), move(resizable), move(fullscreen), move(frameless), move(forced_shadow), move(accessory), move(opacity), move(alpha_hit_threshold), move(base_size), move(size_increment), move(minimum_size), move(resize_aspect_ratio), move(type), move(title), move(parent_window_id), move(launch_origin_rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CreateWindow;

        stream << m_window_id;

        stream << m_rect;

        stream << m_auto_position;

        stream << m_has_alpha_channel;

        stream << m_modal;

        stream << m_minimizable;

        stream << m_closeable;

        stream << m_resizable;

        stream << m_fullscreen;

        stream << m_frameless;

        stream << m_forced_shadow;

        stream << m_accessory;

        stream << m_opacity;

        stream << m_alpha_hit_threshold;

        stream << m_base_size;

        stream << m_size_increment;

        stream << m_minimum_size;

        stream << m_resize_aspect_ratio;

        stream << m_type;

        stream << m_title;

        stream << m_parent_window_id;

        stream << m_launch_origin_rect;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

    const bool& auto_position() const { return m_auto_position; }
    bool take_auto_position() { return move(m_auto_position); }

    const bool& has_alpha_channel() const { return m_has_alpha_channel; }
    bool take_has_alpha_channel() { return move(m_has_alpha_channel); }

    const bool& modal() const { return m_modal; }
    bool take_modal() { return move(m_modal); }

    const bool& minimizable() const { return m_minimizable; }
    bool take_minimizable() { return move(m_minimizable); }

    const bool& closeable() const { return m_closeable; }
    bool take_closeable() { return move(m_closeable); }

    const bool& resizable() const { return m_resizable; }
    bool take_resizable() { return move(m_resizable); }

    const bool& fullscreen() const { return m_fullscreen; }
    bool take_fullscreen() { return move(m_fullscreen); }

    const bool& frameless() const { return m_frameless; }
    bool take_frameless() { return move(m_frameless); }

    const bool& forced_shadow() const { return m_forced_shadow; }
    bool take_forced_shadow() { return move(m_forced_shadow); }

    const bool& accessory() const { return m_accessory; }
    bool take_accessory() { return move(m_accessory); }

    const float& opacity() const { return m_opacity; }
    float take_opacity() { return move(m_opacity); }

    const float& alpha_hit_threshold() const { return m_alpha_hit_threshold; }
    float take_alpha_hit_threshold() { return move(m_alpha_hit_threshold); }

    const Gfx::IntSize& base_size() const { return m_base_size; }
    Gfx::IntSize take_base_size() { return move(m_base_size); }

    const Gfx::IntSize& size_increment() const { return m_size_increment; }
    Gfx::IntSize take_size_increment() { return move(m_size_increment); }

    const Gfx::IntSize& minimum_size() const { return m_minimum_size; }
    Gfx::IntSize take_minimum_size() { return move(m_minimum_size); }

    const Optional<Gfx::IntSize>& resize_aspect_ratio() const { return m_resize_aspect_ratio; }
    Optional<Gfx::IntSize> take_resize_aspect_ratio() { return move(m_resize_aspect_ratio); }

    const i32& type() const { return m_type; }
    i32 take_type() { return move(m_type); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

    const i32& parent_window_id() const { return m_parent_window_id; }
    i32 take_parent_window_id() { return move(m_parent_window_id); }

    const Gfx::IntRect& launch_origin_rect() const { return m_launch_origin_rect; }
    Gfx::IntRect take_launch_origin_rect() { return move(m_launch_origin_rect); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntRect m_rect {};

    bool m_auto_position {};

    bool m_has_alpha_channel {};

    bool m_modal {};

    bool m_minimizable {};

    bool m_closeable {};

    bool m_resizable {};

    bool m_fullscreen {};

    bool m_frameless {};

    bool m_forced_shadow {};

    bool m_accessory {};

    float m_opacity {};

    float m_alpha_hit_threshold {};

    Gfx::IntSize m_base_size {};

    Gfx::IntSize m_size_increment {};

    Gfx::IntSize m_minimum_size {};

    Optional<Gfx::IntSize> m_resize_aspect_ratio {};

    i32 m_type {};

    String m_title {};

    i32 m_parent_window_id {};

    Gfx::IntRect m_launch_origin_rect {};

};

class DestroyWindowResponse final : public IPC::Message {
public:

    DestroyWindowResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DestroyWindowResponse(DestroyWindowResponse const&) = default;
    DestroyWindowResponse(DestroyWindowResponse&&) = default;
    DestroyWindowResponse& operator=(DestroyWindowResponse const&) = default;
    DestroyWindowResponse(Vector<i32> destroyed_window_ids) : m_destroyed_window_ids(move(destroyed_window_ids)) {}
    virtual ~DestroyWindowResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DestroyWindowResponse; }
    static i32 static_message_id() { return (int)MessageID::DestroyWindowResponse; }
    virtual const char* message_name() const override { return "WindowServer::DestroyWindowResponse"; }

    static OwnPtr<DestroyWindowResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<i32> destroyed_window_ids = {};
        if (decoder.decode(destroyed_window_ids).is_error())
            return {};

        return make<DestroyWindowResponse>(move(destroyed_window_ids));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DestroyWindowResponse;

        stream << m_destroyed_window_ids;

        return buffer;
    }

    const Vector<i32>& destroyed_window_ids() const { return m_destroyed_window_ids; }
    Vector<i32> take_destroyed_window_ids() { return move(m_destroyed_window_ids); }

private:
    bool m_ipc_message_valid { true };

    Vector<i32> m_destroyed_window_ids {};

};

class DestroyWindow final : public IPC::Message {
public:

   typedef class DestroyWindowResponse ResponseType;

    DestroyWindow(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DestroyWindow(DestroyWindow const&) = default;
    DestroyWindow(DestroyWindow&&) = default;
    DestroyWindow& operator=(DestroyWindow const&) = default;
    DestroyWindow(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~DestroyWindow() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DestroyWindow; }
    static i32 static_message_id() { return (int)MessageID::DestroyWindow; }
    virtual const char* message_name() const override { return "WindowServer::DestroyWindow"; }

    static OwnPtr<DestroyWindow> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<DestroyWindow>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DestroyWindow;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetWindowTitle final : public IPC::Message {
public:

    SetWindowTitle(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowTitle(SetWindowTitle const&) = default;
    SetWindowTitle(SetWindowTitle&&) = default;
    SetWindowTitle& operator=(SetWindowTitle const&) = default;
    SetWindowTitle(i32 window_id, String title) : m_window_id(move(window_id)), m_title(move(title)) {}
    virtual ~SetWindowTitle() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowTitle; }
    static i32 static_message_id() { return (int)MessageID::SetWindowTitle; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowTitle"; }

    static OwnPtr<SetWindowTitle> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        return make<SetWindowTitle>(move(window_id), move(title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowTitle;

        stream << m_window_id;

        stream << m_title;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    String m_title {};

};

class GetWindowTitleResponse final : public IPC::Message {
public:

    GetWindowTitleResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowTitleResponse(GetWindowTitleResponse const&) = default;
    GetWindowTitleResponse(GetWindowTitleResponse&&) = default;
    GetWindowTitleResponse& operator=(GetWindowTitleResponse const&) = default;
    GetWindowTitleResponse(String title) : m_title(move(title)) {}
    virtual ~GetWindowTitleResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowTitleResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWindowTitleResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowTitleResponse"; }

    static OwnPtr<GetWindowTitleResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        return make<GetWindowTitleResponse>(move(title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowTitleResponse;

        stream << m_title;

        return buffer;
    }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

private:
    bool m_ipc_message_valid { true };

    String m_title {};

};

class GetWindowTitle final : public IPC::Message {
public:

   typedef class GetWindowTitleResponse ResponseType;

    GetWindowTitle(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowTitle(GetWindowTitle const&) = default;
    GetWindowTitle(GetWindowTitle&&) = default;
    GetWindowTitle& operator=(GetWindowTitle const&) = default;
    GetWindowTitle(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~GetWindowTitle() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowTitle; }
    static i32 static_message_id() { return (int)MessageID::GetWindowTitle; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowTitle"; }

    static OwnPtr<GetWindowTitle> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<GetWindowTitle>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowTitle;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetWindowProgress final : public IPC::Message {
public:

    SetWindowProgress(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowProgress(SetWindowProgress const&) = default;
    SetWindowProgress(SetWindowProgress&&) = default;
    SetWindowProgress& operator=(SetWindowProgress const&) = default;
    SetWindowProgress(i32 window_id, Optional<i32> progress) : m_window_id(move(window_id)), m_progress(move(progress)) {}
    virtual ~SetWindowProgress() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowProgress; }
    static i32 static_message_id() { return (int)MessageID::SetWindowProgress; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowProgress"; }

    static OwnPtr<SetWindowProgress> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Optional<i32> progress = {};
        if (decoder.decode(progress).is_error())
            return {};

        return make<SetWindowProgress>(move(window_id), move(progress));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowProgress;

        stream << m_window_id;

        stream << m_progress;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Optional<i32>& progress() const { return m_progress; }
    Optional<i32> take_progress() { return move(m_progress); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Optional<i32> m_progress {};

};

class SetWindowModified final : public IPC::Message {
public:

    SetWindowModified(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowModified(SetWindowModified const&) = default;
    SetWindowModified(SetWindowModified&&) = default;
    SetWindowModified& operator=(SetWindowModified const&) = default;
    SetWindowModified(i32 window_id, bool modified) : m_window_id(move(window_id)), m_modified(move(modified)) {}
    virtual ~SetWindowModified() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowModified; }
    static i32 static_message_id() { return (int)MessageID::SetWindowModified; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowModified"; }

    static OwnPtr<SetWindowModified> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool modified = false;
        if (decoder.decode(modified).is_error())
            return {};

        return make<SetWindowModified>(move(window_id), move(modified));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowModified;

        stream << m_window_id;

        stream << m_modified;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& modified() const { return m_modified; }
    bool take_modified() { return move(m_modified); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_modified {};

};

class IsWindowModifiedResponse final : public IPC::Message {
public:

    IsWindowModifiedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsWindowModifiedResponse(IsWindowModifiedResponse const&) = default;
    IsWindowModifiedResponse(IsWindowModifiedResponse&&) = default;
    IsWindowModifiedResponse& operator=(IsWindowModifiedResponse const&) = default;
    IsWindowModifiedResponse(bool modified) : m_modified(move(modified)) {}
    virtual ~IsWindowModifiedResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::IsWindowModifiedResponse; }
    static i32 static_message_id() { return (int)MessageID::IsWindowModifiedResponse; }
    virtual const char* message_name() const override { return "WindowServer::IsWindowModifiedResponse"; }

    static OwnPtr<IsWindowModifiedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool modified = false;
        if (decoder.decode(modified).is_error())
            return {};

        return make<IsWindowModifiedResponse>(move(modified));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsWindowModifiedResponse;

        stream << m_modified;

        return buffer;
    }

    const bool& modified() const { return m_modified; }
    bool take_modified() { return move(m_modified); }

private:
    bool m_ipc_message_valid { true };

    bool m_modified {};

};

class IsWindowModified final : public IPC::Message {
public:

   typedef class IsWindowModifiedResponse ResponseType;

    IsWindowModified(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsWindowModified(IsWindowModified const&) = default;
    IsWindowModified(IsWindowModified&&) = default;
    IsWindowModified& operator=(IsWindowModified const&) = default;
    IsWindowModified(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~IsWindowModified() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::IsWindowModified; }
    static i32 static_message_id() { return (int)MessageID::IsWindowModified; }
    virtual const char* message_name() const override { return "WindowServer::IsWindowModified"; }

    static OwnPtr<IsWindowModified> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<IsWindowModified>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsWindowModified;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetWindowRectResponse final : public IPC::Message {
public:

    SetWindowRectResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowRectResponse(SetWindowRectResponse const&) = default;
    SetWindowRectResponse(SetWindowRectResponse&&) = default;
    SetWindowRectResponse& operator=(SetWindowRectResponse const&) = default;
    SetWindowRectResponse(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~SetWindowRectResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowRectResponse; }
    static i32 static_message_id() { return (int)MessageID::SetWindowRectResponse; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowRectResponse"; }

    static OwnPtr<SetWindowRectResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<SetWindowRectResponse>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowRectResponse;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class SetWindowRect final : public IPC::Message {
public:

   typedef class SetWindowRectResponse ResponseType;

    SetWindowRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowRect(SetWindowRect const&) = default;
    SetWindowRect(SetWindowRect&&) = default;
    SetWindowRect& operator=(SetWindowRect const&) = default;
    SetWindowRect(i32 window_id, Gfx::IntRect rect) : m_window_id(move(window_id)), m_rect(move(rect)) {}
    virtual ~SetWindowRect() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowRect; }
    static i32 static_message_id() { return (int)MessageID::SetWindowRect; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowRect"; }

    static OwnPtr<SetWindowRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<SetWindowRect>(move(window_id), move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowRect;

        stream << m_window_id;

        stream << m_rect;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntRect m_rect {};

};

class GetWindowRectResponse final : public IPC::Message {
public:

    GetWindowRectResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowRectResponse(GetWindowRectResponse const&) = default;
    GetWindowRectResponse(GetWindowRectResponse&&) = default;
    GetWindowRectResponse& operator=(GetWindowRectResponse const&) = default;
    GetWindowRectResponse(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~GetWindowRectResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowRectResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWindowRectResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowRectResponse"; }

    static OwnPtr<GetWindowRectResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<GetWindowRectResponse>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowRectResponse;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class GetWindowRect final : public IPC::Message {
public:

   typedef class GetWindowRectResponse ResponseType;

    GetWindowRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowRect(GetWindowRect const&) = default;
    GetWindowRect(GetWindowRect&&) = default;
    GetWindowRect& operator=(GetWindowRect const&) = default;
    GetWindowRect(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~GetWindowRect() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowRect; }
    static i32 static_message_id() { return (int)MessageID::GetWindowRect; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowRect"; }

    static OwnPtr<GetWindowRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<GetWindowRect>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowRect;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetWindowMinimumSize final : public IPC::Message {
public:

    SetWindowMinimumSize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowMinimumSize(SetWindowMinimumSize const&) = default;
    SetWindowMinimumSize(SetWindowMinimumSize&&) = default;
    SetWindowMinimumSize& operator=(SetWindowMinimumSize const&) = default;
    SetWindowMinimumSize(i32 window_id, Gfx::IntSize size) : m_window_id(move(window_id)), m_size(move(size)) {}
    virtual ~SetWindowMinimumSize() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowMinimumSize; }
    static i32 static_message_id() { return (int)MessageID::SetWindowMinimumSize; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowMinimumSize"; }

    static OwnPtr<SetWindowMinimumSize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntSize size = {};
        if (decoder.decode(size).is_error())
            return {};

        return make<SetWindowMinimumSize>(move(window_id), move(size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowMinimumSize;

        stream << m_window_id;

        stream << m_size;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntSize& size() const { return m_size; }
    Gfx::IntSize take_size() { return move(m_size); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntSize m_size {};

};

class GetWindowMinimumSizeResponse final : public IPC::Message {
public:

    GetWindowMinimumSizeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowMinimumSizeResponse(GetWindowMinimumSizeResponse const&) = default;
    GetWindowMinimumSizeResponse(GetWindowMinimumSizeResponse&&) = default;
    GetWindowMinimumSizeResponse& operator=(GetWindowMinimumSizeResponse const&) = default;
    GetWindowMinimumSizeResponse(Gfx::IntSize size) : m_size(move(size)) {}
    virtual ~GetWindowMinimumSizeResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowMinimumSizeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWindowMinimumSizeResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowMinimumSizeResponse"; }

    static OwnPtr<GetWindowMinimumSizeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntSize size = {};
        if (decoder.decode(size).is_error())
            return {};

        return make<GetWindowMinimumSizeResponse>(move(size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowMinimumSizeResponse;

        stream << m_size;

        return buffer;
    }

    const Gfx::IntSize& size() const { return m_size; }
    Gfx::IntSize take_size() { return move(m_size); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntSize m_size {};

};

class GetWindowMinimumSize final : public IPC::Message {
public:

   typedef class GetWindowMinimumSizeResponse ResponseType;

    GetWindowMinimumSize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowMinimumSize(GetWindowMinimumSize const&) = default;
    GetWindowMinimumSize(GetWindowMinimumSize&&) = default;
    GetWindowMinimumSize& operator=(GetWindowMinimumSize const&) = default;
    GetWindowMinimumSize(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~GetWindowMinimumSize() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowMinimumSize; }
    static i32 static_message_id() { return (int)MessageID::GetWindowMinimumSize; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowMinimumSize"; }

    static OwnPtr<GetWindowMinimumSize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<GetWindowMinimumSize>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowMinimumSize;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class GetAppletRectOnScreenResponse final : public IPC::Message {
public:

    GetAppletRectOnScreenResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetAppletRectOnScreenResponse(GetAppletRectOnScreenResponse const&) = default;
    GetAppletRectOnScreenResponse(GetAppletRectOnScreenResponse&&) = default;
    GetAppletRectOnScreenResponse& operator=(GetAppletRectOnScreenResponse const&) = default;
    GetAppletRectOnScreenResponse(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~GetAppletRectOnScreenResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetAppletRectOnScreenResponse; }
    static i32 static_message_id() { return (int)MessageID::GetAppletRectOnScreenResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetAppletRectOnScreenResponse"; }

    static OwnPtr<GetAppletRectOnScreenResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<GetAppletRectOnScreenResponse>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetAppletRectOnScreenResponse;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class GetAppletRectOnScreen final : public IPC::Message {
public:

   typedef class GetAppletRectOnScreenResponse ResponseType;

    GetAppletRectOnScreen(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetAppletRectOnScreen(GetAppletRectOnScreen const&) = default;
    GetAppletRectOnScreen(GetAppletRectOnScreen&&) = default;
    GetAppletRectOnScreen& operator=(GetAppletRectOnScreen const&) = default;
    GetAppletRectOnScreen(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~GetAppletRectOnScreen() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetAppletRectOnScreen; }
    static i32 static_message_id() { return (int)MessageID::GetAppletRectOnScreen; }
    virtual const char* message_name() const override { return "WindowServer::GetAppletRectOnScreen"; }

    static OwnPtr<GetAppletRectOnScreen> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<GetAppletRectOnScreen>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetAppletRectOnScreen;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class StartWindowResize final : public IPC::Message {
public:

    StartWindowResize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartWindowResize(StartWindowResize const&) = default;
    StartWindowResize(StartWindowResize&&) = default;
    StartWindowResize& operator=(StartWindowResize const&) = default;
    StartWindowResize(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~StartWindowResize() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::StartWindowResize; }
    static i32 static_message_id() { return (int)MessageID::StartWindowResize; }
    virtual const char* message_name() const override { return "WindowServer::StartWindowResize"; }

    static OwnPtr<StartWindowResize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<StartWindowResize>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartWindowResize;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class IsMaximizedResponse final : public IPC::Message {
public:

    IsMaximizedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsMaximizedResponse(IsMaximizedResponse const&) = default;
    IsMaximizedResponse(IsMaximizedResponse&&) = default;
    IsMaximizedResponse& operator=(IsMaximizedResponse const&) = default;
    IsMaximizedResponse(bool maximized) : m_maximized(move(maximized)) {}
    virtual ~IsMaximizedResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::IsMaximizedResponse; }
    static i32 static_message_id() { return (int)MessageID::IsMaximizedResponse; }
    virtual const char* message_name() const override { return "WindowServer::IsMaximizedResponse"; }

    static OwnPtr<IsMaximizedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool maximized = false;
        if (decoder.decode(maximized).is_error())
            return {};

        return make<IsMaximizedResponse>(move(maximized));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsMaximizedResponse;

        stream << m_maximized;

        return buffer;
    }

    const bool& maximized() const { return m_maximized; }
    bool take_maximized() { return move(m_maximized); }

private:
    bool m_ipc_message_valid { true };

    bool m_maximized {};

};

class IsMaximized final : public IPC::Message {
public:

   typedef class IsMaximizedResponse ResponseType;

    IsMaximized(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsMaximized(IsMaximized const&) = default;
    IsMaximized(IsMaximized&&) = default;
    IsMaximized& operator=(IsMaximized const&) = default;
    IsMaximized(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~IsMaximized() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::IsMaximized; }
    static i32 static_message_id() { return (int)MessageID::IsMaximized; }
    virtual const char* message_name() const override { return "WindowServer::IsMaximized"; }

    static OwnPtr<IsMaximized> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<IsMaximized>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsMaximized;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetMaximized final : public IPC::Message {
public:

    SetMaximized(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMaximized(SetMaximized const&) = default;
    SetMaximized(SetMaximized&&) = default;
    SetMaximized& operator=(SetMaximized const&) = default;
    SetMaximized(i32 window_id, bool maximized) : m_window_id(move(window_id)), m_maximized(move(maximized)) {}
    virtual ~SetMaximized() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetMaximized; }
    static i32 static_message_id() { return (int)MessageID::SetMaximized; }
    virtual const char* message_name() const override { return "WindowServer::SetMaximized"; }

    static OwnPtr<SetMaximized> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool maximized = false;
        if (decoder.decode(maximized).is_error())
            return {};

        return make<SetMaximized>(move(window_id), move(maximized));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMaximized;

        stream << m_window_id;

        stream << m_maximized;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& maximized() const { return m_maximized; }
    bool take_maximized() { return move(m_maximized); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_maximized {};

};

class InvalidateRect final : public IPC::Message {
public:

    InvalidateRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    InvalidateRect(InvalidateRect const&) = default;
    InvalidateRect(InvalidateRect&&) = default;
    InvalidateRect& operator=(InvalidateRect const&) = default;
    InvalidateRect(i32 window_id, Vector<Gfx::IntRect> rects, bool ignore_occlusion) : m_window_id(move(window_id)), m_rects(move(rects)), m_ignore_occlusion(move(ignore_occlusion)) {}
    virtual ~InvalidateRect() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::InvalidateRect; }
    static i32 static_message_id() { return (int)MessageID::InvalidateRect; }
    virtual const char* message_name() const override { return "WindowServer::InvalidateRect"; }

    static OwnPtr<InvalidateRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Vector<Gfx::IntRect> rects = {};
        if (decoder.decode(rects).is_error())
            return {};

        bool ignore_occlusion = false;
        if (decoder.decode(ignore_occlusion).is_error())
            return {};

        return make<InvalidateRect>(move(window_id), move(rects), move(ignore_occlusion));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::InvalidateRect;

        stream << m_window_id;

        stream << m_rects;

        stream << m_ignore_occlusion;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Vector<Gfx::IntRect>& rects() const { return m_rects; }
    Vector<Gfx::IntRect> take_rects() { return move(m_rects); }

    const bool& ignore_occlusion() const { return m_ignore_occlusion; }
    bool take_ignore_occlusion() { return move(m_ignore_occlusion); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Vector<Gfx::IntRect> m_rects {};

    bool m_ignore_occlusion {};

};

class DidFinishPainting final : public IPC::Message {
public:

    DidFinishPainting(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidFinishPainting(DidFinishPainting const&) = default;
    DidFinishPainting(DidFinishPainting&&) = default;
    DidFinishPainting& operator=(DidFinishPainting const&) = default;
    DidFinishPainting(i32 window_id, Vector<Gfx::IntRect> rects) : m_window_id(move(window_id)), m_rects(move(rects)) {}
    virtual ~DidFinishPainting() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DidFinishPainting; }
    static i32 static_message_id() { return (int)MessageID::DidFinishPainting; }
    virtual const char* message_name() const override { return "WindowServer::DidFinishPainting"; }

    static OwnPtr<DidFinishPainting> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Vector<Gfx::IntRect> rects = {};
        if (decoder.decode(rects).is_error())
            return {};

        return make<DidFinishPainting>(move(window_id), move(rects));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidFinishPainting;

        stream << m_window_id;

        stream << m_rects;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Vector<Gfx::IntRect>& rects() const { return m_rects; }
    Vector<Gfx::IntRect> take_rects() { return move(m_rects); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Vector<Gfx::IntRect> m_rects {};

};

class SetGlobalMouseTracking final : public IPC::Message {
public:

    SetGlobalMouseTracking(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetGlobalMouseTracking(SetGlobalMouseTracking const&) = default;
    SetGlobalMouseTracking(SetGlobalMouseTracking&&) = default;
    SetGlobalMouseTracking& operator=(SetGlobalMouseTracking const&) = default;
    SetGlobalMouseTracking(bool enabled) : m_enabled(move(enabled)) {}
    virtual ~SetGlobalMouseTracking() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetGlobalMouseTracking; }
    static i32 static_message_id() { return (int)MessageID::SetGlobalMouseTracking; }
    virtual const char* message_name() const override { return "WindowServer::SetGlobalMouseTracking"; }

    static OwnPtr<SetGlobalMouseTracking> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool enabled = false;
        if (decoder.decode(enabled).is_error())
            return {};

        return make<SetGlobalMouseTracking>(move(enabled));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetGlobalMouseTracking;

        stream << m_enabled;

        return buffer;
    }

    const bool& enabled() const { return m_enabled; }
    bool take_enabled() { return move(m_enabled); }

private:
    bool m_ipc_message_valid { true };

    bool m_enabled {};

};

class SetWindowOpacity final : public IPC::Message {
public:

    SetWindowOpacity(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowOpacity(SetWindowOpacity const&) = default;
    SetWindowOpacity(SetWindowOpacity&&) = default;
    SetWindowOpacity& operator=(SetWindowOpacity const&) = default;
    SetWindowOpacity(i32 window_id, float opacity) : m_window_id(move(window_id)), m_opacity(move(opacity)) {}
    virtual ~SetWindowOpacity() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowOpacity; }
    static i32 static_message_id() { return (int)MessageID::SetWindowOpacity; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowOpacity"; }

    static OwnPtr<SetWindowOpacity> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        float opacity = {};
        if (decoder.decode(opacity).is_error())
            return {};

        return make<SetWindowOpacity>(move(window_id), move(opacity));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowOpacity;

        stream << m_window_id;

        stream << m_opacity;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const float& opacity() const { return m_opacity; }
    float take_opacity() { return move(m_opacity); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    float m_opacity {};

};

class SetWindowAlphaHitThreshold final : public IPC::Message {
public:

    SetWindowAlphaHitThreshold(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowAlphaHitThreshold(SetWindowAlphaHitThreshold const&) = default;
    SetWindowAlphaHitThreshold(SetWindowAlphaHitThreshold&&) = default;
    SetWindowAlphaHitThreshold& operator=(SetWindowAlphaHitThreshold const&) = default;
    SetWindowAlphaHitThreshold(i32 window_id, float threshold) : m_window_id(move(window_id)), m_threshold(move(threshold)) {}
    virtual ~SetWindowAlphaHitThreshold() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowAlphaHitThreshold; }
    static i32 static_message_id() { return (int)MessageID::SetWindowAlphaHitThreshold; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowAlphaHitThreshold"; }

    static OwnPtr<SetWindowAlphaHitThreshold> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        float threshold = {};
        if (decoder.decode(threshold).is_error())
            return {};

        return make<SetWindowAlphaHitThreshold>(move(window_id), move(threshold));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowAlphaHitThreshold;

        stream << m_window_id;

        stream << m_threshold;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const float& threshold() const { return m_threshold; }
    float take_threshold() { return move(m_threshold); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    float m_threshold {};

};

class SetWindowBackingStoreResponse final : public IPC::Message {
public:

    SetWindowBackingStoreResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowBackingStoreResponse(SetWindowBackingStoreResponse const&) = default;
    SetWindowBackingStoreResponse(SetWindowBackingStoreResponse&&) = default;
    SetWindowBackingStoreResponse& operator=(SetWindowBackingStoreResponse const&) = default;
    SetWindowBackingStoreResponse() {}
    virtual ~SetWindowBackingStoreResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowBackingStoreResponse; }
    static i32 static_message_id() { return (int)MessageID::SetWindowBackingStoreResponse; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowBackingStoreResponse"; }

    static OwnPtr<SetWindowBackingStoreResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetWindowBackingStoreResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowBackingStoreResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetWindowBackingStore final : public IPC::Message {
public:

   typedef class SetWindowBackingStoreResponse ResponseType;

    SetWindowBackingStore(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowBackingStore(SetWindowBackingStore const&) = default;
    SetWindowBackingStore(SetWindowBackingStore&&) = default;
    SetWindowBackingStore& operator=(SetWindowBackingStore const&) = default;
    SetWindowBackingStore(i32 window_id, i32 bpp, i32 pitch, IPC::File anon_file, i32 serial, bool has_alpha_channel, Gfx::IntSize size, bool flush_immediately) : m_window_id(move(window_id)), m_bpp(move(bpp)), m_pitch(move(pitch)), m_anon_file(move(anon_file)), m_serial(move(serial)), m_has_alpha_channel(move(has_alpha_channel)), m_size(move(size)), m_flush_immediately(move(flush_immediately)) {}
    virtual ~SetWindowBackingStore() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowBackingStore; }
    static i32 static_message_id() { return (int)MessageID::SetWindowBackingStore; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowBackingStore"; }

    static OwnPtr<SetWindowBackingStore> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        i32 bpp = {};
        if (decoder.decode(bpp).is_error())
            return {};

        i32 pitch = {};
        if (decoder.decode(pitch).is_error())
            return {};

        IPC::File anon_file = {};
        if (decoder.decode(anon_file).is_error())
            return {};

        i32 serial = {};
        if (decoder.decode(serial).is_error())
            return {};

        bool has_alpha_channel = false;
        if (decoder.decode(has_alpha_channel).is_error())
            return {};

        Gfx::IntSize size = {};
        if (decoder.decode(size).is_error())
            return {};

        bool flush_immediately = false;
        if (decoder.decode(flush_immediately).is_error())
            return {};

        return make<SetWindowBackingStore>(move(window_id), move(bpp), move(pitch), move(anon_file), move(serial), move(has_alpha_channel), move(size), move(flush_immediately));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowBackingStore;

        stream << m_window_id;

        stream << m_bpp;

        stream << m_pitch;

        stream << m_anon_file;

        stream << m_serial;

        stream << m_has_alpha_channel;

        stream << m_size;

        stream << m_flush_immediately;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const i32& bpp() const { return m_bpp; }
    i32 take_bpp() { return move(m_bpp); }

    const i32& pitch() const { return m_pitch; }
    i32 take_pitch() { return move(m_pitch); }

    const IPC::File& anon_file() const { return m_anon_file; }
    IPC::File take_anon_file() { return move(m_anon_file); }

    const i32& serial() const { return m_serial; }
    i32 take_serial() { return move(m_serial); }

    const bool& has_alpha_channel() const { return m_has_alpha_channel; }
    bool take_has_alpha_channel() { return move(m_has_alpha_channel); }

    const Gfx::IntSize& size() const { return m_size; }
    Gfx::IntSize take_size() { return move(m_size); }

    const bool& flush_immediately() const { return m_flush_immediately; }
    bool take_flush_immediately() { return move(m_flush_immediately); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    i32 m_bpp {};

    i32 m_pitch {};

    IPC::File m_anon_file {};

    i32 m_serial {};

    bool m_has_alpha_channel {};

    Gfx::IntSize m_size {};

    bool m_flush_immediately {};

};

class SetWindowHasAlphaChannel final : public IPC::Message {
public:

    SetWindowHasAlphaChannel(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowHasAlphaChannel(SetWindowHasAlphaChannel const&) = default;
    SetWindowHasAlphaChannel(SetWindowHasAlphaChannel&&) = default;
    SetWindowHasAlphaChannel& operator=(SetWindowHasAlphaChannel const&) = default;
    SetWindowHasAlphaChannel(i32 window_id, bool has_alpha_channel) : m_window_id(move(window_id)), m_has_alpha_channel(move(has_alpha_channel)) {}
    virtual ~SetWindowHasAlphaChannel() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowHasAlphaChannel; }
    static i32 static_message_id() { return (int)MessageID::SetWindowHasAlphaChannel; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowHasAlphaChannel"; }

    static OwnPtr<SetWindowHasAlphaChannel> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool has_alpha_channel = false;
        if (decoder.decode(has_alpha_channel).is_error())
            return {};

        return make<SetWindowHasAlphaChannel>(move(window_id), move(has_alpha_channel));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowHasAlphaChannel;

        stream << m_window_id;

        stream << m_has_alpha_channel;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& has_alpha_channel() const { return m_has_alpha_channel; }
    bool take_has_alpha_channel() { return move(m_has_alpha_channel); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_has_alpha_channel {};

};

class MoveWindowToFront final : public IPC::Message {
public:

    MoveWindowToFront(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MoveWindowToFront(MoveWindowToFront const&) = default;
    MoveWindowToFront(MoveWindowToFront&&) = default;
    MoveWindowToFront& operator=(MoveWindowToFront const&) = default;
    MoveWindowToFront(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~MoveWindowToFront() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::MoveWindowToFront; }
    static i32 static_message_id() { return (int)MessageID::MoveWindowToFront; }
    virtual const char* message_name() const override { return "WindowServer::MoveWindowToFront"; }

    static OwnPtr<MoveWindowToFront> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<MoveWindowToFront>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MoveWindowToFront;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetFullscreen final : public IPC::Message {
public:

    SetFullscreen(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetFullscreen(SetFullscreen const&) = default;
    SetFullscreen(SetFullscreen&&) = default;
    SetFullscreen& operator=(SetFullscreen const&) = default;
    SetFullscreen(i32 window_id, bool fullscreen) : m_window_id(move(window_id)), m_fullscreen(move(fullscreen)) {}
    virtual ~SetFullscreen() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetFullscreen; }
    static i32 static_message_id() { return (int)MessageID::SetFullscreen; }
    virtual const char* message_name() const override { return "WindowServer::SetFullscreen"; }

    static OwnPtr<SetFullscreen> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool fullscreen = false;
        if (decoder.decode(fullscreen).is_error())
            return {};

        return make<SetFullscreen>(move(window_id), move(fullscreen));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetFullscreen;

        stream << m_window_id;

        stream << m_fullscreen;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& fullscreen() const { return m_fullscreen; }
    bool take_fullscreen() { return move(m_fullscreen); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_fullscreen {};

};

class SetFrameless final : public IPC::Message {
public:

    SetFrameless(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetFrameless(SetFrameless const&) = default;
    SetFrameless(SetFrameless&&) = default;
    SetFrameless& operator=(SetFrameless const&) = default;
    SetFrameless(i32 window_id, bool frameless) : m_window_id(move(window_id)), m_frameless(move(frameless)) {}
    virtual ~SetFrameless() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetFrameless; }
    static i32 static_message_id() { return (int)MessageID::SetFrameless; }
    virtual const char* message_name() const override { return "WindowServer::SetFrameless"; }

    static OwnPtr<SetFrameless> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool frameless = false;
        if (decoder.decode(frameless).is_error())
            return {};

        return make<SetFrameless>(move(window_id), move(frameless));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetFrameless;

        stream << m_window_id;

        stream << m_frameless;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& frameless() const { return m_frameless; }
    bool take_frameless() { return move(m_frameless); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_frameless {};

};

class SetForcedShadow final : public IPC::Message {
public:

    SetForcedShadow(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetForcedShadow(SetForcedShadow const&) = default;
    SetForcedShadow(SetForcedShadow&&) = default;
    SetForcedShadow& operator=(SetForcedShadow const&) = default;
    SetForcedShadow(i32 window_id, bool shadow) : m_window_id(move(window_id)), m_shadow(move(shadow)) {}
    virtual ~SetForcedShadow() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetForcedShadow; }
    static i32 static_message_id() { return (int)MessageID::SetForcedShadow; }
    virtual const char* message_name() const override { return "WindowServer::SetForcedShadow"; }

    static OwnPtr<SetForcedShadow> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool shadow = false;
        if (decoder.decode(shadow).is_error())
            return {};

        return make<SetForcedShadow>(move(window_id), move(shadow));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetForcedShadow;

        stream << m_window_id;

        stream << m_shadow;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& shadow() const { return m_shadow; }
    bool take_shadow() { return move(m_shadow); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_shadow {};

};

class PopupMenu final : public IPC::Message {
public:

    PopupMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PopupMenu(PopupMenu const&) = default;
    PopupMenu(PopupMenu&&) = default;
    PopupMenu& operator=(PopupMenu const&) = default;
    PopupMenu(i32 menu_id, Gfx::IntPoint screen_position) : m_menu_id(move(menu_id)), m_screen_position(move(screen_position)) {}
    virtual ~PopupMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::PopupMenu; }
    static i32 static_message_id() { return (int)MessageID::PopupMenu; }
    virtual const char* message_name() const override { return "WindowServer::PopupMenu"; }

    static OwnPtr<PopupMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        Gfx::IntPoint screen_position = {};
        if (decoder.decode(screen_position).is_error())
            return {};

        return make<PopupMenu>(move(menu_id), move(screen_position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PopupMenu;

        stream << m_menu_id;

        stream << m_screen_position;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const Gfx::IntPoint& screen_position() const { return m_screen_position; }
    Gfx::IntPoint take_screen_position() { return move(m_screen_position); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    Gfx::IntPoint m_screen_position {};

};

class DismissMenu final : public IPC::Message {
public:

    DismissMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DismissMenu(DismissMenu const&) = default;
    DismissMenu(DismissMenu&&) = default;
    DismissMenu& operator=(DismissMenu const&) = default;
    DismissMenu(i32 menu_id) : m_menu_id(move(menu_id)) {}
    virtual ~DismissMenu() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DismissMenu; }
    static i32 static_message_id() { return (int)MessageID::DismissMenu; }
    virtual const char* message_name() const override { return "WindowServer::DismissMenu"; }

    static OwnPtr<DismissMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        return make<DismissMenu>(move(menu_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DismissMenu;

        stream << m_menu_id;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

};

class SetWallpaper final : public IPC::Message {
public:

    SetWallpaper(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWallpaper(SetWallpaper const&) = default;
    SetWallpaper(SetWallpaper&&) = default;
    SetWallpaper& operator=(SetWallpaper const&) = default;
    SetWallpaper(Gfx::ShareableBitmap wallpaper_bitmap) : m_wallpaper_bitmap(move(wallpaper_bitmap)) {}
    virtual ~SetWallpaper() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWallpaper; }
    static i32 static_message_id() { return (int)MessageID::SetWallpaper; }
    virtual const char* message_name() const override { return "WindowServer::SetWallpaper"; }

    static OwnPtr<SetWallpaper> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap wallpaper_bitmap = {};
        if (decoder.decode(wallpaper_bitmap).is_error())
            return {};

        return make<SetWallpaper>(move(wallpaper_bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWallpaper;

        stream << m_wallpaper_bitmap;

        return buffer;
    }

    const Gfx::ShareableBitmap& wallpaper_bitmap() const { return m_wallpaper_bitmap; }
    Gfx::ShareableBitmap take_wallpaper_bitmap() { return move(m_wallpaper_bitmap); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_wallpaper_bitmap {};

};

class SetBackgroundColor final : public IPC::Message {
public:

    SetBackgroundColor(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetBackgroundColor(SetBackgroundColor const&) = default;
    SetBackgroundColor(SetBackgroundColor&&) = default;
    SetBackgroundColor& operator=(SetBackgroundColor const&) = default;
    SetBackgroundColor(String background_color) : m_background_color(move(background_color)) {}
    virtual ~SetBackgroundColor() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetBackgroundColor; }
    static i32 static_message_id() { return (int)MessageID::SetBackgroundColor; }
    virtual const char* message_name() const override { return "WindowServer::SetBackgroundColor"; }

    static OwnPtr<SetBackgroundColor> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String background_color = {};
        if (decoder.decode(background_color).is_error())
            return {};

        return make<SetBackgroundColor>(move(background_color));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetBackgroundColor;

        stream << m_background_color;

        return buffer;
    }

    const String& background_color() const { return m_background_color; }
    String take_background_color() { return move(m_background_color); }

private:
    bool m_ipc_message_valid { true };

    String m_background_color {};

};

class SetWallpaperMode final : public IPC::Message {
public:

    SetWallpaperMode(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWallpaperMode(SetWallpaperMode const&) = default;
    SetWallpaperMode(SetWallpaperMode&&) = default;
    SetWallpaperMode& operator=(SetWallpaperMode const&) = default;
    SetWallpaperMode(String mode) : m_mode(move(mode)) {}
    virtual ~SetWallpaperMode() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWallpaperMode; }
    static i32 static_message_id() { return (int)MessageID::SetWallpaperMode; }
    virtual const char* message_name() const override { return "WindowServer::SetWallpaperMode"; }

    static OwnPtr<SetWallpaperMode> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String mode = {};
        if (decoder.decode(mode).is_error())
            return {};

        return make<SetWallpaperMode>(move(mode));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWallpaperMode;

        stream << m_mode;

        return buffer;
    }

    const String& mode() const { return m_mode; }
    String take_mode() { return move(m_mode); }

private:
    bool m_ipc_message_valid { true };

    String m_mode {};

};

class SetScreenLayoutResponse final : public IPC::Message {
public:

    SetScreenLayoutResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetScreenLayoutResponse(SetScreenLayoutResponse const&) = default;
    SetScreenLayoutResponse(SetScreenLayoutResponse&&) = default;
    SetScreenLayoutResponse& operator=(SetScreenLayoutResponse const&) = default;
    SetScreenLayoutResponse(bool success, String error_msg) : m_success(move(success)), m_error_msg(move(error_msg)) {}
    virtual ~SetScreenLayoutResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetScreenLayoutResponse; }
    static i32 static_message_id() { return (int)MessageID::SetScreenLayoutResponse; }
    virtual const char* message_name() const override { return "WindowServer::SetScreenLayoutResponse"; }

    static OwnPtr<SetScreenLayoutResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        String error_msg = {};
        if (decoder.decode(error_msg).is_error())
            return {};

        return make<SetScreenLayoutResponse>(move(success), move(error_msg));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetScreenLayoutResponse;

        stream << m_success;

        stream << m_error_msg;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

    const String& error_msg() const { return m_error_msg; }
    String take_error_msg() { return move(m_error_msg); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

    String m_error_msg {};

};

class SetScreenLayout final : public IPC::Message {
public:

   typedef class SetScreenLayoutResponse ResponseType;

    SetScreenLayout(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetScreenLayout(SetScreenLayout const&) = default;
    SetScreenLayout(SetScreenLayout&&) = default;
    SetScreenLayout& operator=(SetScreenLayout const&) = default;
    SetScreenLayout(::WindowServer::ScreenLayout screen_layout, bool save) : m_screen_layout(move(screen_layout)), m_save(move(save)) {}
    virtual ~SetScreenLayout() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetScreenLayout; }
    static i32 static_message_id() { return (int)MessageID::SetScreenLayout; }
    virtual const char* message_name() const override { return "WindowServer::SetScreenLayout"; }

    static OwnPtr<SetScreenLayout> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        ::WindowServer::ScreenLayout screen_layout = {};
        if (decoder.decode(screen_layout).is_error())
            return {};

        bool save = false;
        if (decoder.decode(save).is_error())
            return {};

        return make<SetScreenLayout>(move(screen_layout), move(save));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetScreenLayout;

        stream << m_screen_layout;

        stream << m_save;

        return buffer;
    }

    const ::WindowServer::ScreenLayout& screen_layout() const { return m_screen_layout; }
    ::WindowServer::ScreenLayout take_screen_layout() { return move(m_screen_layout); }

    const bool& save() const { return m_save; }
    bool take_save() { return move(m_save); }

private:
    bool m_ipc_message_valid { true };

    ::WindowServer::ScreenLayout m_screen_layout {};

    bool m_save {};

};

class GetScreenLayoutResponse final : public IPC::Message {
public:

    GetScreenLayoutResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenLayoutResponse(GetScreenLayoutResponse const&) = default;
    GetScreenLayoutResponse(GetScreenLayoutResponse&&) = default;
    GetScreenLayoutResponse& operator=(GetScreenLayoutResponse const&) = default;
    GetScreenLayoutResponse(::WindowServer::ScreenLayout screen_layout) : m_screen_layout(move(screen_layout)) {}
    virtual ~GetScreenLayoutResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenLayoutResponse; }
    static i32 static_message_id() { return (int)MessageID::GetScreenLayoutResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenLayoutResponse"; }

    static OwnPtr<GetScreenLayoutResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        ::WindowServer::ScreenLayout screen_layout = {};
        if (decoder.decode(screen_layout).is_error())
            return {};

        return make<GetScreenLayoutResponse>(move(screen_layout));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenLayoutResponse;

        stream << m_screen_layout;

        return buffer;
    }

    const ::WindowServer::ScreenLayout& screen_layout() const { return m_screen_layout; }
    ::WindowServer::ScreenLayout take_screen_layout() { return move(m_screen_layout); }

private:
    bool m_ipc_message_valid { true };

    ::WindowServer::ScreenLayout m_screen_layout {};

};

class GetScreenLayout final : public IPC::Message {
public:

   typedef class GetScreenLayoutResponse ResponseType;

    GetScreenLayout(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenLayout(GetScreenLayout const&) = default;
    GetScreenLayout(GetScreenLayout&&) = default;
    GetScreenLayout& operator=(GetScreenLayout const&) = default;
    GetScreenLayout() {}
    virtual ~GetScreenLayout() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenLayout; }
    static i32 static_message_id() { return (int)MessageID::GetScreenLayout; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenLayout"; }

    static OwnPtr<GetScreenLayout> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetScreenLayout>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenLayout;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SaveScreenLayoutResponse final : public IPC::Message {
public:

    SaveScreenLayoutResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SaveScreenLayoutResponse(SaveScreenLayoutResponse const&) = default;
    SaveScreenLayoutResponse(SaveScreenLayoutResponse&&) = default;
    SaveScreenLayoutResponse& operator=(SaveScreenLayoutResponse const&) = default;
    SaveScreenLayoutResponse(bool success, String error_msg) : m_success(move(success)), m_error_msg(move(error_msg)) {}
    virtual ~SaveScreenLayoutResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SaveScreenLayoutResponse; }
    static i32 static_message_id() { return (int)MessageID::SaveScreenLayoutResponse; }
    virtual const char* message_name() const override { return "WindowServer::SaveScreenLayoutResponse"; }

    static OwnPtr<SaveScreenLayoutResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        String error_msg = {};
        if (decoder.decode(error_msg).is_error())
            return {};

        return make<SaveScreenLayoutResponse>(move(success), move(error_msg));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SaveScreenLayoutResponse;

        stream << m_success;

        stream << m_error_msg;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

    const String& error_msg() const { return m_error_msg; }
    String take_error_msg() { return move(m_error_msg); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

    String m_error_msg {};

};

class SaveScreenLayout final : public IPC::Message {
public:

   typedef class SaveScreenLayoutResponse ResponseType;

    SaveScreenLayout(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SaveScreenLayout(SaveScreenLayout const&) = default;
    SaveScreenLayout(SaveScreenLayout&&) = default;
    SaveScreenLayout& operator=(SaveScreenLayout const&) = default;
    SaveScreenLayout() {}
    virtual ~SaveScreenLayout() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SaveScreenLayout; }
    static i32 static_message_id() { return (int)MessageID::SaveScreenLayout; }
    virtual const char* message_name() const override { return "WindowServer::SaveScreenLayout"; }

    static OwnPtr<SaveScreenLayout> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SaveScreenLayout>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SaveScreenLayout;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class ShowScreenNumbers final : public IPC::Message {
public:

    ShowScreenNumbers(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ShowScreenNumbers(ShowScreenNumbers const&) = default;
    ShowScreenNumbers(ShowScreenNumbers&&) = default;
    ShowScreenNumbers& operator=(ShowScreenNumbers const&) = default;
    ShowScreenNumbers(bool show) : m_show(move(show)) {}
    virtual ~ShowScreenNumbers() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::ShowScreenNumbers; }
    static i32 static_message_id() { return (int)MessageID::ShowScreenNumbers; }
    virtual const char* message_name() const override { return "WindowServer::ShowScreenNumbers"; }

    static OwnPtr<ShowScreenNumbers> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool show = false;
        if (decoder.decode(show).is_error())
            return {};

        return make<ShowScreenNumbers>(move(show));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ShowScreenNumbers;

        stream << m_show;

        return buffer;
    }

    const bool& show() const { return m_show; }
    bool take_show() { return move(m_show); }

private:
    bool m_ipc_message_valid { true };

    bool m_show {};

};

class ApplyWorkspaceSettingsResponse final : public IPC::Message {
public:

    ApplyWorkspaceSettingsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ApplyWorkspaceSettingsResponse(ApplyWorkspaceSettingsResponse const&) = default;
    ApplyWorkspaceSettingsResponse(ApplyWorkspaceSettingsResponse&&) = default;
    ApplyWorkspaceSettingsResponse& operator=(ApplyWorkspaceSettingsResponse const&) = default;
    ApplyWorkspaceSettingsResponse(bool success) : m_success(move(success)) {}
    virtual ~ApplyWorkspaceSettingsResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::ApplyWorkspaceSettingsResponse; }
    static i32 static_message_id() { return (int)MessageID::ApplyWorkspaceSettingsResponse; }
    virtual const char* message_name() const override { return "WindowServer::ApplyWorkspaceSettingsResponse"; }

    static OwnPtr<ApplyWorkspaceSettingsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<ApplyWorkspaceSettingsResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ApplyWorkspaceSettingsResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class ApplyWorkspaceSettings final : public IPC::Message {
public:

   typedef class ApplyWorkspaceSettingsResponse ResponseType;

    ApplyWorkspaceSettings(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ApplyWorkspaceSettings(ApplyWorkspaceSettings const&) = default;
    ApplyWorkspaceSettings(ApplyWorkspaceSettings&&) = default;
    ApplyWorkspaceSettings& operator=(ApplyWorkspaceSettings const&) = default;
    ApplyWorkspaceSettings(u32 rows, u32 columns, bool save) : m_rows(move(rows)), m_columns(move(columns)), m_save(move(save)) {}
    virtual ~ApplyWorkspaceSettings() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::ApplyWorkspaceSettings; }
    static i32 static_message_id() { return (int)MessageID::ApplyWorkspaceSettings; }
    virtual const char* message_name() const override { return "WindowServer::ApplyWorkspaceSettings"; }

    static OwnPtr<ApplyWorkspaceSettings> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 rows = {};
        if (decoder.decode(rows).is_error())
            return {};

        u32 columns = {};
        if (decoder.decode(columns).is_error())
            return {};

        bool save = false;
        if (decoder.decode(save).is_error())
            return {};

        return make<ApplyWorkspaceSettings>(move(rows), move(columns), move(save));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ApplyWorkspaceSettings;

        stream << m_rows;

        stream << m_columns;

        stream << m_save;

        return buffer;
    }

    const u32& rows() const { return m_rows; }
    u32 take_rows() { return move(m_rows); }

    const u32& columns() const { return m_columns; }
    u32 take_columns() { return move(m_columns); }

    const bool& save() const { return m_save; }
    bool take_save() { return move(m_save); }

private:
    bool m_ipc_message_valid { true };

    u32 m_rows {};

    u32 m_columns {};

    bool m_save {};

};

class GetWorkspaceSettingsResponse final : public IPC::Message {
public:

    GetWorkspaceSettingsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWorkspaceSettingsResponse(GetWorkspaceSettingsResponse const&) = default;
    GetWorkspaceSettingsResponse(GetWorkspaceSettingsResponse&&) = default;
    GetWorkspaceSettingsResponse& operator=(GetWorkspaceSettingsResponse const&) = default;
    GetWorkspaceSettingsResponse(u32 rows, u32 columns, u32 max_rows, u32 max_columns) : m_rows(move(rows)), m_columns(move(columns)), m_max_rows(move(max_rows)), m_max_columns(move(max_columns)) {}
    virtual ~GetWorkspaceSettingsResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWorkspaceSettingsResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWorkspaceSettingsResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWorkspaceSettingsResponse"; }

    static OwnPtr<GetWorkspaceSettingsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 rows = {};
        if (decoder.decode(rows).is_error())
            return {};

        u32 columns = {};
        if (decoder.decode(columns).is_error())
            return {};

        u32 max_rows = {};
        if (decoder.decode(max_rows).is_error())
            return {};

        u32 max_columns = {};
        if (decoder.decode(max_columns).is_error())
            return {};

        return make<GetWorkspaceSettingsResponse>(move(rows), move(columns), move(max_rows), move(max_columns));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWorkspaceSettingsResponse;

        stream << m_rows;

        stream << m_columns;

        stream << m_max_rows;

        stream << m_max_columns;

        return buffer;
    }

    const u32& rows() const { return m_rows; }
    u32 take_rows() { return move(m_rows); }

    const u32& columns() const { return m_columns; }
    u32 take_columns() { return move(m_columns); }

    const u32& max_rows() const { return m_max_rows; }
    u32 take_max_rows() { return move(m_max_rows); }

    const u32& max_columns() const { return m_max_columns; }
    u32 take_max_columns() { return move(m_max_columns); }

private:
    bool m_ipc_message_valid { true };

    u32 m_rows {};

    u32 m_columns {};

    u32 m_max_rows {};

    u32 m_max_columns {};

};

class GetWorkspaceSettings final : public IPC::Message {
public:

   typedef class GetWorkspaceSettingsResponse ResponseType;

    GetWorkspaceSettings(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWorkspaceSettings(GetWorkspaceSettings const&) = default;
    GetWorkspaceSettings(GetWorkspaceSettings&&) = default;
    GetWorkspaceSettings& operator=(GetWorkspaceSettings const&) = default;
    GetWorkspaceSettings() {}
    virtual ~GetWorkspaceSettings() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWorkspaceSettings; }
    static i32 static_message_id() { return (int)MessageID::GetWorkspaceSettings; }
    virtual const char* message_name() const override { return "WindowServer::GetWorkspaceSettings"; }

    static OwnPtr<GetWorkspaceSettings> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetWorkspaceSettings>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWorkspaceSettings;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetWindowIconBitmap final : public IPC::Message {
public:

    SetWindowIconBitmap(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowIconBitmap(SetWindowIconBitmap const&) = default;
    SetWindowIconBitmap(SetWindowIconBitmap&&) = default;
    SetWindowIconBitmap& operator=(SetWindowIconBitmap const&) = default;
    SetWindowIconBitmap(i32 window_id, Gfx::ShareableBitmap icon) : m_window_id(move(window_id)), m_icon(move(icon)) {}
    virtual ~SetWindowIconBitmap() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowIconBitmap; }
    static i32 static_message_id() { return (int)MessageID::SetWindowIconBitmap; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowIconBitmap"; }

    static OwnPtr<SetWindowIconBitmap> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::ShareableBitmap icon = {};
        if (decoder.decode(icon).is_error())
            return {};

        return make<SetWindowIconBitmap>(move(window_id), move(icon));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowIconBitmap;

        stream << m_window_id;

        stream << m_icon;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::ShareableBitmap& icon() const { return m_icon; }
    Gfx::ShareableBitmap take_icon() { return move(m_icon); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::ShareableBitmap m_icon {};

};

class GetWallpaperResponse final : public IPC::Message {
public:

    GetWallpaperResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWallpaperResponse(GetWallpaperResponse const&) = default;
    GetWallpaperResponse(GetWallpaperResponse&&) = default;
    GetWallpaperResponse& operator=(GetWallpaperResponse const&) = default;
    GetWallpaperResponse(Gfx::ShareableBitmap wallpaper_bitmap) : m_wallpaper_bitmap(move(wallpaper_bitmap)) {}
    virtual ~GetWallpaperResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWallpaperResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWallpaperResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWallpaperResponse"; }

    static OwnPtr<GetWallpaperResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap wallpaper_bitmap = {};
        if (decoder.decode(wallpaper_bitmap).is_error())
            return {};

        return make<GetWallpaperResponse>(move(wallpaper_bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWallpaperResponse;

        stream << m_wallpaper_bitmap;

        return buffer;
    }

    const Gfx::ShareableBitmap& wallpaper_bitmap() const { return m_wallpaper_bitmap; }
    Gfx::ShareableBitmap take_wallpaper_bitmap() { return move(m_wallpaper_bitmap); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_wallpaper_bitmap {};

};

class GetWallpaper final : public IPC::Message {
public:

   typedef class GetWallpaperResponse ResponseType;

    GetWallpaper(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWallpaper(GetWallpaper const&) = default;
    GetWallpaper(GetWallpaper&&) = default;
    GetWallpaper& operator=(GetWallpaper const&) = default;
    GetWallpaper() {}
    virtual ~GetWallpaper() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWallpaper; }
    static i32 static_message_id() { return (int)MessageID::GetWallpaper; }
    virtual const char* message_name() const override { return "WindowServer::GetWallpaper"; }

    static OwnPtr<GetWallpaper> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetWallpaper>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWallpaper;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetWindowCursor final : public IPC::Message {
public:

    SetWindowCursor(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowCursor(SetWindowCursor const&) = default;
    SetWindowCursor(SetWindowCursor&&) = default;
    SetWindowCursor& operator=(SetWindowCursor const&) = default;
    SetWindowCursor(i32 window_id, i32 cursor_type) : m_window_id(move(window_id)), m_cursor_type(move(cursor_type)) {}
    virtual ~SetWindowCursor() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowCursor; }
    static i32 static_message_id() { return (int)MessageID::SetWindowCursor; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowCursor"; }

    static OwnPtr<SetWindowCursor> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        i32 cursor_type = {};
        if (decoder.decode(cursor_type).is_error())
            return {};

        return make<SetWindowCursor>(move(window_id), move(cursor_type));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowCursor;

        stream << m_window_id;

        stream << m_cursor_type;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const i32& cursor_type() const { return m_cursor_type; }
    i32 take_cursor_type() { return move(m_cursor_type); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    i32 m_cursor_type {};

};

class SetWindowCustomCursor final : public IPC::Message {
public:

    SetWindowCustomCursor(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowCustomCursor(SetWindowCustomCursor const&) = default;
    SetWindowCustomCursor(SetWindowCustomCursor&&) = default;
    SetWindowCustomCursor& operator=(SetWindowCustomCursor const&) = default;
    SetWindowCustomCursor(i32 window_id, Gfx::ShareableBitmap cursor) : m_window_id(move(window_id)), m_cursor(move(cursor)) {}
    virtual ~SetWindowCustomCursor() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowCustomCursor; }
    static i32 static_message_id() { return (int)MessageID::SetWindowCustomCursor; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowCustomCursor"; }

    static OwnPtr<SetWindowCustomCursor> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::ShareableBitmap cursor = {};
        if (decoder.decode(cursor).is_error())
            return {};

        return make<SetWindowCustomCursor>(move(window_id), move(cursor));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowCustomCursor;

        stream << m_window_id;

        stream << m_cursor;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::ShareableBitmap& cursor() const { return m_cursor; }
    Gfx::ShareableBitmap take_cursor() { return move(m_cursor); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::ShareableBitmap m_cursor {};

};

class StartDragResponse final : public IPC::Message {
public:

    StartDragResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartDragResponse(StartDragResponse const&) = default;
    StartDragResponse(StartDragResponse&&) = default;
    StartDragResponse& operator=(StartDragResponse const&) = default;
    StartDragResponse(bool started) : m_started(move(started)) {}
    virtual ~StartDragResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::StartDragResponse; }
    static i32 static_message_id() { return (int)MessageID::StartDragResponse; }
    virtual const char* message_name() const override { return "WindowServer::StartDragResponse"; }

    static OwnPtr<StartDragResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool started = false;
        if (decoder.decode(started).is_error())
            return {};

        return make<StartDragResponse>(move(started));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartDragResponse;

        stream << m_started;

        return buffer;
    }

    const bool& started() const { return m_started; }
    bool take_started() { return move(m_started); }

private:
    bool m_ipc_message_valid { true };

    bool m_started {};

};

class StartDrag final : public IPC::Message {
public:

   typedef class StartDragResponse ResponseType;

    StartDrag(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartDrag(StartDrag const&) = default;
    StartDrag(StartDrag&&) = default;
    StartDrag& operator=(StartDrag const&) = default;
    StartDrag(String text, HashMap<String,ByteBuffer> mime_data, Gfx::ShareableBitmap drag_bitmap) : m_text(move(text)), m_mime_data(move(mime_data)), m_drag_bitmap(move(drag_bitmap)) {}
    virtual ~StartDrag() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::StartDrag; }
    static i32 static_message_id() { return (int)MessageID::StartDrag; }
    virtual const char* message_name() const override { return "WindowServer::StartDrag"; }

    static OwnPtr<StartDrag> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        HashMap<String,ByteBuffer> mime_data = {};
        if (decoder.decode(mime_data).is_error())
            return {};

        Gfx::ShareableBitmap drag_bitmap = {};
        if (decoder.decode(drag_bitmap).is_error())
            return {};

        return make<StartDrag>(move(text), move(mime_data), move(drag_bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartDrag;

        stream << m_text;

        stream << m_mime_data;

        stream << m_drag_bitmap;

        return buffer;
    }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const HashMap<String,ByteBuffer>& mime_data() const { return m_mime_data; }
    HashMap<String,ByteBuffer> take_mime_data() { return move(m_mime_data); }

    const Gfx::ShareableBitmap& drag_bitmap() const { return m_drag_bitmap; }
    Gfx::ShareableBitmap take_drag_bitmap() { return move(m_drag_bitmap); }

private:
    bool m_ipc_message_valid { true };

    String m_text {};

    HashMap<String,ByteBuffer> m_mime_data {};

    Gfx::ShareableBitmap m_drag_bitmap {};

};

class SetSystemThemeResponse final : public IPC::Message {
public:

    SetSystemThemeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSystemThemeResponse(SetSystemThemeResponse const&) = default;
    SetSystemThemeResponse(SetSystemThemeResponse&&) = default;
    SetSystemThemeResponse& operator=(SetSystemThemeResponse const&) = default;
    SetSystemThemeResponse(bool success) : m_success(move(success)) {}
    virtual ~SetSystemThemeResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetSystemThemeResponse; }
    static i32 static_message_id() { return (int)MessageID::SetSystemThemeResponse; }
    virtual const char* message_name() const override { return "WindowServer::SetSystemThemeResponse"; }

    static OwnPtr<SetSystemThemeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetSystemThemeResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSystemThemeResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class SetSystemTheme final : public IPC::Message {
public:

   typedef class SetSystemThemeResponse ResponseType;

    SetSystemTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSystemTheme(SetSystemTheme const&) = default;
    SetSystemTheme(SetSystemTheme&&) = default;
    SetSystemTheme& operator=(SetSystemTheme const&) = default;
    SetSystemTheme(String theme_path, String theme_name, bool keep_desktop_background) : m_theme_path(move(theme_path)), m_theme_name(move(theme_name)), m_keep_desktop_background(move(keep_desktop_background)) {}
    virtual ~SetSystemTheme() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetSystemTheme; }
    static i32 static_message_id() { return (int)MessageID::SetSystemTheme; }
    virtual const char* message_name() const override { return "WindowServer::SetSystemTheme"; }

    static OwnPtr<SetSystemTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String theme_path = {};
        if (decoder.decode(theme_path).is_error())
            return {};

        String theme_name = {};
        if (decoder.decode(theme_name).is_error())
            return {};

        if (!Utf8View(theme_name).validate())
            return {};

        bool keep_desktop_background = false;
        if (decoder.decode(keep_desktop_background).is_error())
            return {};

        return make<SetSystemTheme>(move(theme_path), move(theme_name), move(keep_desktop_background));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSystemTheme;

        stream << m_theme_path;

        stream << m_theme_name;

        stream << m_keep_desktop_background;

        return buffer;
    }

    const String& theme_path() const { return m_theme_path; }
    String take_theme_path() { return move(m_theme_path); }

    const String& theme_name() const { return m_theme_name; }
    String take_theme_name() { return move(m_theme_name); }

    const bool& keep_desktop_background() const { return m_keep_desktop_background; }
    bool take_keep_desktop_background() { return move(m_keep_desktop_background); }

private:
    bool m_ipc_message_valid { true };

    String m_theme_path {};

    String m_theme_name {};

    bool m_keep_desktop_background {};

};

class GetSystemThemeResponse final : public IPC::Message {
public:

    GetSystemThemeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSystemThemeResponse(GetSystemThemeResponse const&) = default;
    GetSystemThemeResponse(GetSystemThemeResponse&&) = default;
    GetSystemThemeResponse& operator=(GetSystemThemeResponse const&) = default;
    GetSystemThemeResponse(String theme_name) : m_theme_name(move(theme_name)) {}
    virtual ~GetSystemThemeResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetSystemThemeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetSystemThemeResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetSystemThemeResponse"; }

    static OwnPtr<GetSystemThemeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String theme_name = {};
        if (decoder.decode(theme_name).is_error())
            return {};

        if (!Utf8View(theme_name).validate())
            return {};

        return make<GetSystemThemeResponse>(move(theme_name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSystemThemeResponse;

        stream << m_theme_name;

        return buffer;
    }

    const String& theme_name() const { return m_theme_name; }
    String take_theme_name() { return move(m_theme_name); }

private:
    bool m_ipc_message_valid { true };

    String m_theme_name {};

};

class GetSystemTheme final : public IPC::Message {
public:

   typedef class GetSystemThemeResponse ResponseType;

    GetSystemTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSystemTheme(GetSystemTheme const&) = default;
    GetSystemTheme(GetSystemTheme&&) = default;
    GetSystemTheme& operator=(GetSystemTheme const&) = default;
    GetSystemTheme() {}
    virtual ~GetSystemTheme() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetSystemTheme; }
    static i32 static_message_id() { return (int)MessageID::GetSystemTheme; }
    virtual const char* message_name() const override { return "WindowServer::GetSystemTheme"; }

    static OwnPtr<GetSystemTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetSystemTheme>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSystemTheme;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class RefreshSystemTheme final : public IPC::Message {
public:

    RefreshSystemTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RefreshSystemTheme(RefreshSystemTheme const&) = default;
    RefreshSystemTheme(RefreshSystemTheme&&) = default;
    RefreshSystemTheme& operator=(RefreshSystemTheme const&) = default;
    RefreshSystemTheme() {}
    virtual ~RefreshSystemTheme() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::RefreshSystemTheme; }
    static i32 static_message_id() { return (int)MessageID::RefreshSystemTheme; }
    virtual const char* message_name() const override { return "WindowServer::RefreshSystemTheme"; }

    static OwnPtr<RefreshSystemTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<RefreshSystemTheme>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RefreshSystemTheme;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class ApplyCursorTheme final : public IPC::Message {
public:

    ApplyCursorTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ApplyCursorTheme(ApplyCursorTheme const&) = default;
    ApplyCursorTheme(ApplyCursorTheme&&) = default;
    ApplyCursorTheme& operator=(ApplyCursorTheme const&) = default;
    ApplyCursorTheme(String name) : m_name(move(name)) {}
    virtual ~ApplyCursorTheme() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::ApplyCursorTheme; }
    static i32 static_message_id() { return (int)MessageID::ApplyCursorTheme; }
    virtual const char* message_name() const override { return "WindowServer::ApplyCursorTheme"; }

    static OwnPtr<ApplyCursorTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        return make<ApplyCursorTheme>(move(name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ApplyCursorTheme;

        stream << m_name;

        return buffer;
    }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

private:
    bool m_ipc_message_valid { true };

    String m_name {};

};

class GetCursorThemeResponse final : public IPC::Message {
public:

    GetCursorThemeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetCursorThemeResponse(GetCursorThemeResponse const&) = default;
    GetCursorThemeResponse(GetCursorThemeResponse&&) = default;
    GetCursorThemeResponse& operator=(GetCursorThemeResponse const&) = default;
    GetCursorThemeResponse(String name) : m_name(move(name)) {}
    virtual ~GetCursorThemeResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetCursorThemeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetCursorThemeResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetCursorThemeResponse"; }

    static OwnPtr<GetCursorThemeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        return make<GetCursorThemeResponse>(move(name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetCursorThemeResponse;

        stream << m_name;

        return buffer;
    }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

private:
    bool m_ipc_message_valid { true };

    String m_name {};

};

class GetCursorTheme final : public IPC::Message {
public:

   typedef class GetCursorThemeResponse ResponseType;

    GetCursorTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetCursorTheme(GetCursorTheme const&) = default;
    GetCursorTheme(GetCursorTheme&&) = default;
    GetCursorTheme& operator=(GetCursorTheme const&) = default;
    GetCursorTheme() {}
    virtual ~GetCursorTheme() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetCursorTheme; }
    static i32 static_message_id() { return (int)MessageID::GetCursorTheme; }
    virtual const char* message_name() const override { return "WindowServer::GetCursorTheme"; }

    static OwnPtr<GetCursorTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetCursorTheme>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetCursorTheme;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSystemFontsResponse final : public IPC::Message {
public:

    SetSystemFontsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSystemFontsResponse(SetSystemFontsResponse const&) = default;
    SetSystemFontsResponse(SetSystemFontsResponse&&) = default;
    SetSystemFontsResponse& operator=(SetSystemFontsResponse const&) = default;
    SetSystemFontsResponse(bool success) : m_success(move(success)) {}
    virtual ~SetSystemFontsResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetSystemFontsResponse; }
    static i32 static_message_id() { return (int)MessageID::SetSystemFontsResponse; }
    virtual const char* message_name() const override { return "WindowServer::SetSystemFontsResponse"; }

    static OwnPtr<SetSystemFontsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetSystemFontsResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSystemFontsResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class SetSystemFonts final : public IPC::Message {
public:

   typedef class SetSystemFontsResponse ResponseType;

    SetSystemFonts(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSystemFonts(SetSystemFonts const&) = default;
    SetSystemFonts(SetSystemFonts&&) = default;
    SetSystemFonts& operator=(SetSystemFonts const&) = default;
    SetSystemFonts(String default_font_query, String fixed_width_font_query) : m_default_font_query(move(default_font_query)), m_fixed_width_font_query(move(fixed_width_font_query)) {}
    virtual ~SetSystemFonts() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetSystemFonts; }
    static i32 static_message_id() { return (int)MessageID::SetSystemFonts; }
    virtual const char* message_name() const override { return "WindowServer::SetSystemFonts"; }

    static OwnPtr<SetSystemFonts> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String default_font_query = {};
        if (decoder.decode(default_font_query).is_error())
            return {};

        String fixed_width_font_query = {};
        if (decoder.decode(fixed_width_font_query).is_error())
            return {};

        return make<SetSystemFonts>(move(default_font_query), move(fixed_width_font_query));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSystemFonts;

        stream << m_default_font_query;

        stream << m_fixed_width_font_query;

        return buffer;
    }

    const String& default_font_query() const { return m_default_font_query; }
    String take_default_font_query() { return move(m_default_font_query); }

    const String& fixed_width_font_query() const { return m_fixed_width_font_query; }
    String take_fixed_width_font_query() { return move(m_fixed_width_font_query); }

private:
    bool m_ipc_message_valid { true };

    String m_default_font_query {};

    String m_fixed_width_font_query {};

};

class SetWindowBaseSizeAndSizeIncrement final : public IPC::Message {
public:

    SetWindowBaseSizeAndSizeIncrement(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowBaseSizeAndSizeIncrement(SetWindowBaseSizeAndSizeIncrement const&) = default;
    SetWindowBaseSizeAndSizeIncrement(SetWindowBaseSizeAndSizeIncrement&&) = default;
    SetWindowBaseSizeAndSizeIncrement& operator=(SetWindowBaseSizeAndSizeIncrement const&) = default;
    SetWindowBaseSizeAndSizeIncrement(i32 window_id, Gfx::IntSize base_size, Gfx::IntSize size_increment) : m_window_id(move(window_id)), m_base_size(move(base_size)), m_size_increment(move(size_increment)) {}
    virtual ~SetWindowBaseSizeAndSizeIncrement() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowBaseSizeAndSizeIncrement; }
    static i32 static_message_id() { return (int)MessageID::SetWindowBaseSizeAndSizeIncrement; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowBaseSizeAndSizeIncrement"; }

    static OwnPtr<SetWindowBaseSizeAndSizeIncrement> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntSize base_size = {};
        if (decoder.decode(base_size).is_error())
            return {};

        Gfx::IntSize size_increment = {};
        if (decoder.decode(size_increment).is_error())
            return {};

        return make<SetWindowBaseSizeAndSizeIncrement>(move(window_id), move(base_size), move(size_increment));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowBaseSizeAndSizeIncrement;

        stream << m_window_id;

        stream << m_base_size;

        stream << m_size_increment;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntSize& base_size() const { return m_base_size; }
    Gfx::IntSize take_base_size() { return move(m_base_size); }

    const Gfx::IntSize& size_increment() const { return m_size_increment; }
    Gfx::IntSize take_size_increment() { return move(m_size_increment); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntSize m_base_size {};

    Gfx::IntSize m_size_increment {};

};

class SetWindowResizeAspectRatio final : public IPC::Message {
public:

    SetWindowResizeAspectRatio(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowResizeAspectRatio(SetWindowResizeAspectRatio const&) = default;
    SetWindowResizeAspectRatio(SetWindowResizeAspectRatio&&) = default;
    SetWindowResizeAspectRatio& operator=(SetWindowResizeAspectRatio const&) = default;
    SetWindowResizeAspectRatio(i32 window_id, Optional<Gfx::IntSize> resize_aspect_ratio) : m_window_id(move(window_id)), m_resize_aspect_ratio(move(resize_aspect_ratio)) {}
    virtual ~SetWindowResizeAspectRatio() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowResizeAspectRatio; }
    static i32 static_message_id() { return (int)MessageID::SetWindowResizeAspectRatio; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowResizeAspectRatio"; }

    static OwnPtr<SetWindowResizeAspectRatio> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Optional<Gfx::IntSize> resize_aspect_ratio = {};
        if (decoder.decode(resize_aspect_ratio).is_error())
            return {};

        return make<SetWindowResizeAspectRatio>(move(window_id), move(resize_aspect_ratio));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowResizeAspectRatio;

        stream << m_window_id;

        stream << m_resize_aspect_ratio;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Optional<Gfx::IntSize>& resize_aspect_ratio() const { return m_resize_aspect_ratio; }
    Optional<Gfx::IntSize> take_resize_aspect_ratio() { return move(m_resize_aspect_ratio); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Optional<Gfx::IntSize> m_resize_aspect_ratio {};

};

class EnableDisplayLink final : public IPC::Message {
public:

    EnableDisplayLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    EnableDisplayLink(EnableDisplayLink const&) = default;
    EnableDisplayLink(EnableDisplayLink&&) = default;
    EnableDisplayLink& operator=(EnableDisplayLink const&) = default;
    EnableDisplayLink() {}
    virtual ~EnableDisplayLink() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::EnableDisplayLink; }
    static i32 static_message_id() { return (int)MessageID::EnableDisplayLink; }
    virtual const char* message_name() const override { return "WindowServer::EnableDisplayLink"; }

    static OwnPtr<EnableDisplayLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<EnableDisplayLink>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::EnableDisplayLink;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DisableDisplayLink final : public IPC::Message {
public:

    DisableDisplayLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DisableDisplayLink(DisableDisplayLink const&) = default;
    DisableDisplayLink(DisableDisplayLink&&) = default;
    DisableDisplayLink& operator=(DisableDisplayLink const&) = default;
    DisableDisplayLink() {}
    virtual ~DisableDisplayLink() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::DisableDisplayLink; }
    static i32 static_message_id() { return (int)MessageID::DisableDisplayLink; }
    virtual const char* message_name() const override { return "WindowServer::DisableDisplayLink"; }

    static OwnPtr<DisableDisplayLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DisableDisplayLink>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DisableDisplayLink;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetGlobalCursorPosition final : public IPC::Message {
public:

    SetGlobalCursorPosition(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetGlobalCursorPosition(SetGlobalCursorPosition const&) = default;
    SetGlobalCursorPosition(SetGlobalCursorPosition&&) = default;
    SetGlobalCursorPosition& operator=(SetGlobalCursorPosition const&) = default;
    SetGlobalCursorPosition(Gfx::IntPoint position) : m_position(move(position)) {}
    virtual ~SetGlobalCursorPosition() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetGlobalCursorPosition; }
    static i32 static_message_id() { return (int)MessageID::SetGlobalCursorPosition; }
    virtual const char* message_name() const override { return "WindowServer::SetGlobalCursorPosition"; }

    static OwnPtr<SetGlobalCursorPosition> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        return make<SetGlobalCursorPosition>(move(position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetGlobalCursorPosition;

        stream << m_position;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

};

class GetGlobalCursorPositionResponse final : public IPC::Message {
public:

    GetGlobalCursorPositionResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetGlobalCursorPositionResponse(GetGlobalCursorPositionResponse const&) = default;
    GetGlobalCursorPositionResponse(GetGlobalCursorPositionResponse&&) = default;
    GetGlobalCursorPositionResponse& operator=(GetGlobalCursorPositionResponse const&) = default;
    GetGlobalCursorPositionResponse(Gfx::IntPoint position) : m_position(move(position)) {}
    virtual ~GetGlobalCursorPositionResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetGlobalCursorPositionResponse; }
    static i32 static_message_id() { return (int)MessageID::GetGlobalCursorPositionResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetGlobalCursorPositionResponse"; }

    static OwnPtr<GetGlobalCursorPositionResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        return make<GetGlobalCursorPositionResponse>(move(position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetGlobalCursorPositionResponse;

        stream << m_position;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

};

class GetGlobalCursorPosition final : public IPC::Message {
public:

   typedef class GetGlobalCursorPositionResponse ResponseType;

    GetGlobalCursorPosition(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetGlobalCursorPosition(GetGlobalCursorPosition const&) = default;
    GetGlobalCursorPosition(GetGlobalCursorPosition&&) = default;
    GetGlobalCursorPosition& operator=(GetGlobalCursorPosition const&) = default;
    GetGlobalCursorPosition() {}
    virtual ~GetGlobalCursorPosition() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetGlobalCursorPosition; }
    static i32 static_message_id() { return (int)MessageID::GetGlobalCursorPosition; }
    virtual const char* message_name() const override { return "WindowServer::GetGlobalCursorPosition"; }

    static OwnPtr<GetGlobalCursorPosition> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetGlobalCursorPosition>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetGlobalCursorPosition;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetMouseAcceleration final : public IPC::Message {
public:

    SetMouseAcceleration(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMouseAcceleration(SetMouseAcceleration const&) = default;
    SetMouseAcceleration(SetMouseAcceleration&&) = default;
    SetMouseAcceleration& operator=(SetMouseAcceleration const&) = default;
    SetMouseAcceleration(float factor) : m_factor(move(factor)) {}
    virtual ~SetMouseAcceleration() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetMouseAcceleration; }
    static i32 static_message_id() { return (int)MessageID::SetMouseAcceleration; }
    virtual const char* message_name() const override { return "WindowServer::SetMouseAcceleration"; }

    static OwnPtr<SetMouseAcceleration> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        float factor = {};
        if (decoder.decode(factor).is_error())
            return {};

        return make<SetMouseAcceleration>(move(factor));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMouseAcceleration;

        stream << m_factor;

        return buffer;
    }

    const float& factor() const { return m_factor; }
    float take_factor() { return move(m_factor); }

private:
    bool m_ipc_message_valid { true };

    float m_factor {};

};

class GetMouseAccelerationResponse final : public IPC::Message {
public:

    GetMouseAccelerationResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetMouseAccelerationResponse(GetMouseAccelerationResponse const&) = default;
    GetMouseAccelerationResponse(GetMouseAccelerationResponse&&) = default;
    GetMouseAccelerationResponse& operator=(GetMouseAccelerationResponse const&) = default;
    GetMouseAccelerationResponse(float factor) : m_factor(move(factor)) {}
    virtual ~GetMouseAccelerationResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetMouseAccelerationResponse; }
    static i32 static_message_id() { return (int)MessageID::GetMouseAccelerationResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetMouseAccelerationResponse"; }

    static OwnPtr<GetMouseAccelerationResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        float factor = {};
        if (decoder.decode(factor).is_error())
            return {};

        return make<GetMouseAccelerationResponse>(move(factor));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetMouseAccelerationResponse;

        stream << m_factor;

        return buffer;
    }

    const float& factor() const { return m_factor; }
    float take_factor() { return move(m_factor); }

private:
    bool m_ipc_message_valid { true };

    float m_factor {};

};

class GetMouseAcceleration final : public IPC::Message {
public:

   typedef class GetMouseAccelerationResponse ResponseType;

    GetMouseAcceleration(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetMouseAcceleration(GetMouseAcceleration const&) = default;
    GetMouseAcceleration(GetMouseAcceleration&&) = default;
    GetMouseAcceleration& operator=(GetMouseAcceleration const&) = default;
    GetMouseAcceleration() {}
    virtual ~GetMouseAcceleration() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetMouseAcceleration; }
    static i32 static_message_id() { return (int)MessageID::GetMouseAcceleration; }
    virtual const char* message_name() const override { return "WindowServer::GetMouseAcceleration"; }

    static OwnPtr<GetMouseAcceleration> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetMouseAcceleration>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetMouseAcceleration;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetScrollStepSize final : public IPC::Message {
public:

    SetScrollStepSize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetScrollStepSize(SetScrollStepSize const&) = default;
    SetScrollStepSize(SetScrollStepSize&&) = default;
    SetScrollStepSize& operator=(SetScrollStepSize const&) = default;
    SetScrollStepSize(u32 step_size) : m_step_size(move(step_size)) {}
    virtual ~SetScrollStepSize() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetScrollStepSize; }
    static i32 static_message_id() { return (int)MessageID::SetScrollStepSize; }
    virtual const char* message_name() const override { return "WindowServer::SetScrollStepSize"; }

    static OwnPtr<SetScrollStepSize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 step_size = {};
        if (decoder.decode(step_size).is_error())
            return {};

        return make<SetScrollStepSize>(move(step_size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetScrollStepSize;

        stream << m_step_size;

        return buffer;
    }

    const u32& step_size() const { return m_step_size; }
    u32 take_step_size() { return move(m_step_size); }

private:
    bool m_ipc_message_valid { true };

    u32 m_step_size {};

};

class GetScrollStepSizeResponse final : public IPC::Message {
public:

    GetScrollStepSizeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScrollStepSizeResponse(GetScrollStepSizeResponse const&) = default;
    GetScrollStepSizeResponse(GetScrollStepSizeResponse&&) = default;
    GetScrollStepSizeResponse& operator=(GetScrollStepSizeResponse const&) = default;
    GetScrollStepSizeResponse(u32 step_size) : m_step_size(move(step_size)) {}
    virtual ~GetScrollStepSizeResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScrollStepSizeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetScrollStepSizeResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetScrollStepSizeResponse"; }

    static OwnPtr<GetScrollStepSizeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 step_size = {};
        if (decoder.decode(step_size).is_error())
            return {};

        return make<GetScrollStepSizeResponse>(move(step_size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScrollStepSizeResponse;

        stream << m_step_size;

        return buffer;
    }

    const u32& step_size() const { return m_step_size; }
    u32 take_step_size() { return move(m_step_size); }

private:
    bool m_ipc_message_valid { true };

    u32 m_step_size {};

};

class GetScrollStepSize final : public IPC::Message {
public:

   typedef class GetScrollStepSizeResponse ResponseType;

    GetScrollStepSize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScrollStepSize(GetScrollStepSize const&) = default;
    GetScrollStepSize(GetScrollStepSize&&) = default;
    GetScrollStepSize& operator=(GetScrollStepSize const&) = default;
    GetScrollStepSize() {}
    virtual ~GetScrollStepSize() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScrollStepSize; }
    static i32 static_message_id() { return (int)MessageID::GetScrollStepSize; }
    virtual const char* message_name() const override { return "WindowServer::GetScrollStepSize"; }

    static OwnPtr<GetScrollStepSize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetScrollStepSize>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScrollStepSize;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class GetScreenBitmapResponse final : public IPC::Message {
public:

    GetScreenBitmapResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenBitmapResponse(GetScreenBitmapResponse const&) = default;
    GetScreenBitmapResponse(GetScreenBitmapResponse&&) = default;
    GetScreenBitmapResponse& operator=(GetScreenBitmapResponse const&) = default;
    GetScreenBitmapResponse(Gfx::ShareableBitmap bitmap) : m_bitmap(move(bitmap)) {}
    virtual ~GetScreenBitmapResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenBitmapResponse; }
    static i32 static_message_id() { return (int)MessageID::GetScreenBitmapResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenBitmapResponse"; }

    static OwnPtr<GetScreenBitmapResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap bitmap = {};
        if (decoder.decode(bitmap).is_error())
            return {};

        return make<GetScreenBitmapResponse>(move(bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenBitmapResponse;

        stream << m_bitmap;

        return buffer;
    }

    const Gfx::ShareableBitmap& bitmap() const { return m_bitmap; }
    Gfx::ShareableBitmap take_bitmap() { return move(m_bitmap); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_bitmap {};

};

class GetScreenBitmap final : public IPC::Message {
public:

   typedef class GetScreenBitmapResponse ResponseType;

    GetScreenBitmap(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenBitmap(GetScreenBitmap const&) = default;
    GetScreenBitmap(GetScreenBitmap&&) = default;
    GetScreenBitmap& operator=(GetScreenBitmap const&) = default;
    GetScreenBitmap(Optional<Gfx::IntRect> rect, Optional<u32> screen_index) : m_rect(move(rect)), m_screen_index(move(screen_index)) {}
    virtual ~GetScreenBitmap() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenBitmap; }
    static i32 static_message_id() { return (int)MessageID::GetScreenBitmap; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenBitmap"; }

    static OwnPtr<GetScreenBitmap> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Optional<Gfx::IntRect> rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        Optional<u32> screen_index = {};
        if (decoder.decode(screen_index).is_error())
            return {};

        return make<GetScreenBitmap>(move(rect), move(screen_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenBitmap;

        stream << m_rect;

        stream << m_screen_index;

        return buffer;
    }

    const Optional<Gfx::IntRect>& rect() const { return m_rect; }
    Optional<Gfx::IntRect> take_rect() { return move(m_rect); }

    const Optional<u32>& screen_index() const { return m_screen_index; }
    Optional<u32> take_screen_index() { return move(m_screen_index); }

private:
    bool m_ipc_message_valid { true };

    Optional<Gfx::IntRect> m_rect {};

    Optional<u32> m_screen_index {};

};

class GetScreenBitmapAroundCursorResponse final : public IPC::Message {
public:

    GetScreenBitmapAroundCursorResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenBitmapAroundCursorResponse(GetScreenBitmapAroundCursorResponse const&) = default;
    GetScreenBitmapAroundCursorResponse(GetScreenBitmapAroundCursorResponse&&) = default;
    GetScreenBitmapAroundCursorResponse& operator=(GetScreenBitmapAroundCursorResponse const&) = default;
    GetScreenBitmapAroundCursorResponse(Gfx::ShareableBitmap bitmap) : m_bitmap(move(bitmap)) {}
    virtual ~GetScreenBitmapAroundCursorResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenBitmapAroundCursorResponse; }
    static i32 static_message_id() { return (int)MessageID::GetScreenBitmapAroundCursorResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenBitmapAroundCursorResponse"; }

    static OwnPtr<GetScreenBitmapAroundCursorResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap bitmap = {};
        if (decoder.decode(bitmap).is_error())
            return {};

        return make<GetScreenBitmapAroundCursorResponse>(move(bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenBitmapAroundCursorResponse;

        stream << m_bitmap;

        return buffer;
    }

    const Gfx::ShareableBitmap& bitmap() const { return m_bitmap; }
    Gfx::ShareableBitmap take_bitmap() { return move(m_bitmap); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_bitmap {};

};

class GetScreenBitmapAroundCursor final : public IPC::Message {
public:

   typedef class GetScreenBitmapAroundCursorResponse ResponseType;

    GetScreenBitmapAroundCursor(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetScreenBitmapAroundCursor(GetScreenBitmapAroundCursor const&) = default;
    GetScreenBitmapAroundCursor(GetScreenBitmapAroundCursor&&) = default;
    GetScreenBitmapAroundCursor& operator=(GetScreenBitmapAroundCursor const&) = default;
    GetScreenBitmapAroundCursor(Gfx::IntSize size) : m_size(move(size)) {}
    virtual ~GetScreenBitmapAroundCursor() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetScreenBitmapAroundCursor; }
    static i32 static_message_id() { return (int)MessageID::GetScreenBitmapAroundCursor; }
    virtual const char* message_name() const override { return "WindowServer::GetScreenBitmapAroundCursor"; }

    static OwnPtr<GetScreenBitmapAroundCursor> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntSize size = {};
        if (decoder.decode(size).is_error())
            return {};

        return make<GetScreenBitmapAroundCursor>(move(size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetScreenBitmapAroundCursor;

        stream << m_size;

        return buffer;
    }

    const Gfx::IntSize& size() const { return m_size; }
    Gfx::IntSize take_size() { return move(m_size); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntSize m_size {};

};

class GetColorUnderCursorResponse final : public IPC::Message {
public:

    GetColorUnderCursorResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetColorUnderCursorResponse(GetColorUnderCursorResponse const&) = default;
    GetColorUnderCursorResponse(GetColorUnderCursorResponse&&) = default;
    GetColorUnderCursorResponse& operator=(GetColorUnderCursorResponse const&) = default;
    GetColorUnderCursorResponse(Optional<Gfx::Color> color) : m_color(move(color)) {}
    virtual ~GetColorUnderCursorResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetColorUnderCursorResponse; }
    static i32 static_message_id() { return (int)MessageID::GetColorUnderCursorResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetColorUnderCursorResponse"; }

    static OwnPtr<GetColorUnderCursorResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Optional<Gfx::Color> color = {};
        if (decoder.decode(color).is_error())
            return {};

        return make<GetColorUnderCursorResponse>(move(color));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetColorUnderCursorResponse;

        stream << m_color;

        return buffer;
    }

    const Optional<Gfx::Color>& color() const { return m_color; }
    Optional<Gfx::Color> take_color() { return move(m_color); }

private:
    bool m_ipc_message_valid { true };

    Optional<Gfx::Color> m_color {};

};

class GetColorUnderCursor final : public IPC::Message {
public:

   typedef class GetColorUnderCursorResponse ResponseType;

    GetColorUnderCursor(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetColorUnderCursor(GetColorUnderCursor const&) = default;
    GetColorUnderCursor(GetColorUnderCursor&&) = default;
    GetColorUnderCursor& operator=(GetColorUnderCursor const&) = default;
    GetColorUnderCursor() {}
    virtual ~GetColorUnderCursor() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetColorUnderCursor; }
    static i32 static_message_id() { return (int)MessageID::GetColorUnderCursor; }
    virtual const char* message_name() const override { return "WindowServer::GetColorUnderCursor"; }

    static OwnPtr<GetColorUnderCursor> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetColorUnderCursor>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetColorUnderCursor;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class Pong final : public IPC::Message {
public:

    Pong(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Pong(Pong const&) = default;
    Pong(Pong&&) = default;
    Pong& operator=(Pong const&) = default;
    Pong() {}
    virtual ~Pong() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::Pong; }
    static i32 static_message_id() { return (int)MessageID::Pong; }
    virtual const char* message_name() const override { return "WindowServer::Pong"; }

    static OwnPtr<Pong> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<Pong>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Pong;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetDoubleClickSpeed final : public IPC::Message {
public:

    SetDoubleClickSpeed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetDoubleClickSpeed(SetDoubleClickSpeed const&) = default;
    SetDoubleClickSpeed(SetDoubleClickSpeed&&) = default;
    SetDoubleClickSpeed& operator=(SetDoubleClickSpeed const&) = default;
    SetDoubleClickSpeed(int speed) : m_speed(move(speed)) {}
    virtual ~SetDoubleClickSpeed() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetDoubleClickSpeed; }
    static i32 static_message_id() { return (int)MessageID::SetDoubleClickSpeed; }
    virtual const char* message_name() const override { return "WindowServer::SetDoubleClickSpeed"; }

    static OwnPtr<SetDoubleClickSpeed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int speed = {};
        if (decoder.decode(speed).is_error())
            return {};

        return make<SetDoubleClickSpeed>(move(speed));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetDoubleClickSpeed;

        stream << m_speed;

        return buffer;
    }

    const int& speed() const { return m_speed; }
    int take_speed() { return move(m_speed); }

private:
    bool m_ipc_message_valid { true };

    int m_speed {};

};

class GetDoubleClickSpeedResponse final : public IPC::Message {
public:

    GetDoubleClickSpeedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetDoubleClickSpeedResponse(GetDoubleClickSpeedResponse const&) = default;
    GetDoubleClickSpeedResponse(GetDoubleClickSpeedResponse&&) = default;
    GetDoubleClickSpeedResponse& operator=(GetDoubleClickSpeedResponse const&) = default;
    GetDoubleClickSpeedResponse(int speed) : m_speed(move(speed)) {}
    virtual ~GetDoubleClickSpeedResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetDoubleClickSpeedResponse; }
    static i32 static_message_id() { return (int)MessageID::GetDoubleClickSpeedResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetDoubleClickSpeedResponse"; }

    static OwnPtr<GetDoubleClickSpeedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int speed = {};
        if (decoder.decode(speed).is_error())
            return {};

        return make<GetDoubleClickSpeedResponse>(move(speed));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetDoubleClickSpeedResponse;

        stream << m_speed;

        return buffer;
    }

    const int& speed() const { return m_speed; }
    int take_speed() { return move(m_speed); }

private:
    bool m_ipc_message_valid { true };

    int m_speed {};

};

class GetDoubleClickSpeed final : public IPC::Message {
public:

   typedef class GetDoubleClickSpeedResponse ResponseType;

    GetDoubleClickSpeed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetDoubleClickSpeed(GetDoubleClickSpeed const&) = default;
    GetDoubleClickSpeed(GetDoubleClickSpeed&&) = default;
    GetDoubleClickSpeed& operator=(GetDoubleClickSpeed const&) = default;
    GetDoubleClickSpeed() {}
    virtual ~GetDoubleClickSpeed() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetDoubleClickSpeed; }
    static i32 static_message_id() { return (int)MessageID::GetDoubleClickSpeed; }
    virtual const char* message_name() const override { return "WindowServer::GetDoubleClickSpeed"; }

    static OwnPtr<GetDoubleClickSpeed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetDoubleClickSpeed>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetDoubleClickSpeed;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetButtonsSwitched final : public IPC::Message {
public:

    SetButtonsSwitched(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetButtonsSwitched(SetButtonsSwitched const&) = default;
    SetButtonsSwitched(SetButtonsSwitched&&) = default;
    SetButtonsSwitched& operator=(SetButtonsSwitched const&) = default;
    SetButtonsSwitched(bool switched) : m_switched(move(switched)) {}
    virtual ~SetButtonsSwitched() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetButtonsSwitched; }
    static i32 static_message_id() { return (int)MessageID::SetButtonsSwitched; }
    virtual const char* message_name() const override { return "WindowServer::SetButtonsSwitched"; }

    static OwnPtr<SetButtonsSwitched> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool switched = false;
        if (decoder.decode(switched).is_error())
            return {};

        return make<SetButtonsSwitched>(move(switched));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetButtonsSwitched;

        stream << m_switched;

        return buffer;
    }

    const bool& switched() const { return m_switched; }
    bool take_switched() { return move(m_switched); }

private:
    bool m_ipc_message_valid { true };

    bool m_switched {};

};

class GetButtonsSwitchedResponse final : public IPC::Message {
public:

    GetButtonsSwitchedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetButtonsSwitchedResponse(GetButtonsSwitchedResponse const&) = default;
    GetButtonsSwitchedResponse(GetButtonsSwitchedResponse&&) = default;
    GetButtonsSwitchedResponse& operator=(GetButtonsSwitchedResponse const&) = default;
    GetButtonsSwitchedResponse(bool switched) : m_switched(move(switched)) {}
    virtual ~GetButtonsSwitchedResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetButtonsSwitchedResponse; }
    static i32 static_message_id() { return (int)MessageID::GetButtonsSwitchedResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetButtonsSwitchedResponse"; }

    static OwnPtr<GetButtonsSwitchedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool switched = false;
        if (decoder.decode(switched).is_error())
            return {};

        return make<GetButtonsSwitchedResponse>(move(switched));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetButtonsSwitchedResponse;

        stream << m_switched;

        return buffer;
    }

    const bool& switched() const { return m_switched; }
    bool take_switched() { return move(m_switched); }

private:
    bool m_ipc_message_valid { true };

    bool m_switched {};

};

class GetButtonsSwitched final : public IPC::Message {
public:

   typedef class GetButtonsSwitchedResponse ResponseType;

    GetButtonsSwitched(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetButtonsSwitched(GetButtonsSwitched const&) = default;
    GetButtonsSwitched(GetButtonsSwitched&&) = default;
    GetButtonsSwitched& operator=(GetButtonsSwitched const&) = default;
    GetButtonsSwitched() {}
    virtual ~GetButtonsSwitched() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetButtonsSwitched; }
    static i32 static_message_id() { return (int)MessageID::GetButtonsSwitched; }
    virtual const char* message_name() const override { return "WindowServer::GetButtonsSwitched"; }

    static OwnPtr<GetButtonsSwitched> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetButtonsSwitched>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetButtonsSwitched;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class GetDesktopDisplayScaleResponse final : public IPC::Message {
public:

    GetDesktopDisplayScaleResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetDesktopDisplayScaleResponse(GetDesktopDisplayScaleResponse const&) = default;
    GetDesktopDisplayScaleResponse(GetDesktopDisplayScaleResponse&&) = default;
    GetDesktopDisplayScaleResponse& operator=(GetDesktopDisplayScaleResponse const&) = default;
    GetDesktopDisplayScaleResponse(int desktop_display_scale) : m_desktop_display_scale(move(desktop_display_scale)) {}
    virtual ~GetDesktopDisplayScaleResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetDesktopDisplayScaleResponse; }
    static i32 static_message_id() { return (int)MessageID::GetDesktopDisplayScaleResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetDesktopDisplayScaleResponse"; }

    static OwnPtr<GetDesktopDisplayScaleResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int desktop_display_scale = {};
        if (decoder.decode(desktop_display_scale).is_error())
            return {};

        return make<GetDesktopDisplayScaleResponse>(move(desktop_display_scale));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetDesktopDisplayScaleResponse;

        stream << m_desktop_display_scale;

        return buffer;
    }

    const int& desktop_display_scale() const { return m_desktop_display_scale; }
    int take_desktop_display_scale() { return move(m_desktop_display_scale); }

private:
    bool m_ipc_message_valid { true };

    int m_desktop_display_scale {};

};

class GetDesktopDisplayScale final : public IPC::Message {
public:

   typedef class GetDesktopDisplayScaleResponse ResponseType;

    GetDesktopDisplayScale(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetDesktopDisplayScale(GetDesktopDisplayScale const&) = default;
    GetDesktopDisplayScale(GetDesktopDisplayScale&&) = default;
    GetDesktopDisplayScale& operator=(GetDesktopDisplayScale const&) = default;
    GetDesktopDisplayScale(u32 screen_index) : m_screen_index(move(screen_index)) {}
    virtual ~GetDesktopDisplayScale() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetDesktopDisplayScale; }
    static i32 static_message_id() { return (int)MessageID::GetDesktopDisplayScale; }
    virtual const char* message_name() const override { return "WindowServer::GetDesktopDisplayScale"; }

    static OwnPtr<GetDesktopDisplayScale> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 screen_index = {};
        if (decoder.decode(screen_index).is_error())
            return {};

        return make<GetDesktopDisplayScale>(move(screen_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetDesktopDisplayScale;

        stream << m_screen_index;

        return buffer;
    }

    const u32& screen_index() const { return m_screen_index; }
    u32 take_screen_index() { return move(m_screen_index); }

private:
    bool m_ipc_message_valid { true };

    u32 m_screen_index {};

};

class SetFlashFlush final : public IPC::Message {
public:

    SetFlashFlush(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetFlashFlush(SetFlashFlush const&) = default;
    SetFlashFlush(SetFlashFlush&&) = default;
    SetFlashFlush& operator=(SetFlashFlush const&) = default;
    SetFlashFlush(bool enabled) : m_enabled(move(enabled)) {}
    virtual ~SetFlashFlush() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetFlashFlush; }
    static i32 static_message_id() { return (int)MessageID::SetFlashFlush; }
    virtual const char* message_name() const override { return "WindowServer::SetFlashFlush"; }

    static OwnPtr<SetFlashFlush> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool enabled = false;
        if (decoder.decode(enabled).is_error())
            return {};

        return make<SetFlashFlush>(move(enabled));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetFlashFlush;

        stream << m_enabled;

        return buffer;
    }

    const bool& enabled() const { return m_enabled; }
    bool take_enabled() { return move(m_enabled); }

private:
    bool m_ipc_message_valid { true };

    bool m_enabled {};

};

class SetWindowParentFromClient final : public IPC::Message {
public:

    SetWindowParentFromClient(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowParentFromClient(SetWindowParentFromClient const&) = default;
    SetWindowParentFromClient(SetWindowParentFromClient&&) = default;
    SetWindowParentFromClient& operator=(SetWindowParentFromClient const&) = default;
    SetWindowParentFromClient(i32 client_id, i32 parent_id, i32 child_id) : m_client_id(move(client_id)), m_parent_id(move(parent_id)), m_child_id(move(child_id)) {}
    virtual ~SetWindowParentFromClient() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowParentFromClient; }
    static i32 static_message_id() { return (int)MessageID::SetWindowParentFromClient; }
    virtual const char* message_name() const override { return "WindowServer::SetWindowParentFromClient"; }

    static OwnPtr<SetWindowParentFromClient> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 parent_id = {};
        if (decoder.decode(parent_id).is_error())
            return {};

        i32 child_id = {};
        if (decoder.decode(child_id).is_error())
            return {};

        return make<SetWindowParentFromClient>(move(client_id), move(parent_id), move(child_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowParentFromClient;

        stream << m_client_id;

        stream << m_parent_id;

        stream << m_child_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& parent_id() const { return m_parent_id; }
    i32 take_parent_id() { return move(m_parent_id); }

    const i32& child_id() const { return m_child_id; }
    i32 take_child_id() { return move(m_child_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_parent_id {};

    i32 m_child_id {};

};

class GetWindowRectFromClientResponse final : public IPC::Message {
public:

    GetWindowRectFromClientResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowRectFromClientResponse(GetWindowRectFromClientResponse const&) = default;
    GetWindowRectFromClientResponse(GetWindowRectFromClientResponse&&) = default;
    GetWindowRectFromClientResponse& operator=(GetWindowRectFromClientResponse const&) = default;
    GetWindowRectFromClientResponse(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~GetWindowRectFromClientResponse() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowRectFromClientResponse; }
    static i32 static_message_id() { return (int)MessageID::GetWindowRectFromClientResponse; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowRectFromClientResponse"; }

    static OwnPtr<GetWindowRectFromClientResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<GetWindowRectFromClientResponse>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowRectFromClientResponse;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class GetWindowRectFromClient final : public IPC::Message {
public:

   typedef class GetWindowRectFromClientResponse ResponseType;

    GetWindowRectFromClient(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetWindowRectFromClient(GetWindowRectFromClient const&) = default;
    GetWindowRectFromClient(GetWindowRectFromClient&&) = default;
    GetWindowRectFromClient& operator=(GetWindowRectFromClient const&) = default;
    GetWindowRectFromClient(i32 client_id, i32 window_id) : m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~GetWindowRectFromClient() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::GetWindowRectFromClient; }
    static i32 static_message_id() { return (int)MessageID::GetWindowRectFromClient; }
    virtual const char* message_name() const override { return "WindowServer::GetWindowRectFromClient"; }

    static OwnPtr<GetWindowRectFromClient> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<GetWindowRectFromClient>(move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetWindowRectFromClient;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

};

class AddWindowStealingForClient final : public IPC::Message {
public:

    AddWindowStealingForClient(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddWindowStealingForClient(AddWindowStealingForClient const&) = default;
    AddWindowStealingForClient(AddWindowStealingForClient&&) = default;
    AddWindowStealingForClient& operator=(AddWindowStealingForClient const&) = default;
    AddWindowStealingForClient(i32 client_id, i32 window_id) : m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~AddWindowStealingForClient() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::AddWindowStealingForClient; }
    static i32 static_message_id() { return (int)MessageID::AddWindowStealingForClient; }
    virtual const char* message_name() const override { return "WindowServer::AddWindowStealingForClient"; }

    static OwnPtr<AddWindowStealingForClient> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<AddWindowStealingForClient>(move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddWindowStealingForClient;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

};

class RemoveWindowStealingForClient final : public IPC::Message {
public:

    RemoveWindowStealingForClient(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RemoveWindowStealingForClient(RemoveWindowStealingForClient const&) = default;
    RemoveWindowStealingForClient(RemoveWindowStealingForClient&&) = default;
    RemoveWindowStealingForClient& operator=(RemoveWindowStealingForClient const&) = default;
    RemoveWindowStealingForClient(i32 client_id, i32 window_id) : m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~RemoveWindowStealingForClient() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::RemoveWindowStealingForClient; }
    static i32 static_message_id() { return (int)MessageID::RemoveWindowStealingForClient; }
    virtual const char* message_name() const override { return "WindowServer::RemoveWindowStealingForClient"; }

    static OwnPtr<RemoveWindowStealingForClient> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<RemoveWindowStealingForClient>(move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RemoveWindowStealingForClient;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

};

class RemoveWindowStealing final : public IPC::Message {
public:

    RemoveWindowStealing(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RemoveWindowStealing(RemoveWindowStealing const&) = default;
    RemoveWindowStealing(RemoveWindowStealing&&) = default;
    RemoveWindowStealing& operator=(RemoveWindowStealing const&) = default;
    RemoveWindowStealing(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~RemoveWindowStealing() override {}

    virtual u32 endpoint_magic() const override { return 2938215075; }
    virtual i32 message_id() const override { return (int)MessageID::RemoveWindowStealing; }
    static i32 static_message_id() { return (int)MessageID::RemoveWindowStealing; }
    virtual const char* message_name() const override { return "WindowServer::RemoveWindowStealing"; }

    static OwnPtr<RemoveWindowStealing> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<RemoveWindowStealing>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RemoveWindowStealing;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

} // namespace Messages::WindowServer

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WindowServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_create_menu(
i32 menu_id, String menu_title) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::CreateMenu { menu_id, move(menu_title) });

    }

    void async_destroy_menu(
i32 menu_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::DestroyMenu { menu_id });

    }

    void async_add_menu(
i32 window_id, i32 menu_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::AddMenu { window_id, menu_id });

    }

    void async_add_menu_item(
i32 menu_id, i32 identifier, i32 submenu_id, String text, bool enabled, bool checkable, bool checked, bool is_default, String shortcut, Gfx::ShareableBitmap icon, bool exclusive) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::AddMenuItem { menu_id, identifier, submenu_id, move(text), enabled, checkable, checked, is_default, move(shortcut), move(icon), exclusive });

    }

    void async_add_menu_separator(
i32 menu_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::AddMenuSeparator { menu_id });

    }

    void async_update_menu_item(
i32 menu_id, i32 identifier, i32 submenu_id, String text, bool enabled, bool checkable, bool checked, bool is_default, String shortcut) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::UpdateMenuItem { menu_id, identifier, submenu_id, move(text), enabled, checkable, checked, is_default, move(shortcut) });

    }

    void async_remove_menu_item(
i32 menu_id, i32 identifier) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::RemoveMenuItem { menu_id, identifier });

    }

    void async_flash_menubar_menu(
i32 window_id, i32 menu_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::FlashMenubarMenu { window_id, menu_id });

    }

    void async_create_window(
i32 window_id, Gfx::IntRect rect, bool auto_position, bool has_alpha_channel, bool modal, bool minimizable, bool closeable, bool resizable, bool fullscreen, bool frameless, bool forced_shadow, bool accessory, float opacity, float alpha_hit_threshold, Gfx::IntSize base_size, Gfx::IntSize size_increment, Gfx::IntSize minimum_size, Optional<Gfx::IntSize> resize_aspect_ratio, i32 type, String title, i32 parent_window_id, Gfx::IntRect launch_origin_rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::CreateWindow { window_id, move(rect), auto_position, has_alpha_channel, modal, minimizable, closeable, resizable, fullscreen, frameless, forced_shadow, accessory, opacity, alpha_hit_threshold, move(base_size), move(size_increment), move(minimum_size), move(resize_aspect_ratio), type, move(title), parent_window_id, move(launch_origin_rect) });

    }

    Vector<i32> destroy_window(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::DestroyWindow>(window_id)->take_destroyed_window_ids();
    }

    void async_destroy_window(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::DestroyWindow { window_id });

    }

    IPC::IPCErrorOr<Vector<i32>> try_destroy_window(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::DestroyWindow>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_title(
i32 window_id, String title) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowTitle { window_id, move(title) });

    }

    String get_window_title(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::GetWindowTitle>(window_id)->take_title();
    }

    void async_get_window_title(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWindowTitle { window_id });

    }

    IPC::IPCErrorOr<String> try_get_window_title(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWindowTitle>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_progress(
i32 window_id, Optional<i32> progress) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowProgress { window_id, move(progress) });

    }

    void async_set_window_modified(
i32 window_id, bool modified) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowModified { window_id, modified });

    }

    bool is_window_modified(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::IsWindowModified>(window_id)->take_modified();
    }

    void async_is_window_modified(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::IsWindowModified { window_id });

    }

    IPC::IPCErrorOr<bool> try_is_window_modified(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::IsWindowModified>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Gfx::IntRect set_window_rect(
i32 window_id, Gfx::IntRect rect) {
        return m_connection.template send_sync<Messages::WindowServer::SetWindowRect>(window_id, move(rect))->take_rect();
    }

    void async_set_window_rect(
i32 window_id, Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowRect { window_id, move(rect) });

    }

    IPC::IPCErrorOr<Gfx::IntRect> try_set_window_rect(
i32 window_id, Gfx::IntRect rect) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SetWindowRect>(window_id, move(rect));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Gfx::IntRect get_window_rect(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::GetWindowRect>(window_id)->take_rect();
    }

    void async_get_window_rect(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWindowRect { window_id });

    }

    IPC::IPCErrorOr<Gfx::IntRect> try_get_window_rect(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWindowRect>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_minimum_size(
i32 window_id, Gfx::IntSize size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowMinimumSize { window_id, move(size) });

    }

    Gfx::IntSize get_window_minimum_size(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::GetWindowMinimumSize>(window_id)->take_size();
    }

    void async_get_window_minimum_size(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWindowMinimumSize { window_id });

    }

    IPC::IPCErrorOr<Gfx::IntSize> try_get_window_minimum_size(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWindowMinimumSize>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Gfx::IntRect get_applet_rect_on_screen(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::GetAppletRectOnScreen>(window_id)->take_rect();
    }

    void async_get_applet_rect_on_screen(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetAppletRectOnScreen { window_id });

    }

    IPC::IPCErrorOr<Gfx::IntRect> try_get_applet_rect_on_screen(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetAppletRectOnScreen>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_start_window_resize(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::StartWindowResize { window_id });

    }

    bool is_maximized(
i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::IsMaximized>(window_id)->take_maximized();
    }

    void async_is_maximized(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::IsMaximized { window_id });

    }

    IPC::IPCErrorOr<bool> try_is_maximized(
i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::IsMaximized>(window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_maximized(
i32 window_id, bool maximized) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetMaximized { window_id, maximized });

    }

    void async_invalidate_rect(
i32 window_id, Vector<Gfx::IntRect> rects, bool ignore_occlusion) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::InvalidateRect { window_id, move(rects), ignore_occlusion });

    }

    void async_did_finish_painting(
i32 window_id, Vector<Gfx::IntRect> rects) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::DidFinishPainting { window_id, move(rects) });

    }

    void async_set_global_mouse_tracking(
bool enabled) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetGlobalMouseTracking { enabled });

    }

    void async_set_window_opacity(
i32 window_id, float opacity) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowOpacity { window_id, opacity });

    }

    void async_set_window_alpha_hit_threshold(
i32 window_id, float threshold) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowAlphaHitThreshold { window_id, threshold });

    }

    void set_window_backing_store(
i32 window_id, i32 bpp, i32 pitch, IPC::File anon_file, i32 serial, bool has_alpha_channel, Gfx::IntSize size, bool flush_immediately) {
        (void) m_connection.template send_sync<Messages::WindowServer::SetWindowBackingStore>(window_id, bpp, pitch, move(anon_file), serial, has_alpha_channel, move(size), flush_immediately);
    }

    void async_set_window_backing_store(
i32 window_id, i32 bpp, i32 pitch, IPC::File anon_file, i32 serial, bool has_alpha_channel, Gfx::IntSize size, bool flush_immediately) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowBackingStore { window_id, bpp, pitch, move(anon_file), serial, has_alpha_channel, move(size), flush_immediately });

    }

    IPC::IPCErrorOr<void> try_set_window_backing_store(
i32 window_id, i32 bpp, i32 pitch, IPC::File anon_file, i32 serial, bool has_alpha_channel, Gfx::IntSize size, bool flush_immediately) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SetWindowBackingStore>(window_id, bpp, pitch, move(anon_file), serial, has_alpha_channel, move(size), flush_immediately);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void async_set_window_has_alpha_channel(
i32 window_id, bool has_alpha_channel) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowHasAlphaChannel { window_id, has_alpha_channel });

    }

    void async_move_window_to_front(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::MoveWindowToFront { window_id });

    }

    void async_set_fullscreen(
i32 window_id, bool fullscreen) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetFullscreen { window_id, fullscreen });

    }

    void async_set_frameless(
i32 window_id, bool frameless) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetFrameless { window_id, frameless });

    }

    void async_set_forced_shadow(
i32 window_id, bool shadow) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetForcedShadow { window_id, shadow });

    }

    void async_popup_menu(
i32 menu_id, Gfx::IntPoint screen_position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::PopupMenu { menu_id, move(screen_position) });

    }

    void async_dismiss_menu(
i32 menu_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::DismissMenu { menu_id });

    }

    void async_set_wallpaper(
Gfx::ShareableBitmap wallpaper_bitmap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWallpaper { move(wallpaper_bitmap) });

    }

    void async_set_background_color(
String background_color) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetBackgroundColor { move(background_color) });

    }

    void async_set_wallpaper_mode(
String mode) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWallpaperMode { move(mode) });

    }

    Messages::WindowServer::SetScreenLayoutResponse set_screen_layout(
::WindowServer::ScreenLayout screen_layout, bool save) {
        return move(*m_connection.template send_sync<Messages::WindowServer::SetScreenLayout>(move(screen_layout), save));
    }

    void async_set_screen_layout(
::WindowServer::ScreenLayout screen_layout, bool save) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetScreenLayout { move(screen_layout), save });

    }

    IPC::IPCErrorOr<Messages::WindowServer::SetScreenLayoutResponse> try_set_screen_layout(
::WindowServer::ScreenLayout screen_layout, bool save) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SetScreenLayout>(move(screen_layout), save);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    ::WindowServer::ScreenLayout get_screen_layout(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetScreenLayout>()->take_screen_layout();
    }

    void async_get_screen_layout(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetScreenLayout {  });

    }

    IPC::IPCErrorOr<::WindowServer::ScreenLayout> try_get_screen_layout(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetScreenLayout>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Messages::WindowServer::SaveScreenLayoutResponse save_screen_layout(
) {
        return move(*m_connection.template send_sync<Messages::WindowServer::SaveScreenLayout>());
    }

    void async_save_screen_layout(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SaveScreenLayout {  });

    }

    IPC::IPCErrorOr<Messages::WindowServer::SaveScreenLayoutResponse> try_save_screen_layout(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SaveScreenLayout>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_show_screen_numbers(
bool show) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::ShowScreenNumbers { show });

    }

    bool apply_workspace_settings(
u32 rows, u32 columns, bool save) {
        return m_connection.template send_sync<Messages::WindowServer::ApplyWorkspaceSettings>(rows, columns, save)->take_success();
    }

    void async_apply_workspace_settings(
u32 rows, u32 columns, bool save) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::ApplyWorkspaceSettings { rows, columns, save });

    }

    IPC::IPCErrorOr<bool> try_apply_workspace_settings(
u32 rows, u32 columns, bool save) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::ApplyWorkspaceSettings>(rows, columns, save);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Messages::WindowServer::GetWorkspaceSettingsResponse get_workspace_settings(
) {
        return move(*m_connection.template send_sync<Messages::WindowServer::GetWorkspaceSettings>());
    }

    void async_get_workspace_settings(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWorkspaceSettings {  });

    }

    IPC::IPCErrorOr<Messages::WindowServer::GetWorkspaceSettingsResponse> try_get_workspace_settings(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWorkspaceSettings>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_icon_bitmap(
i32 window_id, Gfx::ShareableBitmap icon) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowIconBitmap { window_id, move(icon) });

    }

    Gfx::ShareableBitmap get_wallpaper(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetWallpaper>()->take_wallpaper_bitmap();
    }

    void async_get_wallpaper(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWallpaper {  });

    }

    IPC::IPCErrorOr<Gfx::ShareableBitmap> try_get_wallpaper(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWallpaper>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_cursor(
i32 window_id, i32 cursor_type) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowCursor { window_id, cursor_type });

    }

    void async_set_window_custom_cursor(
i32 window_id, Gfx::ShareableBitmap cursor) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowCustomCursor { window_id, move(cursor) });

    }

    bool start_drag(
String text, HashMap<String,ByteBuffer> mime_data, Gfx::ShareableBitmap drag_bitmap) {
        return m_connection.template send_sync<Messages::WindowServer::StartDrag>(move(text), move(mime_data), move(drag_bitmap))->take_started();
    }

    void async_start_drag(
String text, HashMap<String,ByteBuffer> mime_data, Gfx::ShareableBitmap drag_bitmap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::StartDrag { move(text), move(mime_data), move(drag_bitmap) });

    }

    IPC::IPCErrorOr<bool> try_start_drag(
String text, HashMap<String,ByteBuffer> mime_data, Gfx::ShareableBitmap drag_bitmap) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::StartDrag>(move(text), move(mime_data), move(drag_bitmap));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool set_system_theme(
String theme_path, String theme_name, bool keep_desktop_background) {
        return m_connection.template send_sync<Messages::WindowServer::SetSystemTheme>(move(theme_path), move(theme_name), keep_desktop_background)->take_success();
    }

    void async_set_system_theme(
String theme_path, String theme_name, bool keep_desktop_background) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetSystemTheme { move(theme_path), move(theme_name), keep_desktop_background });

    }

    IPC::IPCErrorOr<bool> try_set_system_theme(
String theme_path, String theme_name, bool keep_desktop_background) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SetSystemTheme>(move(theme_path), move(theme_name), keep_desktop_background);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    String get_system_theme(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetSystemTheme>()->take_theme_name();
    }

    void async_get_system_theme(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetSystemTheme {  });

    }

    IPC::IPCErrorOr<String> try_get_system_theme(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetSystemTheme>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_refresh_system_theme(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::RefreshSystemTheme {  });

    }

    void async_apply_cursor_theme(
String name) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::ApplyCursorTheme { move(name) });

    }

    String get_cursor_theme(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetCursorTheme>()->take_name();
    }

    void async_get_cursor_theme(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetCursorTheme {  });

    }

    IPC::IPCErrorOr<String> try_get_cursor_theme(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetCursorTheme>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool set_system_fonts(
String default_font_query, String fixed_width_font_query) {
        return m_connection.template send_sync<Messages::WindowServer::SetSystemFonts>(move(default_font_query), move(fixed_width_font_query))->take_success();
    }

    void async_set_system_fonts(
String default_font_query, String fixed_width_font_query) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetSystemFonts { move(default_font_query), move(fixed_width_font_query) });

    }

    IPC::IPCErrorOr<bool> try_set_system_fonts(
String default_font_query, String fixed_width_font_query) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::SetSystemFonts>(move(default_font_query), move(fixed_width_font_query));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_window_base_size_and_size_increment(
i32 window_id, Gfx::IntSize base_size, Gfx::IntSize size_increment) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowBaseSizeAndSizeIncrement { window_id, move(base_size), move(size_increment) });

    }

    void async_set_window_resize_aspect_ratio(
i32 window_id, Optional<Gfx::IntSize> resize_aspect_ratio) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowResizeAspectRatio { window_id, move(resize_aspect_ratio) });

    }

    void async_enable_display_link(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::EnableDisplayLink {  });

    }

    void async_disable_display_link(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::DisableDisplayLink {  });

    }

    void async_set_global_cursor_position(
Gfx::IntPoint position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetGlobalCursorPosition { move(position) });

    }

    Gfx::IntPoint get_global_cursor_position(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetGlobalCursorPosition>()->take_position();
    }

    void async_get_global_cursor_position(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetGlobalCursorPosition {  });

    }

    IPC::IPCErrorOr<Gfx::IntPoint> try_get_global_cursor_position(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetGlobalCursorPosition>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_mouse_acceleration(
float factor) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetMouseAcceleration { factor });

    }

    float get_mouse_acceleration(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetMouseAcceleration>()->take_factor();
    }

    void async_get_mouse_acceleration(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetMouseAcceleration {  });

    }

    IPC::IPCErrorOr<float> try_get_mouse_acceleration(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetMouseAcceleration>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_scroll_step_size(
u32 step_size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetScrollStepSize { step_size });

    }

    u32 get_scroll_step_size(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetScrollStepSize>()->take_step_size();
    }

    void async_get_scroll_step_size(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetScrollStepSize {  });

    }

    IPC::IPCErrorOr<u32> try_get_scroll_step_size(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetScrollStepSize>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Gfx::ShareableBitmap get_screen_bitmap(
Optional<Gfx::IntRect> rect, Optional<u32> screen_index) {
        return m_connection.template send_sync<Messages::WindowServer::GetScreenBitmap>(move(rect), move(screen_index))->take_bitmap();
    }

    void async_get_screen_bitmap(
Optional<Gfx::IntRect> rect, Optional<u32> screen_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetScreenBitmap { move(rect), move(screen_index) });

    }

    IPC::IPCErrorOr<Gfx::ShareableBitmap> try_get_screen_bitmap(
Optional<Gfx::IntRect> rect, Optional<u32> screen_index) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetScreenBitmap>(move(rect), move(screen_index));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Gfx::ShareableBitmap get_screen_bitmap_around_cursor(
Gfx::IntSize size) {
        return m_connection.template send_sync<Messages::WindowServer::GetScreenBitmapAroundCursor>(move(size))->take_bitmap();
    }

    void async_get_screen_bitmap_around_cursor(
Gfx::IntSize size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetScreenBitmapAroundCursor { move(size) });

    }

    IPC::IPCErrorOr<Gfx::ShareableBitmap> try_get_screen_bitmap_around_cursor(
Gfx::IntSize size) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetScreenBitmapAroundCursor>(move(size));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Optional<Gfx::Color> get_color_under_cursor(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetColorUnderCursor>()->take_color();
    }

    void async_get_color_under_cursor(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetColorUnderCursor {  });

    }

    IPC::IPCErrorOr<Optional<Gfx::Color>> try_get_color_under_cursor(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetColorUnderCursor>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_pong(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::Pong {  });

    }

    void async_set_double_click_speed(
int speed) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetDoubleClickSpeed { speed });

    }

    int get_double_click_speed(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetDoubleClickSpeed>()->take_speed();
    }

    void async_get_double_click_speed(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetDoubleClickSpeed {  });

    }

    IPC::IPCErrorOr<int> try_get_double_click_speed(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetDoubleClickSpeed>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_buttons_switched(
bool switched) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetButtonsSwitched { switched });

    }

    bool get_buttons_switched(
) {
        return m_connection.template send_sync<Messages::WindowServer::GetButtonsSwitched>()->take_switched();
    }

    void async_get_buttons_switched(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetButtonsSwitched {  });

    }

    IPC::IPCErrorOr<bool> try_get_buttons_switched(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetButtonsSwitched>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    int get_desktop_display_scale(
u32 screen_index) {
        return m_connection.template send_sync<Messages::WindowServer::GetDesktopDisplayScale>(screen_index)->take_desktop_display_scale();
    }

    void async_get_desktop_display_scale(
u32 screen_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetDesktopDisplayScale { screen_index });

    }

    IPC::IPCErrorOr<int> try_get_desktop_display_scale(
u32 screen_index) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetDesktopDisplayScale>(screen_index);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_flash_flush(
bool enabled) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetFlashFlush { enabled });

    }

    void async_set_window_parent_from_client(
i32 client_id, i32 parent_id, i32 child_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::SetWindowParentFromClient { client_id, parent_id, child_id });

    }

    Gfx::IntRect get_window_rect_from_client(
i32 client_id, i32 window_id) {
        return m_connection.template send_sync<Messages::WindowServer::GetWindowRectFromClient>(client_id, window_id)->take_rect();
    }

    void async_get_window_rect_from_client(
i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::GetWindowRectFromClient { client_id, window_id });

    }

    IPC::IPCErrorOr<Gfx::IntRect> try_get_window_rect_from_client(
i32 client_id, i32 window_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WindowServer::GetWindowRectFromClient>(client_id, window_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_add_window_stealing_for_client(
i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::AddWindowStealingForClient { client_id, window_id });

    }

    void async_remove_window_stealing_for_client(
i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::RemoveWindowStealingForClient { client_id, window_id });

    }

    void async_remove_window_stealing(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowServer::RemoveWindowStealing { window_id });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowServerProxy;
class WindowServerStub;

class WindowServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WindowServerProxy<LocalEndpoint, WindowServerEndpoint>;
    using Stub = WindowServerStub;

    static u32 static_magic() { return 2938215075; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 2938215075) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WindowServer::MessageID::CreateMenu:
            message = Messages::WindowServer::CreateMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DestroyMenu:
            message = Messages::WindowServer::DestroyMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::AddMenu:
            message = Messages::WindowServer::AddMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::AddMenuItem:
            message = Messages::WindowServer::AddMenuItem::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::AddMenuSeparator:
            message = Messages::WindowServer::AddMenuSeparator::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::UpdateMenuItem:
            message = Messages::WindowServer::UpdateMenuItem::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::RemoveMenuItem:
            message = Messages::WindowServer::RemoveMenuItem::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::FlashMenubarMenu:
            message = Messages::WindowServer::FlashMenubarMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::CreateWindow:
            message = Messages::WindowServer::CreateWindow::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DestroyWindow:
            message = Messages::WindowServer::DestroyWindow::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DestroyWindowResponse:
            message = Messages::WindowServer::DestroyWindowResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowTitle:
            message = Messages::WindowServer::SetWindowTitle::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowTitle:
            message = Messages::WindowServer::GetWindowTitle::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowTitleResponse:
            message = Messages::WindowServer::GetWindowTitleResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowProgress:
            message = Messages::WindowServer::SetWindowProgress::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowModified:
            message = Messages::WindowServer::SetWindowModified::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::IsWindowModified:
            message = Messages::WindowServer::IsWindowModified::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::IsWindowModifiedResponse:
            message = Messages::WindowServer::IsWindowModifiedResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowRect:
            message = Messages::WindowServer::SetWindowRect::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowRectResponse:
            message = Messages::WindowServer::SetWindowRectResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowRect:
            message = Messages::WindowServer::GetWindowRect::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowRectResponse:
            message = Messages::WindowServer::GetWindowRectResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowMinimumSize:
            message = Messages::WindowServer::SetWindowMinimumSize::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowMinimumSize:
            message = Messages::WindowServer::GetWindowMinimumSize::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowMinimumSizeResponse:
            message = Messages::WindowServer::GetWindowMinimumSizeResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetAppletRectOnScreen:
            message = Messages::WindowServer::GetAppletRectOnScreen::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetAppletRectOnScreenResponse:
            message = Messages::WindowServer::GetAppletRectOnScreenResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::StartWindowResize:
            message = Messages::WindowServer::StartWindowResize::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::IsMaximized:
            message = Messages::WindowServer::IsMaximized::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::IsMaximizedResponse:
            message = Messages::WindowServer::IsMaximizedResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetMaximized:
            message = Messages::WindowServer::SetMaximized::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::InvalidateRect:
            message = Messages::WindowServer::InvalidateRect::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DidFinishPainting:
            message = Messages::WindowServer::DidFinishPainting::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetGlobalMouseTracking:
            message = Messages::WindowServer::SetGlobalMouseTracking::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowOpacity:
            message = Messages::WindowServer::SetWindowOpacity::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowAlphaHitThreshold:
            message = Messages::WindowServer::SetWindowAlphaHitThreshold::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowBackingStore:
            message = Messages::WindowServer::SetWindowBackingStore::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowBackingStoreResponse:
            message = Messages::WindowServer::SetWindowBackingStoreResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowHasAlphaChannel:
            message = Messages::WindowServer::SetWindowHasAlphaChannel::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::MoveWindowToFront:
            message = Messages::WindowServer::MoveWindowToFront::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetFullscreen:
            message = Messages::WindowServer::SetFullscreen::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetFrameless:
            message = Messages::WindowServer::SetFrameless::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetForcedShadow:
            message = Messages::WindowServer::SetForcedShadow::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::PopupMenu:
            message = Messages::WindowServer::PopupMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DismissMenu:
            message = Messages::WindowServer::DismissMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWallpaper:
            message = Messages::WindowServer::SetWallpaper::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetBackgroundColor:
            message = Messages::WindowServer::SetBackgroundColor::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWallpaperMode:
            message = Messages::WindowServer::SetWallpaperMode::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetScreenLayout:
            message = Messages::WindowServer::SetScreenLayout::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetScreenLayoutResponse:
            message = Messages::WindowServer::SetScreenLayoutResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenLayout:
            message = Messages::WindowServer::GetScreenLayout::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenLayoutResponse:
            message = Messages::WindowServer::GetScreenLayoutResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SaveScreenLayout:
            message = Messages::WindowServer::SaveScreenLayout::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SaveScreenLayoutResponse:
            message = Messages::WindowServer::SaveScreenLayoutResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::ShowScreenNumbers:
            message = Messages::WindowServer::ShowScreenNumbers::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::ApplyWorkspaceSettings:
            message = Messages::WindowServer::ApplyWorkspaceSettings::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::ApplyWorkspaceSettingsResponse:
            message = Messages::WindowServer::ApplyWorkspaceSettingsResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWorkspaceSettings:
            message = Messages::WindowServer::GetWorkspaceSettings::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWorkspaceSettingsResponse:
            message = Messages::WindowServer::GetWorkspaceSettingsResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowIconBitmap:
            message = Messages::WindowServer::SetWindowIconBitmap::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWallpaper:
            message = Messages::WindowServer::GetWallpaper::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWallpaperResponse:
            message = Messages::WindowServer::GetWallpaperResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowCursor:
            message = Messages::WindowServer::SetWindowCursor::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowCustomCursor:
            message = Messages::WindowServer::SetWindowCustomCursor::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::StartDrag:
            message = Messages::WindowServer::StartDrag::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::StartDragResponse:
            message = Messages::WindowServer::StartDragResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetSystemTheme:
            message = Messages::WindowServer::SetSystemTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetSystemThemeResponse:
            message = Messages::WindowServer::SetSystemThemeResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetSystemTheme:
            message = Messages::WindowServer::GetSystemTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetSystemThemeResponse:
            message = Messages::WindowServer::GetSystemThemeResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::RefreshSystemTheme:
            message = Messages::WindowServer::RefreshSystemTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::ApplyCursorTheme:
            message = Messages::WindowServer::ApplyCursorTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetCursorTheme:
            message = Messages::WindowServer::GetCursorTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetCursorThemeResponse:
            message = Messages::WindowServer::GetCursorThemeResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetSystemFonts:
            message = Messages::WindowServer::SetSystemFonts::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetSystemFontsResponse:
            message = Messages::WindowServer::SetSystemFontsResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowBaseSizeAndSizeIncrement:
            message = Messages::WindowServer::SetWindowBaseSizeAndSizeIncrement::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowResizeAspectRatio:
            message = Messages::WindowServer::SetWindowResizeAspectRatio::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::EnableDisplayLink:
            message = Messages::WindowServer::EnableDisplayLink::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::DisableDisplayLink:
            message = Messages::WindowServer::DisableDisplayLink::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetGlobalCursorPosition:
            message = Messages::WindowServer::SetGlobalCursorPosition::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetGlobalCursorPosition:
            message = Messages::WindowServer::GetGlobalCursorPosition::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetGlobalCursorPositionResponse:
            message = Messages::WindowServer::GetGlobalCursorPositionResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetMouseAcceleration:
            message = Messages::WindowServer::SetMouseAcceleration::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetMouseAcceleration:
            message = Messages::WindowServer::GetMouseAcceleration::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetMouseAccelerationResponse:
            message = Messages::WindowServer::GetMouseAccelerationResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetScrollStepSize:
            message = Messages::WindowServer::SetScrollStepSize::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScrollStepSize:
            message = Messages::WindowServer::GetScrollStepSize::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScrollStepSizeResponse:
            message = Messages::WindowServer::GetScrollStepSizeResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenBitmap:
            message = Messages::WindowServer::GetScreenBitmap::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenBitmapResponse:
            message = Messages::WindowServer::GetScreenBitmapResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenBitmapAroundCursor:
            message = Messages::WindowServer::GetScreenBitmapAroundCursor::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetScreenBitmapAroundCursorResponse:
            message = Messages::WindowServer::GetScreenBitmapAroundCursorResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetColorUnderCursor:
            message = Messages::WindowServer::GetColorUnderCursor::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetColorUnderCursorResponse:
            message = Messages::WindowServer::GetColorUnderCursorResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::Pong:
            message = Messages::WindowServer::Pong::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetDoubleClickSpeed:
            message = Messages::WindowServer::SetDoubleClickSpeed::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetDoubleClickSpeed:
            message = Messages::WindowServer::GetDoubleClickSpeed::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetDoubleClickSpeedResponse:
            message = Messages::WindowServer::GetDoubleClickSpeedResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetButtonsSwitched:
            message = Messages::WindowServer::SetButtonsSwitched::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetButtonsSwitched:
            message = Messages::WindowServer::GetButtonsSwitched::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetButtonsSwitchedResponse:
            message = Messages::WindowServer::GetButtonsSwitchedResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetDesktopDisplayScale:
            message = Messages::WindowServer::GetDesktopDisplayScale::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetDesktopDisplayScaleResponse:
            message = Messages::WindowServer::GetDesktopDisplayScaleResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetFlashFlush:
            message = Messages::WindowServer::SetFlashFlush::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::SetWindowParentFromClient:
            message = Messages::WindowServer::SetWindowParentFromClient::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowRectFromClient:
            message = Messages::WindowServer::GetWindowRectFromClient::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::GetWindowRectFromClientResponse:
            message = Messages::WindowServer::GetWindowRectFromClientResponse::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::AddWindowStealingForClient:
            message = Messages::WindowServer::AddWindowStealingForClient::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::RemoveWindowStealingForClient:
            message = Messages::WindowServer::RemoveWindowStealingForClient::decode(stream, socket);
            break;

        case (int)Messages::WindowServer::MessageID::RemoveWindowStealing:
            message = Messages::WindowServer::RemoveWindowStealing::decode(stream, socket);
            break;

        default:

            return {};
        }

        if (stream.handle_any_error()) {

            return {};
        }

        return message;
    }

};

class WindowServerStub : public IPC::Stub {
public:
    WindowServerStub() { }
    virtual ~WindowServerStub() override { }

    virtual u32 magic() const override { return 2938215075; }
    virtual String name() const override { return "WindowServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WindowServer::MessageID::CreateMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::CreateMenu&>(message);
            create_menu(request.menu_id(), request.menu_title());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::DestroyMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::DestroyMenu&>(message);
            destroy_menu(request.menu_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::AddMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::AddMenu&>(message);
            add_menu(request.window_id(), request.menu_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::AddMenuItem: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::AddMenuItem&>(message);
            add_menu_item(request.menu_id(), request.identifier(), request.submenu_id(), request.text(), request.enabled(), request.checkable(), request.checked(), request.is_default(), request.shortcut(), request.icon(), request.exclusive());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::AddMenuSeparator: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::AddMenuSeparator&>(message);
            add_menu_separator(request.menu_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::UpdateMenuItem: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::UpdateMenuItem&>(message);
            update_menu_item(request.menu_id(), request.identifier(), request.submenu_id(), request.text(), request.enabled(), request.checkable(), request.checked(), request.is_default(), request.shortcut());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::RemoveMenuItem: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::RemoveMenuItem&>(message);
            remove_menu_item(request.menu_id(), request.identifier());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::FlashMenubarMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::FlashMenubarMenu&>(message);
            flash_menubar_menu(request.window_id(), request.menu_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::CreateWindow: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::CreateWindow&>(message);
            create_window(request.window_id(), request.rect(), request.auto_position(), request.has_alpha_channel(), request.modal(), request.minimizable(), request.closeable(), request.resizable(), request.fullscreen(), request.frameless(), request.forced_shadow(), request.accessory(), request.opacity(), request.alpha_hit_threshold(), request.base_size(), request.size_increment(), request.minimum_size(), request.resize_aspect_ratio(), request.type(), request.title(), request.parent_window_id(), request.launch_origin_rect());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::DestroyWindow: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::DestroyWindow&>(message);
            auto response = destroy_window(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowTitle: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowTitle&>(message);
            set_window_title(request.window_id(), request.title());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetWindowTitle: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWindowTitle&>(message);
            auto response = get_window_title(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowProgress: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowProgress&>(message);
            set_window_progress(request.window_id(), request.progress());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowModified: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowModified&>(message);
            set_window_modified(request.window_id(), request.modified());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::IsWindowModified: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::IsWindowModified&>(message);
            auto response = is_window_modified(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowRect&>(message);
            auto response = set_window_rect(request.window_id(), request.rect());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetWindowRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWindowRect&>(message);
            auto response = get_window_rect(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowMinimumSize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowMinimumSize&>(message);
            set_window_minimum_size(request.window_id(), request.size());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetWindowMinimumSize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWindowMinimumSize&>(message);
            auto response = get_window_minimum_size(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetAppletRectOnScreen: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetAppletRectOnScreen&>(message);
            auto response = get_applet_rect_on_screen(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::StartWindowResize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::StartWindowResize&>(message);
            start_window_resize(request.window_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::IsMaximized: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::IsMaximized&>(message);
            auto response = is_maximized(request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetMaximized: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetMaximized&>(message);
            set_maximized(request.window_id(), request.maximized());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::InvalidateRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::InvalidateRect&>(message);
            invalidate_rect(request.window_id(), request.rects(), request.ignore_occlusion());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::DidFinishPainting: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::DidFinishPainting&>(message);
            did_finish_painting(request.window_id(), request.rects());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetGlobalMouseTracking: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetGlobalMouseTracking&>(message);
            set_global_mouse_tracking(request.enabled());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowOpacity: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowOpacity&>(message);
            set_window_opacity(request.window_id(), request.opacity());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowAlphaHitThreshold: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowAlphaHitThreshold&>(message);
            set_window_alpha_hit_threshold(request.window_id(), request.threshold());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowBackingStore: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowBackingStore&>(message);
            set_window_backing_store(request.window_id(), request.bpp(), request.pitch(), request.anon_file(), request.serial(), request.has_alpha_channel(), request.size(), request.flush_immediately());
            auto response = Messages::WindowServer::SetWindowBackingStoreResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowHasAlphaChannel: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowHasAlphaChannel&>(message);
            set_window_has_alpha_channel(request.window_id(), request.has_alpha_channel());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::MoveWindowToFront: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::MoveWindowToFront&>(message);
            move_window_to_front(request.window_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetFullscreen: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetFullscreen&>(message);
            set_fullscreen(request.window_id(), request.fullscreen());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetFrameless: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetFrameless&>(message);
            set_frameless(request.window_id(), request.frameless());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetForcedShadow: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetForcedShadow&>(message);
            set_forced_shadow(request.window_id(), request.shadow());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::PopupMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::PopupMenu&>(message);
            popup_menu(request.menu_id(), request.screen_position());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::DismissMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::DismissMenu&>(message);
            dismiss_menu(request.menu_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWallpaper: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWallpaper&>(message);
            set_wallpaper(request.wallpaper_bitmap());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetBackgroundColor: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetBackgroundColor&>(message);
            set_background_color(request.background_color());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWallpaperMode: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWallpaperMode&>(message);
            set_wallpaper_mode(request.mode());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetScreenLayout: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetScreenLayout&>(message);
            auto response = set_screen_layout(request.screen_layout(), request.save());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetScreenLayout: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetScreenLayout&>(message);
            auto response = get_screen_layout();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SaveScreenLayout: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SaveScreenLayout&>(message);
            auto response = save_screen_layout();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::ShowScreenNumbers: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::ShowScreenNumbers&>(message);
            show_screen_numbers(request.show());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::ApplyWorkspaceSettings: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::ApplyWorkspaceSettings&>(message);
            auto response = apply_workspace_settings(request.rows(), request.columns(), request.save());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetWorkspaceSettings: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWorkspaceSettings&>(message);
            auto response = get_workspace_settings();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowIconBitmap: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowIconBitmap&>(message);
            set_window_icon_bitmap(request.window_id(), request.icon());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetWallpaper: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWallpaper&>(message);
            auto response = get_wallpaper();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowCursor: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowCursor&>(message);
            set_window_cursor(request.window_id(), request.cursor_type());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowCustomCursor: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowCustomCursor&>(message);
            set_window_custom_cursor(request.window_id(), request.cursor());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::StartDrag: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::StartDrag&>(message);
            auto response = start_drag(request.text(), request.mime_data(), request.drag_bitmap());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetSystemTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetSystemTheme&>(message);
            auto response = set_system_theme(request.theme_path(), request.theme_name(), request.keep_desktop_background());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetSystemTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetSystemTheme&>(message);
            auto response = get_system_theme();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::RefreshSystemTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::RefreshSystemTheme&>(message);
            refresh_system_theme();
            return {};

        }

        case (int)Messages::WindowServer::MessageID::ApplyCursorTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::ApplyCursorTheme&>(message);
            apply_cursor_theme(request.name());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetCursorTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetCursorTheme&>(message);
            auto response = get_cursor_theme();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetSystemFonts: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetSystemFonts&>(message);
            auto response = set_system_fonts(request.default_font_query(), request.fixed_width_font_query());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetWindowBaseSizeAndSizeIncrement: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowBaseSizeAndSizeIncrement&>(message);
            set_window_base_size_and_size_increment(request.window_id(), request.base_size(), request.size_increment());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowResizeAspectRatio: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowResizeAspectRatio&>(message);
            set_window_resize_aspect_ratio(request.window_id(), request.resize_aspect_ratio());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::EnableDisplayLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::EnableDisplayLink&>(message);
            enable_display_link();
            return {};

        }

        case (int)Messages::WindowServer::MessageID::DisableDisplayLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::DisableDisplayLink&>(message);
            disable_display_link();
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetGlobalCursorPosition: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetGlobalCursorPosition&>(message);
            set_global_cursor_position(request.position());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetGlobalCursorPosition: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetGlobalCursorPosition&>(message);
            auto response = get_global_cursor_position();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetMouseAcceleration: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetMouseAcceleration&>(message);
            set_mouse_acceleration(request.factor());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetMouseAcceleration: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetMouseAcceleration&>(message);
            auto response = get_mouse_acceleration();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetScrollStepSize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetScrollStepSize&>(message);
            set_scroll_step_size(request.step_size());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetScrollStepSize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetScrollStepSize&>(message);
            auto response = get_scroll_step_size();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetScreenBitmap: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetScreenBitmap&>(message);
            auto response = get_screen_bitmap(request.rect(), request.screen_index());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetScreenBitmapAroundCursor: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetScreenBitmapAroundCursor&>(message);
            auto response = get_screen_bitmap_around_cursor(request.size());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetColorUnderCursor: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetColorUnderCursor&>(message);
            auto response = get_color_under_cursor();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::Pong: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::Pong&>(message);
            pong();
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetDoubleClickSpeed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetDoubleClickSpeed&>(message);
            set_double_click_speed(request.speed());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetDoubleClickSpeed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetDoubleClickSpeed&>(message);
            auto response = get_double_click_speed();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetButtonsSwitched: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetButtonsSwitched&>(message);
            set_buttons_switched(request.switched());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetButtonsSwitched: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetButtonsSwitched&>(message);
            auto response = get_buttons_switched();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::GetDesktopDisplayScale: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetDesktopDisplayScale&>(message);
            auto response = get_desktop_display_scale(request.screen_index());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::SetFlashFlush: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetFlashFlush&>(message);
            set_flash_flush(request.enabled());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::SetWindowParentFromClient: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::SetWindowParentFromClient&>(message);
            set_window_parent_from_client(request.client_id(), request.parent_id(), request.child_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::GetWindowRectFromClient: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::GetWindowRectFromClient&>(message);
            auto response = get_window_rect_from_client(request.client_id(), request.window_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WindowServer::MessageID::AddWindowStealingForClient: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::AddWindowStealingForClient&>(message);
            add_window_stealing_for_client(request.client_id(), request.window_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::RemoveWindowStealingForClient: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::RemoveWindowStealingForClient&>(message);
            remove_window_stealing_for_client(request.client_id(), request.window_id());
            return {};

        }

        case (int)Messages::WindowServer::MessageID::RemoveWindowStealing: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowServer::RemoveWindowStealing&>(message);
            remove_window_stealing(request.window_id());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void create_menu(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] String const& menu_title) = 0;

    virtual void destroy_menu(
[[maybe_unused]] i32 menu_id) = 0;

    virtual void add_menu(
[[maybe_unused]] i32 window_id, [[maybe_unused]] i32 menu_id) = 0;

    virtual void add_menu_item(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] i32 identifier, [[maybe_unused]] i32 submenu_id, [[maybe_unused]] String const& text, [[maybe_unused]] bool enabled, [[maybe_unused]] bool checkable, [[maybe_unused]] bool checked, [[maybe_unused]] bool is_default, [[maybe_unused]] String const& shortcut, [[maybe_unused]] Gfx::ShareableBitmap const& icon, [[maybe_unused]] bool exclusive) = 0;

    virtual void add_menu_separator(
[[maybe_unused]] i32 menu_id) = 0;

    virtual void update_menu_item(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] i32 identifier, [[maybe_unused]] i32 submenu_id, [[maybe_unused]] String const& text, [[maybe_unused]] bool enabled, [[maybe_unused]] bool checkable, [[maybe_unused]] bool checked, [[maybe_unused]] bool is_default, [[maybe_unused]] String const& shortcut) = 0;

    virtual void remove_menu_item(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] i32 identifier) = 0;

    virtual void flash_menubar_menu(
[[maybe_unused]] i32 window_id, [[maybe_unused]] i32 menu_id) = 0;

    virtual void create_window(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntRect const& rect, [[maybe_unused]] bool auto_position, [[maybe_unused]] bool has_alpha_channel, [[maybe_unused]] bool modal, [[maybe_unused]] bool minimizable, [[maybe_unused]] bool closeable, [[maybe_unused]] bool resizable, [[maybe_unused]] bool fullscreen, [[maybe_unused]] bool frameless, [[maybe_unused]] bool forced_shadow, [[maybe_unused]] bool accessory, [[maybe_unused]] float opacity, [[maybe_unused]] float alpha_hit_threshold, [[maybe_unused]] Gfx::IntSize const& base_size, [[maybe_unused]] Gfx::IntSize const& size_increment, [[maybe_unused]] Gfx::IntSize const& minimum_size, [[maybe_unused]] Optional<Gfx::IntSize> const& resize_aspect_ratio, [[maybe_unused]] i32 type, [[maybe_unused]] String const& title, [[maybe_unused]] i32 parent_window_id, [[maybe_unused]] Gfx::IntRect const& launch_origin_rect) = 0;

    virtual Messages::WindowServer::DestroyWindowResponse destroy_window(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_window_title(
[[maybe_unused]] i32 window_id, [[maybe_unused]] String const& title) = 0;

    virtual Messages::WindowServer::GetWindowTitleResponse get_window_title(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_window_progress(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Optional<i32> const& progress) = 0;

    virtual void set_window_modified(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool modified) = 0;

    virtual Messages::WindowServer::IsWindowModifiedResponse is_window_modified(
[[maybe_unused]] i32 window_id) = 0;

    virtual Messages::WindowServer::SetWindowRectResponse set_window_rect(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual Messages::WindowServer::GetWindowRectResponse get_window_rect(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_window_minimum_size(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntSize const& size) = 0;

    virtual Messages::WindowServer::GetWindowMinimumSizeResponse get_window_minimum_size(
[[maybe_unused]] i32 window_id) = 0;

    virtual Messages::WindowServer::GetAppletRectOnScreenResponse get_applet_rect_on_screen(
[[maybe_unused]] i32 window_id) = 0;

    virtual void start_window_resize(
[[maybe_unused]] i32 window_id) = 0;

    virtual Messages::WindowServer::IsMaximizedResponse is_maximized(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_maximized(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool maximized) = 0;

    virtual void invalidate_rect(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Vector<Gfx::IntRect> const& rects, [[maybe_unused]] bool ignore_occlusion) = 0;

    virtual void did_finish_painting(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Vector<Gfx::IntRect> const& rects) = 0;

    virtual void set_global_mouse_tracking(
[[maybe_unused]] bool enabled) = 0;

    virtual void set_window_opacity(
[[maybe_unused]] i32 window_id, [[maybe_unused]] float opacity) = 0;

    virtual void set_window_alpha_hit_threshold(
[[maybe_unused]] i32 window_id, [[maybe_unused]] float threshold) = 0;

    virtual void set_window_backing_store(
[[maybe_unused]] i32 window_id, [[maybe_unused]] i32 bpp, [[maybe_unused]] i32 pitch, [[maybe_unused]] IPC::File const& anon_file, [[maybe_unused]] i32 serial, [[maybe_unused]] bool has_alpha_channel, [[maybe_unused]] Gfx::IntSize const& size, [[maybe_unused]] bool flush_immediately) = 0;

    virtual void set_window_has_alpha_channel(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool has_alpha_channel) = 0;

    virtual void move_window_to_front(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_fullscreen(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool fullscreen) = 0;

    virtual void set_frameless(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool frameless) = 0;

    virtual void set_forced_shadow(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool shadow) = 0;

    virtual void popup_menu(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] Gfx::IntPoint const& screen_position) = 0;

    virtual void dismiss_menu(
[[maybe_unused]] i32 menu_id) = 0;

    virtual void set_wallpaper(
[[maybe_unused]] Gfx::ShareableBitmap const& wallpaper_bitmap) = 0;

    virtual void set_background_color(
[[maybe_unused]] String const& background_color) = 0;

    virtual void set_wallpaper_mode(
[[maybe_unused]] String const& mode) = 0;

    virtual Messages::WindowServer::SetScreenLayoutResponse set_screen_layout(
[[maybe_unused]] ::WindowServer::ScreenLayout const& screen_layout, [[maybe_unused]] bool save) = 0;

    virtual Messages::WindowServer::GetScreenLayoutResponse get_screen_layout(
) = 0;

    virtual Messages::WindowServer::SaveScreenLayoutResponse save_screen_layout(
) = 0;

    virtual void show_screen_numbers(
[[maybe_unused]] bool show) = 0;

    virtual Messages::WindowServer::ApplyWorkspaceSettingsResponse apply_workspace_settings(
[[maybe_unused]] u32 rows, [[maybe_unused]] u32 columns, [[maybe_unused]] bool save) = 0;

    virtual Messages::WindowServer::GetWorkspaceSettingsResponse get_workspace_settings(
) = 0;

    virtual void set_window_icon_bitmap(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::ShareableBitmap const& icon) = 0;

    virtual Messages::WindowServer::GetWallpaperResponse get_wallpaper(
) = 0;

    virtual void set_window_cursor(
[[maybe_unused]] i32 window_id, [[maybe_unused]] i32 cursor_type) = 0;

    virtual void set_window_custom_cursor(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::ShareableBitmap const& cursor) = 0;

    virtual Messages::WindowServer::StartDragResponse start_drag(
[[maybe_unused]] String const& text, [[maybe_unused]] HashMap<String,ByteBuffer> const& mime_data, [[maybe_unused]] Gfx::ShareableBitmap const& drag_bitmap) = 0;

    virtual Messages::WindowServer::SetSystemThemeResponse set_system_theme(
[[maybe_unused]] String const& theme_path, [[maybe_unused]] String const& theme_name, [[maybe_unused]] bool keep_desktop_background) = 0;

    virtual Messages::WindowServer::GetSystemThemeResponse get_system_theme(
) = 0;

    virtual void refresh_system_theme(
) = 0;

    virtual void apply_cursor_theme(
[[maybe_unused]] String const& name) = 0;

    virtual Messages::WindowServer::GetCursorThemeResponse get_cursor_theme(
) = 0;

    virtual Messages::WindowServer::SetSystemFontsResponse set_system_fonts(
[[maybe_unused]] String const& default_font_query, [[maybe_unused]] String const& fixed_width_font_query) = 0;

    virtual void set_window_base_size_and_size_increment(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntSize const& base_size, [[maybe_unused]] Gfx::IntSize const& size_increment) = 0;

    virtual void set_window_resize_aspect_ratio(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Optional<Gfx::IntSize> const& resize_aspect_ratio) = 0;

    virtual void enable_display_link(
) = 0;

    virtual void disable_display_link(
) = 0;

    virtual void set_global_cursor_position(
[[maybe_unused]] Gfx::IntPoint const& position) = 0;

    virtual Messages::WindowServer::GetGlobalCursorPositionResponse get_global_cursor_position(
) = 0;

    virtual void set_mouse_acceleration(
[[maybe_unused]] float factor) = 0;

    virtual Messages::WindowServer::GetMouseAccelerationResponse get_mouse_acceleration(
) = 0;

    virtual void set_scroll_step_size(
[[maybe_unused]] u32 step_size) = 0;

    virtual Messages::WindowServer::GetScrollStepSizeResponse get_scroll_step_size(
) = 0;

    virtual Messages::WindowServer::GetScreenBitmapResponse get_screen_bitmap(
[[maybe_unused]] Optional<Gfx::IntRect> const& rect, [[maybe_unused]] Optional<u32> const& screen_index) = 0;

    virtual Messages::WindowServer::GetScreenBitmapAroundCursorResponse get_screen_bitmap_around_cursor(
[[maybe_unused]] Gfx::IntSize const& size) = 0;

    virtual Messages::WindowServer::GetColorUnderCursorResponse get_color_under_cursor(
) = 0;

    virtual void pong(
) = 0;

    virtual void set_double_click_speed(
[[maybe_unused]] int speed) = 0;

    virtual Messages::WindowServer::GetDoubleClickSpeedResponse get_double_click_speed(
) = 0;

    virtual void set_buttons_switched(
[[maybe_unused]] bool switched) = 0;

    virtual Messages::WindowServer::GetButtonsSwitchedResponse get_buttons_switched(
) = 0;

    virtual Messages::WindowServer::GetDesktopDisplayScaleResponse get_desktop_display_scale(
[[maybe_unused]] u32 screen_index) = 0;

    virtual void set_flash_flush(
[[maybe_unused]] bool enabled) = 0;

    virtual void set_window_parent_from_client(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 parent_id, [[maybe_unused]] i32 child_id) = 0;

    virtual Messages::WindowServer::GetWindowRectFromClientResponse get_window_rect_from_client(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void add_window_stealing_for_client(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void remove_window_stealing_for_client(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void remove_window_stealing(
[[maybe_unused]] i32 window_id) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

