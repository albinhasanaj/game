#pragma once
#include "hp.h"
#include "statblock.h"

class Rogue : public HP, public StatBlock {
public:
    static const HPType HPGROWTH = (HPType)13u;
    static const StatType BASESTR = (StatType)3u;
    static const StatType BASEINT = (StatType)2u;
    Rogue() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}

private:
};
