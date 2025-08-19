#include "Item.h"
int Item::totalCreated = 0;
Item::Item() : name("Default Item"), price(0.0), calories(0) {
    this->id = ++totalCreated;
}

Item::Item(const std::string& name) : price(0.0), calories(0) {
    this->name = name;
    this->id = ++totalCreated;
}

Item::Item(const std::string& name, double price, int calories)
    : name(name), price(price), calories(calories) {
    this->id = ++totalCreated;
}


Item::Item(const int id, const std::string& name, const double price, const int calories) 
    : name(name), price(price), calories(calories) {
    
    this->id = ++totalCreated;
}

Item::Item(const Item& copy) 
    : name(copy.name), price(copy.price), calories(copy.calories) {

    this->id = ++totalCreated;
}



Item::~Item() {--totalCreated; }

// --- Functions --- 
std::string Item::toFullString() const {
    std::string s = "item(";
    s += std::to_string(id) + ",";
    s += name + ",";
    s += std::to_string(price) + ",";
    s += std::to_string(calories);
    s += ")";                // no extra comma
    return s;
}

std::string Item::toString() const {
    std::string price = std::to_string(this->price);
    std::string calories = std::to_string(this->calories);

    std::string str = "item(";
    str = str + this->name + ",";
    str = str + price + ","; 
    str = str + calories + ","; 
    str = str + ")";
    return str;
}

Item Item::compare(const Item& other) const {
    if (this->calories < other.calories) {
        return *this;
    } else {
        return other;
    }
}

int Item::getNumOfItems() {
    return Item::totalCreated;
}



// ---  Getters ---
int Item::getId() const {
    return this->id;
}

std::string Item::getName() const {
    return this->name;
}

double Item::getPrice() const {
    return this->price;
}

int Item::getCalories() const {
    return this->calories;
}

// --- Setters --- 
void Item::setId(const int id) {
    this->id = id;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setPrice(const double price) {
    this->price = price;
}

void Item::setCalories(const int calories) {
    this->calories = calories;
}



