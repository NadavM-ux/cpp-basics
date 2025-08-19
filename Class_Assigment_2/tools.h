#pragma once
#include <iostream>
#include "Item.h"
#include "Resturant.h"

// Print the menu items with details
void printMenuItems(Item** menu, int size);

// Return the order (Order*) in the restaurant with the fewest calories.
// If there are no orders, return nullptr.
Order* minCalories(const Resturant& rest);
