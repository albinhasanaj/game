#pragma once

typedef std::uint16_t StatType;

class StatBlock {
    // pass
    StatType Strength; // 0xFF
    StatType Intellect; // 0xFF --> half an int = 8 bits 

public:
    StatBlock() {
        Strength = (StatType)1u;
        Intellect = (StatType)1u;
    }
    explicit StatBlock(StatType s, StatType i) {
        Strength = s;
        Intellect = i;
    }

    StatType getStrength() const {
        return Strength;
    }

    StatType getIntellect() const {
        return Intellect;
    }
};