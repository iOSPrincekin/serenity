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

namespace Messages::ConfigServer {

enum class MessageID : i32 {
    PledgeDomains = 1,
    MonitorDomain = 2,
    ListConfigGroups = 3,
    ListConfigGroupsResponse = 4,
    ListConfigKeys = 5,
    ListConfigKeysResponse = 6,
    ReadStringValue = 7,
    ReadStringValueResponse = 8,
    ReadI32Value = 9,
    ReadI32ValueResponse = 10,
    ReadBoolValue = 11,
    ReadBoolValueResponse = 12,
    WriteStringValue = 13,
    WriteStringValueResponse = 14,
    WriteI32Value = 15,
    WriteI32ValueResponse = 16,
    WriteBoolValue = 17,
    WriteBoolValueResponse = 18,
    RemoveKey = 19,
};

class PledgeDomains final : public IPC::Message {
public:

    PledgeDomains(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PledgeDomains(PledgeDomains const&) = default;
    PledgeDomains(PledgeDomains&&) = default;
    PledgeDomains& operator=(PledgeDomains const&) = default;
    PledgeDomains(Vector<String> domains) : m_domains(move(domains)) {}
    virtual ~PledgeDomains() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::PledgeDomains; }
    static i32 static_message_id() { return (int)MessageID::PledgeDomains; }
    virtual const char* message_name() const override { return "ConfigServer::PledgeDomains"; }

    static OwnPtr<PledgeDomains> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> domains = {};
        if (decoder.decode(domains).is_error())
            return {};

        return make<PledgeDomains>(move(domains));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PledgeDomains;

        stream << m_domains;

        return buffer;
    }

    const Vector<String>& domains() const { return m_domains; }
    Vector<String> take_domains() { return move(m_domains); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_domains {};

};

class MonitorDomain final : public IPC::Message {
public:

    MonitorDomain(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MonitorDomain(MonitorDomain const&) = default;
    MonitorDomain(MonitorDomain&&) = default;
    MonitorDomain& operator=(MonitorDomain const&) = default;
    MonitorDomain(String domain) : m_domain(move(domain)) {}
    virtual ~MonitorDomain() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::MonitorDomain; }
    static i32 static_message_id() { return (int)MessageID::MonitorDomain; }
    virtual const char* message_name() const override { return "ConfigServer::MonitorDomain"; }

    static OwnPtr<MonitorDomain> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        return make<MonitorDomain>(move(domain));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MonitorDomain;

        stream << m_domain;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

};

class ListConfigGroupsResponse final : public IPC::Message {
public:

    ListConfigGroupsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ListConfigGroupsResponse(ListConfigGroupsResponse const&) = default;
    ListConfigGroupsResponse(ListConfigGroupsResponse&&) = default;
    ListConfigGroupsResponse& operator=(ListConfigGroupsResponse const&) = default;
    ListConfigGroupsResponse(Vector<String> groups) : m_groups(move(groups)) {}
    virtual ~ListConfigGroupsResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ListConfigGroupsResponse; }
    static i32 static_message_id() { return (int)MessageID::ListConfigGroupsResponse; }
    virtual const char* message_name() const override { return "ConfigServer::ListConfigGroupsResponse"; }

    static OwnPtr<ListConfigGroupsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> groups = {};
        if (decoder.decode(groups).is_error())
            return {};

        return make<ListConfigGroupsResponse>(move(groups));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ListConfigGroupsResponse;

        stream << m_groups;

        return buffer;
    }

    const Vector<String>& groups() const { return m_groups; }
    Vector<String> take_groups() { return move(m_groups); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_groups {};

};

class ListConfigGroups final : public IPC::Message {
public:

   typedef class ListConfigGroupsResponse ResponseType;

    ListConfigGroups(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ListConfigGroups(ListConfigGroups const&) = default;
    ListConfigGroups(ListConfigGroups&&) = default;
    ListConfigGroups& operator=(ListConfigGroups const&) = default;
    ListConfigGroups(String domain) : m_domain(move(domain)) {}
    virtual ~ListConfigGroups() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ListConfigGroups; }
    static i32 static_message_id() { return (int)MessageID::ListConfigGroups; }
    virtual const char* message_name() const override { return "ConfigServer::ListConfigGroups"; }

    static OwnPtr<ListConfigGroups> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        return make<ListConfigGroups>(move(domain));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ListConfigGroups;

        stream << m_domain;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

};

class ListConfigKeysResponse final : public IPC::Message {
public:

    ListConfigKeysResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ListConfigKeysResponse(ListConfigKeysResponse const&) = default;
    ListConfigKeysResponse(ListConfigKeysResponse&&) = default;
    ListConfigKeysResponse& operator=(ListConfigKeysResponse const&) = default;
    ListConfigKeysResponse(Vector<String> keys) : m_keys(move(keys)) {}
    virtual ~ListConfigKeysResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ListConfigKeysResponse; }
    static i32 static_message_id() { return (int)MessageID::ListConfigKeysResponse; }
    virtual const char* message_name() const override { return "ConfigServer::ListConfigKeysResponse"; }

    static OwnPtr<ListConfigKeysResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> keys = {};
        if (decoder.decode(keys).is_error())
            return {};

        return make<ListConfigKeysResponse>(move(keys));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ListConfigKeysResponse;

        stream << m_keys;

        return buffer;
    }

    const Vector<String>& keys() const { return m_keys; }
    Vector<String> take_keys() { return move(m_keys); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_keys {};

};

class ListConfigKeys final : public IPC::Message {
public:

   typedef class ListConfigKeysResponse ResponseType;

    ListConfigKeys(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ListConfigKeys(ListConfigKeys const&) = default;
    ListConfigKeys(ListConfigKeys&&) = default;
    ListConfigKeys& operator=(ListConfigKeys const&) = default;
    ListConfigKeys(String domain, String group) : m_domain(move(domain)), m_group(move(group)) {}
    virtual ~ListConfigKeys() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ListConfigKeys; }
    static i32 static_message_id() { return (int)MessageID::ListConfigKeys; }
    virtual const char* message_name() const override { return "ConfigServer::ListConfigKeys"; }

    static OwnPtr<ListConfigKeys> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String domain = {};
        if (decoder.decode(domain).is_error())
            return {};

        String group = {};
        if (decoder.decode(group).is_error())
            return {};

        return make<ListConfigKeys>(move(domain), move(group));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ListConfigKeys;

        stream << m_domain;

        stream << m_group;

        return buffer;
    }

    const String& domain() const { return m_domain; }
    String take_domain() { return move(m_domain); }

    const String& group() const { return m_group; }
    String take_group() { return move(m_group); }

private:
    bool m_ipc_message_valid { true };

    String m_domain {};

    String m_group {};

};

class ReadStringValueResponse final : public IPC::Message {
public:

    ReadStringValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadStringValueResponse(ReadStringValueResponse const&) = default;
    ReadStringValueResponse(ReadStringValueResponse&&) = default;
    ReadStringValueResponse& operator=(ReadStringValueResponse const&) = default;
    ReadStringValueResponse(Optional<String> value) : m_value(move(value)) {}
    virtual ~ReadStringValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadStringValueResponse; }
    static i32 static_message_id() { return (int)MessageID::ReadStringValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::ReadStringValueResponse"; }

    static OwnPtr<ReadStringValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Optional<String> value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<ReadStringValueResponse>(move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadStringValueResponse;

        stream << m_value;

        return buffer;
    }

    const Optional<String>& value() const { return m_value; }
    Optional<String> take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    Optional<String> m_value {};

};

class ReadStringValue final : public IPC::Message {
public:

   typedef class ReadStringValueResponse ResponseType;

    ReadStringValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadStringValue(ReadStringValue const&) = default;
    ReadStringValue(ReadStringValue&&) = default;
    ReadStringValue& operator=(ReadStringValue const&) = default;
    ReadStringValue(String domain, String group, String key) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)) {}
    virtual ~ReadStringValue() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadStringValue; }
    static i32 static_message_id() { return (int)MessageID::ReadStringValue; }
    virtual const char* message_name() const override { return "ConfigServer::ReadStringValue"; }

    static OwnPtr<ReadStringValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<ReadStringValue>(move(domain), move(group), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadStringValue;

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

class ReadI32ValueResponse final : public IPC::Message {
public:

    ReadI32ValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadI32ValueResponse(ReadI32ValueResponse const&) = default;
    ReadI32ValueResponse(ReadI32ValueResponse&&) = default;
    ReadI32ValueResponse& operator=(ReadI32ValueResponse const&) = default;
    ReadI32ValueResponse(Optional<i32> value) : m_value(move(value)) {}
    virtual ~ReadI32ValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadI32ValueResponse; }
    static i32 static_message_id() { return (int)MessageID::ReadI32ValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::ReadI32ValueResponse"; }

    static OwnPtr<ReadI32ValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Optional<i32> value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<ReadI32ValueResponse>(move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadI32ValueResponse;

        stream << m_value;

        return buffer;
    }

    const Optional<i32>& value() const { return m_value; }
    Optional<i32> take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    Optional<i32> m_value {};

};

class ReadI32Value final : public IPC::Message {
public:

   typedef class ReadI32ValueResponse ResponseType;

    ReadI32Value(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadI32Value(ReadI32Value const&) = default;
    ReadI32Value(ReadI32Value&&) = default;
    ReadI32Value& operator=(ReadI32Value const&) = default;
    ReadI32Value(String domain, String group, String key) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)) {}
    virtual ~ReadI32Value() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadI32Value; }
    static i32 static_message_id() { return (int)MessageID::ReadI32Value; }
    virtual const char* message_name() const override { return "ConfigServer::ReadI32Value"; }

    static OwnPtr<ReadI32Value> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<ReadI32Value>(move(domain), move(group), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadI32Value;

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

class ReadBoolValueResponse final : public IPC::Message {
public:

    ReadBoolValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadBoolValueResponse(ReadBoolValueResponse const&) = default;
    ReadBoolValueResponse(ReadBoolValueResponse&&) = default;
    ReadBoolValueResponse& operator=(ReadBoolValueResponse const&) = default;
    ReadBoolValueResponse(Optional<bool> value) : m_value(move(value)) {}
    virtual ~ReadBoolValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadBoolValueResponse; }
    static i32 static_message_id() { return (int)MessageID::ReadBoolValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::ReadBoolValueResponse"; }

    static OwnPtr<ReadBoolValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Optional<bool> value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<ReadBoolValueResponse>(move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadBoolValueResponse;

        stream << m_value;

        return buffer;
    }

    const Optional<bool>& value() const { return m_value; }
    Optional<bool> take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    Optional<bool> m_value {};

};

class ReadBoolValue final : public IPC::Message {
public:

   typedef class ReadBoolValueResponse ResponseType;

    ReadBoolValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadBoolValue(ReadBoolValue const&) = default;
    ReadBoolValue(ReadBoolValue&&) = default;
    ReadBoolValue& operator=(ReadBoolValue const&) = default;
    ReadBoolValue(String domain, String group, String key) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)) {}
    virtual ~ReadBoolValue() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::ReadBoolValue; }
    static i32 static_message_id() { return (int)MessageID::ReadBoolValue; }
    virtual const char* message_name() const override { return "ConfigServer::ReadBoolValue"; }

    static OwnPtr<ReadBoolValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<ReadBoolValue>(move(domain), move(group), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadBoolValue;

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

class WriteStringValueResponse final : public IPC::Message {
public:

    WriteStringValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteStringValueResponse(WriteStringValueResponse const&) = default;
    WriteStringValueResponse(WriteStringValueResponse&&) = default;
    WriteStringValueResponse& operator=(WriteStringValueResponse const&) = default;
    WriteStringValueResponse() {}
    virtual ~WriteStringValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteStringValueResponse; }
    static i32 static_message_id() { return (int)MessageID::WriteStringValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::WriteStringValueResponse"; }

    static OwnPtr<WriteStringValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<WriteStringValueResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteStringValueResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class WriteStringValue final : public IPC::Message {
public:

   typedef class WriteStringValueResponse ResponseType;

    WriteStringValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteStringValue(WriteStringValue const&) = default;
    WriteStringValue(WriteStringValue&&) = default;
    WriteStringValue& operator=(WriteStringValue const&) = default;
    WriteStringValue(String domain, String group, String key, String value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~WriteStringValue() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteStringValue; }
    static i32 static_message_id() { return (int)MessageID::WriteStringValue; }
    virtual const char* message_name() const override { return "ConfigServer::WriteStringValue"; }

    static OwnPtr<WriteStringValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<WriteStringValue>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteStringValue;

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

class WriteI32ValueResponse final : public IPC::Message {
public:

    WriteI32ValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteI32ValueResponse(WriteI32ValueResponse const&) = default;
    WriteI32ValueResponse(WriteI32ValueResponse&&) = default;
    WriteI32ValueResponse& operator=(WriteI32ValueResponse const&) = default;
    WriteI32ValueResponse() {}
    virtual ~WriteI32ValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteI32ValueResponse; }
    static i32 static_message_id() { return (int)MessageID::WriteI32ValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::WriteI32ValueResponse"; }

    static OwnPtr<WriteI32ValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<WriteI32ValueResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteI32ValueResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class WriteI32Value final : public IPC::Message {
public:

   typedef class WriteI32ValueResponse ResponseType;

    WriteI32Value(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteI32Value(WriteI32Value const&) = default;
    WriteI32Value(WriteI32Value&&) = default;
    WriteI32Value& operator=(WriteI32Value const&) = default;
    WriteI32Value(String domain, String group, String key, i32 value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~WriteI32Value() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteI32Value; }
    static i32 static_message_id() { return (int)MessageID::WriteI32Value; }
    virtual const char* message_name() const override { return "ConfigServer::WriteI32Value"; }

    static OwnPtr<WriteI32Value> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<WriteI32Value>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteI32Value;

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

class WriteBoolValueResponse final : public IPC::Message {
public:

    WriteBoolValueResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteBoolValueResponse(WriteBoolValueResponse const&) = default;
    WriteBoolValueResponse(WriteBoolValueResponse&&) = default;
    WriteBoolValueResponse& operator=(WriteBoolValueResponse const&) = default;
    WriteBoolValueResponse() {}
    virtual ~WriteBoolValueResponse() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteBoolValueResponse; }
    static i32 static_message_id() { return (int)MessageID::WriteBoolValueResponse; }
    virtual const char* message_name() const override { return "ConfigServer::WriteBoolValueResponse"; }

    static OwnPtr<WriteBoolValueResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<WriteBoolValueResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteBoolValueResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class WriteBoolValue final : public IPC::Message {
public:

   typedef class WriteBoolValueResponse ResponseType;

    WriteBoolValue(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WriteBoolValue(WriteBoolValue const&) = default;
    WriteBoolValue(WriteBoolValue&&) = default;
    WriteBoolValue& operator=(WriteBoolValue const&) = default;
    WriteBoolValue(String domain, String group, String key, bool value) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)), m_value(move(value)) {}
    virtual ~WriteBoolValue() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::WriteBoolValue; }
    static i32 static_message_id() { return (int)MessageID::WriteBoolValue; }
    virtual const char* message_name() const override { return "ConfigServer::WriteBoolValue"; }

    static OwnPtr<WriteBoolValue> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<WriteBoolValue>(move(domain), move(group), move(key), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WriteBoolValue;

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

class RemoveKey final : public IPC::Message {
public:

    RemoveKey(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RemoveKey(RemoveKey const&) = default;
    RemoveKey(RemoveKey&&) = default;
    RemoveKey& operator=(RemoveKey const&) = default;
    RemoveKey(String domain, String group, String key) : m_domain(move(domain)), m_group(move(group)), m_key(move(key)) {}
    virtual ~RemoveKey() override {}

    virtual u32 endpoint_magic() const override { return 252595060; }
    virtual i32 message_id() const override { return (int)MessageID::RemoveKey; }
    static i32 static_message_id() { return (int)MessageID::RemoveKey; }
    virtual const char* message_name() const override { return "ConfigServer::RemoveKey"; }

    static OwnPtr<RemoveKey> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<RemoveKey>(move(domain), move(group), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RemoveKey;

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

} // namespace Messages::ConfigServer

template<typename LocalEndpoint, typename PeerEndpoint>
class ConfigServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    ConfigServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_pledge_domains(
Vector<String> domains) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::PledgeDomains { move(domains) });

    }

    void async_monitor_domain(
String domain) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::MonitorDomain { move(domain) });

    }

    Vector<String> list_config_groups(
String domain) {
        return m_connection.template send_sync<Messages::ConfigServer::ListConfigGroups>(move(domain))->take_groups();
    }

    void async_list_config_groups(
String domain) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::ListConfigGroups { move(domain) });

    }

    IPC::IPCErrorOr<Vector<String>> try_list_config_groups(
String domain) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::ListConfigGroups>(move(domain));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Vector<String> list_config_keys(
String domain, String group) {
        return m_connection.template send_sync<Messages::ConfigServer::ListConfigKeys>(move(domain), move(group))->take_keys();
    }

    void async_list_config_keys(
String domain, String group) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::ListConfigKeys { move(domain), move(group) });

    }

    IPC::IPCErrorOr<Vector<String>> try_list_config_keys(
String domain, String group) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::ListConfigKeys>(move(domain), move(group));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Optional<String> read_string_value(
String domain, String group, String key) {
        return m_connection.template send_sync<Messages::ConfigServer::ReadStringValue>(move(domain), move(group), move(key))->take_value();
    }

    void async_read_string_value(
String domain, String group, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::ReadStringValue { move(domain), move(group), move(key) });

    }

    IPC::IPCErrorOr<Optional<String>> try_read_string_value(
String domain, String group, String key) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::ReadStringValue>(move(domain), move(group), move(key));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Optional<i32> read_i32_value(
String domain, String group, String key) {
        return m_connection.template send_sync<Messages::ConfigServer::ReadI32Value>(move(domain), move(group), move(key))->take_value();
    }

    void async_read_i32_value(
String domain, String group, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::ReadI32Value { move(domain), move(group), move(key) });

    }

    IPC::IPCErrorOr<Optional<i32>> try_read_i32_value(
String domain, String group, String key) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::ReadI32Value>(move(domain), move(group), move(key));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Optional<bool> read_bool_value(
String domain, String group, String key) {
        return m_connection.template send_sync<Messages::ConfigServer::ReadBoolValue>(move(domain), move(group), move(key))->take_value();
    }

    void async_read_bool_value(
String domain, String group, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::ReadBoolValue { move(domain), move(group), move(key) });

    }

    IPC::IPCErrorOr<Optional<bool>> try_read_bool_value(
String domain, String group, String key) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::ReadBoolValue>(move(domain), move(group), move(key));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void write_string_value(
String domain, String group, String key, String value) {
        (void) m_connection.template send_sync<Messages::ConfigServer::WriteStringValue>(move(domain), move(group), move(key), move(value));
    }

    void async_write_string_value(
String domain, String group, String key, String value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::WriteStringValue { move(domain), move(group), move(key), move(value) });

    }

    IPC::IPCErrorOr<void> try_write_string_value(
String domain, String group, String key, String value) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::WriteStringValue>(move(domain), move(group), move(key), move(value));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void write_i32_value(
String domain, String group, String key, i32 value) {
        (void) m_connection.template send_sync<Messages::ConfigServer::WriteI32Value>(move(domain), move(group), move(key), value);
    }

    void async_write_i32_value(
String domain, String group, String key, i32 value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::WriteI32Value { move(domain), move(group), move(key), value });

    }

    IPC::IPCErrorOr<void> try_write_i32_value(
String domain, String group, String key, i32 value) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::WriteI32Value>(move(domain), move(group), move(key), value);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void write_bool_value(
String domain, String group, String key, bool value) {
        (void) m_connection.template send_sync<Messages::ConfigServer::WriteBoolValue>(move(domain), move(group), move(key), value);
    }

    void async_write_bool_value(
String domain, String group, String key, bool value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::WriteBoolValue { move(domain), move(group), move(key), value });

    }

    IPC::IPCErrorOr<void> try_write_bool_value(
String domain, String group, String key, bool value) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ConfigServer::WriteBoolValue>(move(domain), move(group), move(key), value);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void async_remove_key(
String domain, String group, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ConfigServer::RemoveKey { move(domain), move(group), move(key) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class ConfigServerProxy;
class ConfigServerStub;

class ConfigServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = ConfigServerProxy<LocalEndpoint, ConfigServerEndpoint>;
    using Stub = ConfigServerStub;

    static u32 static_magic() { return 252595060; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 252595060) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::ConfigServer::MessageID::PledgeDomains:
            message = Messages::ConfigServer::PledgeDomains::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::MonitorDomain:
            message = Messages::ConfigServer::MonitorDomain::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ListConfigGroups:
            message = Messages::ConfigServer::ListConfigGroups::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ListConfigGroupsResponse:
            message = Messages::ConfigServer::ListConfigGroupsResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ListConfigKeys:
            message = Messages::ConfigServer::ListConfigKeys::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ListConfigKeysResponse:
            message = Messages::ConfigServer::ListConfigKeysResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadStringValue:
            message = Messages::ConfigServer::ReadStringValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadStringValueResponse:
            message = Messages::ConfigServer::ReadStringValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadI32Value:
            message = Messages::ConfigServer::ReadI32Value::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadI32ValueResponse:
            message = Messages::ConfigServer::ReadI32ValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadBoolValue:
            message = Messages::ConfigServer::ReadBoolValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::ReadBoolValueResponse:
            message = Messages::ConfigServer::ReadBoolValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteStringValue:
            message = Messages::ConfigServer::WriteStringValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteStringValueResponse:
            message = Messages::ConfigServer::WriteStringValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteI32Value:
            message = Messages::ConfigServer::WriteI32Value::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteI32ValueResponse:
            message = Messages::ConfigServer::WriteI32ValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteBoolValue:
            message = Messages::ConfigServer::WriteBoolValue::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::WriteBoolValueResponse:
            message = Messages::ConfigServer::WriteBoolValueResponse::decode(stream, socket);
            break;

        case (int)Messages::ConfigServer::MessageID::RemoveKey:
            message = Messages::ConfigServer::RemoveKey::decode(stream, socket);
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

class ConfigServerStub : public IPC::Stub {
public:
    ConfigServerStub() { }
    virtual ~ConfigServerStub() override { }

    virtual u32 magic() const override { return 252595060; }
    virtual String name() const override { return "ConfigServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::ConfigServer::MessageID::PledgeDomains: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::PledgeDomains&>(message);
            pledge_domains(request.domains());
            return {};

        }

        case (int)Messages::ConfigServer::MessageID::MonitorDomain: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::MonitorDomain&>(message);
            monitor_domain(request.domain());
            return {};

        }

        case (int)Messages::ConfigServer::MessageID::ListConfigGroups: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::ListConfigGroups&>(message);
            auto response = list_config_groups(request.domain());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::ListConfigKeys: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::ListConfigKeys&>(message);
            auto response = list_config_keys(request.domain(), request.group());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::ReadStringValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::ReadStringValue&>(message);
            auto response = read_string_value(request.domain(), request.group(), request.key());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::ReadI32Value: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::ReadI32Value&>(message);
            auto response = read_i32_value(request.domain(), request.group(), request.key());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::ReadBoolValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::ReadBoolValue&>(message);
            auto response = read_bool_value(request.domain(), request.group(), request.key());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::WriteStringValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::WriteStringValue&>(message);
            write_string_value(request.domain(), request.group(), request.key(), request.value());
            auto response = Messages::ConfigServer::WriteStringValueResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::WriteI32Value: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::WriteI32Value&>(message);
            write_i32_value(request.domain(), request.group(), request.key(), request.value());
            auto response = Messages::ConfigServer::WriteI32ValueResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::WriteBoolValue: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::WriteBoolValue&>(message);
            write_bool_value(request.domain(), request.group(), request.key(), request.value());
            auto response = Messages::ConfigServer::WriteBoolValueResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ConfigServer::MessageID::RemoveKey: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ConfigServer::RemoveKey&>(message);
            remove_key(request.domain(), request.group(), request.key());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void pledge_domains(
[[maybe_unused]] Vector<String> const& domains) = 0;

    virtual void monitor_domain(
[[maybe_unused]] String const& domain) = 0;

    virtual Messages::ConfigServer::ListConfigGroupsResponse list_config_groups(
[[maybe_unused]] String const& domain) = 0;

    virtual Messages::ConfigServer::ListConfigKeysResponse list_config_keys(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group) = 0;

    virtual Messages::ConfigServer::ReadStringValueResponse read_string_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key) = 0;

    virtual Messages::ConfigServer::ReadI32ValueResponse read_i32_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key) = 0;

    virtual Messages::ConfigServer::ReadBoolValueResponse read_bool_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key) = 0;

    virtual void write_string_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] String const& value) = 0;

    virtual void write_i32_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] i32 value) = 0;

    virtual void write_bool_value(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key, [[maybe_unused]] bool value) = 0;

    virtual void remove_key(
[[maybe_unused]] String const& domain, [[maybe_unused]] String const& group, [[maybe_unused]] String const& key) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

