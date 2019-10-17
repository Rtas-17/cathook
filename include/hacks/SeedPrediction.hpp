/*
 * SeedPrediction.hpp
 *
 *  Created on: Jul 27, 2018
 *      Author: bencat07
 */
#include <boost/circular_buffer.hpp>
#include <settings/Bool.hpp>
#include <boost/move/utility_core.hpp>

#include "reclasses.hpp"
#include "C_TEFireBullets.hpp"
#include "common.hpp"

class C_TEFireBullets;
#pragma once
namespace hacks::tf2::seedprediction
{
bool predon();
void handleFireBullets(C_TEFireBullets *);
struct seedstruct
{
    int tickcount;
    int seed;
    float time;
    bool operator<(const seedstruct &rhs) const
    {
        return tickcount < rhs.tickcount;
    }
};
struct predictSeed2
{
    seedstruct base;
    int tickcount;
    float resolution;
    bool operator<(const predictSeed2 &rhs) const
    {
        return tickcount < rhs.tickcount;
    }
};
struct IntervalEdge
{
    int pos;
    float val;
    bool operator<(const IntervalEdge &rhs) const
    {
        return val < rhs.val;
    }
};
typedef boost::circular_buffer<seedstruct> buf;
typedef boost::circular_buffer<predictSeed2> buf2;
typedef boost::circular_buffer<IntervalEdge> buf3;
extern buf bases;
extern buf2 rebased;
extern buf3 intervals;
void selectBase();
float predictOffset(const seedstruct &entry, int targetTick, float clockRes);
} // namespace hacks::tf2::seedprediction
