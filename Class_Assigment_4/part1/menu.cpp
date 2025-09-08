#include "menu.h"
#include "animals.h"

#define MIN_ANIMALS 5

bool Menu::addAnimal() {
    int choice = 0;
    std::cout << "\n--- Select an animal to add ---" << std::endl;
    std::cout << "1. Lion" << std::endl;
    std::cout << "2. Zebra" << std::endl;
    std::cout << "3. Sponge" << std::endl;
    std::cout << "4. Cow" << std::endl;
    std::cout << "5. White Shark" << std::endl;
    std::cout << "6. Wolf" << std::endl;
    std::cout << "7. Horse" << std::endl;
    std::cout << "8. Sheep" << std::endl;
    std::cout << "9. Buffalo" << std::endl;
    std::cout << "10. Coral" << std::endl;

    std::cout << "Enter your choice:";
    std::cin >> choice;

    Animal* newAnimal = nullptr;
    switch (choice) {
        case 1: newAnimal = new Lion(); break;
        case 2: newAnimal = new Zebra(); break;
        case 3: newAnimal = new Sponge(); break;
        case 4: newAnimal = new Cow(); break;
        case 5: newAnimal = new WhiteShark(); break;
        case 6: newAnimal = new Wolf(); break;
        case 7: newAnimal = new Horse(); break;
        case 8: newAnimal = new Sheep(); break;
        case 9: newAnimal = new Buffalo(); break;
        case 10: newAnimal = new Coral(); break;
        default:
            std::cout << "Invalid animal choice." << std::endl;
            return false;
            
    }
    if (!(zoo.addAnimal(newAnimal))) {
        delete newAnimal;
        return false;
    }
    return true;
}

void Menu::run() {
    std::cout << "The zoo is empty. Please add 5 animals to begin." << std::endl;
    for (int i = 0; i < MIN_ANIMALS;) {
        std::cout << "\nAdding Animal " << (i + 1) << " of 5: " << std::endl;
        if (this->addAnimal()) {
            i++;
        }
    }

    int choice = 0;

    while (choice != 6) {
        // Display all menu options
        std::cout << "\n--- Zoo Menu ---" << std::endl;
        std::cout << "1. Add another animal" << std::endl;
        std::cout << "2. Feed all animals" << std::endl;
        std::cout << "3. Show all animals' performance" << std::endl;
        std::cout << "4. Activate mobile animals" << std::endl;
        std::cout << "5. Start the Lion hunting show" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        // Read user input
        std::cin >> choice;

        switch (choice) {
            case 1:
                addAnimal();
                break;
            case 2:
                zoo.feedAll();
                break;
            case 3:
                zoo.showAll();
                break;
            case 4:
                zoo.activateAll();
                break;
            case 5:
                zoo.lionShow();
                break;
            case 6:
                std::cout << "Ending Program GoodBye! " << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    }
}