#pragma once // Only include this file once

typedef std::uint16_t HPType;

class HP {
public:
    //returns true if set sucessfully
    bool setMaxHP(HPType newMaxHP) {
        if (newMaxHP < 1)
            return false;

        MaxHP = newMaxHP;

        if (CurrentHP > MaxHP)
            CurrentHP = MaxHP;

        return true;
    }

    HPType getMaxHP() const {
        return MaxHP;
    }

    HPType getCurrentHP() const {
        return CurrentHP;
    }

    void takeDamage(HPType damage) {
        if (damage > CurrentHP) {
            CurrentHP = 0;
            return;
        }

        CurrentHP -= damage;
    }

    void heal(HPType amount) {
        if (CurrentHP + amount > MaxHP) {
            CurrentHP = MaxHP;
            return;
        }

        CurrentHP += amount;
    }

    // Default constructor
    HP() {
        CurrentHP = 1;
        MaxHP = 1;
    }

    // Constructor with parameters
    HP(HPType cHP, HPType mHP) {
        CurrentHP = cHP;
        MaxHP = mHP;

        if (CurrentHP > MaxHP)
            CurrentHP = MaxHP;
    }

private:
    HPType CurrentHP;
    HPType MaxHP;
};