#pragma once
#include "hp.h"
#include "statblock.h"

class Warrior : public HP, public StatBlock {
public:
    static const HPType HPGROWTH = (HPType)19u;
    static const StatType BASESTR = (StatType)4u;
    static const StatType BASEINT = (StatType)1u;
    Warrior() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}

private:
};
