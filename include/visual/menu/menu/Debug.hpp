/*
  Created on 27.07.18.
*/

#pragma once

#include "BaseMenuObject.hpp"

namespace zerokernel {
class BaseMenuObject;
}  // namespace zerokernel

namespace zerokernel::debug
{

class UiTreeGraph
{
public:
    UiTreeGraph(BaseMenuObject *object, int depth);

    int depth{ 0 };
};
} // namespace zerokernel::debug