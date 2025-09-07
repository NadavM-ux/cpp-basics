// zoo.h

#ifndef ZOO_H
#define ZOO_H

#include "animals.h"

class Zoo {
private:
    static const int maxAnimals  = 200; // total cages
    static const int maxMobiles  = 100; // cages for mobile animals
    static const int maxLions    = 200; // lions list size (at most total animals)

    Animal*        animals[maxAnimals];
    int            animalCount;

    MobileAnimal*  mobiles[maxMobiles];
    int            mobileCount;

    Lion*          lions[maxLions];
    int            lionCount;

public:
    Zoo();

    // Destructor frees all animals exactly once (from the main list).
    ~Zoo();

    // Only place RTTI is allowed (dynamic_cast).
    // Takes ownership of 'a' on success; returns false and DOES NOT
    // take ownership on failure.
    bool addAnimal(Animal* a);

    void feedAll();     // feed all animals
    void showAll();     // all animals perform their show
    void activateAll(); // exercise all mobile animals
    void lionShow();    // stadium hunting show (all lions)
};

#endif // ZOO_H
