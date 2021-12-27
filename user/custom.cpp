#include "pch-il2cpp.h"

#include <Windows.h>
#include "custom.h"

app::ClientState__Enum Custom::GetClientState() noexcept {
    return app::PhotonNetwork_get_connectionStateDetailed(NULL);
    /*
    enum class ClientState__Enum : int32_t {
    Uninitialized = 0x00000000,
    PeerCreated = 0x00000001,
    Queued = 0x00000002,
    Authenticated = 0x00000003,
    JoinedLobby = 0x00000004,
    DisconnectingFromMasterserver = 0x00000005,
    ConnectingToGameserver = 0x00000006,
    ConnectedToGameserver = 0x00000007,
    Joining = 0x00000008,
    Joined = 0x00000009,
    Leaving = 0x0000000a,
    DisconnectingFromGameserver = 0x0000000b,
    ConnectingToMasterserver = 0x0000000c,
    QueuedComingFromGameserver = 0x0000000d,
    Disconnecting = 0x0000000e,
    Disconnected = 0x0000000f,
    ConnectedToMaster = 0x00000010,
    ConnectingToNameServer = 0x00000011,
    ConnectedToNameServer = 0x00000012,
    DisconnectingFromNameServer = 0x00000013,
    Authenticating = 0x00000014,
};*/
}