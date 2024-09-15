#include <iostream>
#include "allclasses.h"

int main() {
    Warrior warr1;
    Wizard wiz1;
    Clerik cler1;
    Rogue rog1;

    std::cout << "Warrior\n" << "HP: " << warr1.getCurrentHP() << "/" << warr1.getMaxHP() << "\n" << "Strength: " << warr1.getStrength() << "\n" << "Intellect: " << warr1.getIntellect() << "\n\n";

    std::cout << "Wizard\n" << "HP: " << wiz1.getCurrentHP() << "/" << wiz1.getMaxHP() << "\n" << "Strength: " << wiz1.getStrength() << "\n" << "Intellect: " << wiz1.getIntellect() << "\n\n";

    std::cout << "Clerik\n" << "HP: " << cler1.getCurrentHP() << "/" << cler1.getMaxHP() << "\n" << "Strength: " << cler1.getStrength() << "\n" << "Intellect: " << cler1.getIntellect() << "\n\n";

    std::cout << "Rogue\n" << "HP: " << rog1.getCurrentHP() << "/" << rog1.getMaxHP() << "\n" << "Strength: " << rog1.getStrength() << "\n" << "Intellect: " << rog1.getIntellect() << "\n\n";
    return 0;
}