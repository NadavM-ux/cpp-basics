#include "tools.h"

void printMenuItems(Item** menu, int size) {
    for (int i = 0; i < size; ++i) {
        // assumes Item has toFullString()
        std::cout << (i + 1) << ". " << menu[i]->toFullString() << "\n";
    }
}

Order* minCalories(const Resturant& rest) {
    Order** orders = rest.getOrders();
    int     n      = rest.getOrdersCount();
    if (!orders || n == 0) return nullptr;

    int bestIdx = 0;
    int bestCal = orders[0]->getCalories();
    for (int i = 1; i < n; ++i) {
        int c = orders[i]->getCalories();
        if (c < bestCal) { bestCal = c; bestIdx = i; }
    }
    return orders[bestIdx];  // pointer to an order owned by the restaurant
}
