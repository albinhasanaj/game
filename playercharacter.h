#pragma once

#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>

typedef std::uint64_t EXPType;
typedef std::uint16_t LevelType;

class PlayerCharacterDelegate : public StatBlock {
public:
    static const EXPType LEVEL2AT = 100u;

    PlayerCharacterDelegate() : StatBlock(0u, 0u) {
        CurrentLevel = 1u;
        CurrentEXP = 0u;
        EXPToNextLevel = LEVEL2AT;
        HP = std::make_unique<PointWell>();
    }

    void gainEXP(std::uint64_t gainedEXP) {
        CurrentEXP += gainedEXP;
        while (check_if_leveled()) {};
    }

    LevelType getLevel() const {
        return CurrentLevel;
    }

    EXPType getCurrentEXP() const {
        return CurrentEXP;
    }

    EXPType getEXPToNextLevel() const {
        return EXPToNextLevel;
    }

    virtual void LevelUp() = 0;
    virtual std::string getClassName() = 0;

    std::unique_ptr<PointWell> HP;

protected:
    LevelType CurrentLevel;
    LevelType LevelUpsAvailable;
    EXPType CurrentEXP;
    EXPType EXPToNextLevel;

    bool check_if_leveled() {
        static const LevelType LEVELSCALAR = 2u;
        if (CurrentEXP >= EXPToNextLevel) {
            CurrentLevel++;
            LevelUp();
            EXPToNextLevel *= LEVELSCALAR;
            return true;
        }
        return false;
    }
};

#define PCCONSTRUCT : PlayerCharacterDelegate() {\
    HP->setMax(BASEHP);\
    HP->increase(BASEHP);\
    increaseStats(BASESTR, BASEINT);}

#define LEVELUP void LevelUp() override {\
        HP->setMax((WellType)(BASEHP / 2.f) + HP->getMax());\
        HP->increase((WellType)(BASEHP / 2.f));\
        increaseStats((StatType)((BASESTR + 1u) / 2.f), (StatType)((BASEINT + 1u) / 2.f));};

class Cleric : public PlayerCharacterDelegate {
public:
    static const WellType BASEHP = (WellType)14u;
    static const StatType BASESTR = (StatType)2u;
    static const StatType BASEINT = (StatType)3u;

    Cleric()PCCONSTRUCT;

    std::string getClassName() override { return std::string("Cleric"); };


private:
    LEVELUP;
};

class Rogue : public PlayerCharacterDelegate {
public:
    static const WellType BASEHP = (WellType)12u;
    static const StatType BASESTR = (StatType)3u;
    static const StatType BASEINT = (StatType)5u;

    Rogue()PCCONSTRUCT;

    std::string getClassName() override { return std::string("Rogue"); };


private:
    LEVELUP;
};

class Warrior : public PlayerCharacterDelegate {
public:
    static const WellType BASEHP = (WellType)12u;
    static const StatType BASESTR = (StatType)3u;
    static const StatType BASEINT = (StatType)5u;

    Warrior()PCCONSTRUCT;

    std::string getClassName() override { return std::string("Warrior"); };


private:
    LEVELUP;
};


class Wizard : public PlayerCharacterDelegate {
public:
    static const WellType BASEHP = (WellType)10u;
    static const StatType BASESTR = (StatType)1u;
    static const StatType BASEINT = (StatType)4u;

    Wizard()PCCONSTRUCT;

    std::string getClassName() override { return std::string("Wizard"); };


private:
    LEVELUP;
};



class PlayerCharacter {
private:
    PlayerCharacterDelegate* PcClass;
public:
    PlayerCharacter() = delete;
    PlayerCharacter(PlayerCharacterDelegate* pc) : PcClass(pc) {};
    ~PlayerCharacter() { delete PcClass; PcClass = nullptr; }

    std::string getClassName() {
        return PcClass->getClassName();
    }
    LevelType getLevel() {
        return PcClass->getLevel();
    }
    EXPType getCurrentEXP() {
        return PcClass->getCurrentEXP();
    }
    EXPType getEXPToNextLevel() {
        return PcClass->getEXPToNextLevel();
    }
    WellType getcurrentHP() {
        return PcClass->HP->getCurrent();
    }
    WellType getMaxHP() {
        return PcClass->HP->getMax();
    }
    StatType getStrength() {
        return PcClass->getStrength();
    }
    StatType getIntellect() {
        return PcClass->getIntellect();
    }
    void gainEXP(EXPType gainedEXP) {
        PcClass->gainEXP(gainedEXP);
    }
    void takeDamage(WellType damage) {
        PcClass->HP->reduce(damage);
    }
    void heal(WellType amount) {
        PcClass->HP->increase(amount);
    }
};