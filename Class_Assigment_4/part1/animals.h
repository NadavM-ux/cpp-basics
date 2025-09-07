// animals.h
// Header file containing class declarations for various animals in the zoo.
//
// This file defines an abstract base class `Animal` and a hierarchy of
// derived classes representing the different types of animals described
// in the assignment. Each animal knows its species and can perform
// several actions: eating, displaying a show to visitors and (for
// mobile animals) performing physical activity. Before any action is
// executed the animal prints its own type as required by the
// specification.

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <iostream>

// Base abstract class representing any animal in the zoo.
class Animal {
protected:
    // The species/type name of the animal (e.g., "Lion", "Sponge").
    std::string species;
public:
    // Constructor accepts a string identifying the species.
    explicit Animal(const std::string &sp) : species(sp) {}
    // Virtual destructor for proper cleanup via base pointers.
    virtual ~Animal() = default;

    // Returns true if the animal can move (i.e., is mobile).
    virtual bool isMobile() const = 0;
    // Performs the eating action. Must be overridden by derived classes.
    virtual void eat() = 0;
    // Performs the show/display action. Must be overridden by derived classes.
    virtual void show() = 0;
    // Performs physical activity. Only meaningful for mobile animals.
    // The default implementation does nothing and can be overridden.
    virtual void exercise() {}
    // Helper to print the species name before every action. Keeps
    // printing logic in one place.
    void printSpecies() const {
        std::cout << species << std::endl;
    }
};

// Immobile animals cannot move. They do not have a meaningful exercise
// method, so it remains the default no‑op. These animals still eat and
// show their beauty to visitors.
class ImmobileAnimal : public Animal {
public:
    explicit ImmobileAnimal(const std::string &sp) : Animal(sp) {}
    // Immobile animals are not mobile.
    bool isMobile() const override { return false; }
    // Inherit default exercise() doing nothing.
};

// Mobile animals can move and therefore have a non‑trivial exercise
// method. They divide into carnivores and herbivores.
class MobileAnimal : public Animal {
public:
    explicit MobileAnimal(const std::string &sp) : Animal(sp) {}
    // Mobile animals are mobile.
    bool isMobile() const override { return true; }
    // Mobile animals must provide an implementation for exercise.
    void exercise() override = 0;
};

// Carnivores eat other animals. They share common eating and exercise
// behaviour but differ in how they display themselves to visitors. Each
// carnivore has a preferred prey printed during eating.
class Carnivore : public MobileAnimal {
protected:
    std::string prey; // the name of the prey this carnivore likes to eat
public:
    Carnivore(const std::string &sp, const std::string &pr)
        : MobileAnimal(sp), prey(pr) {}
    // Carnivores eat by preying on other animals. Print the species name
    // and then the common eating message with the specific prey.
    void eat() override {
        printSpecies();
        std::cout << "Preying! Eating " << prey << "! Yummy!" << std::endl;
    }
    // Carnivores exercise by running after potential food.
    void exercise() override {
        printSpecies();
        std::cout << "Running after potential food." << std::endl;
    }
    // Carnivores must implement their own show behaviour.
    virtual void show() override = 0;
};

// Herbivores eat plants and display similarly but have different exercise
// behaviour based on their family. Derived classes override
// getExerciseMsg() to provide the appropriate text.
class Herbivore : public MobileAnimal {
public:
    explicit Herbivore(const std::string &sp) : MobileAnimal(sp) {}
    // All herbivores eat grass.
    void eat() override {
        printSpecies();
        std::cout << "Eating grass." << std::endl;
    }
    // All herbivores display the same bored stare.
    void show() override {
        printSpecies();
        std::cout << "Borred staring at the guests." << std::endl;
    }
    // Herbivores exercise differently depending on the concrete family.
    void exercise() override {
        printSpecies();
        std::cout << getExerciseMsg() << std::endl;
    }
    // Derived classes must supply the message printed during exercise.
    virtual std::string getExerciseMsg() const = 0;
};

// Family of herbivores that run fast in circles (e.g., horse, zebra).
class HorseFamily : public Herbivore {
public:
    explicit HorseFamily(const std::string &sp) : Herbivore(sp) {}
    std::string getExerciseMsg() const override {
        return "Running fast in circles.";
    }
};

// Family of herbivores that walk slowly in the garden (e.g., cow, sheep, buffalo).
class CattleFamily : public Herbivore {
public:
    explicit CattleFamily(const std::string &sp) : Herbivore(sp) {}
    std::string getExerciseMsg() const override {
        return "Walking slowly in the garden.";
    }
};

// Concrete species declarations. Each species constructor simply sets
// the species name and passes the correct prey or exercise family as
// appropriate.

// Carnivores
class Lion : public Carnivore {
public:
    Lion() : Carnivore("Lion", "Gnu") {}
    void show() override {
        printSpecies();
        std::cout << "Royal walking in the garden." << std::endl;
    }
    // Lions have a special stadium performance: hunting.
    void huntShow() {
        printSpecies();
        std::cout << "Hunting!" << std::endl;
    }
};

class WhiteShark : public Carnivore {
public:
    WhiteShark() : Carnivore("White shark", "Fish") {}
    void show() override {
        printSpecies();
        std::cout << "Water diving." << std::endl;
    }
};

class Wolf : public Carnivore {
public:
    Wolf() : Carnivore("Wolf", "Rabbit") {}
    void show() override {
        printSpecies();
        std::cout << "Joyful running and flapping their tail." << std::endl;
    }
};

// Herbivores – horse family
class Zebra : public HorseFamily {
public:
    Zebra() : HorseFamily("Zebra") {}
};

class Horse : public HorseFamily {
public:
    Horse() : HorseFamily("Horse") {}
};

// Herbivores – cattle and sheep family
class Cow : public CattleFamily {
public:
    Cow() : CattleFamily("Cow") {}
};

class Sheep : public CattleFamily {
public:
    Sheep() : CattleFamily("Sheep") {}
};

class Buffalo : public CattleFamily {
public:
    Buffalo() : CattleFamily("Buffalo") {}
};

// Immobile animals – sponges and corals
class Sponge : public ImmobileAnimal {
public:
    Sponge() : ImmobileAnimal("Sponge") {}
    void eat() override {
        printSpecies();
        std::cout << "Filtering waterflow to obtain food." << std::endl;
    }
    void show() override {
        printSpecies();
        std::cout << "Beautiful & colorful views!" << std::endl;
    }
};

class Coral : public ImmobileAnimal {
public:
    Coral() : ImmobileAnimal("Coral") {}
    void eat() override {
        printSpecies();
        std::cout << "Feeding on a variety of small sea-organisms." << std::endl;
    }
    void show() override {
        printSpecies();
        std::cout << "Beautiful & colorful views!" << std::endl;
    }
};

#endif // ANIMALS_H