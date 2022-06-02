#pragma once
#include <AK/URL.h>
#include <LibCore/AnonymousBuffer.h>
#include <LibGfx/ShareableBitmap.h>
#include <LibWeb/CSS/PreferredColorScheme.h>
#include <LibWeb/CSS/Selector.h>
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

namespace Messages::WebContentServer {

enum class MessageID : i32 {
    UpdateSystemTheme = 1,
    UpdateSystemFonts = 2,
    UpdateScreenRects = 3,
    LoadUrl = 4,
    LoadHtml = 5,
    AddBackingStore = 6,
    RemoveBackingStore = 7,
    Paint = 8,
    SetViewportRect = 9,
    MouseDown = 10,
    MouseMove = 11,
    MouseUp = 12,
    MouseWheel = 13,
    KeyDown = 14,
    KeyUp = 15,
    DebugRequest = 16,
    GetSource = 17,
    InspectDomTree = 18,
    InspectDomNode = 19,
    InspectDomNodeResponse = 20,
    GetHoveredNodeId = 21,
    GetHoveredNodeIdResponse = 22,
    JsConsoleInput = 23,
    JsConsoleRequestMessages = 24,
    RunJavascript = 25,
    DumpLayoutTree = 26,
    DumpLayoutTreeResponse = 27,
    GetSelectedText = 28,
    GetSelectedTextResponse = 29,
    SelectAll = 30,
    SetContentFilters = 31,
    SetProxyMappings = 32,
    SetPreferredColorScheme = 33,
    SetHasFocus = 34,
    SetIsScriptingEnabled = 35,
    GetLocalStorageEntries = 36,
    GetLocalStorageEntriesResponse = 37,
};

class UpdateSystemTheme final : public IPC::Message {
public:

    UpdateSystemTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateSystemTheme(UpdateSystemTheme const&) = default;
    UpdateSystemTheme(UpdateSystemTheme&&) = default;
    UpdateSystemTheme& operator=(UpdateSystemTheme const&) = default;
    UpdateSystemTheme(Core::AnonymousBuffer theme_buffer) : m_theme_buffer(move(theme_buffer)) {}
    virtual ~UpdateSystemTheme() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateSystemTheme; }
    static i32 static_message_id() { return (int)MessageID::UpdateSystemTheme; }
    virtual const char* message_name() const override { return "WebContentServer::UpdateSystemTheme"; }

    static OwnPtr<UpdateSystemTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Core::AnonymousBuffer theme_buffer = {};
        if (decoder.decode(theme_buffer).is_error())
            return {};

        return make<UpdateSystemTheme>(move(theme_buffer));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateSystemTheme;

        stream << m_theme_buffer;

        return buffer;
    }

    const Core::AnonymousBuffer& theme_buffer() const { return m_theme_buffer; }
    Core::AnonymousBuffer take_theme_buffer() { return move(m_theme_buffer); }

private:
    bool m_ipc_message_valid { true };

    Core::AnonymousBuffer m_theme_buffer {};

};

class UpdateSystemFonts final : public IPC::Message {
public:

    UpdateSystemFonts(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateSystemFonts(UpdateSystemFonts const&) = default;
    UpdateSystemFonts(UpdateSystemFonts&&) = default;
    UpdateSystemFonts& operator=(UpdateSystemFonts const&) = default;
    UpdateSystemFonts(String default_font_query, String fixed_width_font_query) : m_default_font_query(move(default_font_query)), m_fixed_width_font_query(move(fixed_width_font_query)) {}
    virtual ~UpdateSystemFonts() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateSystemFonts; }
    static i32 static_message_id() { return (int)MessageID::UpdateSystemFonts; }
    virtual const char* message_name() const override { return "WebContentServer::UpdateSystemFonts"; }

    static OwnPtr<UpdateSystemFonts> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String default_font_query = {};
        if (decoder.decode(default_font_query).is_error())
            return {};

        String fixed_width_font_query = {};
        if (decoder.decode(fixed_width_font_query).is_error())
            return {};

        return make<UpdateSystemFonts>(move(default_font_query), move(fixed_width_font_query));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateSystemFonts;

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

class UpdateScreenRects final : public IPC::Message {
public:

    UpdateScreenRects(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateScreenRects(UpdateScreenRects const&) = default;
    UpdateScreenRects(UpdateScreenRects&&) = default;
    UpdateScreenRects& operator=(UpdateScreenRects const&) = default;
    UpdateScreenRects(Vector<Gfx::IntRect> rects, u32 main_screen_index) : m_rects(move(rects)), m_main_screen_index(move(main_screen_index)) {}
    virtual ~UpdateScreenRects() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateScreenRects; }
    static i32 static_message_id() { return (int)MessageID::UpdateScreenRects; }
    virtual const char* message_name() const override { return "WebContentServer::UpdateScreenRects"; }

    static OwnPtr<UpdateScreenRects> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<Gfx::IntRect> rects = {};
        if (decoder.decode(rects).is_error())
            return {};

        u32 main_screen_index = {};
        if (decoder.decode(main_screen_index).is_error())
            return {};

        return make<UpdateScreenRects>(move(rects), move(main_screen_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateScreenRects;

        stream << m_rects;

        stream << m_main_screen_index;

        return buffer;
    }

    const Vector<Gfx::IntRect>& rects() const { return m_rects; }
    Vector<Gfx::IntRect> take_rects() { return move(m_rects); }

    const u32& main_screen_index() const { return m_main_screen_index; }
    u32 take_main_screen_index() { return move(m_main_screen_index); }

private:
    bool m_ipc_message_valid { true };

    Vector<Gfx::IntRect> m_rects {};

    u32 m_main_screen_index {};

};

class LoadUrl final : public IPC::Message {
public:

    LoadUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LoadUrl(LoadUrl const&) = default;
    LoadUrl(LoadUrl&&) = default;
    LoadUrl& operator=(LoadUrl const&) = default;
    LoadUrl(URL url) : m_url(move(url)) {}
    virtual ~LoadUrl() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::LoadUrl; }
    static i32 static_message_id() { return (int)MessageID::LoadUrl; }
    virtual const char* message_name() const override { return "WebContentServer::LoadUrl"; }

    static OwnPtr<LoadUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<LoadUrl>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LoadUrl;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class LoadHtml final : public IPC::Message {
public:

    LoadHtml(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LoadHtml(LoadHtml const&) = default;
    LoadHtml(LoadHtml&&) = default;
    LoadHtml& operator=(LoadHtml const&) = default;
    LoadHtml(String html, URL url) : m_html(move(html)), m_url(move(url)) {}
    virtual ~LoadHtml() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::LoadHtml; }
    static i32 static_message_id() { return (int)MessageID::LoadHtml; }
    virtual const char* message_name() const override { return "WebContentServer::LoadHtml"; }

    static OwnPtr<LoadHtml> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String html = {};
        if (decoder.decode(html).is_error())
            return {};

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<LoadHtml>(move(html), move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LoadHtml;

        stream << m_html;

        stream << m_url;

        return buffer;
    }

    const String& html() const { return m_html; }
    String take_html() { return move(m_html); }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    String m_html {};

    URL m_url {};

};

class AddBackingStore final : public IPC::Message {
public:

    AddBackingStore(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddBackingStore(AddBackingStore const&) = default;
    AddBackingStore(AddBackingStore&&) = default;
    AddBackingStore& operator=(AddBackingStore const&) = default;
    AddBackingStore(i32 backing_store_id, Gfx::ShareableBitmap bitmap) : m_backing_store_id(move(backing_store_id)), m_bitmap(move(bitmap)) {}
    virtual ~AddBackingStore() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::AddBackingStore; }
    static i32 static_message_id() { return (int)MessageID::AddBackingStore; }
    virtual const char* message_name() const override { return "WebContentServer::AddBackingStore"; }

    static OwnPtr<AddBackingStore> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 backing_store_id = {};
        if (decoder.decode(backing_store_id).is_error())
            return {};

        Gfx::ShareableBitmap bitmap = {};
        if (decoder.decode(bitmap).is_error())
            return {};

        return make<AddBackingStore>(move(backing_store_id), move(bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddBackingStore;

        stream << m_backing_store_id;

        stream << m_bitmap;

        return buffer;
    }

    const i32& backing_store_id() const { return m_backing_store_id; }
    i32 take_backing_store_id() { return move(m_backing_store_id); }

    const Gfx::ShareableBitmap& bitmap() const { return m_bitmap; }
    Gfx::ShareableBitmap take_bitmap() { return move(m_bitmap); }

private:
    bool m_ipc_message_valid { true };

    i32 m_backing_store_id {};

    Gfx::ShareableBitmap m_bitmap {};

};

class RemoveBackingStore final : public IPC::Message {
public:

    RemoveBackingStore(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RemoveBackingStore(RemoveBackingStore const&) = default;
    RemoveBackingStore(RemoveBackingStore&&) = default;
    RemoveBackingStore& operator=(RemoveBackingStore const&) = default;
    RemoveBackingStore(i32 backing_store_id) : m_backing_store_id(move(backing_store_id)) {}
    virtual ~RemoveBackingStore() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::RemoveBackingStore; }
    static i32 static_message_id() { return (int)MessageID::RemoveBackingStore; }
    virtual const char* message_name() const override { return "WebContentServer::RemoveBackingStore"; }

    static OwnPtr<RemoveBackingStore> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 backing_store_id = {};
        if (decoder.decode(backing_store_id).is_error())
            return {};

        return make<RemoveBackingStore>(move(backing_store_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RemoveBackingStore;

        stream << m_backing_store_id;

        return buffer;
    }

    const i32& backing_store_id() const { return m_backing_store_id; }
    i32 take_backing_store_id() { return move(m_backing_store_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_backing_store_id {};

};

class Paint final : public IPC::Message {
public:

    Paint(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Paint(Paint const&) = default;
    Paint(Paint&&) = default;
    Paint& operator=(Paint const&) = default;
    Paint(Gfx::IntRect content_rect, i32 backing_store_id) : m_content_rect(move(content_rect)), m_backing_store_id(move(backing_store_id)) {}
    virtual ~Paint() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::Paint; }
    static i32 static_message_id() { return (int)MessageID::Paint; }
    virtual const char* message_name() const override { return "WebContentServer::Paint"; }

    static OwnPtr<Paint> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect content_rect = {};
        if (decoder.decode(content_rect).is_error())
            return {};

        i32 backing_store_id = {};
        if (decoder.decode(backing_store_id).is_error())
            return {};

        return make<Paint>(move(content_rect), move(backing_store_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Paint;

        stream << m_content_rect;

        stream << m_backing_store_id;

        return buffer;
    }

    const Gfx::IntRect& content_rect() const { return m_content_rect; }
    Gfx::IntRect take_content_rect() { return move(m_content_rect); }

    const i32& backing_store_id() const { return m_backing_store_id; }
    i32 take_backing_store_id() { return move(m_backing_store_id); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_content_rect {};

    i32 m_backing_store_id {};

};

class SetViewportRect final : public IPC::Message {
public:

    SetViewportRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetViewportRect(SetViewportRect const&) = default;
    SetViewportRect(SetViewportRect&&) = default;
    SetViewportRect& operator=(SetViewportRect const&) = default;
    SetViewportRect(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~SetViewportRect() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetViewportRect; }
    static i32 static_message_id() { return (int)MessageID::SetViewportRect; }
    virtual const char* message_name() const override { return "WebContentServer::SetViewportRect"; }

    static OwnPtr<SetViewportRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<SetViewportRect>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetViewportRect;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class MouseDown final : public IPC::Message {
public:

    MouseDown(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseDown(MouseDown const&) = default;
    MouseDown(MouseDown&&) = default;
    MouseDown& operator=(MouseDown const&) = default;
    MouseDown(Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) : m_position(move(position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)) {}
    virtual ~MouseDown() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::MouseDown; }
    static i32 static_message_id() { return (int)MessageID::MouseDown; }
    virtual const char* message_name() const override { return "WebContentServer::MouseDown"; }

    static OwnPtr<MouseDown> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        unsigned button = {};
        if (decoder.decode(button).is_error())
            return {};

        unsigned buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<MouseDown>(move(position), move(button), move(buttons), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseDown;

        stream << m_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

    const unsigned& button() const { return m_button; }
    unsigned take_button() { return move(m_button); }

    const unsigned& buttons() const { return m_buttons; }
    unsigned take_buttons() { return move(m_buttons); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

    unsigned m_button {};

    unsigned m_buttons {};

    unsigned m_modifiers {};

};

class MouseMove final : public IPC::Message {
public:

    MouseMove(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseMove(MouseMove const&) = default;
    MouseMove(MouseMove&&) = default;
    MouseMove& operator=(MouseMove const&) = default;
    MouseMove(Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) : m_position(move(position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)) {}
    virtual ~MouseMove() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::MouseMove; }
    static i32 static_message_id() { return (int)MessageID::MouseMove; }
    virtual const char* message_name() const override { return "WebContentServer::MouseMove"; }

    static OwnPtr<MouseMove> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        unsigned button = {};
        if (decoder.decode(button).is_error())
            return {};

        unsigned buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<MouseMove>(move(position), move(button), move(buttons), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseMove;

        stream << m_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

    const unsigned& button() const { return m_button; }
    unsigned take_button() { return move(m_button); }

    const unsigned& buttons() const { return m_buttons; }
    unsigned take_buttons() { return move(m_buttons); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

    unsigned m_button {};

    unsigned m_buttons {};

    unsigned m_modifiers {};

};

class MouseUp final : public IPC::Message {
public:

    MouseUp(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseUp(MouseUp const&) = default;
    MouseUp(MouseUp&&) = default;
    MouseUp& operator=(MouseUp const&) = default;
    MouseUp(Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) : m_position(move(position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)) {}
    virtual ~MouseUp() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::MouseUp; }
    static i32 static_message_id() { return (int)MessageID::MouseUp; }
    virtual const char* message_name() const override { return "WebContentServer::MouseUp"; }

    static OwnPtr<MouseUp> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        unsigned button = {};
        if (decoder.decode(button).is_error())
            return {};

        unsigned buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<MouseUp>(move(position), move(button), move(buttons), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseUp;

        stream << m_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

    const unsigned& button() const { return m_button; }
    unsigned take_button() { return move(m_button); }

    const unsigned& buttons() const { return m_buttons; }
    unsigned take_buttons() { return move(m_buttons); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

    unsigned m_button {};

    unsigned m_buttons {};

    unsigned m_modifiers {};

};

class MouseWheel final : public IPC::Message {
public:

    MouseWheel(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseWheel(MouseWheel const&) = default;
    MouseWheel(MouseWheel&&) = default;
    MouseWheel& operator=(MouseWheel const&) = default;
    MouseWheel(Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers, i32 wheel_delta_x, i32 wheel_delta_y) : m_position(move(position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)) {}
    virtual ~MouseWheel() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::MouseWheel; }
    static i32 static_message_id() { return (int)MessageID::MouseWheel; }
    virtual const char* message_name() const override { return "WebContentServer::MouseWheel"; }

    static OwnPtr<MouseWheel> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        unsigned button = {};
        if (decoder.decode(button).is_error())
            return {};

        unsigned buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        return make<MouseWheel>(move(position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseWheel;

        stream << m_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

    const unsigned& button() const { return m_button; }
    unsigned take_button() { return move(m_button); }

    const unsigned& buttons() const { return m_buttons; }
    unsigned take_buttons() { return move(m_buttons); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

    unsigned m_button {};

    unsigned m_buttons {};

    unsigned m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

};

class KeyDown final : public IPC::Message {
public:

    KeyDown(decltype(nullptr)) : m_ipc_message_valid(false) { }
    KeyDown(KeyDown const&) = default;
    KeyDown(KeyDown&&) = default;
    KeyDown& operator=(KeyDown const&) = default;
    KeyDown(i32 key, unsigned modifiers, u32 code_point) : m_key(move(key)), m_modifiers(move(modifiers)), m_code_point(move(code_point)) {}
    virtual ~KeyDown() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::KeyDown; }
    static i32 static_message_id() { return (int)MessageID::KeyDown; }
    virtual const char* message_name() const override { return "WebContentServer::KeyDown"; }

    static OwnPtr<KeyDown> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 key = {};
        if (decoder.decode(key).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        u32 code_point = {};
        if (decoder.decode(code_point).is_error())
            return {};

        return make<KeyDown>(move(key), move(modifiers), move(code_point));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::KeyDown;

        stream << m_key;

        stream << m_modifiers;

        stream << m_code_point;

        return buffer;
    }

    const i32& key() const { return m_key; }
    i32 take_key() { return move(m_key); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

    const u32& code_point() const { return m_code_point; }
    u32 take_code_point() { return move(m_code_point); }

private:
    bool m_ipc_message_valid { true };

    i32 m_key {};

    unsigned m_modifiers {};

    u32 m_code_point {};

};

class KeyUp final : public IPC::Message {
public:

    KeyUp(decltype(nullptr)) : m_ipc_message_valid(false) { }
    KeyUp(KeyUp const&) = default;
    KeyUp(KeyUp&&) = default;
    KeyUp& operator=(KeyUp const&) = default;
    KeyUp(i32 key, unsigned modifiers, u32 code_point) : m_key(move(key)), m_modifiers(move(modifiers)), m_code_point(move(code_point)) {}
    virtual ~KeyUp() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::KeyUp; }
    static i32 static_message_id() { return (int)MessageID::KeyUp; }
    virtual const char* message_name() const override { return "WebContentServer::KeyUp"; }

    static OwnPtr<KeyUp> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 key = {};
        if (decoder.decode(key).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        u32 code_point = {};
        if (decoder.decode(code_point).is_error())
            return {};

        return make<KeyUp>(move(key), move(modifiers), move(code_point));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::KeyUp;

        stream << m_key;

        stream << m_modifiers;

        stream << m_code_point;

        return buffer;
    }

    const i32& key() const { return m_key; }
    i32 take_key() { return move(m_key); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

    const u32& code_point() const { return m_code_point; }
    u32 take_code_point() { return move(m_code_point); }

private:
    bool m_ipc_message_valid { true };

    i32 m_key {};

    unsigned m_modifiers {};

    u32 m_code_point {};

};

class DebugRequest final : public IPC::Message {
public:

    DebugRequest(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DebugRequest(DebugRequest const&) = default;
    DebugRequest(DebugRequest&&) = default;
    DebugRequest& operator=(DebugRequest const&) = default;
    DebugRequest(String request, String argument) : m_request(move(request)), m_argument(move(argument)) {}
    virtual ~DebugRequest() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::DebugRequest; }
    static i32 static_message_id() { return (int)MessageID::DebugRequest; }
    virtual const char* message_name() const override { return "WebContentServer::DebugRequest"; }

    static OwnPtr<DebugRequest> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String request = {};
        if (decoder.decode(request).is_error())
            return {};

        String argument = {};
        if (decoder.decode(argument).is_error())
            return {};

        return make<DebugRequest>(move(request), move(argument));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DebugRequest;

        stream << m_request;

        stream << m_argument;

        return buffer;
    }

    const String& request() const { return m_request; }
    String take_request() { return move(m_request); }

    const String& argument() const { return m_argument; }
    String take_argument() { return move(m_argument); }

private:
    bool m_ipc_message_valid { true };

    String m_request {};

    String m_argument {};

};

class GetSource final : public IPC::Message {
public:

    GetSource(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSource(GetSource const&) = default;
    GetSource(GetSource&&) = default;
    GetSource& operator=(GetSource const&) = default;
    GetSource() {}
    virtual ~GetSource() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetSource; }
    static i32 static_message_id() { return (int)MessageID::GetSource; }
    virtual const char* message_name() const override { return "WebContentServer::GetSource"; }

    static OwnPtr<GetSource> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetSource>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSource;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class InspectDomTree final : public IPC::Message {
public:

    InspectDomTree(decltype(nullptr)) : m_ipc_message_valid(false) { }
    InspectDomTree(InspectDomTree const&) = default;
    InspectDomTree(InspectDomTree&&) = default;
    InspectDomTree& operator=(InspectDomTree const&) = default;
    InspectDomTree() {}
    virtual ~InspectDomTree() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::InspectDomTree; }
    static i32 static_message_id() { return (int)MessageID::InspectDomTree; }
    virtual const char* message_name() const override { return "WebContentServer::InspectDomTree"; }

    static OwnPtr<InspectDomTree> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<InspectDomTree>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::InspectDomTree;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class InspectDomNodeResponse final : public IPC::Message {
public:

    InspectDomNodeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    InspectDomNodeResponse(InspectDomNodeResponse const&) = default;
    InspectDomNodeResponse(InspectDomNodeResponse&&) = default;
    InspectDomNodeResponse& operator=(InspectDomNodeResponse const&) = default;
    InspectDomNodeResponse(bool has_style, String specified_style, String computed_style, String custom_properties, String node_box_sizing) : m_has_style(move(has_style)), m_specified_style(move(specified_style)), m_computed_style(move(computed_style)), m_custom_properties(move(custom_properties)), m_node_box_sizing(move(node_box_sizing)) {}
    virtual ~InspectDomNodeResponse() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::InspectDomNodeResponse; }
    static i32 static_message_id() { return (int)MessageID::InspectDomNodeResponse; }
    virtual const char* message_name() const override { return "WebContentServer::InspectDomNodeResponse"; }

    static OwnPtr<InspectDomNodeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool has_style = false;
        if (decoder.decode(has_style).is_error())
            return {};

        String specified_style = {};
        if (decoder.decode(specified_style).is_error())
            return {};

        String computed_style = {};
        if (decoder.decode(computed_style).is_error())
            return {};

        String custom_properties = {};
        if (decoder.decode(custom_properties).is_error())
            return {};

        String node_box_sizing = {};
        if (decoder.decode(node_box_sizing).is_error())
            return {};

        return make<InspectDomNodeResponse>(move(has_style), move(specified_style), move(computed_style), move(custom_properties), move(node_box_sizing));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::InspectDomNodeResponse;

        stream << m_has_style;

        stream << m_specified_style;

        stream << m_computed_style;

        stream << m_custom_properties;

        stream << m_node_box_sizing;

        return buffer;
    }

    const bool& has_style() const { return m_has_style; }
    bool take_has_style() { return move(m_has_style); }

    const String& specified_style() const { return m_specified_style; }
    String take_specified_style() { return move(m_specified_style); }

    const String& computed_style() const { return m_computed_style; }
    String take_computed_style() { return move(m_computed_style); }

    const String& custom_properties() const { return m_custom_properties; }
    String take_custom_properties() { return move(m_custom_properties); }

    const String& node_box_sizing() const { return m_node_box_sizing; }
    String take_node_box_sizing() { return move(m_node_box_sizing); }

private:
    bool m_ipc_message_valid { true };

    bool m_has_style {};

    String m_specified_style {};

    String m_computed_style {};

    String m_custom_properties {};

    String m_node_box_sizing {};

};

class InspectDomNode final : public IPC::Message {
public:

   typedef class InspectDomNodeResponse ResponseType;

    InspectDomNode(decltype(nullptr)) : m_ipc_message_valid(false) { }
    InspectDomNode(InspectDomNode const&) = default;
    InspectDomNode(InspectDomNode&&) = default;
    InspectDomNode& operator=(InspectDomNode const&) = default;
    InspectDomNode(i32 node_id, Optional<Web::CSS::Selector::PseudoElement> pseudo_element) : m_node_id(move(node_id)), m_pseudo_element(move(pseudo_element)) {}
    virtual ~InspectDomNode() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::InspectDomNode; }
    static i32 static_message_id() { return (int)MessageID::InspectDomNode; }
    virtual const char* message_name() const override { return "WebContentServer::InspectDomNode"; }

    static OwnPtr<InspectDomNode> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 node_id = {};
        if (decoder.decode(node_id).is_error())
            return {};

        Optional<Web::CSS::Selector::PseudoElement> pseudo_element = {};
        if (decoder.decode(pseudo_element).is_error())
            return {};

        return make<InspectDomNode>(move(node_id), move(pseudo_element));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::InspectDomNode;

        stream << m_node_id;

        stream << m_pseudo_element;

        return buffer;
    }

    const i32& node_id() const { return m_node_id; }
    i32 take_node_id() { return move(m_node_id); }

    const Optional<Web::CSS::Selector::PseudoElement>& pseudo_element() const { return m_pseudo_element; }
    Optional<Web::CSS::Selector::PseudoElement> take_pseudo_element() { return move(m_pseudo_element); }

private:
    bool m_ipc_message_valid { true };

    i32 m_node_id {};

    Optional<Web::CSS::Selector::PseudoElement> m_pseudo_element {};

};

class GetHoveredNodeIdResponse final : public IPC::Message {
public:

    GetHoveredNodeIdResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHoveredNodeIdResponse(GetHoveredNodeIdResponse const&) = default;
    GetHoveredNodeIdResponse(GetHoveredNodeIdResponse&&) = default;
    GetHoveredNodeIdResponse& operator=(GetHoveredNodeIdResponse const&) = default;
    GetHoveredNodeIdResponse(i32 node_id) : m_node_id(move(node_id)) {}
    virtual ~GetHoveredNodeIdResponse() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetHoveredNodeIdResponse; }
    static i32 static_message_id() { return (int)MessageID::GetHoveredNodeIdResponse; }
    virtual const char* message_name() const override { return "WebContentServer::GetHoveredNodeIdResponse"; }

    static OwnPtr<GetHoveredNodeIdResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 node_id = {};
        if (decoder.decode(node_id).is_error())
            return {};

        return make<GetHoveredNodeIdResponse>(move(node_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHoveredNodeIdResponse;

        stream << m_node_id;

        return buffer;
    }

    const i32& node_id() const { return m_node_id; }
    i32 take_node_id() { return move(m_node_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_node_id {};

};

class GetHoveredNodeId final : public IPC::Message {
public:

   typedef class GetHoveredNodeIdResponse ResponseType;

    GetHoveredNodeId(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHoveredNodeId(GetHoveredNodeId const&) = default;
    GetHoveredNodeId(GetHoveredNodeId&&) = default;
    GetHoveredNodeId& operator=(GetHoveredNodeId const&) = default;
    GetHoveredNodeId() {}
    virtual ~GetHoveredNodeId() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetHoveredNodeId; }
    static i32 static_message_id() { return (int)MessageID::GetHoveredNodeId; }
    virtual const char* message_name() const override { return "WebContentServer::GetHoveredNodeId"; }

    static OwnPtr<GetHoveredNodeId> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetHoveredNodeId>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHoveredNodeId;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class JsConsoleInput final : public IPC::Message {
public:

    JsConsoleInput(decltype(nullptr)) : m_ipc_message_valid(false) { }
    JsConsoleInput(JsConsoleInput const&) = default;
    JsConsoleInput(JsConsoleInput&&) = default;
    JsConsoleInput& operator=(JsConsoleInput const&) = default;
    JsConsoleInput(String js_source) : m_js_source(move(js_source)) {}
    virtual ~JsConsoleInput() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::JsConsoleInput; }
    static i32 static_message_id() { return (int)MessageID::JsConsoleInput; }
    virtual const char* message_name() const override { return "WebContentServer::JsConsoleInput"; }

    static OwnPtr<JsConsoleInput> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String js_source = {};
        if (decoder.decode(js_source).is_error())
            return {};

        return make<JsConsoleInput>(move(js_source));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::JsConsoleInput;

        stream << m_js_source;

        return buffer;
    }

    const String& js_source() const { return m_js_source; }
    String take_js_source() { return move(m_js_source); }

private:
    bool m_ipc_message_valid { true };

    String m_js_source {};

};

class JsConsoleRequestMessages final : public IPC::Message {
public:

    JsConsoleRequestMessages(decltype(nullptr)) : m_ipc_message_valid(false) { }
    JsConsoleRequestMessages(JsConsoleRequestMessages const&) = default;
    JsConsoleRequestMessages(JsConsoleRequestMessages&&) = default;
    JsConsoleRequestMessages& operator=(JsConsoleRequestMessages const&) = default;
    JsConsoleRequestMessages(i32 start_index) : m_start_index(move(start_index)) {}
    virtual ~JsConsoleRequestMessages() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::JsConsoleRequestMessages; }
    static i32 static_message_id() { return (int)MessageID::JsConsoleRequestMessages; }
    virtual const char* message_name() const override { return "WebContentServer::JsConsoleRequestMessages"; }

    static OwnPtr<JsConsoleRequestMessages> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 start_index = {};
        if (decoder.decode(start_index).is_error())
            return {};

        return make<JsConsoleRequestMessages>(move(start_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::JsConsoleRequestMessages;

        stream << m_start_index;

        return buffer;
    }

    const i32& start_index() const { return m_start_index; }
    i32 take_start_index() { return move(m_start_index); }

private:
    bool m_ipc_message_valid { true };

    i32 m_start_index {};

};

class RunJavascript final : public IPC::Message {
public:

    RunJavascript(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RunJavascript(RunJavascript const&) = default;
    RunJavascript(RunJavascript&&) = default;
    RunJavascript& operator=(RunJavascript const&) = default;
    RunJavascript(String js_source) : m_js_source(move(js_source)) {}
    virtual ~RunJavascript() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::RunJavascript; }
    static i32 static_message_id() { return (int)MessageID::RunJavascript; }
    virtual const char* message_name() const override { return "WebContentServer::RunJavascript"; }

    static OwnPtr<RunJavascript> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String js_source = {};
        if (decoder.decode(js_source).is_error())
            return {};

        return make<RunJavascript>(move(js_source));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RunJavascript;

        stream << m_js_source;

        return buffer;
    }

    const String& js_source() const { return m_js_source; }
    String take_js_source() { return move(m_js_source); }

private:
    bool m_ipc_message_valid { true };

    String m_js_source {};

};

class DumpLayoutTreeResponse final : public IPC::Message {
public:

    DumpLayoutTreeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DumpLayoutTreeResponse(DumpLayoutTreeResponse const&) = default;
    DumpLayoutTreeResponse(DumpLayoutTreeResponse&&) = default;
    DumpLayoutTreeResponse& operator=(DumpLayoutTreeResponse const&) = default;
    DumpLayoutTreeResponse(String dump) : m_dump(move(dump)) {}
    virtual ~DumpLayoutTreeResponse() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::DumpLayoutTreeResponse; }
    static i32 static_message_id() { return (int)MessageID::DumpLayoutTreeResponse; }
    virtual const char* message_name() const override { return "WebContentServer::DumpLayoutTreeResponse"; }

    static OwnPtr<DumpLayoutTreeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String dump = {};
        if (decoder.decode(dump).is_error())
            return {};

        return make<DumpLayoutTreeResponse>(move(dump));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DumpLayoutTreeResponse;

        stream << m_dump;

        return buffer;
    }

    const String& dump() const { return m_dump; }
    String take_dump() { return move(m_dump); }

private:
    bool m_ipc_message_valid { true };

    String m_dump {};

};

class DumpLayoutTree final : public IPC::Message {
public:

   typedef class DumpLayoutTreeResponse ResponseType;

    DumpLayoutTree(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DumpLayoutTree(DumpLayoutTree const&) = default;
    DumpLayoutTree(DumpLayoutTree&&) = default;
    DumpLayoutTree& operator=(DumpLayoutTree const&) = default;
    DumpLayoutTree() {}
    virtual ~DumpLayoutTree() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::DumpLayoutTree; }
    static i32 static_message_id() { return (int)MessageID::DumpLayoutTree; }
    virtual const char* message_name() const override { return "WebContentServer::DumpLayoutTree"; }

    static OwnPtr<DumpLayoutTree> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DumpLayoutTree>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DumpLayoutTree;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class GetSelectedTextResponse final : public IPC::Message {
public:

    GetSelectedTextResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSelectedTextResponse(GetSelectedTextResponse const&) = default;
    GetSelectedTextResponse(GetSelectedTextResponse&&) = default;
    GetSelectedTextResponse& operator=(GetSelectedTextResponse const&) = default;
    GetSelectedTextResponse(String selection) : m_selection(move(selection)) {}
    virtual ~GetSelectedTextResponse() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetSelectedTextResponse; }
    static i32 static_message_id() { return (int)MessageID::GetSelectedTextResponse; }
    virtual const char* message_name() const override { return "WebContentServer::GetSelectedTextResponse"; }

    static OwnPtr<GetSelectedTextResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String selection = {};
        if (decoder.decode(selection).is_error())
            return {};

        return make<GetSelectedTextResponse>(move(selection));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSelectedTextResponse;

        stream << m_selection;

        return buffer;
    }

    const String& selection() const { return m_selection; }
    String take_selection() { return move(m_selection); }

private:
    bool m_ipc_message_valid { true };

    String m_selection {};

};

class GetSelectedText final : public IPC::Message {
public:

   typedef class GetSelectedTextResponse ResponseType;

    GetSelectedText(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSelectedText(GetSelectedText const&) = default;
    GetSelectedText(GetSelectedText&&) = default;
    GetSelectedText& operator=(GetSelectedText const&) = default;
    GetSelectedText() {}
    virtual ~GetSelectedText() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetSelectedText; }
    static i32 static_message_id() { return (int)MessageID::GetSelectedText; }
    virtual const char* message_name() const override { return "WebContentServer::GetSelectedText"; }

    static OwnPtr<GetSelectedText> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetSelectedText>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSelectedText;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SelectAll final : public IPC::Message {
public:

    SelectAll(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SelectAll(SelectAll const&) = default;
    SelectAll(SelectAll&&) = default;
    SelectAll& operator=(SelectAll const&) = default;
    SelectAll() {}
    virtual ~SelectAll() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SelectAll; }
    static i32 static_message_id() { return (int)MessageID::SelectAll; }
    virtual const char* message_name() const override { return "WebContentServer::SelectAll"; }

    static OwnPtr<SelectAll> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SelectAll>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SelectAll;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetContentFilters final : public IPC::Message {
public:

    SetContentFilters(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetContentFilters(SetContentFilters const&) = default;
    SetContentFilters(SetContentFilters&&) = default;
    SetContentFilters& operator=(SetContentFilters const&) = default;
    SetContentFilters(Vector<String> filters) : m_filters(move(filters)) {}
    virtual ~SetContentFilters() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetContentFilters; }
    static i32 static_message_id() { return (int)MessageID::SetContentFilters; }
    virtual const char* message_name() const override { return "WebContentServer::SetContentFilters"; }

    static OwnPtr<SetContentFilters> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> filters = {};
        if (decoder.decode(filters).is_error())
            return {};

        return make<SetContentFilters>(move(filters));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetContentFilters;

        stream << m_filters;

        return buffer;
    }

    const Vector<String>& filters() const { return m_filters; }
    Vector<String> take_filters() { return move(m_filters); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_filters {};

};

class SetProxyMappings final : public IPC::Message {
public:

    SetProxyMappings(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetProxyMappings(SetProxyMappings const&) = default;
    SetProxyMappings(SetProxyMappings&&) = default;
    SetProxyMappings& operator=(SetProxyMappings const&) = default;
    SetProxyMappings(Vector<String> proxies, HashMap<String,size_t> mappings) : m_proxies(move(proxies)), m_mappings(move(mappings)) {}
    virtual ~SetProxyMappings() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetProxyMappings; }
    static i32 static_message_id() { return (int)MessageID::SetProxyMappings; }
    virtual const char* message_name() const override { return "WebContentServer::SetProxyMappings"; }

    static OwnPtr<SetProxyMappings> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> proxies = {};
        if (decoder.decode(proxies).is_error())
            return {};

        HashMap<String,size_t> mappings = {};
        if (decoder.decode(mappings).is_error())
            return {};

        return make<SetProxyMappings>(move(proxies), move(mappings));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetProxyMappings;

        stream << m_proxies;

        stream << m_mappings;

        return buffer;
    }

    const Vector<String>& proxies() const { return m_proxies; }
    Vector<String> take_proxies() { return move(m_proxies); }

    const HashMap<String,size_t>& mappings() const { return m_mappings; }
    HashMap<String,size_t> take_mappings() { return move(m_mappings); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_proxies {};

    HashMap<String,size_t> m_mappings {};

};

class SetPreferredColorScheme final : public IPC::Message {
public:

    SetPreferredColorScheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetPreferredColorScheme(SetPreferredColorScheme const&) = default;
    SetPreferredColorScheme(SetPreferredColorScheme&&) = default;
    SetPreferredColorScheme& operator=(SetPreferredColorScheme const&) = default;
    SetPreferredColorScheme(Web::CSS::PreferredColorScheme color_scheme) : m_color_scheme(move(color_scheme)) {}
    virtual ~SetPreferredColorScheme() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetPreferredColorScheme; }
    static i32 static_message_id() { return (int)MessageID::SetPreferredColorScheme; }
    virtual const char* message_name() const override { return "WebContentServer::SetPreferredColorScheme"; }

    static OwnPtr<SetPreferredColorScheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Web::CSS::PreferredColorScheme color_scheme = {};
        if (decoder.decode(color_scheme).is_error())
            return {};

        return make<SetPreferredColorScheme>(move(color_scheme));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetPreferredColorScheme;

        stream << m_color_scheme;

        return buffer;
    }

    const Web::CSS::PreferredColorScheme& color_scheme() const { return m_color_scheme; }
    Web::CSS::PreferredColorScheme take_color_scheme() { return move(m_color_scheme); }

private:
    bool m_ipc_message_valid { true };

    Web::CSS::PreferredColorScheme m_color_scheme {};

};

class SetHasFocus final : public IPC::Message {
public:

    SetHasFocus(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetHasFocus(SetHasFocus const&) = default;
    SetHasFocus(SetHasFocus&&) = default;
    SetHasFocus& operator=(SetHasFocus const&) = default;
    SetHasFocus(bool has_focus) : m_has_focus(move(has_focus)) {}
    virtual ~SetHasFocus() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetHasFocus; }
    static i32 static_message_id() { return (int)MessageID::SetHasFocus; }
    virtual const char* message_name() const override { return "WebContentServer::SetHasFocus"; }

    static OwnPtr<SetHasFocus> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool has_focus = false;
        if (decoder.decode(has_focus).is_error())
            return {};

        return make<SetHasFocus>(move(has_focus));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetHasFocus;

        stream << m_has_focus;

        return buffer;
    }

    const bool& has_focus() const { return m_has_focus; }
    bool take_has_focus() { return move(m_has_focus); }

private:
    bool m_ipc_message_valid { true };

    bool m_has_focus {};

};

class SetIsScriptingEnabled final : public IPC::Message {
public:

    SetIsScriptingEnabled(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetIsScriptingEnabled(SetIsScriptingEnabled const&) = default;
    SetIsScriptingEnabled(SetIsScriptingEnabled&&) = default;
    SetIsScriptingEnabled& operator=(SetIsScriptingEnabled const&) = default;
    SetIsScriptingEnabled(bool is_scripting_enabled) : m_is_scripting_enabled(move(is_scripting_enabled)) {}
    virtual ~SetIsScriptingEnabled() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::SetIsScriptingEnabled; }
    static i32 static_message_id() { return (int)MessageID::SetIsScriptingEnabled; }
    virtual const char* message_name() const override { return "WebContentServer::SetIsScriptingEnabled"; }

    static OwnPtr<SetIsScriptingEnabled> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool is_scripting_enabled = false;
        if (decoder.decode(is_scripting_enabled).is_error())
            return {};

        return make<SetIsScriptingEnabled>(move(is_scripting_enabled));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetIsScriptingEnabled;

        stream << m_is_scripting_enabled;

        return buffer;
    }

    const bool& is_scripting_enabled() const { return m_is_scripting_enabled; }
    bool take_is_scripting_enabled() { return move(m_is_scripting_enabled); }

private:
    bool m_ipc_message_valid { true };

    bool m_is_scripting_enabled {};

};

class GetLocalStorageEntriesResponse final : public IPC::Message {
public:

    GetLocalStorageEntriesResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetLocalStorageEntriesResponse(GetLocalStorageEntriesResponse const&) = default;
    GetLocalStorageEntriesResponse(GetLocalStorageEntriesResponse&&) = default;
    GetLocalStorageEntriesResponse& operator=(GetLocalStorageEntriesResponse const&) = default;
    GetLocalStorageEntriesResponse(OrderedHashMap<String,String> entries) : m_entries(move(entries)) {}
    virtual ~GetLocalStorageEntriesResponse() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetLocalStorageEntriesResponse; }
    static i32 static_message_id() { return (int)MessageID::GetLocalStorageEntriesResponse; }
    virtual const char* message_name() const override { return "WebContentServer::GetLocalStorageEntriesResponse"; }

    static OwnPtr<GetLocalStorageEntriesResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        OrderedHashMap<String,String> entries = {};
        if (decoder.decode(entries).is_error())
            return {};

        return make<GetLocalStorageEntriesResponse>(move(entries));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetLocalStorageEntriesResponse;

        stream << m_entries;

        return buffer;
    }

    const OrderedHashMap<String,String>& entries() const { return m_entries; }
    OrderedHashMap<String,String> take_entries() { return move(m_entries); }

private:
    bool m_ipc_message_valid { true };

    OrderedHashMap<String,String> m_entries {};

};

class GetLocalStorageEntries final : public IPC::Message {
public:

   typedef class GetLocalStorageEntriesResponse ResponseType;

    GetLocalStorageEntries(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetLocalStorageEntries(GetLocalStorageEntries const&) = default;
    GetLocalStorageEntries(GetLocalStorageEntries&&) = default;
    GetLocalStorageEntries& operator=(GetLocalStorageEntries const&) = default;
    GetLocalStorageEntries() {}
    virtual ~GetLocalStorageEntries() override {}

    virtual u32 endpoint_magic() const override { return 4289017466; }
    virtual i32 message_id() const override { return (int)MessageID::GetLocalStorageEntries; }
    static i32 static_message_id() { return (int)MessageID::GetLocalStorageEntries; }
    virtual const char* message_name() const override { return "WebContentServer::GetLocalStorageEntries"; }

    static OwnPtr<GetLocalStorageEntries> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetLocalStorageEntries>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetLocalStorageEntries;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::WebContentServer

template<typename LocalEndpoint, typename PeerEndpoint>
class WebContentServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WebContentServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_update_system_theme(
Core::AnonymousBuffer theme_buffer) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::UpdateSystemTheme { move(theme_buffer) });

    }

    void async_update_system_fonts(
String default_font_query, String fixed_width_font_query) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::UpdateSystemFonts { move(default_font_query), move(fixed_width_font_query) });

    }

    void async_update_screen_rects(
Vector<Gfx::IntRect> rects, u32 main_screen_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::UpdateScreenRects { move(rects), main_screen_index });

    }

    void async_load_url(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::LoadUrl { move(url) });

    }

    void async_load_html(
String html, URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::LoadHtml { move(html), move(url) });

    }

    void async_add_backing_store(
i32 backing_store_id, Gfx::ShareableBitmap bitmap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::AddBackingStore { backing_store_id, move(bitmap) });

    }

    void async_remove_backing_store(
i32 backing_store_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::RemoveBackingStore { backing_store_id });

    }

    void async_paint(
Gfx::IntRect content_rect, i32 backing_store_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::Paint { move(content_rect), backing_store_id });

    }

    void async_set_viewport_rect(
Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetViewportRect { move(rect) });

    }

    void async_mouse_down(
Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::MouseDown { move(position), button, buttons, modifiers });

    }

    void async_mouse_move(
Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::MouseMove { move(position), button, buttons, modifiers });

    }

    void async_mouse_up(
Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::MouseUp { move(position), button, buttons, modifiers });

    }

    void async_mouse_wheel(
Gfx::IntPoint position, unsigned button, unsigned buttons, unsigned modifiers, i32 wheel_delta_x, i32 wheel_delta_y) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::MouseWheel { move(position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y });

    }

    void async_key_down(
i32 key, unsigned modifiers, u32 code_point) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::KeyDown { key, modifiers, code_point });

    }

    void async_key_up(
i32 key, unsigned modifiers, u32 code_point) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::KeyUp { key, modifiers, code_point });

    }

    void async_debug_request(
String request, String argument) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::DebugRequest { move(request), move(argument) });

    }

    void async_get_source(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::GetSource {  });

    }

    void async_inspect_dom_tree(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::InspectDomTree {  });

    }

    Messages::WebContentServer::InspectDomNodeResponse inspect_dom_node(
i32 node_id, Optional<Web::CSS::Selector::PseudoElement> pseudo_element) {
        return move(*m_connection.template send_sync<Messages::WebContentServer::InspectDomNode>(node_id, move(pseudo_element)));
    }

    void async_inspect_dom_node(
i32 node_id, Optional<Web::CSS::Selector::PseudoElement> pseudo_element) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::InspectDomNode { node_id, move(pseudo_element) });

    }

    IPC::IPCErrorOr<Messages::WebContentServer::InspectDomNodeResponse> try_inspect_dom_node(
i32 node_id, Optional<Web::CSS::Selector::PseudoElement> pseudo_element) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentServer::InspectDomNode>(node_id, move(pseudo_element));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    i32 get_hovered_node_id(
) {
        return m_connection.template send_sync<Messages::WebContentServer::GetHoveredNodeId>()->take_node_id();
    }

    void async_get_hovered_node_id(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::GetHoveredNodeId {  });

    }

    IPC::IPCErrorOr<i32> try_get_hovered_node_id(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentServer::GetHoveredNodeId>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_js_console_input(
String js_source) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::JsConsoleInput { move(js_source) });

    }

    void async_js_console_request_messages(
i32 start_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::JsConsoleRequestMessages { start_index });

    }

    void async_run_javascript(
String js_source) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::RunJavascript { move(js_source) });

    }

    String dump_layout_tree(
) {
        return m_connection.template send_sync<Messages::WebContentServer::DumpLayoutTree>()->take_dump();
    }

    void async_dump_layout_tree(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::DumpLayoutTree {  });

    }

    IPC::IPCErrorOr<String> try_dump_layout_tree(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentServer::DumpLayoutTree>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    String get_selected_text(
) {
        return m_connection.template send_sync<Messages::WebContentServer::GetSelectedText>()->take_selection();
    }

    void async_get_selected_text(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::GetSelectedText {  });

    }

    IPC::IPCErrorOr<String> try_get_selected_text(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentServer::GetSelectedText>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_select_all(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SelectAll {  });

    }

    void async_set_content_filters(
Vector<String> filters) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetContentFilters { move(filters) });

    }

    void async_set_proxy_mappings(
Vector<String> proxies, HashMap<String,size_t> mappings) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetProxyMappings { move(proxies), move(mappings) });

    }

    void async_set_preferred_color_scheme(
Web::CSS::PreferredColorScheme color_scheme) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetPreferredColorScheme { move(color_scheme) });

    }

    void async_set_has_focus(
bool has_focus) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetHasFocus { has_focus });

    }

    void async_set_is_scripting_enabled(
bool is_scripting_enabled) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::SetIsScriptingEnabled { is_scripting_enabled });

    }

    OrderedHashMap<String,String> get_local_storage_entries(
) {
        return m_connection.template send_sync<Messages::WebContentServer::GetLocalStorageEntries>()->take_entries();
    }

    void async_get_local_storage_entries(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentServer::GetLocalStorageEntries {  });

    }

    IPC::IPCErrorOr<OrderedHashMap<String,String>> try_get_local_storage_entries(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentServer::GetLocalStorageEntries>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WebContentServerProxy;
class WebContentServerStub;

class WebContentServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WebContentServerProxy<LocalEndpoint, WebContentServerEndpoint>;
    using Stub = WebContentServerStub;

    static u32 static_magic() { return 4289017466; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 4289017466) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WebContentServer::MessageID::UpdateSystemTheme:
            message = Messages::WebContentServer::UpdateSystemTheme::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::UpdateSystemFonts:
            message = Messages::WebContentServer::UpdateSystemFonts::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::UpdateScreenRects:
            message = Messages::WebContentServer::UpdateScreenRects::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::LoadUrl:
            message = Messages::WebContentServer::LoadUrl::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::LoadHtml:
            message = Messages::WebContentServer::LoadHtml::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::AddBackingStore:
            message = Messages::WebContentServer::AddBackingStore::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::RemoveBackingStore:
            message = Messages::WebContentServer::RemoveBackingStore::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::Paint:
            message = Messages::WebContentServer::Paint::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetViewportRect:
            message = Messages::WebContentServer::SetViewportRect::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::MouseDown:
            message = Messages::WebContentServer::MouseDown::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::MouseMove:
            message = Messages::WebContentServer::MouseMove::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::MouseUp:
            message = Messages::WebContentServer::MouseUp::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::MouseWheel:
            message = Messages::WebContentServer::MouseWheel::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::KeyDown:
            message = Messages::WebContentServer::KeyDown::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::KeyUp:
            message = Messages::WebContentServer::KeyUp::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::DebugRequest:
            message = Messages::WebContentServer::DebugRequest::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetSource:
            message = Messages::WebContentServer::GetSource::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::InspectDomTree:
            message = Messages::WebContentServer::InspectDomTree::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::InspectDomNode:
            message = Messages::WebContentServer::InspectDomNode::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::InspectDomNodeResponse:
            message = Messages::WebContentServer::InspectDomNodeResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetHoveredNodeId:
            message = Messages::WebContentServer::GetHoveredNodeId::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetHoveredNodeIdResponse:
            message = Messages::WebContentServer::GetHoveredNodeIdResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::JsConsoleInput:
            message = Messages::WebContentServer::JsConsoleInput::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::JsConsoleRequestMessages:
            message = Messages::WebContentServer::JsConsoleRequestMessages::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::RunJavascript:
            message = Messages::WebContentServer::RunJavascript::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::DumpLayoutTree:
            message = Messages::WebContentServer::DumpLayoutTree::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::DumpLayoutTreeResponse:
            message = Messages::WebContentServer::DumpLayoutTreeResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetSelectedText:
            message = Messages::WebContentServer::GetSelectedText::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetSelectedTextResponse:
            message = Messages::WebContentServer::GetSelectedTextResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SelectAll:
            message = Messages::WebContentServer::SelectAll::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetContentFilters:
            message = Messages::WebContentServer::SetContentFilters::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetProxyMappings:
            message = Messages::WebContentServer::SetProxyMappings::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetPreferredColorScheme:
            message = Messages::WebContentServer::SetPreferredColorScheme::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetHasFocus:
            message = Messages::WebContentServer::SetHasFocus::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::SetIsScriptingEnabled:
            message = Messages::WebContentServer::SetIsScriptingEnabled::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetLocalStorageEntries:
            message = Messages::WebContentServer::GetLocalStorageEntries::decode(stream, socket);
            break;

        case (int)Messages::WebContentServer::MessageID::GetLocalStorageEntriesResponse:
            message = Messages::WebContentServer::GetLocalStorageEntriesResponse::decode(stream, socket);
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

class WebContentServerStub : public IPC::Stub {
public:
    WebContentServerStub() { }
    virtual ~WebContentServerStub() override { }

    virtual u32 magic() const override { return 4289017466; }
    virtual String name() const override { return "WebContentServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WebContentServer::MessageID::UpdateSystemTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::UpdateSystemTheme&>(message);
            update_system_theme(request.theme_buffer());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::UpdateSystemFonts: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::UpdateSystemFonts&>(message);
            update_system_fonts(request.default_font_query(), request.fixed_width_font_query());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::UpdateScreenRects: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::UpdateScreenRects&>(message);
            update_screen_rects(request.rects(), request.main_screen_index());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::LoadUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::LoadUrl&>(message);
            load_url(request.url());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::LoadHtml: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::LoadHtml&>(message);
            load_html(request.html(), request.url());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::AddBackingStore: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::AddBackingStore&>(message);
            add_backing_store(request.backing_store_id(), request.bitmap());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::RemoveBackingStore: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::RemoveBackingStore&>(message);
            remove_backing_store(request.backing_store_id());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::Paint: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::Paint&>(message);
            paint(request.content_rect(), request.backing_store_id());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetViewportRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetViewportRect&>(message);
            set_viewport_rect(request.rect());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::MouseDown: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::MouseDown&>(message);
            mouse_down(request.position(), request.button(), request.buttons(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::MouseMove: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::MouseMove&>(message);
            mouse_move(request.position(), request.button(), request.buttons(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::MouseUp: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::MouseUp&>(message);
            mouse_up(request.position(), request.button(), request.buttons(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::MouseWheel: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::MouseWheel&>(message);
            mouse_wheel(request.position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::KeyDown: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::KeyDown&>(message);
            key_down(request.key(), request.modifiers(), request.code_point());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::KeyUp: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::KeyUp&>(message);
            key_up(request.key(), request.modifiers(), request.code_point());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::DebugRequest: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::DebugRequest&>(message);
            debug_request(request.request(), request.argument());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::GetSource: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::GetSource&>(message);
            get_source();
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::InspectDomTree: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::InspectDomTree&>(message);
            inspect_dom_tree();
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::InspectDomNode: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::InspectDomNode&>(message);
            auto response = inspect_dom_node(request.node_id(), request.pseudo_element());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentServer::MessageID::GetHoveredNodeId: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::GetHoveredNodeId&>(message);
            auto response = get_hovered_node_id();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentServer::MessageID::JsConsoleInput: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::JsConsoleInput&>(message);
            js_console_input(request.js_source());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::JsConsoleRequestMessages: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::JsConsoleRequestMessages&>(message);
            js_console_request_messages(request.start_index());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::RunJavascript: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::RunJavascript&>(message);
            run_javascript(request.js_source());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::DumpLayoutTree: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::DumpLayoutTree&>(message);
            auto response = dump_layout_tree();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentServer::MessageID::GetSelectedText: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::GetSelectedText&>(message);
            auto response = get_selected_text();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentServer::MessageID::SelectAll: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SelectAll&>(message);
            select_all();
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetContentFilters: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetContentFilters&>(message);
            set_content_filters(request.filters());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetProxyMappings: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetProxyMappings&>(message);
            set_proxy_mappings(request.proxies(), request.mappings());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetPreferredColorScheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetPreferredColorScheme&>(message);
            set_preferred_color_scheme(request.color_scheme());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetHasFocus: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetHasFocus&>(message);
            set_has_focus(request.has_focus());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::SetIsScriptingEnabled: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::SetIsScriptingEnabled&>(message);
            set_is_scripting_enabled(request.is_scripting_enabled());
            return {};

        }

        case (int)Messages::WebContentServer::MessageID::GetLocalStorageEntries: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentServer::GetLocalStorageEntries&>(message);
            auto response = get_local_storage_entries();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual void update_system_theme(
[[maybe_unused]] Core::AnonymousBuffer const& theme_buffer) = 0;

    virtual void update_system_fonts(
[[maybe_unused]] String const& default_font_query, [[maybe_unused]] String const& fixed_width_font_query) = 0;

    virtual void update_screen_rects(
[[maybe_unused]] Vector<Gfx::IntRect> const& rects, [[maybe_unused]] u32 main_screen_index) = 0;

    virtual void load_url(
[[maybe_unused]] URL const& url) = 0;

    virtual void load_html(
[[maybe_unused]] String const& html, [[maybe_unused]] URL const& url) = 0;

    virtual void add_backing_store(
[[maybe_unused]] i32 backing_store_id, [[maybe_unused]] Gfx::ShareableBitmap const& bitmap) = 0;

    virtual void remove_backing_store(
[[maybe_unused]] i32 backing_store_id) = 0;

    virtual void paint(
[[maybe_unused]] Gfx::IntRect const& content_rect, [[maybe_unused]] i32 backing_store_id) = 0;

    virtual void set_viewport_rect(
[[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual void mouse_down(
[[maybe_unused]] Gfx::IntPoint const& position, [[maybe_unused]] unsigned button, [[maybe_unused]] unsigned buttons, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void mouse_move(
[[maybe_unused]] Gfx::IntPoint const& position, [[maybe_unused]] unsigned button, [[maybe_unused]] unsigned buttons, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void mouse_up(
[[maybe_unused]] Gfx::IntPoint const& position, [[maybe_unused]] unsigned button, [[maybe_unused]] unsigned buttons, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void mouse_wheel(
[[maybe_unused]] Gfx::IntPoint const& position, [[maybe_unused]] unsigned button, [[maybe_unused]] unsigned buttons, [[maybe_unused]] unsigned modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y) = 0;

    virtual void key_down(
[[maybe_unused]] i32 key, [[maybe_unused]] unsigned modifiers, [[maybe_unused]] u32 code_point) = 0;

    virtual void key_up(
[[maybe_unused]] i32 key, [[maybe_unused]] unsigned modifiers, [[maybe_unused]] u32 code_point) = 0;

    virtual void debug_request(
[[maybe_unused]] String const& request, [[maybe_unused]] String const& argument) = 0;

    virtual void get_source(
) = 0;

    virtual void inspect_dom_tree(
) = 0;

    virtual Messages::WebContentServer::InspectDomNodeResponse inspect_dom_node(
[[maybe_unused]] i32 node_id, [[maybe_unused]] Optional<Web::CSS::Selector::PseudoElement> const& pseudo_element) = 0;

    virtual Messages::WebContentServer::GetHoveredNodeIdResponse get_hovered_node_id(
) = 0;

    virtual void js_console_input(
[[maybe_unused]] String const& js_source) = 0;

    virtual void js_console_request_messages(
[[maybe_unused]] i32 start_index) = 0;

    virtual void run_javascript(
[[maybe_unused]] String const& js_source) = 0;

    virtual Messages::WebContentServer::DumpLayoutTreeResponse dump_layout_tree(
) = 0;

    virtual Messages::WebContentServer::GetSelectedTextResponse get_selected_text(
) = 0;

    virtual void select_all(
) = 0;

    virtual void set_content_filters(
[[maybe_unused]] Vector<String> const& filters) = 0;

    virtual void set_proxy_mappings(
[[maybe_unused]] Vector<String> const& proxies, [[maybe_unused]] HashMap<String,size_t> const& mappings) = 0;

    virtual void set_preferred_color_scheme(
[[maybe_unused]] Web::CSS::PreferredColorScheme const& color_scheme) = 0;

    virtual void set_has_focus(
[[maybe_unused]] bool has_focus) = 0;

    virtual void set_is_scripting_enabled(
[[maybe_unused]] bool is_scripting_enabled) = 0;

    virtual Messages::WebContentServer::GetLocalStorageEntriesResponse get_local_storage_entries(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

