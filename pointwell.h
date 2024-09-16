#pragma once // Only include this file once

#include <cstdint>
typedef std::uint16_t WellType;

class PointWell {
public:
    //returns true if set sucessfully
    bool setMax(WellType newMax) {
        if (newMax < 1)
            return false;

        Max = newMax;

        if (Current > Max)
            Current = Max;

        return true;
    }

    WellType getMax() const {
        return Max;
    }

    WellType getCurrent() const {
        return Current;
    }

    void reduce(WellType damage) {
        if (damage > Current) {
            Current = 0;
            return;
        }

        Current -= damage;
    }

    void increase(WellType amount) {
        if (Current + amount > Max) {
            Current = Max;
            return;
        }

        Current += amount;
    }

    // Default constructor
    PointWell() {
        Current = 1;
        Max = 1;
    }

    // Constructor with parameters
    PointWell(WellType c, WellType m) {
        Current = c;
        Max = m;

        if (Current > Max)
            Current = Max;
    }

private:
    WellType Current;
    WellType Max;
};