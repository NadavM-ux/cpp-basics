// zoo.cpp
#include "zoo.h"

Zoo::Zoo() : animalCount(0), mobileCount(0), lionCount(0) {}
Zoo::~Zoo() {
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
}

bool Zoo::addAnimal(Animal* a) {
    animals[animalCount++] = a;
    
    // Check if its a mobile animal
    MobileAnimal* mobile = dynamic_cast<MobileAnimal*>(a);
    if (mobile != nullptr && mobileCount < maxMobiles) {
        mobiles[mobileCount++] = mobile;
    }

    Lion* lion = dynamic_cast<Lion*>(a);
    if (lion != nullptr && lionCount < maxLions) {
        lions[lionCount++] = lion;
    }

    return true;
}

void Zoo::feedAll() {
    std::cout << " Feeding All Animals " << std::endl;
    for (int i = 0; i < animalCount; i++) {
        animals[i]->eat();
    }
}

void Zoo::showAll() {
    std::cout << " Showing All Animals " << std::endl;
    for (int i = 0; i < animalCount; i++) {
        animals[i]->show();
    }
}

void Zoo::activateAll() {
    std::cout << "\n--- Activating all mobile animals ---" << std::endl;
    // Loop through the 'mobiles' array and call exercise() on each one.
    for (int i = 0; i < mobileCount; i++) {
        mobiles[i]->exercise();
    }
}

void Zoo::lionShow() {
    std::cout << "\n--- Starting the Lion hunting show! ---" << std::endl;
    // Loop through the 'lions' array and call their special huntShow() method.
    for (int i = 0; i < lionCount; i++) {
        lions[i]->huntShow();
    }
}