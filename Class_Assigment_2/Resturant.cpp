#include "Resturant.h"
#include <iostream>   // for printMenu / printOrders

/// ----- Ctors / Dtor -----

Resturant::Resturant()
    : resturantName(""), items(nullptr), itemsCount(0), orders(nullptr), ordersCount(0) {}

Resturant::Resturant(const std::string& resturatName, Item** resturantMenu, int menuSize)
    : resturantName(resturatName), items(nullptr), itemsCount(0), orders(nullptr), ordersCount(0)
{
    // Deep-copy the incoming menu so the restaurant owns its own Items
    if (resturantMenu && menuSize > 0) {
        items = new Item*[menuSize];
        for (int i = 0; i < menuSize; ++i) {
            items[i] = new Item(*resturantMenu[i]);   // copy-construct each Item
        }
        itemsCount = menuSize;
    }
}

// Copy-ctor: copy name and deep-copy Items; do NOT copy Orders (start empty)
Resturant::Resturant(const Resturant& other)
    : resturantName(other.resturantName),
      items(nullptr), itemsCount(0),
      orders(nullptr), ordersCount(0)
{
    if (other.items && other.itemsCount > 0) {
        items = new Item*[other.itemsCount];
        for (int i = 0; i < other.itemsCount; ++i) {
            items[i] = new Item(*other.items[i]);     // deep copy each Item
        }
        itemsCount = other.itemsCount;
    }
    // orders stays empty by spec
}

void Resturant::addMenuItem(const Item& item) {
    Item** newArr = new Item*[itemsCount + 1];
    for (int i = 0; i < itemsCount; ++i) newArr[i] = items[i];
    newArr[itemsCount] = new Item(item);   // copy-construct
    delete[] items;
    items = newArr;
    itemsCount += 1;
}

void Resturant::addOrders(Order** arr, int count) {
    if (!arr || count <= 0) return;
    Order** newArr = new Order*[ordersCount + count];
    for (int i = 0; i < ordersCount; ++i) newArr[i] = orders[i];
    for (int j = 0; j < count; ++j) newArr[ordersCount + j] = new Order(*arr[j]); // deep copy
    delete[] orders;
    orders = newArr;
    ordersCount += count;
}
void Resturant::setResturantName(const std::string& name) { resturantName = name; }
void Resturant::setName(const std::string& name)          { resturantName = name; }


// Copy-assignment: free current, deep-copy Items, reset Orders
Resturant& Resturant::operator=(const Resturant& other) {
    if (this == &other) return *this; // self-assignment guard

    // Free current Items
    if (items) {
        for (int i = 0; i < itemsCount; ++i) delete items[i];
        delete[] items;
        items = nullptr;
        itemsCount = 0;
    }

    // Free current Orders
    if (orders) {
        for (int i = 0; i < ordersCount; ++i) delete orders[i];
        delete[] orders;
        orders = nullptr;
        ordersCount = 0;
    }

    // Copy simple field(s)
    resturantName = other.resturantName;

    // Deep-copy Items
    if (other.items && other.itemsCount > 0) {
        items = new Item*[other.itemsCount];
        for (int i = 0; i < other.itemsCount; ++i) {
            items[i] = new Item(*other.items[i]);
        }
        itemsCount = other.itemsCount;
    }

    // Per spec: do NOT copy orders; leave empty
    return *this;
}

Resturant::~Resturant() {
    if (items) {
        for (int i = 0; i < itemsCount; ++i) delete items[i];
        delete[] items;
        items = nullptr;
        itemsCount = 0;
    }
    if (orders) {
        for (int i = 0; i < ordersCount; ++i) delete orders[i];
        delete[] orders;
        orders = nullptr;
        ordersCount = 0;
    }
}

/// ----- Getters -----

std::string Resturant::getResturantName() const { return resturantName; }
Item**      Resturant::getMenu() const         { return items; }
int         Resturant::getMenuSize() const    { return itemsCount; }
Order**     Resturant::getOrders() const        { return orders; }
int         Resturant::getOrdersCount() const   { return ordersCount; }

/// ----- Setter -----

void Resturant::setName(std::string& name) { resturantName = name; }

/// ----- Functions -----

// Adds a COPY of the given Item object to the menu the restaurant owns
void Resturant::addMenuItem(Item* itemPtr) {
    // allocate new pointer array (+1)
    Item** newArr = new Item*[itemsCount + 1];

    // copy existing pointers
    for (int i = 0; i < itemsCount; ++i) newArr[i] = items[i];

    // append a deep copy of the incoming Item
    newArr[itemsCount] = new Item(*itemPtr);

    // swap in
    delete[] items;           // delete old array (not the items)
    items = newArr;
    itemsCount += 1;
}

// Remove by 1-based index. Deletes the owned Item and compacts the array.
void Resturant::removeMenuItem(int index) {
    if (index < 1 || index > itemsCount) return; // tiny guard; remove if inputs are guaranteed valid
    int rem = index - 1;

    // delete the Item object we own at that slot
    delete items[rem];

    if (itemsCount == 1) {
        delete[] items;
        items = nullptr;
        itemsCount = 0;
        return;
    }

    // compact to a new array of size-1
    Item** newArr = new Item*[itemsCount - 1];
    for (int i = 0, w = 0; i < itemsCount; ++i) {
        if (i == rem) continue;
        newArr[w++] = items[i];
    }
    delete[] items;
    items = newArr;
    itemsCount -= 1;
}

// Adds a COPY of the given Order to the restaurant's orders
void Resturant::addOrders(const Order* orderPtr) {
    Order** newArr = new Order*[ordersCount + 1];

    // copy existing order pointers
    for (int i = 0; i < ordersCount; ++i) newArr[i] = orders[i];

    // append a deep copy of the Order object
    newArr[ordersCount] = new Order(*orderPtr);

    delete[] orders;  // delete only the pointer array
    orders = newArr;
    ordersCount += 1;
}

void Resturant::printMenu() const {
    std::cout << "Menu (" << itemsCount << " items):\n";
    for (int i = 0; i < itemsCount; ++i) {
        std::cout << "  " << (i + 1) << ". " << items[i]->toString() << "\n";
    }
}

void Resturant::printOrders() const {
    std::cout << "Orders (" << ordersCount << "):\n";
    for (int i = 0; i < ordersCount; ++i) {
        std::cout << "  " << (i + 1) << ". " << orders[i]->toString() << "\n";
    }
}

// Simple summary string
std::string Resturant::toString() const {
    std::string s = "Restaurant: " + resturantName + "\n";
    s += "Items: " + std::to_string(itemsCount) + "\n";
    s += "Orders: " + std::to_string(ordersCount) + "\n";
    return s;
}
