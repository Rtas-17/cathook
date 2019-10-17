/*
  Created on 02.07.18.
*/

#include <string>

#include "Manager.hpp"
#include "Registered.hpp"

namespace settings {
class IVariable;
}  // namespace settings

void settings::registerVariable(IVariable &variable, std::string name)
{
    Manager::instance().add(variable, name);
}
