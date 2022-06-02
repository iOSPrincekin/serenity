#pragma once
#include <AK/URL.h>
#include <LibCore/AnonymousBuffer.h>
#include <LibGfx/ShareableBitmap.h>
#include <LibWeb/Cookie/ParsedCookie.h>
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

namespace Messages::WebContentClient {

enum class MessageID : i32 {
    DidStartLoading = 1,
    DidFinishLoading = 2,
    DidPaint = 3,
    DidInvalidateContentRect = 4,
    DidChangeSelection = 5,
    DidRequestCursorChange = 6,
    DidLayout = 7,
    DidChangeTitle = 8,
    DidRequestScroll = 9,
    DidRequestScrollTo = 10,
    DidRequestScrollIntoView = 11,
    DidEnterTooltipArea = 12,
    DidLeaveTooltipArea = 13,
    DidHoverLink = 14,
    DidUnhoverLink = 15,
    DidClickLink = 16,
    DidMiddleClickLink = 17,
    DidRequestContextMenu = 18,
    DidRequestLinkContextMenu = 19,
    DidRequestImageContextMenu = 20,
    DidRequestAlert = 21,
    DidRequestAlertResponse = 22,
    DidRequestConfirm = 23,
    DidRequestConfirmResponse = 24,
    DidRequestPrompt = 25,
    DidRequestPromptResponse = 26,
    DidGetSource = 27,
    DidGetDomTree = 28,
    DidGetDomNodeProperties = 29,
    DidChangeFavicon = 30,
    DidRequestCookie = 31,
    DidRequestCookieResponse = 32,
    DidSetCookie = 33,
    DidUpdateResourceCount = 34,
    DidOutputJsConsoleMessage = 35,
    DidGetJsConsoleMessages = 36,
};

class DidStartLoading final : public IPC::Message {
public:

    DidStartLoading(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidStartLoading(DidStartLoading const&) = default;
    DidStartLoading(DidStartLoading&&) = default;
    DidStartLoading& operator=(DidStartLoading const&) = default;
    DidStartLoading(URL url) : m_url(move(url)) {}
    virtual ~DidStartLoading() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidStartLoading; }
    static i32 static_message_id() { return (int)MessageID::DidStartLoading; }
    virtual const char* message_name() const override { return "WebContentClient::DidStartLoading"; }

    static OwnPtr<DidStartLoading> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<DidStartLoading>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidStartLoading;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class DidFinishLoading final : public IPC::Message {
public:

    DidFinishLoading(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidFinishLoading(DidFinishLoading const&) = default;
    DidFinishLoading(DidFinishLoading&&) = default;
    DidFinishLoading& operator=(DidFinishLoading const&) = default;
    DidFinishLoading(URL url) : m_url(move(url)) {}
    virtual ~DidFinishLoading() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidFinishLoading; }
    static i32 static_message_id() { return (int)MessageID::DidFinishLoading; }
    virtual const char* message_name() const override { return "WebContentClient::DidFinishLoading"; }

    static OwnPtr<DidFinishLoading> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<DidFinishLoading>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidFinishLoading;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class DidPaint final : public IPC::Message {
public:

    DidPaint(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidPaint(DidPaint const&) = default;
    DidPaint(DidPaint&&) = default;
    DidPaint& operator=(DidPaint const&) = default;
    DidPaint(Gfx::IntRect content_rect, i32 bitmap_id) : m_content_rect(move(content_rect)), m_bitmap_id(move(bitmap_id)) {}
    virtual ~DidPaint() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidPaint; }
    static i32 static_message_id() { return (int)MessageID::DidPaint; }
    virtual const char* message_name() const override { return "WebContentClient::DidPaint"; }

    static OwnPtr<DidPaint> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect content_rect = {};
        if (decoder.decode(content_rect).is_error())
            return {};

        i32 bitmap_id = {};
        if (decoder.decode(bitmap_id).is_error())
            return {};

        return make<DidPaint>(move(content_rect), move(bitmap_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidPaint;

        stream << m_content_rect;

        stream << m_bitmap_id;

        return buffer;
    }

    const Gfx::IntRect& content_rect() const { return m_content_rect; }
    Gfx::IntRect take_content_rect() { return move(m_content_rect); }

    const i32& bitmap_id() const { return m_bitmap_id; }
    i32 take_bitmap_id() { return move(m_bitmap_id); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_content_rect {};

    i32 m_bitmap_id {};

};

class DidInvalidateContentRect final : public IPC::Message {
public:

    DidInvalidateContentRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidInvalidateContentRect(DidInvalidateContentRect const&) = default;
    DidInvalidateContentRect(DidInvalidateContentRect&&) = default;
    DidInvalidateContentRect& operator=(DidInvalidateContentRect const&) = default;
    DidInvalidateContentRect(Gfx::IntRect content_rect) : m_content_rect(move(content_rect)) {}
    virtual ~DidInvalidateContentRect() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidInvalidateContentRect; }
    static i32 static_message_id() { return (int)MessageID::DidInvalidateContentRect; }
    virtual const char* message_name() const override { return "WebContentClient::DidInvalidateContentRect"; }

    static OwnPtr<DidInvalidateContentRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect content_rect = {};
        if (decoder.decode(content_rect).is_error())
            return {};

        return make<DidInvalidateContentRect>(move(content_rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidInvalidateContentRect;

        stream << m_content_rect;

        return buffer;
    }

    const Gfx::IntRect& content_rect() const { return m_content_rect; }
    Gfx::IntRect take_content_rect() { return move(m_content_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_content_rect {};

};

class DidChangeSelection final : public IPC::Message {
public:

    DidChangeSelection(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidChangeSelection(DidChangeSelection const&) = default;
    DidChangeSelection(DidChangeSelection&&) = default;
    DidChangeSelection& operator=(DidChangeSelection const&) = default;
    DidChangeSelection() {}
    virtual ~DidChangeSelection() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidChangeSelection; }
    static i32 static_message_id() { return (int)MessageID::DidChangeSelection; }
    virtual const char* message_name() const override { return "WebContentClient::DidChangeSelection"; }

    static OwnPtr<DidChangeSelection> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DidChangeSelection>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidChangeSelection;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DidRequestCursorChange final : public IPC::Message {
public:

    DidRequestCursorChange(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestCursorChange(DidRequestCursorChange const&) = default;
    DidRequestCursorChange(DidRequestCursorChange&&) = default;
    DidRequestCursorChange& operator=(DidRequestCursorChange const&) = default;
    DidRequestCursorChange(i32 cursor_type) : m_cursor_type(move(cursor_type)) {}
    virtual ~DidRequestCursorChange() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestCursorChange; }
    static i32 static_message_id() { return (int)MessageID::DidRequestCursorChange; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestCursorChange"; }

    static OwnPtr<DidRequestCursorChange> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 cursor_type = {};
        if (decoder.decode(cursor_type).is_error())
            return {};

        return make<DidRequestCursorChange>(move(cursor_type));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestCursorChange;

        stream << m_cursor_type;

        return buffer;
    }

    const i32& cursor_type() const { return m_cursor_type; }
    i32 take_cursor_type() { return move(m_cursor_type); }

private:
    bool m_ipc_message_valid { true };

    i32 m_cursor_type {};

};

class DidLayout final : public IPC::Message {
public:

    DidLayout(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidLayout(DidLayout const&) = default;
    DidLayout(DidLayout&&) = default;
    DidLayout& operator=(DidLayout const&) = default;
    DidLayout(Gfx::IntSize content_size) : m_content_size(move(content_size)) {}
    virtual ~DidLayout() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidLayout; }
    static i32 static_message_id() { return (int)MessageID::DidLayout; }
    virtual const char* message_name() const override { return "WebContentClient::DidLayout"; }

    static OwnPtr<DidLayout> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntSize content_size = {};
        if (decoder.decode(content_size).is_error())
            return {};

        return make<DidLayout>(move(content_size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidLayout;

        stream << m_content_size;

        return buffer;
    }

    const Gfx::IntSize& content_size() const { return m_content_size; }
    Gfx::IntSize take_content_size() { return move(m_content_size); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntSize m_content_size {};

};

class DidChangeTitle final : public IPC::Message {
public:

    DidChangeTitle(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidChangeTitle(DidChangeTitle const&) = default;
    DidChangeTitle(DidChangeTitle&&) = default;
    DidChangeTitle& operator=(DidChangeTitle const&) = default;
    DidChangeTitle(String title) : m_title(move(title)) {}
    virtual ~DidChangeTitle() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidChangeTitle; }
    static i32 static_message_id() { return (int)MessageID::DidChangeTitle; }
    virtual const char* message_name() const override { return "WebContentClient::DidChangeTitle"; }

    static OwnPtr<DidChangeTitle> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        return make<DidChangeTitle>(move(title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidChangeTitle;

        stream << m_title;

        return buffer;
    }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

private:
    bool m_ipc_message_valid { true };

    String m_title {};

};

class DidRequestScroll final : public IPC::Message {
public:

    DidRequestScroll(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestScroll(DidRequestScroll const&) = default;
    DidRequestScroll(DidRequestScroll&&) = default;
    DidRequestScroll& operator=(DidRequestScroll const&) = default;
    DidRequestScroll(i32 x_delta, i32 y_delta) : m_x_delta(move(x_delta)), m_y_delta(move(y_delta)) {}
    virtual ~DidRequestScroll() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestScroll; }
    static i32 static_message_id() { return (int)MessageID::DidRequestScroll; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestScroll"; }

    static OwnPtr<DidRequestScroll> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 x_delta = {};
        if (decoder.decode(x_delta).is_error())
            return {};

        i32 y_delta = {};
        if (decoder.decode(y_delta).is_error())
            return {};

        return make<DidRequestScroll>(move(x_delta), move(y_delta));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestScroll;

        stream << m_x_delta;

        stream << m_y_delta;

        return buffer;
    }

    const i32& x_delta() const { return m_x_delta; }
    i32 take_x_delta() { return move(m_x_delta); }

    const i32& y_delta() const { return m_y_delta; }
    i32 take_y_delta() { return move(m_y_delta); }

private:
    bool m_ipc_message_valid { true };

    i32 m_x_delta {};

    i32 m_y_delta {};

};

class DidRequestScrollTo final : public IPC::Message {
public:

    DidRequestScrollTo(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestScrollTo(DidRequestScrollTo const&) = default;
    DidRequestScrollTo(DidRequestScrollTo&&) = default;
    DidRequestScrollTo& operator=(DidRequestScrollTo const&) = default;
    DidRequestScrollTo(Gfx::IntPoint scroll_position) : m_scroll_position(move(scroll_position)) {}
    virtual ~DidRequestScrollTo() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestScrollTo; }
    static i32 static_message_id() { return (int)MessageID::DidRequestScrollTo; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestScrollTo"; }

    static OwnPtr<DidRequestScrollTo> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint scroll_position = {};
        if (decoder.decode(scroll_position).is_error())
            return {};

        return make<DidRequestScrollTo>(move(scroll_position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestScrollTo;

        stream << m_scroll_position;

        return buffer;
    }

    const Gfx::IntPoint& scroll_position() const { return m_scroll_position; }
    Gfx::IntPoint take_scroll_position() { return move(m_scroll_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_scroll_position {};

};

class DidRequestScrollIntoView final : public IPC::Message {
public:

    DidRequestScrollIntoView(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestScrollIntoView(DidRequestScrollIntoView const&) = default;
    DidRequestScrollIntoView(DidRequestScrollIntoView&&) = default;
    DidRequestScrollIntoView& operator=(DidRequestScrollIntoView const&) = default;
    DidRequestScrollIntoView(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~DidRequestScrollIntoView() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestScrollIntoView; }
    static i32 static_message_id() { return (int)MessageID::DidRequestScrollIntoView; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestScrollIntoView"; }

    static OwnPtr<DidRequestScrollIntoView> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<DidRequestScrollIntoView>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestScrollIntoView;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class DidEnterTooltipArea final : public IPC::Message {
public:

    DidEnterTooltipArea(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidEnterTooltipArea(DidEnterTooltipArea const&) = default;
    DidEnterTooltipArea(DidEnterTooltipArea&&) = default;
    DidEnterTooltipArea& operator=(DidEnterTooltipArea const&) = default;
    DidEnterTooltipArea(Gfx::IntPoint content_position, String title) : m_content_position(move(content_position)), m_title(move(title)) {}
    virtual ~DidEnterTooltipArea() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidEnterTooltipArea; }
    static i32 static_message_id() { return (int)MessageID::DidEnterTooltipArea; }
    virtual const char* message_name() const override { return "WebContentClient::DidEnterTooltipArea"; }

    static OwnPtr<DidEnterTooltipArea> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint content_position = {};
        if (decoder.decode(content_position).is_error())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        return make<DidEnterTooltipArea>(move(content_position), move(title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidEnterTooltipArea;

        stream << m_content_position;

        stream << m_title;

        return buffer;
    }

    const Gfx::IntPoint& content_position() const { return m_content_position; }
    Gfx::IntPoint take_content_position() { return move(m_content_position); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_content_position {};

    String m_title {};

};

class DidLeaveTooltipArea final : public IPC::Message {
public:

    DidLeaveTooltipArea(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidLeaveTooltipArea(DidLeaveTooltipArea const&) = default;
    DidLeaveTooltipArea(DidLeaveTooltipArea&&) = default;
    DidLeaveTooltipArea& operator=(DidLeaveTooltipArea const&) = default;
    DidLeaveTooltipArea() {}
    virtual ~DidLeaveTooltipArea() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidLeaveTooltipArea; }
    static i32 static_message_id() { return (int)MessageID::DidLeaveTooltipArea; }
    virtual const char* message_name() const override { return "WebContentClient::DidLeaveTooltipArea"; }

    static OwnPtr<DidLeaveTooltipArea> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DidLeaveTooltipArea>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidLeaveTooltipArea;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DidHoverLink final : public IPC::Message {
public:

    DidHoverLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidHoverLink(DidHoverLink const&) = default;
    DidHoverLink(DidHoverLink&&) = default;
    DidHoverLink& operator=(DidHoverLink const&) = default;
    DidHoverLink(URL url) : m_url(move(url)) {}
    virtual ~DidHoverLink() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidHoverLink; }
    static i32 static_message_id() { return (int)MessageID::DidHoverLink; }
    virtual const char* message_name() const override { return "WebContentClient::DidHoverLink"; }

    static OwnPtr<DidHoverLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<DidHoverLink>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidHoverLink;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class DidUnhoverLink final : public IPC::Message {
public:

    DidUnhoverLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidUnhoverLink(DidUnhoverLink const&) = default;
    DidUnhoverLink(DidUnhoverLink&&) = default;
    DidUnhoverLink& operator=(DidUnhoverLink const&) = default;
    DidUnhoverLink() {}
    virtual ~DidUnhoverLink() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidUnhoverLink; }
    static i32 static_message_id() { return (int)MessageID::DidUnhoverLink; }
    virtual const char* message_name() const override { return "WebContentClient::DidUnhoverLink"; }

    static OwnPtr<DidUnhoverLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DidUnhoverLink>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidUnhoverLink;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DidClickLink final : public IPC::Message {
public:

    DidClickLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidClickLink(DidClickLink const&) = default;
    DidClickLink(DidClickLink&&) = default;
    DidClickLink& operator=(DidClickLink const&) = default;
    DidClickLink(URL url, String target, unsigned modifiers) : m_url(move(url)), m_target(move(target)), m_modifiers(move(modifiers)) {}
    virtual ~DidClickLink() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidClickLink; }
    static i32 static_message_id() { return (int)MessageID::DidClickLink; }
    virtual const char* message_name() const override { return "WebContentClient::DidClickLink"; }

    static OwnPtr<DidClickLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String target = {};
        if (decoder.decode(target).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<DidClickLink>(move(url), move(target), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidClickLink;

        stream << m_url;

        stream << m_target;

        stream << m_modifiers;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& target() const { return m_target; }
    String take_target() { return move(m_target); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    String m_target {};

    unsigned m_modifiers {};

};

class DidMiddleClickLink final : public IPC::Message {
public:

    DidMiddleClickLink(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidMiddleClickLink(DidMiddleClickLink const&) = default;
    DidMiddleClickLink(DidMiddleClickLink&&) = default;
    DidMiddleClickLink& operator=(DidMiddleClickLink const&) = default;
    DidMiddleClickLink(URL url, String target, unsigned modifiers) : m_url(move(url)), m_target(move(target)), m_modifiers(move(modifiers)) {}
    virtual ~DidMiddleClickLink() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidMiddleClickLink; }
    static i32 static_message_id() { return (int)MessageID::DidMiddleClickLink; }
    virtual const char* message_name() const override { return "WebContentClient::DidMiddleClickLink"; }

    static OwnPtr<DidMiddleClickLink> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String target = {};
        if (decoder.decode(target).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<DidMiddleClickLink>(move(url), move(target), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidMiddleClickLink;

        stream << m_url;

        stream << m_target;

        stream << m_modifiers;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& target() const { return m_target; }
    String take_target() { return move(m_target); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    String m_target {};

    unsigned m_modifiers {};

};

class DidRequestContextMenu final : public IPC::Message {
public:

    DidRequestContextMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestContextMenu(DidRequestContextMenu const&) = default;
    DidRequestContextMenu(DidRequestContextMenu&&) = default;
    DidRequestContextMenu& operator=(DidRequestContextMenu const&) = default;
    DidRequestContextMenu(Gfx::IntPoint content_position) : m_content_position(move(content_position)) {}
    virtual ~DidRequestContextMenu() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestContextMenu; }
    static i32 static_message_id() { return (int)MessageID::DidRequestContextMenu; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestContextMenu"; }

    static OwnPtr<DidRequestContextMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint content_position = {};
        if (decoder.decode(content_position).is_error())
            return {};

        return make<DidRequestContextMenu>(move(content_position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestContextMenu;

        stream << m_content_position;

        return buffer;
    }

    const Gfx::IntPoint& content_position() const { return m_content_position; }
    Gfx::IntPoint take_content_position() { return move(m_content_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_content_position {};

};

class DidRequestLinkContextMenu final : public IPC::Message {
public:

    DidRequestLinkContextMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestLinkContextMenu(DidRequestLinkContextMenu const&) = default;
    DidRequestLinkContextMenu(DidRequestLinkContextMenu&&) = default;
    DidRequestLinkContextMenu& operator=(DidRequestLinkContextMenu const&) = default;
    DidRequestLinkContextMenu(Gfx::IntPoint content_position, URL url, String target, unsigned modifiers) : m_content_position(move(content_position)), m_url(move(url)), m_target(move(target)), m_modifiers(move(modifiers)) {}
    virtual ~DidRequestLinkContextMenu() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestLinkContextMenu; }
    static i32 static_message_id() { return (int)MessageID::DidRequestLinkContextMenu; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestLinkContextMenu"; }

    static OwnPtr<DidRequestLinkContextMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint content_position = {};
        if (decoder.decode(content_position).is_error())
            return {};

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String target = {};
        if (decoder.decode(target).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        return make<DidRequestLinkContextMenu>(move(content_position), move(url), move(target), move(modifiers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestLinkContextMenu;

        stream << m_content_position;

        stream << m_url;

        stream << m_target;

        stream << m_modifiers;

        return buffer;
    }

    const Gfx::IntPoint& content_position() const { return m_content_position; }
    Gfx::IntPoint take_content_position() { return move(m_content_position); }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& target() const { return m_target; }
    String take_target() { return move(m_target); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_content_position {};

    URL m_url {};

    String m_target {};

    unsigned m_modifiers {};

};

class DidRequestImageContextMenu final : public IPC::Message {
public:

    DidRequestImageContextMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestImageContextMenu(DidRequestImageContextMenu const&) = default;
    DidRequestImageContextMenu(DidRequestImageContextMenu&&) = default;
    DidRequestImageContextMenu& operator=(DidRequestImageContextMenu const&) = default;
    DidRequestImageContextMenu(Gfx::IntPoint content_position, URL url, String target, unsigned modifiers, Gfx::ShareableBitmap bitmap) : m_content_position(move(content_position)), m_url(move(url)), m_target(move(target)), m_modifiers(move(modifiers)), m_bitmap(move(bitmap)) {}
    virtual ~DidRequestImageContextMenu() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestImageContextMenu; }
    static i32 static_message_id() { return (int)MessageID::DidRequestImageContextMenu; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestImageContextMenu"; }

    static OwnPtr<DidRequestImageContextMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint content_position = {};
        if (decoder.decode(content_position).is_error())
            return {};

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String target = {};
        if (decoder.decode(target).is_error())
            return {};

        unsigned modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        Gfx::ShareableBitmap bitmap = {};
        if (decoder.decode(bitmap).is_error())
            return {};

        return make<DidRequestImageContextMenu>(move(content_position), move(url), move(target), move(modifiers), move(bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestImageContextMenu;

        stream << m_content_position;

        stream << m_url;

        stream << m_target;

        stream << m_modifiers;

        stream << m_bitmap;

        return buffer;
    }

    const Gfx::IntPoint& content_position() const { return m_content_position; }
    Gfx::IntPoint take_content_position() { return move(m_content_position); }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& target() const { return m_target; }
    String take_target() { return move(m_target); }

    const unsigned& modifiers() const { return m_modifiers; }
    unsigned take_modifiers() { return move(m_modifiers); }

    const Gfx::ShareableBitmap& bitmap() const { return m_bitmap; }
    Gfx::ShareableBitmap take_bitmap() { return move(m_bitmap); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_content_position {};

    URL m_url {};

    String m_target {};

    unsigned m_modifiers {};

    Gfx::ShareableBitmap m_bitmap {};

};

class DidRequestAlertResponse final : public IPC::Message {
public:

    DidRequestAlertResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestAlertResponse(DidRequestAlertResponse const&) = default;
    DidRequestAlertResponse(DidRequestAlertResponse&&) = default;
    DidRequestAlertResponse& operator=(DidRequestAlertResponse const&) = default;
    DidRequestAlertResponse() {}
    virtual ~DidRequestAlertResponse() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestAlertResponse; }
    static i32 static_message_id() { return (int)MessageID::DidRequestAlertResponse; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestAlertResponse"; }

    static OwnPtr<DidRequestAlertResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DidRequestAlertResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestAlertResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DidRequestAlert final : public IPC::Message {
public:

   typedef class DidRequestAlertResponse ResponseType;

    DidRequestAlert(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestAlert(DidRequestAlert const&) = default;
    DidRequestAlert(DidRequestAlert&&) = default;
    DidRequestAlert& operator=(DidRequestAlert const&) = default;
    DidRequestAlert(String message) : m_message(move(message)) {}
    virtual ~DidRequestAlert() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestAlert; }
    static i32 static_message_id() { return (int)MessageID::DidRequestAlert; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestAlert"; }

    static OwnPtr<DidRequestAlert> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String message = {};
        if (decoder.decode(message).is_error())
            return {};

        return make<DidRequestAlert>(move(message));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestAlert;

        stream << m_message;

        return buffer;
    }

    const String& message() const { return m_message; }
    String take_message() { return move(m_message); }

private:
    bool m_ipc_message_valid { true };

    String m_message {};

};

class DidRequestConfirmResponse final : public IPC::Message {
public:

    DidRequestConfirmResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestConfirmResponse(DidRequestConfirmResponse const&) = default;
    DidRequestConfirmResponse(DidRequestConfirmResponse&&) = default;
    DidRequestConfirmResponse& operator=(DidRequestConfirmResponse const&) = default;
    DidRequestConfirmResponse(bool result) : m_result(move(result)) {}
    virtual ~DidRequestConfirmResponse() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestConfirmResponse; }
    static i32 static_message_id() { return (int)MessageID::DidRequestConfirmResponse; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestConfirmResponse"; }

    static OwnPtr<DidRequestConfirmResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool result = false;
        if (decoder.decode(result).is_error())
            return {};

        return make<DidRequestConfirmResponse>(move(result));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestConfirmResponse;

        stream << m_result;

        return buffer;
    }

    const bool& result() const { return m_result; }
    bool take_result() { return move(m_result); }

private:
    bool m_ipc_message_valid { true };

    bool m_result {};

};

class DidRequestConfirm final : public IPC::Message {
public:

   typedef class DidRequestConfirmResponse ResponseType;

    DidRequestConfirm(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestConfirm(DidRequestConfirm const&) = default;
    DidRequestConfirm(DidRequestConfirm&&) = default;
    DidRequestConfirm& operator=(DidRequestConfirm const&) = default;
    DidRequestConfirm(String message) : m_message(move(message)) {}
    virtual ~DidRequestConfirm() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestConfirm; }
    static i32 static_message_id() { return (int)MessageID::DidRequestConfirm; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestConfirm"; }

    static OwnPtr<DidRequestConfirm> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String message = {};
        if (decoder.decode(message).is_error())
            return {};

        return make<DidRequestConfirm>(move(message));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestConfirm;

        stream << m_message;

        return buffer;
    }

    const String& message() const { return m_message; }
    String take_message() { return move(m_message); }

private:
    bool m_ipc_message_valid { true };

    String m_message {};

};

class DidRequestPromptResponse final : public IPC::Message {
public:

    DidRequestPromptResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestPromptResponse(DidRequestPromptResponse const&) = default;
    DidRequestPromptResponse(DidRequestPromptResponse&&) = default;
    DidRequestPromptResponse& operator=(DidRequestPromptResponse const&) = default;
    DidRequestPromptResponse(String response) : m_response(move(response)) {}
    virtual ~DidRequestPromptResponse() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestPromptResponse; }
    static i32 static_message_id() { return (int)MessageID::DidRequestPromptResponse; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestPromptResponse"; }

    static OwnPtr<DidRequestPromptResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String response = {};
        if (decoder.decode(response).is_error())
            return {};

        return make<DidRequestPromptResponse>(move(response));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestPromptResponse;

        stream << m_response;

        return buffer;
    }

    const String& response() const { return m_response; }
    String take_response() { return move(m_response); }

private:
    bool m_ipc_message_valid { true };

    String m_response {};

};

class DidRequestPrompt final : public IPC::Message {
public:

   typedef class DidRequestPromptResponse ResponseType;

    DidRequestPrompt(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestPrompt(DidRequestPrompt const&) = default;
    DidRequestPrompt(DidRequestPrompt&&) = default;
    DidRequestPrompt& operator=(DidRequestPrompt const&) = default;
    DidRequestPrompt(String message, String default_) : m_message(move(message)), m_default_(move(default_)) {}
    virtual ~DidRequestPrompt() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestPrompt; }
    static i32 static_message_id() { return (int)MessageID::DidRequestPrompt; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestPrompt"; }

    static OwnPtr<DidRequestPrompt> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String message = {};
        if (decoder.decode(message).is_error())
            return {};

        String default_ = {};
        if (decoder.decode(default_).is_error())
            return {};

        return make<DidRequestPrompt>(move(message), move(default_));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestPrompt;

        stream << m_message;

        stream << m_default_;

        return buffer;
    }

    const String& message() const { return m_message; }
    String take_message() { return move(m_message); }

    const String& default_() const { return m_default_; }
    String take_default_() { return move(m_default_); }

private:
    bool m_ipc_message_valid { true };

    String m_message {};

    String m_default_ {};

};

class DidGetSource final : public IPC::Message {
public:

    DidGetSource(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidGetSource(DidGetSource const&) = default;
    DidGetSource(DidGetSource&&) = default;
    DidGetSource& operator=(DidGetSource const&) = default;
    DidGetSource(URL url, String source) : m_url(move(url)), m_source(move(source)) {}
    virtual ~DidGetSource() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidGetSource; }
    static i32 static_message_id() { return (int)MessageID::DidGetSource; }
    virtual const char* message_name() const override { return "WebContentClient::DidGetSource"; }

    static OwnPtr<DidGetSource> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String source = {};
        if (decoder.decode(source).is_error())
            return {};

        return make<DidGetSource>(move(url), move(source));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidGetSource;

        stream << m_url;

        stream << m_source;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& source() const { return m_source; }
    String take_source() { return move(m_source); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    String m_source {};

};

class DidGetDomTree final : public IPC::Message {
public:

    DidGetDomTree(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidGetDomTree(DidGetDomTree const&) = default;
    DidGetDomTree(DidGetDomTree&&) = default;
    DidGetDomTree& operator=(DidGetDomTree const&) = default;
    DidGetDomTree(String dom_tree) : m_dom_tree(move(dom_tree)) {}
    virtual ~DidGetDomTree() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidGetDomTree; }
    static i32 static_message_id() { return (int)MessageID::DidGetDomTree; }
    virtual const char* message_name() const override { return "WebContentClient::DidGetDomTree"; }

    static OwnPtr<DidGetDomTree> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String dom_tree = {};
        if (decoder.decode(dom_tree).is_error())
            return {};

        return make<DidGetDomTree>(move(dom_tree));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidGetDomTree;

        stream << m_dom_tree;

        return buffer;
    }

    const String& dom_tree() const { return m_dom_tree; }
    String take_dom_tree() { return move(m_dom_tree); }

private:
    bool m_ipc_message_valid { true };

    String m_dom_tree {};

};

class DidGetDomNodeProperties final : public IPC::Message {
public:

    DidGetDomNodeProperties(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidGetDomNodeProperties(DidGetDomNodeProperties const&) = default;
    DidGetDomNodeProperties(DidGetDomNodeProperties&&) = default;
    DidGetDomNodeProperties& operator=(DidGetDomNodeProperties const&) = default;
    DidGetDomNodeProperties(i32 node_id, String specified_style, String computed_style, String custom_properties, String node_box_sizing_json) : m_node_id(move(node_id)), m_specified_style(move(specified_style)), m_computed_style(move(computed_style)), m_custom_properties(move(custom_properties)), m_node_box_sizing_json(move(node_box_sizing_json)) {}
    virtual ~DidGetDomNodeProperties() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidGetDomNodeProperties; }
    static i32 static_message_id() { return (int)MessageID::DidGetDomNodeProperties; }
    virtual const char* message_name() const override { return "WebContentClient::DidGetDomNodeProperties"; }

    static OwnPtr<DidGetDomNodeProperties> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 node_id = {};
        if (decoder.decode(node_id).is_error())
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

        String node_box_sizing_json = {};
        if (decoder.decode(node_box_sizing_json).is_error())
            return {};

        return make<DidGetDomNodeProperties>(move(node_id), move(specified_style), move(computed_style), move(custom_properties), move(node_box_sizing_json));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidGetDomNodeProperties;

        stream << m_node_id;

        stream << m_specified_style;

        stream << m_computed_style;

        stream << m_custom_properties;

        stream << m_node_box_sizing_json;

        return buffer;
    }

    const i32& node_id() const { return m_node_id; }
    i32 take_node_id() { return move(m_node_id); }

    const String& specified_style() const { return m_specified_style; }
    String take_specified_style() { return move(m_specified_style); }

    const String& computed_style() const { return m_computed_style; }
    String take_computed_style() { return move(m_computed_style); }

    const String& custom_properties() const { return m_custom_properties; }
    String take_custom_properties() { return move(m_custom_properties); }

    const String& node_box_sizing_json() const { return m_node_box_sizing_json; }
    String take_node_box_sizing_json() { return move(m_node_box_sizing_json); }

private:
    bool m_ipc_message_valid { true };

    i32 m_node_id {};

    String m_specified_style {};

    String m_computed_style {};

    String m_custom_properties {};

    String m_node_box_sizing_json {};

};

class DidChangeFavicon final : public IPC::Message {
public:

    DidChangeFavicon(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidChangeFavicon(DidChangeFavicon const&) = default;
    DidChangeFavicon(DidChangeFavicon&&) = default;
    DidChangeFavicon& operator=(DidChangeFavicon const&) = default;
    DidChangeFavicon(Gfx::ShareableBitmap favicon) : m_favicon(move(favicon)) {}
    virtual ~DidChangeFavicon() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidChangeFavicon; }
    static i32 static_message_id() { return (int)MessageID::DidChangeFavicon; }
    virtual const char* message_name() const override { return "WebContentClient::DidChangeFavicon"; }

    static OwnPtr<DidChangeFavicon> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap favicon = {};
        if (decoder.decode(favicon).is_error())
            return {};

        return make<DidChangeFavicon>(move(favicon));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidChangeFavicon;

        stream << m_favicon;

        return buffer;
    }

    const Gfx::ShareableBitmap& favicon() const { return m_favicon; }
    Gfx::ShareableBitmap take_favicon() { return move(m_favicon); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_favicon {};

};

class DidRequestCookieResponse final : public IPC::Message {
public:

    DidRequestCookieResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestCookieResponse(DidRequestCookieResponse const&) = default;
    DidRequestCookieResponse(DidRequestCookieResponse&&) = default;
    DidRequestCookieResponse& operator=(DidRequestCookieResponse const&) = default;
    DidRequestCookieResponse(String cookie) : m_cookie(move(cookie)) {}
    virtual ~DidRequestCookieResponse() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestCookieResponse; }
    static i32 static_message_id() { return (int)MessageID::DidRequestCookieResponse; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestCookieResponse"; }

    static OwnPtr<DidRequestCookieResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String cookie = {};
        if (decoder.decode(cookie).is_error())
            return {};

        return make<DidRequestCookieResponse>(move(cookie));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestCookieResponse;

        stream << m_cookie;

        return buffer;
    }

    const String& cookie() const { return m_cookie; }
    String take_cookie() { return move(m_cookie); }

private:
    bool m_ipc_message_valid { true };

    String m_cookie {};

};

class DidRequestCookie final : public IPC::Message {
public:

   typedef class DidRequestCookieResponse ResponseType;

    DidRequestCookie(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidRequestCookie(DidRequestCookie const&) = default;
    DidRequestCookie(DidRequestCookie&&) = default;
    DidRequestCookie& operator=(DidRequestCookie const&) = default;
    DidRequestCookie(URL url, u8 source) : m_url(move(url)), m_source(move(source)) {}
    virtual ~DidRequestCookie() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidRequestCookie; }
    static i32 static_message_id() { return (int)MessageID::DidRequestCookie; }
    virtual const char* message_name() const override { return "WebContentClient::DidRequestCookie"; }

    static OwnPtr<DidRequestCookie> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        u8 source = {};
        if (decoder.decode(source).is_error())
            return {};

        return make<DidRequestCookie>(move(url), move(source));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidRequestCookie;

        stream << m_url;

        stream << m_source;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const u8& source() const { return m_source; }
    u8 take_source() { return move(m_source); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    u8 m_source {};

};

class DidSetCookie final : public IPC::Message {
public:

    DidSetCookie(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidSetCookie(DidSetCookie const&) = default;
    DidSetCookie(DidSetCookie&&) = default;
    DidSetCookie& operator=(DidSetCookie const&) = default;
    DidSetCookie(URL url, Web::Cookie::ParsedCookie cookie, u8 source) : m_url(move(url)), m_cookie(move(cookie)), m_source(move(source)) {}
    virtual ~DidSetCookie() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidSetCookie; }
    static i32 static_message_id() { return (int)MessageID::DidSetCookie; }
    virtual const char* message_name() const override { return "WebContentClient::DidSetCookie"; }

    static OwnPtr<DidSetCookie> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        Web::Cookie::ParsedCookie cookie = {};
        if (decoder.decode(cookie).is_error())
            return {};

        u8 source = {};
        if (decoder.decode(source).is_error())
            return {};

        return make<DidSetCookie>(move(url), move(cookie), move(source));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidSetCookie;

        stream << m_url;

        stream << m_cookie;

        stream << m_source;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const Web::Cookie::ParsedCookie& cookie() const { return m_cookie; }
    Web::Cookie::ParsedCookie take_cookie() { return move(m_cookie); }

    const u8& source() const { return m_source; }
    u8 take_source() { return move(m_source); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    Web::Cookie::ParsedCookie m_cookie {};

    u8 m_source {};

};

class DidUpdateResourceCount final : public IPC::Message {
public:

    DidUpdateResourceCount(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidUpdateResourceCount(DidUpdateResourceCount const&) = default;
    DidUpdateResourceCount(DidUpdateResourceCount&&) = default;
    DidUpdateResourceCount& operator=(DidUpdateResourceCount const&) = default;
    DidUpdateResourceCount(i32 count_waiting) : m_count_waiting(move(count_waiting)) {}
    virtual ~DidUpdateResourceCount() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidUpdateResourceCount; }
    static i32 static_message_id() { return (int)MessageID::DidUpdateResourceCount; }
    virtual const char* message_name() const override { return "WebContentClient::DidUpdateResourceCount"; }

    static OwnPtr<DidUpdateResourceCount> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 count_waiting = {};
        if (decoder.decode(count_waiting).is_error())
            return {};

        return make<DidUpdateResourceCount>(move(count_waiting));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidUpdateResourceCount;

        stream << m_count_waiting;

        return buffer;
    }

    const i32& count_waiting() const { return m_count_waiting; }
    i32 take_count_waiting() { return move(m_count_waiting); }

private:
    bool m_ipc_message_valid { true };

    i32 m_count_waiting {};

};

class DidOutputJsConsoleMessage final : public IPC::Message {
public:

    DidOutputJsConsoleMessage(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidOutputJsConsoleMessage(DidOutputJsConsoleMessage const&) = default;
    DidOutputJsConsoleMessage(DidOutputJsConsoleMessage&&) = default;
    DidOutputJsConsoleMessage& operator=(DidOutputJsConsoleMessage const&) = default;
    DidOutputJsConsoleMessage(i32 message_index) : m_message_index(move(message_index)) {}
    virtual ~DidOutputJsConsoleMessage() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidOutputJsConsoleMessage; }
    static i32 static_message_id() { return (int)MessageID::DidOutputJsConsoleMessage; }
    virtual const char* message_name() const override { return "WebContentClient::DidOutputJsConsoleMessage"; }

    static OwnPtr<DidOutputJsConsoleMessage> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 message_index = {};
        if (decoder.decode(message_index).is_error())
            return {};

        return make<DidOutputJsConsoleMessage>(move(message_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidOutputJsConsoleMessage;

        stream << m_message_index;

        return buffer;
    }

    const i32& message_index() const { return m_message_index; }
    i32 take_message_index() { return move(m_message_index); }

private:
    bool m_ipc_message_valid { true };

    i32 m_message_index {};

};

class DidGetJsConsoleMessages final : public IPC::Message {
public:

    DidGetJsConsoleMessages(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DidGetJsConsoleMessages(DidGetJsConsoleMessages const&) = default;
    DidGetJsConsoleMessages(DidGetJsConsoleMessages&&) = default;
    DidGetJsConsoleMessages& operator=(DidGetJsConsoleMessages const&) = default;
    DidGetJsConsoleMessages(i32 start_index, Vector<String> message_types, Vector<String> messages) : m_start_index(move(start_index)), m_message_types(move(message_types)), m_messages(move(messages)) {}
    virtual ~DidGetJsConsoleMessages() override {}

    virtual u32 endpoint_magic() const override { return 2565717604; }
    virtual i32 message_id() const override { return (int)MessageID::DidGetJsConsoleMessages; }
    static i32 static_message_id() { return (int)MessageID::DidGetJsConsoleMessages; }
    virtual const char* message_name() const override { return "WebContentClient::DidGetJsConsoleMessages"; }

    static OwnPtr<DidGetJsConsoleMessages> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 start_index = {};
        if (decoder.decode(start_index).is_error())
            return {};

        Vector<String> message_types = {};
        if (decoder.decode(message_types).is_error())
            return {};

        Vector<String> messages = {};
        if (decoder.decode(messages).is_error())
            return {};

        return make<DidGetJsConsoleMessages>(move(start_index), move(message_types), move(messages));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DidGetJsConsoleMessages;

        stream << m_start_index;

        stream << m_message_types;

        stream << m_messages;

        return buffer;
    }

    const i32& start_index() const { return m_start_index; }
    i32 take_start_index() { return move(m_start_index); }

    const Vector<String>& message_types() const { return m_message_types; }
    Vector<String> take_message_types() { return move(m_message_types); }

    const Vector<String>& messages() const { return m_messages; }
    Vector<String> take_messages() { return move(m_messages); }

private:
    bool m_ipc_message_valid { true };

    i32 m_start_index {};

    Vector<String> m_message_types {};

    Vector<String> m_messages {};

};

} // namespace Messages::WebContentClient

template<typename LocalEndpoint, typename PeerEndpoint>
class WebContentClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WebContentClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_did_start_loading(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidStartLoading { move(url) });

    }

    void async_did_finish_loading(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidFinishLoading { move(url) });

    }

    void async_did_paint(
Gfx::IntRect content_rect, i32 bitmap_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidPaint { move(content_rect), bitmap_id });

    }

    void async_did_invalidate_content_rect(
Gfx::IntRect content_rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidInvalidateContentRect { move(content_rect) });

    }

    void async_did_change_selection(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidChangeSelection {  });

    }

    void async_did_request_cursor_change(
i32 cursor_type) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestCursorChange { cursor_type });

    }

    void async_did_layout(
Gfx::IntSize content_size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidLayout { move(content_size) });

    }

    void async_did_change_title(
String title) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidChangeTitle { move(title) });

    }

    void async_did_request_scroll(
i32 x_delta, i32 y_delta) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestScroll { x_delta, y_delta });

    }

    void async_did_request_scroll_to(
Gfx::IntPoint scroll_position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestScrollTo { move(scroll_position) });

    }

    void async_did_request_scroll_into_view(
Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestScrollIntoView { move(rect) });

    }

    void async_did_enter_tooltip_area(
Gfx::IntPoint content_position, String title) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidEnterTooltipArea { move(content_position), move(title) });

    }

    void async_did_leave_tooltip_area(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidLeaveTooltipArea {  });

    }

    void async_did_hover_link(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidHoverLink { move(url) });

    }

    void async_did_unhover_link(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidUnhoverLink {  });

    }

    void async_did_click_link(
URL url, String target, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidClickLink { move(url), move(target), modifiers });

    }

    void async_did_middle_click_link(
URL url, String target, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidMiddleClickLink { move(url), move(target), modifiers });

    }

    void async_did_request_context_menu(
Gfx::IntPoint content_position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestContextMenu { move(content_position) });

    }

    void async_did_request_link_context_menu(
Gfx::IntPoint content_position, URL url, String target, unsigned modifiers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestLinkContextMenu { move(content_position), move(url), move(target), modifiers });

    }

    void async_did_request_image_context_menu(
Gfx::IntPoint content_position, URL url, String target, unsigned modifiers, Gfx::ShareableBitmap bitmap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestImageContextMenu { move(content_position), move(url), move(target), modifiers, move(bitmap) });

    }

    void did_request_alert(
String message) {
        (void) m_connection.template send_sync<Messages::WebContentClient::DidRequestAlert>(move(message));
    }

    void async_did_request_alert(
String message) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestAlert { move(message) });

    }

    IPC::IPCErrorOr<void> try_did_request_alert(
String message) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentClient::DidRequestAlert>(move(message));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    bool did_request_confirm(
String message) {
        return m_connection.template send_sync<Messages::WebContentClient::DidRequestConfirm>(move(message))->take_result();
    }

    void async_did_request_confirm(
String message) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestConfirm { move(message) });

    }

    IPC::IPCErrorOr<bool> try_did_request_confirm(
String message) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentClient::DidRequestConfirm>(move(message));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    String did_request_prompt(
String message, String default_) {
        return m_connection.template send_sync<Messages::WebContentClient::DidRequestPrompt>(move(message), move(default_))->take_response();
    }

    void async_did_request_prompt(
String message, String default_) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestPrompt { move(message), move(default_) });

    }

    IPC::IPCErrorOr<String> try_did_request_prompt(
String message, String default_) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentClient::DidRequestPrompt>(move(message), move(default_));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_did_get_source(
URL url, String source) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidGetSource { move(url), move(source) });

    }

    void async_did_get_dom_tree(
String dom_tree) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidGetDomTree { move(dom_tree) });

    }

    void async_did_get_dom_node_properties(
i32 node_id, String specified_style, String computed_style, String custom_properties, String node_box_sizing_json) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidGetDomNodeProperties { node_id, move(specified_style), move(computed_style), move(custom_properties), move(node_box_sizing_json) });

    }

    void async_did_change_favicon(
Gfx::ShareableBitmap favicon) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidChangeFavicon { move(favicon) });

    }

    String did_request_cookie(
URL url, u8 source) {
        return m_connection.template send_sync<Messages::WebContentClient::DidRequestCookie>(move(url), source)->take_cookie();
    }

    void async_did_request_cookie(
URL url, u8 source) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidRequestCookie { move(url), source });

    }

    IPC::IPCErrorOr<String> try_did_request_cookie(
URL url, u8 source) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebContentClient::DidRequestCookie>(move(url), source);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_did_set_cookie(
URL url, Web::Cookie::ParsedCookie cookie, u8 source) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidSetCookie { move(url), move(cookie), source });

    }

    void async_did_update_resource_count(
i32 count_waiting) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidUpdateResourceCount { count_waiting });

    }

    void async_did_output_js_console_message(
i32 message_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidOutputJsConsoleMessage { message_index });

    }

    void async_did_get_js_console_messages(
i32 start_index, Vector<String> message_types, Vector<String> messages) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebContentClient::DidGetJsConsoleMessages { start_index, move(message_types), move(messages) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WebContentClientProxy;
class WebContentClientStub;

class WebContentClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WebContentClientProxy<LocalEndpoint, WebContentClientEndpoint>;
    using Stub = WebContentClientStub;

    static u32 static_magic() { return 2565717604; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 2565717604) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WebContentClient::MessageID::DidStartLoading:
            message = Messages::WebContentClient::DidStartLoading::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidFinishLoading:
            message = Messages::WebContentClient::DidFinishLoading::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidPaint:
            message = Messages::WebContentClient::DidPaint::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidInvalidateContentRect:
            message = Messages::WebContentClient::DidInvalidateContentRect::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidChangeSelection:
            message = Messages::WebContentClient::DidChangeSelection::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestCursorChange:
            message = Messages::WebContentClient::DidRequestCursorChange::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidLayout:
            message = Messages::WebContentClient::DidLayout::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidChangeTitle:
            message = Messages::WebContentClient::DidChangeTitle::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestScroll:
            message = Messages::WebContentClient::DidRequestScroll::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestScrollTo:
            message = Messages::WebContentClient::DidRequestScrollTo::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestScrollIntoView:
            message = Messages::WebContentClient::DidRequestScrollIntoView::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidEnterTooltipArea:
            message = Messages::WebContentClient::DidEnterTooltipArea::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidLeaveTooltipArea:
            message = Messages::WebContentClient::DidLeaveTooltipArea::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidHoverLink:
            message = Messages::WebContentClient::DidHoverLink::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidUnhoverLink:
            message = Messages::WebContentClient::DidUnhoverLink::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidClickLink:
            message = Messages::WebContentClient::DidClickLink::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidMiddleClickLink:
            message = Messages::WebContentClient::DidMiddleClickLink::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestContextMenu:
            message = Messages::WebContentClient::DidRequestContextMenu::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestLinkContextMenu:
            message = Messages::WebContentClient::DidRequestLinkContextMenu::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestImageContextMenu:
            message = Messages::WebContentClient::DidRequestImageContextMenu::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestAlert:
            message = Messages::WebContentClient::DidRequestAlert::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestAlertResponse:
            message = Messages::WebContentClient::DidRequestAlertResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestConfirm:
            message = Messages::WebContentClient::DidRequestConfirm::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestConfirmResponse:
            message = Messages::WebContentClient::DidRequestConfirmResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestPrompt:
            message = Messages::WebContentClient::DidRequestPrompt::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestPromptResponse:
            message = Messages::WebContentClient::DidRequestPromptResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidGetSource:
            message = Messages::WebContentClient::DidGetSource::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidGetDomTree:
            message = Messages::WebContentClient::DidGetDomTree::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidGetDomNodeProperties:
            message = Messages::WebContentClient::DidGetDomNodeProperties::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidChangeFavicon:
            message = Messages::WebContentClient::DidChangeFavicon::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestCookie:
            message = Messages::WebContentClient::DidRequestCookie::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidRequestCookieResponse:
            message = Messages::WebContentClient::DidRequestCookieResponse::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidSetCookie:
            message = Messages::WebContentClient::DidSetCookie::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidUpdateResourceCount:
            message = Messages::WebContentClient::DidUpdateResourceCount::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidOutputJsConsoleMessage:
            message = Messages::WebContentClient::DidOutputJsConsoleMessage::decode(stream, socket);
            break;

        case (int)Messages::WebContentClient::MessageID::DidGetJsConsoleMessages:
            message = Messages::WebContentClient::DidGetJsConsoleMessages::decode(stream, socket);
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

class WebContentClientStub : public IPC::Stub {
public:
    WebContentClientStub() { }
    virtual ~WebContentClientStub() override { }

    virtual u32 magic() const override { return 2565717604; }
    virtual String name() const override { return "WebContentClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WebContentClient::MessageID::DidStartLoading: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidStartLoading&>(message);
            did_start_loading(request.url());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidFinishLoading: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidFinishLoading&>(message);
            did_finish_loading(request.url());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidPaint: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidPaint&>(message);
            did_paint(request.content_rect(), request.bitmap_id());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidInvalidateContentRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidInvalidateContentRect&>(message);
            did_invalidate_content_rect(request.content_rect());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidChangeSelection: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidChangeSelection&>(message);
            did_change_selection();
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestCursorChange: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestCursorChange&>(message);
            did_request_cursor_change(request.cursor_type());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidLayout: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidLayout&>(message);
            did_layout(request.content_size());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidChangeTitle: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidChangeTitle&>(message);
            did_change_title(request.title());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestScroll: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestScroll&>(message);
            did_request_scroll(request.x_delta(), request.y_delta());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestScrollTo: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestScrollTo&>(message);
            did_request_scroll_to(request.scroll_position());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestScrollIntoView: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestScrollIntoView&>(message);
            did_request_scroll_into_view(request.rect());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidEnterTooltipArea: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidEnterTooltipArea&>(message);
            did_enter_tooltip_area(request.content_position(), request.title());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidLeaveTooltipArea: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidLeaveTooltipArea&>(message);
            did_leave_tooltip_area();
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidHoverLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidHoverLink&>(message);
            did_hover_link(request.url());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidUnhoverLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidUnhoverLink&>(message);
            did_unhover_link();
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidClickLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidClickLink&>(message);
            did_click_link(request.url(), request.target(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidMiddleClickLink: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidMiddleClickLink&>(message);
            did_middle_click_link(request.url(), request.target(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestContextMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestContextMenu&>(message);
            did_request_context_menu(request.content_position());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestLinkContextMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestLinkContextMenu&>(message);
            did_request_link_context_menu(request.content_position(), request.url(), request.target(), request.modifiers());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestImageContextMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestImageContextMenu&>(message);
            did_request_image_context_menu(request.content_position(), request.url(), request.target(), request.modifiers(), request.bitmap());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestAlert: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestAlert&>(message);
            did_request_alert(request.message());
            auto response = Messages::WebContentClient::DidRequestAlertResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestConfirm: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestConfirm&>(message);
            auto response = did_request_confirm(request.message());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestPrompt: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestPrompt&>(message);
            auto response = did_request_prompt(request.message(), request.default_());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentClient::MessageID::DidGetSource: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidGetSource&>(message);
            did_get_source(request.url(), request.source());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidGetDomTree: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidGetDomTree&>(message);
            did_get_dom_tree(request.dom_tree());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidGetDomNodeProperties: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidGetDomNodeProperties&>(message);
            did_get_dom_node_properties(request.node_id(), request.specified_style(), request.computed_style(), request.custom_properties(), request.node_box_sizing_json());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidChangeFavicon: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidChangeFavicon&>(message);
            did_change_favicon(request.favicon());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidRequestCookie: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidRequestCookie&>(message);
            auto response = did_request_cookie(request.url(), request.source());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebContentClient::MessageID::DidSetCookie: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidSetCookie&>(message);
            did_set_cookie(request.url(), request.cookie(), request.source());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidUpdateResourceCount: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidUpdateResourceCount&>(message);
            did_update_resource_count(request.count_waiting());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidOutputJsConsoleMessage: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidOutputJsConsoleMessage&>(message);
            did_output_js_console_message(request.message_index());
            return {};

        }

        case (int)Messages::WebContentClient::MessageID::DidGetJsConsoleMessages: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebContentClient::DidGetJsConsoleMessages&>(message);
            did_get_js_console_messages(request.start_index(), request.message_types(), request.messages());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void did_start_loading(
[[maybe_unused]] URL const& url) = 0;

    virtual void did_finish_loading(
[[maybe_unused]] URL const& url) = 0;

    virtual void did_paint(
[[maybe_unused]] Gfx::IntRect const& content_rect, [[maybe_unused]] i32 bitmap_id) = 0;

    virtual void did_invalidate_content_rect(
[[maybe_unused]] Gfx::IntRect const& content_rect) = 0;

    virtual void did_change_selection(
) = 0;

    virtual void did_request_cursor_change(
[[maybe_unused]] i32 cursor_type) = 0;

    virtual void did_layout(
[[maybe_unused]] Gfx::IntSize const& content_size) = 0;

    virtual void did_change_title(
[[maybe_unused]] String const& title) = 0;

    virtual void did_request_scroll(
[[maybe_unused]] i32 x_delta, [[maybe_unused]] i32 y_delta) = 0;

    virtual void did_request_scroll_to(
[[maybe_unused]] Gfx::IntPoint const& scroll_position) = 0;

    virtual void did_request_scroll_into_view(
[[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual void did_enter_tooltip_area(
[[maybe_unused]] Gfx::IntPoint const& content_position, [[maybe_unused]] String const& title) = 0;

    virtual void did_leave_tooltip_area(
) = 0;

    virtual void did_hover_link(
[[maybe_unused]] URL const& url) = 0;

    virtual void did_unhover_link(
) = 0;

    virtual void did_click_link(
[[maybe_unused]] URL const& url, [[maybe_unused]] String const& target, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void did_middle_click_link(
[[maybe_unused]] URL const& url, [[maybe_unused]] String const& target, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void did_request_context_menu(
[[maybe_unused]] Gfx::IntPoint const& content_position) = 0;

    virtual void did_request_link_context_menu(
[[maybe_unused]] Gfx::IntPoint const& content_position, [[maybe_unused]] URL const& url, [[maybe_unused]] String const& target, [[maybe_unused]] unsigned modifiers) = 0;

    virtual void did_request_image_context_menu(
[[maybe_unused]] Gfx::IntPoint const& content_position, [[maybe_unused]] URL const& url, [[maybe_unused]] String const& target, [[maybe_unused]] unsigned modifiers, [[maybe_unused]] Gfx::ShareableBitmap const& bitmap) = 0;

    virtual void did_request_alert(
[[maybe_unused]] String const& message) = 0;

    virtual Messages::WebContentClient::DidRequestConfirmResponse did_request_confirm(
[[maybe_unused]] String const& message) = 0;

    virtual Messages::WebContentClient::DidRequestPromptResponse did_request_prompt(
[[maybe_unused]] String const& message, [[maybe_unused]] String const& default_) = 0;

    virtual void did_get_source(
[[maybe_unused]] URL const& url, [[maybe_unused]] String const& source) = 0;

    virtual void did_get_dom_tree(
[[maybe_unused]] String const& dom_tree) = 0;

    virtual void did_get_dom_node_properties(
[[maybe_unused]] i32 node_id, [[maybe_unused]] String const& specified_style, [[maybe_unused]] String const& computed_style, [[maybe_unused]] String const& custom_properties, [[maybe_unused]] String const& node_box_sizing_json) = 0;

    virtual void did_change_favicon(
[[maybe_unused]] Gfx::ShareableBitmap const& favicon) = 0;

    virtual Messages::WebContentClient::DidRequestCookieResponse did_request_cookie(
[[maybe_unused]] URL const& url, [[maybe_unused]] u8 source) = 0;

    virtual void did_set_cookie(
[[maybe_unused]] URL const& url, [[maybe_unused]] Web::Cookie::ParsedCookie const& cookie, [[maybe_unused]] u8 source) = 0;

    virtual void did_update_resource_count(
[[maybe_unused]] i32 count_waiting) = 0;

    virtual void did_output_js_console_message(
[[maybe_unused]] i32 message_index) = 0;

    virtual void did_get_js_console_messages(
[[maybe_unused]] i32 start_index, [[maybe_unused]] Vector<String> const& message_types, [[maybe_unused]] Vector<String> const& messages) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

