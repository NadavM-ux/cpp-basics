#pragma once
#include <string>
#include "Time.h"
#include "Item.h"

class Order {
private:
    std::string name;
    Time        time;
    Item**      item;      // array of pointers; we do NOT delete the Items themselves
    int         itemSize;

public:
    Order();
    Order(const std::string& name);
    Order(const std::string& name, const Time& orderTime);

    // Add many items by indices (1-based)
    Order(const std::string& name,
          const Time& orderTime,
          Item** menu, int menuSize,
          int* itemIndex, int itemAmount);

    // Add one item by index (1-based)
    Order(const std::string& name,
          Item** menu, int menuSize,
          int itemIndex);

    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();

    // Getters
    std::string getName() const;
    Time        getTime() const;
    Item**      getItem() const;
    int         getMenuSize() const;

    // Setters
    void setName(const std::string& name);
    void setTime(const Time& time);

    // Functions (assume inputs are valid; indices are 1-based)
    void addItems(Item** menu, int menuSize, int* indices, int count);
    void addItems(Item** menu, int menuSize, int index1based);
    void removeItem(int index);     
    int  getTotal() const;          
    int  getCalories() const;       
    std::string toString() const;   
};
