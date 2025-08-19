#include "Order.h"

// ---------- constructors ----------

Order::Order()
    : name(""), time(), item(nullptr), itemSize(0) {}

Order::Order(const std::string& name)
    : name(name), time(), item(nullptr), itemSize(0) {}

Order::Order(const std::string& name, const Time& orderTime)
    : name(name), time(orderTime), item(nullptr), itemSize(0) {}

// many-items ctor → just delegate to addItems
Order::Order(const std::string& name,
             const Time& orderTime,
             Item** menu, int menuSize,
             int* itemIndex, int itemAmount)
    : name(name), time(orderTime), item(nullptr), itemSize(0)
{
    addItems(menu, menuSize, itemIndex, itemAmount);
}
void Order::addItems(Item** menu, int menuSize, int index1based) {
    addItems(menu, menuSize, &index1based, 1); // reuse the main function
}

// single-item ctor (handy wrapper)
Order::Order(const std::string& name,
             Item** menu, int menuSize,
             int itemIndex)
    : name(name), time(), item(nullptr), itemSize(0)
{
    addItems(menu, menuSize, &itemIndex, 1);
}

// copy-ctor: deep-copy the POINTER ARRAY (not the Items).
Order::Order(const Order& other)
    : name(other.name), time(), item(nullptr), itemSize(other.itemSize)
{
    if (itemSize > 0) {
        item = new Item*[itemSize];
        for (int i = 0; i < itemSize; ++i) {
            item[i] = other.item[i];  // copy pointers only
        }
    }
}

// copy assignment (Rule of Three)
Order& Order::operator=(const Order& other) {
    if (this == &other) return *this;

    name = other.name;
    time = other.time;  // copy on assignment is fine

    Item** newArr = nullptr;
    if (other.itemSize > 0) {
        newArr = new Item*[other.itemSize];
        for (int i = 0; i < other.itemSize; ++i) {
            newArr[i] = other.item[i];
        }
    }

    delete[] item;
    item = newArr;
    itemSize = other.itemSize;
    return *this;
}

// destructor: delete the ARRAY of pointers (we do NOT delete the Items)
Order::~Order() {
    delete[] item;
    item = nullptr;
    itemSize = 0;
}

// ---------- getters ----------

std::string Order::getName() const { return name; }
Time        Order::getTime() const { return time; }
Item**      Order::getItem() const { return item; }
int         Order::getMenuSize() const { return itemSize; }

// ---------- setters ----------

void Order::setName(const std::string& n) { name = n; }
void Order::setTime(const Time& t) { time = t; }

// ---------- functions ----------

// addItems: assumes inputs are valid; indices are 1-based
void Order::addItems(Item** menu, int /*menuSize*/, int* indices, int count) {
    int old = itemSize;

    // 1) new array: old + count
    Item** newArr = new Item*[old + count];

    // 2) copy existing pointers
    for (int i = 0; i < old; ++i) {
        newArr[i] = item[i];
    }

    // 3) append from menu using 1-based indices
    for (int i = 0; i < count; ++i) {
        newArr[old + i] = menu[ indices[i] - 1 ];
    }

    // 4) swap in
    delete[] item;
    item = newArr;
    itemSize = old + count;
}

// remove an item by 1-based index (tiny safety check included)
void Order::removeItem(int index) {
    if (index < 1 || index > itemSize) return;  // if you truly assume valid, you can delete this
    int rem = index - 1;

    if (itemSize == 1) {
        delete[] item;
        item = nullptr;
        itemSize = 0;
        return;
    }

    Item** newArr = new Item*[itemSize - 1];
    for (int i = 0, w = 0; i < itemSize; ++i) {
        if (i == rem) continue;
        newArr[w++] = item[i];
    }
    delete[] item;
    item = newArr;
    itemSize -= 1;
}

int Order::getTotal() const {
    int sum = 0;
    for (int i = 0; i < itemSize; ++i) {
        sum += item[i]->getPrice();   // assumes Item::getPrice() exists
    }
    return sum;
}

int Order::getCalories() const {
    int sum = 0;
    for (int i = 0; i < itemSize; ++i) {
        sum += item[i]->getCalories(); // assumes Item::getCalories() exists
    }
    return sum;
}

std::string Order::toString() const {
    std::string s = "Order for: " + name + "\n";
    s += "Time: " + time.toString() + "\n";
    s += "Items: " + std::to_string(itemSize) + "\n";
    for (int i = 0; i < itemSize; ++i) {
        s += "  " + std::to_string(i + 1) + ". " + item[i]->toString() + "\n";
    }
    s += "Total: " + std::to_string(getTotal())
       + " | Calories: " + std::to_string(getCalories());
    return s;
}
