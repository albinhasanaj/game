#include <iostream>
#include "playercharacter.h"

int main() {
    PlayerCharacter p1(new Warrior());
    PlayerCharacter p2(new Wizard());
    PlayerCharacter p3(new Rogue());
    PlayerCharacter p4(new Cleric());


    std::cout << p1.getClassName() << std::endl;
    std::cout << p2.getClassName() << std::endl;
    std::cout << p3.getClassName() << std::endl;
    std::cout << p4.getClassName() << std::endl;


    return 0;

};
