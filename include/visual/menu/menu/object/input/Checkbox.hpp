/*
  Created by Jenny White on 29.04.18.
  Copyright (c) 2018 nullworks. All rights reserved.
*/

#pragma once

#include <settings/Bool.hpp>
#include <menu/BaseMenuObject.hpp>
#include <menu/Menu.hpp>
#include <iostream>

namespace settings {
template <typename T> class Variable;
}  // namespace settings
namespace tinyxml2 {
class XMLElement;
}  // namespace tinyxml2

namespace zerokernel
{

class Checkbox : public BaseMenuObject
{
public:
    ~Checkbox() override = default;

    Checkbox();

    explicit Checkbox(settings::Variable<bool> &option);

    void render() override;

    void setVariable(settings::Variable<bool> &variable);

    bool onLeftMouseClick() override;

    void loadFromXml(const tinyxml2::XMLElement *data) override;

protected:
    settings::Variable<bool> *option{ nullptr };
};
} // namespace zerokernel
