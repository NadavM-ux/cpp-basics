#pragma once
#include "Order.h"
#include "Item.h"
#include <string>

class Resturant {
    private:
        std::string resturantName;
        Item** items;
        int itemsCount;

        Order** orders;
        int ordersCount;  
    
    public:
        Resturant();
        Resturant(const std::string& resturatName, Item** resturantMenu, int menuSize);
        Resturant(const Resturant& other);
        Resturant& operator=(const Resturant& other);
        ~Resturant();


        // --- Getters ---
        std::string getResturantName() const;
        Item** getMenu() const;
        int getMenuSize() const;
        Order** getOrders() const;
        int getOrdersCount() const;
        

        // --- Setters ---
        void setName(std::string& resturantName);

        // --- Functions ---
        void addMenuItem(Item* itemPtr);
        void removeMenuItem(int index);
        void addOrders(const Order* orderPtr);
        void addMenuItem(const Item& item);   
        void printMenu() const;
        void addOrders(Order** arr, int count);    // NEW overload
// change the old one
void setResturantName(const std::string& resturantName);  // was non-const ref
// add the driver’s name
void setName(const std::string& name);

        void printOrders() const;
        std::string toString() const;
};
