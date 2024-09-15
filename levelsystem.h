#pragma once

#include <cstdint>

typedef std::uint64_t EXPType;
typedef std::uint16_t LevelType;

class LevelSystem {
public:
    static const EXPType LEVEL2AT = 100u;

    LevelSystem() {
        CurrentLevel = 1u;
        CurrentEXP = 0u;
        LevelUpsAvailable = 0u;
        EXPToNextLevel = LEVEL2AT;
    }

    void gainEXP(std::uint64_t gainedEXP) {
        CurrentEXP += gainedEXP;
        check_if_leveled();
    }


protected:
    LevelType CurrentLevel;
    LevelType LevelUpsAvailable;
    EXPType CurrentEXP;
    EXPType EXPToNextLevel;


    void check_if_leveled() {

        if (CurrentEXP < 100u) {
            return;
        }

        static const LevelType LEVELSCALAR = 2u;
    }
};
