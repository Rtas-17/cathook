#pragma once
#include <map>
#include <optional>

#include "timer.hpp"
#include "public/mathlib/vector.h"

class Vector;

namespace soundcache
{
std::optional<Vector> GetSoundLocation(int entid);
void cache_sound(const Vector *Origin, int source);
} // namespace soundcache
