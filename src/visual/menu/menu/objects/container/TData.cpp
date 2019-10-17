#include <menu/object/container/TRow.hpp>
#include <menu/object/container/TData.hpp>

#include "BaseMenuObject.hpp"
#include "BoundingBox.hpp"
#include "Container.hpp"

/*
  Created on 08.07.18.
*/

void zerokernel::TData::setParent(zerokernel::BaseMenuObject *parent)
{
    Container::setParent(parent);

    row = dynamic_cast<TRow *>(parent);
}

zerokernel::TData::TData()
{
    bb.height.setContent();
}
