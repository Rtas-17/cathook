/*
 * angles.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: nullifiedcat
 */

#include <cdll_int.h>
#include <math.h>
#include <mathlib/vector.h>
#include <string.h>
#include <stdexcept>

#include "entitycache.hpp"
#include "globals.h"
#include "interfaces.hpp"
#include "netvars.hpp"
#include "usercmd.hpp"

namespace angles
{

angle_data_s data_[32];

void Update()
{
    for (int i = 1; i < 33; i++)
    {
        auto &d           = data_idx(i);
        CachedEntity *ent = ENTITY(i);
        if (CE_GOOD(ent) && !CE_BYTE(ent, netvar.iLifeState))
        {
            if (!d.good)
            {
                memset(&d, 0, sizeof(angle_data_s));
            }
            if (i == g_IEngine->GetLocalPlayer())
            {
                d.push(current_user_cmd->viewangles);
            }
            else
            {
                d.push(CE_VECTOR(ent, netvar.m_angEyeAngles));
            }
        }
        else
        {
            d.good = false;
        }
    }
}
} // namespace angles
