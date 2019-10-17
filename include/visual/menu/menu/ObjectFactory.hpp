/*
  Created by Jenny White on 01.05.18.
  Copyright (c) 2018 nullworks. All rights reserved.
*/

#pragma once

#include <menu/BaseMenuObject.hpp>
#include <memory>
#include <string>

namespace tinyxml2 {
class XMLElement;
}  // namespace tinyxml2

namespace zerokernel
{
class BaseMenuObject;

class ObjectFactory
{
public:
    static std::unique_ptr<BaseMenuObject> createObjectFromXml(const tinyxml2::XMLElement *element);
    static std::unique_ptr<BaseMenuObject> createAutoVariable(const tinyxml2::XMLElement *element);
    static std::unique_ptr<BaseMenuObject> createFromPrefab(const std::string &prefab_id);
};
} // namespace zerokernel