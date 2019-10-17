/*
  Created by Jenny White on 29.04.18.
  Copyright (c) 2018 nullworks. All rights reserved.
*/

#include <time.h>

#include "HookedMethods.hpp"
#include "HookTools.hpp"
#include "SimpleIPC/ipcb.hpp"
#include "chatstack.hpp"
#include "config.h"
#include "globals.h"
#include "ipc.hpp"
#include "playerlist.hpp"

namespace hooked_methods
{

DEFINE_HOOKED_METHOD(LevelShutdown, void, void *this_)
{
    need_name_change = true;
    playerlist::Save();
    g_Settings.bInvalid = true;
    chat_stack::Reset();
#if ENABLE_VISUALS
    effect_glow::g_EffectGlow.Shutdown();
    effect_chams::g_EffectChams.Shutdown();
#endif
    EC::run(EC::LevelShutdown);
#if ENABLE_IPC
    if (ipc::peer)
    {
        ipc::peer->memory->peer_user_data[ipc::peer->client_id].ts_disconnected = time(nullptr);
    }
#endif
    return original::LevelShutdown(this_);
}
} // namespace hooked_methods
