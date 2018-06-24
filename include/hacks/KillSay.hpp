/*
 * KillSay.h
 *
 *  Created on: Jan 19, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "common.hpp"

class CatCommand;

class KillSayEventListener : public IGameEventListener2
{
    virtual void FireGameEvent(IGameEvent *event);
};

namespace hacks::shared::killsay
{

void Init();
void Shutdown();
void Reload();
std::string ComposeKillSay(IGameEvent *event);

extern const std::vector<std::string> builtin_default;
extern const std::vector<std::string> builtin_nonecore_offensive;
extern const std::vector<std::string> builtin_nonecore_mlg;
}
