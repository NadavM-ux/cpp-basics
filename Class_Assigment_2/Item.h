#pragma once
#include <string>

class Item {
    private:
        int id;
        std::string name;
        double price;
        int calories;

        static int totalCreated; // Count how many objects have been created.
    public:
        // --- Constructors ---
        Item();
        Item(const std::string& name, double price, int calories);
        Item(const std::string& name);
        Item(const int id, const std::string& name, const double price, const int calories);
        Item(const Item& copy);

        // -- Destractors
        ~Item();

        // -- Getters 
        int getId() const;
        std::string getName() const;
        double getPrice() const;
        int getCalories() const;

        // --- Setters ---
        void setId(const int id);
        void setName(const std::string& name);
        void setPrice(const double price);
        void setCalories(const int calories);

        std::string toFullString() const;
        std::string toString() const;
        Item compare(const Item& other) const;

        static int getNumOfItems();
};