#pragma once
#include <LibCore/AnonymousBuffer.h>
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

namespace Messages::AudioClient {

enum class MessageID : i32 {
    MainMixMutedStateChanged = 1,
    MainMixVolumeChanged = 2,
    ClientVolumeChanged = 3,
};

class MainMixMutedStateChanged final : public IPC::Message {
public:

    MainMixMutedStateChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MainMixMutedStateChanged(MainMixMutedStateChanged const&) = default;
    MainMixMutedStateChanged(MainMixMutedStateChanged&&) = default;
    MainMixMutedStateChanged& operator=(MainMixMutedStateChanged const&) = default;
    MainMixMutedStateChanged(bool muted) : m_muted(move(muted)) {}
    virtual ~MainMixMutedStateChanged() override {}

    virtual u32 endpoint_magic() const override { return 1126638765; }
    virtual i32 message_id() const override { return (int)MessageID::MainMixMutedStateChanged; }
    static i32 static_message_id() { return (int)MessageID::MainMixMutedStateChanged; }
    virtual const char* message_name() const override { return "AudioClient::MainMixMutedStateChanged"; }

    static OwnPtr<MainMixMutedStateChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool muted = false;
        if (decoder.decode(muted).is_error())
            return {};

        return make<MainMixMutedStateChanged>(move(muted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MainMixMutedStateChanged;

        stream << m_muted;

        return buffer;
    }

    const bool& muted() const { return m_muted; }
    bool take_muted() { return move(m_muted); }

private:
    bool m_ipc_message_valid { true };

    bool m_muted {};

};

class MainMixVolumeChanged final : public IPC::Message {
public:

    MainMixVolumeChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MainMixVolumeChanged(MainMixVolumeChanged const&) = default;
    MainMixVolumeChanged(MainMixVolumeChanged&&) = default;
    MainMixVolumeChanged& operator=(MainMixVolumeChanged const&) = default;
    MainMixVolumeChanged(double volume) : m_volume(move(volume)) {}
    virtual ~MainMixVolumeChanged() override {}

    virtual u32 endpoint_magic() const override { return 1126638765; }
    virtual i32 message_id() const override { return (int)MessageID::MainMixVolumeChanged; }
    static i32 static_message_id() { return (int)MessageID::MainMixVolumeChanged; }
    virtual const char* message_name() const override { return "AudioClient::MainMixVolumeChanged"; }

    static OwnPtr<MainMixVolumeChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<MainMixVolumeChanged>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MainMixVolumeChanged;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

class ClientVolumeChanged final : public IPC::Message {
public:

    ClientVolumeChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ClientVolumeChanged(ClientVolumeChanged const&) = default;
    ClientVolumeChanged(ClientVolumeChanged&&) = default;
    ClientVolumeChanged& operator=(ClientVolumeChanged const&) = default;
    ClientVolumeChanged(double volume) : m_volume(move(volume)) {}
    virtual ~ClientVolumeChanged() override {}

    virtual u32 endpoint_magic() const override { return 1126638765; }
    virtual i32 message_id() const override { return (int)MessageID::ClientVolumeChanged; }
    static i32 static_message_id() { return (int)MessageID::ClientVolumeChanged; }
    virtual const char* message_name() const override { return "AudioClient::ClientVolumeChanged"; }

    static OwnPtr<ClientVolumeChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<ClientVolumeChanged>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ClientVolumeChanged;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

} // namespace Messages::AudioClient

template<typename LocalEndpoint, typename PeerEndpoint>
class AudioClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    AudioClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_main_mix_muted_state_changed(
bool muted) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioClient::MainMixMutedStateChanged { muted });

    }

    void async_main_mix_volume_changed(
double volume) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioClient::MainMixVolumeChanged { volume });

    }

    void async_client_volume_changed(
double volume) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioClient::ClientVolumeChanged { volume });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class AudioClientProxy;
class AudioClientStub;

class AudioClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = AudioClientProxy<LocalEndpoint, AudioClientEndpoint>;
    using Stub = AudioClientStub;

    static u32 static_magic() { return 1126638765; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1126638765) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::AudioClient::MessageID::MainMixMutedStateChanged:
            message = Messages::AudioClient::MainMixMutedStateChanged::decode(stream, socket);
            break;

        case (int)Messages::AudioClient::MessageID::MainMixVolumeChanged:
            message = Messages::AudioClient::MainMixVolumeChanged::decode(stream, socket);
            break;

        case (int)Messages::AudioClient::MessageID::ClientVolumeChanged:
            message = Messages::AudioClient::ClientVolumeChanged::decode(stream, socket);
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

class AudioClientStub : public IPC::Stub {
public:
    AudioClientStub() { }
    virtual ~AudioClientStub() override { }

    virtual u32 magic() const override { return 1126638765; }
    virtual String name() const override { return "AudioClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::AudioClient::MessageID::MainMixMutedStateChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioClient::MainMixMutedStateChanged&>(message);
            main_mix_muted_state_changed(request.muted());
            return {};

        }

        case (int)Messages::AudioClient::MessageID::MainMixVolumeChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioClient::MainMixVolumeChanged&>(message);
            main_mix_volume_changed(request.volume());
            return {};

        }

        case (int)Messages::AudioClient::MessageID::ClientVolumeChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioClient::ClientVolumeChanged&>(message);
            client_volume_changed(request.volume());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void main_mix_muted_state_changed(
[[maybe_unused]] bool muted) = 0;

    virtual void main_mix_volume_changed(
[[maybe_unused]] double volume) = 0;

    virtual void client_volume_changed(
[[maybe_unused]] double volume) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

