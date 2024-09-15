#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"

class Clerik : public HP, public StatBlock, public LevelSystem {
public:
    static const HPType HPGROWTH = (HPType)14u;
    static const StatType BASESTR = (StatType)2u;
    static const StatType BASEINT = (StatType)3u;
    Clerik() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}

private:
};
