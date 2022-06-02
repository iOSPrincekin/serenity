#pragma once
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

namespace Messages::ConfigClient {

enum class MessageID : i32 {
    NotifyChangedStringValue = 1,
    NotifyChangedI32Value = 2,
    NotifyChangedBoolValue = 3,
    NotifyRemovedKey = 4,
};

class NotifyChangedStringValue final : public IPC::Message {
public:

    NotifyChangedStringValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    NotifyChangedStringValue(NotifyChangedStringValue const&) = default;
    NotifyChangedStringValue(NotifyChangedStringValue&&) = default;
    NotifyChangedStringValue& operator=(NotifyChangedStringValue const&) = default;
    NotifyChangedStringValue(String domain, String group, String key, String value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~NotifyChangedStringValue() override {}

    virtual u32 endpoint_magic() const override { return 1419546125; }
    virtual i32 message_id() const override { return (int)MessageID::NotifyChangedStringValue; }
    static i32 static_message_id() { return (int)MessageID::NotifyChangedStringValue; }
    virtual const char* message_name() const override { return "ConfigClient::NotifyChangedStringValue"; }

    static OwnPtr<NotifyChangedStringValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        String group = {};
        if (decoder.decode(group).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        String value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<NotifyChangedStringValue>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::NotifyChangedStringValue;

        stream << m_domain;

        stream << m_group;

        stream << m_key;

        stream << m_value;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

    const String& group() const { return m_group; }
    String take_group() { return move(m_group); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

    const String& value() const { return m_value; }
    String take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

    String m_group {};

    String m_key {};

    String m_value {};

};

class NotifyChangedI32Value final : public IPC::Message {
public:

    NotifyChangedI32Value(decltype(nullptr)) : m_ipc_message_valid(false) { }
    NotifyChangedI32Value(NotifyChangedI32Value const&) = default;
    NotifyChangedI32Value(NotifyChangedI32Value&&) = default;
    NotifyChangedI32Value& operator=(NotifyChangedI32Value const&) = default;
    NotifyChangedI32Value(String domain, String group, String key, i32 value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~NotifyChangedI32Value() override {}

    virtual u32 endpoint_magic() const override { return 1419546125; }
    virtual i32 message_id() const override { return (int)MessageID::NotifyChangedI32Value; }
    static i32 static_message_id() { return (int)MessageID::NotifyChangedI32Value; }
    virtual const char* message_name() const override { return "ConfigClient::NotifyChangedI32Value"; }

    static OwnPtr<NotifyChangedI32Value> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        String group = {};
        if (decoder.decode(group).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        i32 value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<NotifyChangedI32Value>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::NotifyChangedI32Value;

        stream << m_domain;

        stream << m_group;

        stream << m_key;

        stream << m_value;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

    const String& group() const { return m_group; }
    String take_group() { return move(m_group); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

    const i32& value() const { return m_value; }
    i32 take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

    String m_group {};

    String m_key {};

    i32 m_value {};

};

class NotifyChangedBoolValue final : public IPC::Message {
public:

    NotifyChangedBoolValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    NotifyChangedBoolValue(NotifyChangedBoolValue const&) = default;
    NotifyChangedBoolValue(NotifyChangedBoolValue&&) = default;
    NotifyChangedBoolValue& operator=(NotifyChangedBoolValue const&) = default;
    NotifyChangedBoolValue(String domain, String group, String key, bool value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~NotifyChangedBoolValue() override {}

    virtual u32 endpoint_magic() const override { return 1419546125; }
    virtual i32 message_id() const override { return (int)MessageID::NotifyChangedBoolValue; }
    static i32 static_message_id() { return (int)MessageID::NotifyChangedBoolValue; }
    virtual const char* message_name() const override { return "ConfigClient::NotifyChangedBoolValue"; }

    static OwnPtr<NotifyChangedBoolValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        String group = {};
        if (decoder.decode(group).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        bool value = false;
        if (decoder.decode(value).is_error())
            return {};

        return make<NotifyChangedBoolValue>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::NotifyChangedBoolValue;

        stream << m_domain;

        stream << m_group;

        stream << m_key;

        stream << m_value;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

    const String& group() const { return m_group; }
    String take_group() { return move(m_group); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

    const bool& value() const { return m_value; }
    bool take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

    String m_group {};

    String m_key {};

    bool m_value {};

};

class NotifyRemovedKey final : public IPC::Message {
public:

    NotifyRemovedKey(decltype(nullptr)) : m_ipc_message_valid(false) { }
    NotifyRemovedKey(NotifyRemovedKey const&) = default;
    NotifyRemovedKey(NotifyRemovedKey&&) = default;
    NotifyRemovedKey& operator=(NotifyRemovedKey const&) = default;
    NotifyRemovedKey(String domain, String group, String key) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)) {}
    virtual ~NotifyRemovedKey() override {}

    virtual u32 endpoint_magic() const override { return 1419546125; }
    virtual i32 message_id() const override { return (int)MessageID::NotifyRemovedKey; }
    static i32 static_message_id() { return (int)MessageID::NotifyRemovedKey; }
    virtual const char* message_name() const override { return "ConfigClient::NotifyRemovedKey"; }

    static OwnPtr<NotifyRemovedKey> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        String group = {};
        if (decoder.decode(group).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        return make<NotifyRemovedKey>(move(domain), move(group), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::NotifyRemovedKey;

        stream << m_domain;

        stream << m_group;

        stream << m_key;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

    const String& group() const { return m_group; }
    String take_group() { return move(m_group); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

    String m_group {};

    String m_key {};

};

} // namespace Messages::ConfigClient

template<typename LocalEndpoint, typename PeerEndpoint>
class ConfigClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    ConfigClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_notify_changed_string_value(
String domain, String group, String key, String value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigClient::NotifyChangedStringValue { move(domain), move(group), move(key), move(value) });

    }

    void async_notify_changed_i32_value(
String domain, String group, String key, i32 value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigClient::NotifyChangedI32Value { move(domain), move(group), move(key), value });

    }

    void async_notify_changed_bool_value(
String domain, String group, String key, bool value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigClient::NotifyChangedBoolValue { move(domain), move(group), move(key), value });

    }

    void async_notify_removed_key(
String domain, String group, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigClient::NotifyRemovedKey { move(domain), move(group), move(key) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class ConfigClientProxy;
class ConfigClientStub;

class ConfigClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = ConfigClientProxy<LocalEndpoint, ConfigClientEndpoint>;
    using Stub = ConfigClientStub;

    static u32 static_magic() { return 1419546125; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1419546125) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::ConfigClient::MessageID::NotifyChangedStringValue:
            message = Messages::ConfigClient::NotifyChangedStringValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigClient::MessageID::NotifyChangedI32Value:
            message = Messages::ConfigClient::NotifyChangedI32Value::decode(stream, socket);
            break;

        case (int)Messages::ConfigClient::MessageID::NotifyChangedBoolValue:
            message = Messages::ConfigClient::NotifyChangedBoolValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigClient::MessageID::NotifyRemovedKey:
            message = Messages::ConfigClient::NotifyRemovedKey::decode(stream, socket);
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

class ConfigClientStub : public IPC::Stub {
public:
    ConfigClientStub() { }
    virtual ~ConfigClientStub() override { }

    virtual u32 magic() const override { return 1419546125; }
    virtual String name() const override { return "ConfigClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::ConfigClient::MessageID::NotifyChangedStringValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigClient::NotifyChangedStringValue&>(message);
            notify_changed_string_value(request.domain(), request.group(), request.key(), request.value());
            return {};

        }

        case (int)Messages::ConfigClient::MessageID::NotifyChangedI32Value: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigClient::NotifyChangedI32Value&>(message);
            notify_changed_i32_value(request.domain(), request.group(), request.key(), request.value());
            return {};

        }

        case (int)Messages::ConfigClient::MessageID::NotifyChangedBoolValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigClient::NotifyChangedBoolValue&>(message);
            notify_changed_bool_value(request.domain(), request.group(), request.key(), request.value());
            return {};

        }

        case (int)Messages::ConfigClient::MessageID::NotifyRemovedKey: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigClient::NotifyRemovedKey&>(message);
            notify_removed_key(request.domain(), request.group(), request.key());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void notify_changed_string_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] String const& value) = 0;

    virtual void notify_changed_i32_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] i32 value) = 0;

    virtual void notify_changed_bool_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] bool value) = 0;

    virtual void notify_removed_key(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

