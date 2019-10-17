/*
  Created by Jenny White on 13.05.18.
  Copyright (c) 2018 nullworks. All rights reserved.
*/

#pragma once

#include <menu/BaseMenuObject.hpp>
#include <menu/KeyValue.hpp>
#include <string>

namespace zerokernel
{
class BaseMenuObject;

class Message
{
public:
    explicit Message(std::string name);

    const std::string name;
    KeyValue kv;
    BaseMenuObject *sender{ nullptr };
};
} // namespace zerokernel