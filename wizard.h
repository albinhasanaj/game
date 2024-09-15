#pragma once
#include "hp.h"
#include "statblock.h"

class Wizard : public HP, public StatBlock {
public:
    static const HPType HPGROWTH = (HPType)9u;
    static const StatType BASESTR = (StatType)1u;
    static const StatType BASEINT = (StatType)4u;
    Wizard() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}

private:
};
