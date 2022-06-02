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

namespace Messages::InspectorServer {

enum class MessageID : i32 {
    GetAllObjects = 1,
    GetAllObjectsResponse = 2,
    SetInspectedObject = 3,
    SetInspectedObjectResponse = 4,
    SetObjectProperty = 5,
    SetObjectPropertyResponse = 6,
    Identify = 7,
    IdentifyResponse = 8,
    IsInspectable = 9,
    IsInspectableResponse = 10,
};

class GetAllObjectsResponse final : public IPC::Message {
public:

    GetAllObjectsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetAllObjectsResponse(GetAllObjectsResponse const&) = default;
    GetAllObjectsResponse(GetAllObjectsResponse&&) = default;
    GetAllObjectsResponse& operator=(GetAllObjectsResponse const&) = default;
    GetAllObjectsResponse(String json) : m_json(move(json)) {}
    virtual ~GetAllObjectsResponse() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::GetAllObjectsResponse; }
    static i32 static_message_id() { return (int)MessageID::GetAllObjectsResponse; }
    virtual const char* message_name() const override { return "InspectorServer::GetAllObjectsResponse"; }

    static OwnPtr<GetAllObjectsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String json = {};
        if (decoder.decode(json).is_error())
            return {};

        return make<GetAllObjectsResponse>(move(json));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetAllObjectsResponse;

        stream << m_json;

        return buffer;
    }

    const String& json() const { return m_json; }
    String take_json() { return move(m_json); }

private:
    bool m_ipc_message_valid { true };

    String m_json {};

};

class GetAllObjects final : public IPC::Message {
public:

   typedef class GetAllObjectsResponse ResponseType;

    GetAllObjects(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetAllObjects(GetAllObjects const&) = default;
    GetAllObjects(GetAllObjects&&) = default;
    GetAllObjects& operator=(GetAllObjects const&) = default;
    GetAllObjects(i32 pid) : m_pid(move(pid)) {}
    virtual ~GetAllObjects() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::GetAllObjects; }
    static i32 static_message_id() { return (int)MessageID::GetAllObjects; }
    virtual const char* message_name() const override { return "InspectorServer::GetAllObjects"; }

    static OwnPtr<GetAllObjects> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 pid = {};
        if (decoder.decode(pid).is_error())
            return {};

        return make<GetAllObjects>(move(pid));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetAllObjects;

        stream << m_pid;

        return buffer;
    }

    const i32& pid() const { return m_pid; }
    i32 take_pid() { return move(m_pid); }

private:
    bool m_ipc_message_valid { true };

    i32 m_pid {};

};

class SetInspectedObjectResponse final : public IPC::Message {
public:

    SetInspectedObjectResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetInspectedObjectResponse(SetInspectedObjectResponse const&) = default;
    SetInspectedObjectResponse(SetInspectedObjectResponse&&) = default;
    SetInspectedObjectResponse& operator=(SetInspectedObjectResponse const&) = default;
    SetInspectedObjectResponse(bool success) : m_success(move(success)) {}
    virtual ~SetInspectedObjectResponse() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::SetInspectedObjectResponse; }
    static i32 static_message_id() { return (int)MessageID::SetInspectedObjectResponse; }
    virtual const char* message_name() const override { return "InspectorServer::SetInspectedObjectResponse"; }

    static OwnPtr<SetInspectedObjectResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetInspectedObjectResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetInspectedObjectResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class SetInspectedObject final : public IPC::Message {
public:

   typedef class SetInspectedObjectResponse ResponseType;

    SetInspectedObject(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetInspectedObject(SetInspectedObject const&) = default;
    SetInspectedObject(SetInspectedObject&&) = default;
    SetInspectedObject& operator=(SetInspectedObject const&) = default;
    SetInspectedObject(i32 pid, u64 object_id) : m_pid(move(pid)), m_object_id(move(object_id)) {}
    virtual ~SetInspectedObject() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::SetInspectedObject; }
    static i32 static_message_id() { return (int)MessageID::SetInspectedObject; }
    virtual const char* message_name() const override { return "InspectorServer::SetInspectedObject"; }

    static OwnPtr<SetInspectedObject> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 pid = {};
        if (decoder.decode(pid).is_error())
            return {};

        u64 object_id = {};
        if (decoder.decode(object_id).is_error())
            return {};

        return make<SetInspectedObject>(move(pid), move(object_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetInspectedObject;

        stream << m_pid;

        stream << m_object_id;

        return buffer;
    }

    const i32& pid() const { return m_pid; }
    i32 take_pid() { return move(m_pid); }

    const u64& object_id() const { return m_object_id; }
    u64 take_object_id() { return move(m_object_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_pid {};

    u64 m_object_id {};

};

class SetObjectPropertyResponse final : public IPC::Message {
public:

    SetObjectPropertyResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetObjectPropertyResponse(SetObjectPropertyResponse const&) = default;
    SetObjectPropertyResponse(SetObjectPropertyResponse&&) = default;
    SetObjectPropertyResponse& operator=(SetObjectPropertyResponse const&) = default;
    SetObjectPropertyResponse(bool success) : m_success(move(success)) {}
    virtual ~SetObjectPropertyResponse() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::SetObjectPropertyResponse; }
    static i32 static_message_id() { return (int)MessageID::SetObjectPropertyResponse; }
    virtual const char* message_name() const override { return "InspectorServer::SetObjectPropertyResponse"; }

    static OwnPtr<SetObjectPropertyResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetObjectPropertyResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetObjectPropertyResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class SetObjectProperty final : public IPC::Message {
public:

   typedef class SetObjectPropertyResponse ResponseType;

    SetObjectProperty(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetObjectProperty(SetObjectProperty const&) = default;
    SetObjectProperty(SetObjectProperty&&) = default;
    SetObjectProperty& operator=(SetObjectProperty const&) = default;
    SetObjectProperty(i32 pid, u64 object_id, String name, String value) : m_pid(move(pid)), m_object_id(move(object_id)), m_name(move(name)), m_value(move(value)) {}
    virtual ~SetObjectProperty() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::SetObjectProperty; }
    static i32 static_message_id() { return (int)MessageID::SetObjectProperty; }
    virtual const char* message_name() const override { return "InspectorServer::SetObjectProperty"; }

    static OwnPtr<SetObjectProperty> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 pid = {};
        if (decoder.decode(pid).is_error())
            return {};

        u64 object_id = {};
        if (decoder.decode(object_id).is_error())
            return {};

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        String value = {};
        if (decoder.decode(value).is_error())
            return {};

        return make<SetObjectProperty>(move(pid), move(object_id), move(name), move(value));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetObjectProperty;

        stream << m_pid;

        stream << m_object_id;

        stream << m_name;

        stream << m_value;

        return buffer;
    }

    const i32& pid() const { return m_pid; }
    i32 take_pid() { return move(m_pid); }

    const u64& object_id() const { return m_object_id; }
    u64 take_object_id() { return move(m_object_id); }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

    const String& value() const { return m_value; }
    String take_value() { return move(m_value); }

private:
    bool m_ipc_message_valid { true };

    i32 m_pid {};

    u64 m_object_id {};

    String m_name {};

    String m_value {};

};

class IdentifyResponse final : public IPC::Message {
public:

    IdentifyResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IdentifyResponse(IdentifyResponse const&) = default;
    IdentifyResponse(IdentifyResponse&&) = default;
    IdentifyResponse& operator=(IdentifyResponse const&) = default;
    IdentifyResponse(String json) : m_json(move(json)) {}
    virtual ~IdentifyResponse() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::IdentifyResponse; }
    static i32 static_message_id() { return (int)MessageID::IdentifyResponse; }
    virtual const char* message_name() const override { return "InspectorServer::IdentifyResponse"; }

    static OwnPtr<IdentifyResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String json = {};
        if (decoder.decode(json).is_error())
            return {};

        return make<IdentifyResponse>(move(json));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IdentifyResponse;

        stream << m_json;

        return buffer;
    }

    const String& json() const { return m_json; }
    String take_json() { return move(m_json); }

private:
    bool m_ipc_message_valid { true };

    String m_json {};

};

class Identify final : public IPC::Message {
public:

   typedef class IdentifyResponse ResponseType;

    Identify(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Identify(Identify const&) = default;
    Identify(Identify&&) = default;
    Identify& operator=(Identify const&) = default;
    Identify(i32 pid) : m_pid(move(pid)) {}
    virtual ~Identify() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::Identify; }
    static i32 static_message_id() { return (int)MessageID::Identify; }
    virtual const char* message_name() const override { return "InspectorServer::Identify"; }

    static OwnPtr<Identify> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 pid = {};
        if (decoder.decode(pid).is_error())
            return {};

        return make<Identify>(move(pid));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Identify;

        stream << m_pid;

        return buffer;
    }

    const i32& pid() const { return m_pid; }
    i32 take_pid() { return move(m_pid); }

private:
    bool m_ipc_message_valid { true };

    i32 m_pid {};

};

class IsInspectableResponse final : public IPC::Message {
public:

    IsInspectableResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsInspectableResponse(IsInspectableResponse const&) = default;
    IsInspectableResponse(IsInspectableResponse&&) = default;
    IsInspectableResponse& operator=(IsInspectableResponse const&) = default;
    IsInspectableResponse(bool inspectable) : m_inspectable(move(inspectable)) {}
    virtual ~IsInspectableResponse() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::IsInspectableResponse; }
    static i32 static_message_id() { return (int)MessageID::IsInspectableResponse; }
    virtual const char* message_name() const override { return "InspectorServer::IsInspectableResponse"; }

    static OwnPtr<IsInspectableResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool inspectable = false;
        if (decoder.decode(inspectable).is_error())
            return {};

        return make<IsInspectableResponse>(move(inspectable));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsInspectableResponse;

        stream << m_inspectable;

        return buffer;
    }

    const bool& inspectable() const { return m_inspectable; }
    bool take_inspectable() { return move(m_inspectable); }

private:
    bool m_ipc_message_valid { true };

    bool m_inspectable {};

};

class IsInspectable final : public IPC::Message {
public:

   typedef class IsInspectableResponse ResponseType;

    IsInspectable(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsInspectable(IsInspectable const&) = default;
    IsInspectable(IsInspectable&&) = default;
    IsInspectable& operator=(IsInspectable const&) = default;
    IsInspectable(i32 pid) : m_pid(move(pid)) {}
    virtual ~IsInspectable() override {}

    virtual u32 endpoint_magic() const override { return 2225086633; }
    virtual i32 message_id() const override { return (int)MessageID::IsInspectable; }
    static i32 static_message_id() { return (int)MessageID::IsInspectable; }
    virtual const char* message_name() const override { return "InspectorServer::IsInspectable"; }

    static OwnPtr<IsInspectable> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 pid = {};
        if (decoder.decode(pid).is_error())
            return {};

        return make<IsInspectable>(move(pid));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsInspectable;

        stream << m_pid;

        return buffer;
    }

    const i32& pid() const { return m_pid; }
    i32 take_pid() { return move(m_pid); }

private:
    bool m_ipc_message_valid { true };

    i32 m_pid {};

};

} // namespace Messages::InspectorServer

template<typename LocalEndpoint, typename PeerEndpoint>
class InspectorServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    InspectorServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    String get_all_objects(
i32 pid) {
        return m_connection.template send_sync<Messages::InspectorServer::GetAllObjects>(pid)->take_json();
    }

    void async_get_all_objects(
i32 pid) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::InspectorServer::GetAllObjects { pid });

    }

    IPC::IPCErrorOr<String> try_get_all_objects(
i32 pid) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::InspectorServer::GetAllObjects>(pid);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool set_inspected_object(
i32 pid, u64 object_id) {
        return m_connection.template send_sync<Messages::InspectorServer::SetInspectedObject>(pid, object_id)->take_success();
    }

    void async_set_inspected_object(
i32 pid, u64 object_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::InspectorServer::SetInspectedObject { pid, object_id });

    }

    IPC::IPCErrorOr<bool> try_set_inspected_object(
i32 pid, u64 object_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::InspectorServer::SetInspectedObject>(pid, object_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool set_object_property(
i32 pid, u64 object_id, String name, String value) {
        return m_connection.template send_sync<Messages::InspectorServer::SetObjectProperty>(pid, object_id, move(name), move(value))->take_success();
    }

    void async_set_object_property(
i32 pid, u64 object_id, String name, String value) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::InspectorServer::SetObjectProperty { pid, object_id, move(name), move(value) });

    }

    IPC::IPCErrorOr<bool> try_set_object_property(
i32 pid, u64 object_id, String name, String value) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::InspectorServer::SetObjectProperty>(pid, object_id, move(name), move(value));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    String identify(
i32 pid) {
        return m_connection.template send_sync<Messages::InspectorServer::Identify>(pid)->take_json();
    }

    void async_identify(
i32 pid) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::InspectorServer::Identify { pid });

    }

    IPC::IPCErrorOr<String> try_identify(
i32 pid) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::InspectorServer::Identify>(pid);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool is_inspectable(
i32 pid) {
        return m_connection.template send_sync<Messages::InspectorServer::IsInspectable>(pid)->take_inspectable();
    }

    void async_is_inspectable(
i32 pid) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::InspectorServer::IsInspectable { pid });

    }

    IPC::IPCErrorOr<bool> try_is_inspectable(
i32 pid) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::InspectorServer::IsInspectable>(pid);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class InspectorServerProxy;
class InspectorServerStub;

class InspectorServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = InspectorServerProxy<LocalEndpoint, InspectorServerEndpoint>;
    using Stub = InspectorServerStub;

    static u32 static_magic() { return 2225086633; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 2225086633) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::InspectorServer::MessageID::GetAllObjects:
            message = Messages::InspectorServer::GetAllObjects::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::GetAllObjectsResponse:
            message = Messages::InspectorServer::GetAllObjectsResponse::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::SetInspectedObject:
            message = Messages::InspectorServer::SetInspectedObject::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::SetInspectedObjectResponse:
            message = Messages::InspectorServer::SetInspectedObjectResponse::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::SetObjectProperty:
            message = Messages::InspectorServer::SetObjectProperty::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::SetObjectPropertyResponse:
            message = Messages::InspectorServer::SetObjectPropertyResponse::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::Identify:
            message = Messages::InspectorServer::Identify::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::IdentifyResponse:
            message = Messages::InspectorServer::IdentifyResponse::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::IsInspectable:
            message = Messages::InspectorServer::IsInspectable::decode(stream, socket);
            break;

        case (int)Messages::InspectorServer::MessageID::IsInspectableResponse:
            message = Messages::InspectorServer::IsInspectableResponse::decode(stream, socket);
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

class InspectorServerStub : public IPC::Stub {
public:
    InspectorServerStub() { }
    virtual ~InspectorServerStub() override { }

    virtual u32 magic() const override { return 2225086633; }
    virtual String name() const override { return "InspectorServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::InspectorServer::MessageID::GetAllObjects: {

            [[maybe_unused]] auto& request = static_cast<const Messages::InspectorServer::GetAllObjects&>(message);
            auto response = get_all_objects(request.pid());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::InspectorServer::MessageID::SetInspectedObject: {

            [[maybe_unused]] auto& request = static_cast<const Messages::InspectorServer::SetInspectedObject&>(message);
            auto response = set_inspected_object(request.pid(), request.object_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::InspectorServer::MessageID::SetObjectProperty: {

            [[maybe_unused]] auto& request = static_cast<const Messages::InspectorServer::SetObjectProperty&>(message);
            auto response = set_object_property(request.pid(), request.object_id(), request.name(), request.value());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::InspectorServer::MessageID::Identify: {

            [[maybe_unused]] auto& request = static_cast<const Messages::InspectorServer::Identify&>(message);
            auto response = identify(request.pid());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::InspectorServer::MessageID::IsInspectable: {

            [[maybe_unused]] auto& request = static_cast<const Messages::InspectorServer::IsInspectable&>(message);
            auto response = is_inspectable(request.pid());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual Messages::InspectorServer::GetAllObjectsResponse get_all_objects(
[[maybe_unused]] i32 pid) = 0;

    virtual Messages::InspectorServer::SetInspectedObjectResponse set_inspected_object(
[[maybe_unused]] i32 pid, [[maybe_unused]] u64 object_id) = 0;

    virtual Messages::InspectorServer::SetObjectPropertyResponse set_object_property(
[[maybe_unused]] i32 pid, [[maybe_unused]] u64 object_id, [[maybe_unused]] String const& name, [[maybe_unused]] String const& value) = 0;

    virtual Messages::InspectorServer::IdentifyResponse identify(
[[maybe_unused]] i32 pid) = 0;

    virtual Messages::InspectorServer::IsInspectableResponse is_inspectable(
[[maybe_unused]] i32 pid) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

