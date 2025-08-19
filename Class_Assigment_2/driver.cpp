#include <thread>
#include <iostream>
#include "Resturant.h"
#include "tools.h"

using namespace std;

int main() {
cout << "<<< Time >>>" << endl;
Time time1;
cout << time1.toString() << endl;
Time time2(10, 4, 35);
cout << time1.compare(time2) << " " << time2.compare(time1) <<
" " << time1.compare(time1) << endl;
cout << "<<< Item >>>" << endl;
Item item1("burger");
cout << item1.toFullString() << endl;
Item item2("cola", 10.49f, 300);
cout << item2.toFullString() << endl;
Item item3(item1);
item3.setName("nutburger");
item3.setPrice(12.3f);
item3.setCalories(250);
cout << item3.toFullString() << endl;
cout << "compare: " << item2.compare(item3).toString() << endl;
Item* menu[] = { new Item("McDouble",10,400), new Item("Big_Mac",12,550),
new Item("McChicken",10,400), new Item("Fries",5,320),
new Item("Cappuccino",3,160), new Item("Coca-Cola",5,210) };
cout << "items amount: " << Item::getNumOfItems() << endl;
printMenuItems(menu, 6);
cout << "<<< Order >>>" << endl;
Order order1("David");
cout << order1.toString() << endl;
order1.addItems(menu, 6, 1);
cout << order1.toString() << endl;
order1.addItems(menu, 6, new int[2] { 3, 5 }, 2);
cout << order1.toString() << endl;
order1.removeItem(2);
cout << order1.toString() << endl;
Order order2("Tali", Time(10, 23, 37), menu, 6, new int[4] {2,4,5,6}, 4);
cout << order2.toString() << endl;
Order order3(order2);
order3.setName("Jim");
cout << order3.toString() << endl;
cout << "<<< Restaurant >>>" << endl;
Resturant rest1("BurgerPoint", menu, 6);
cout << rest1.toString() << endl;
rest1.printMenu();
cout << "-------------------------------------\n";
rest1.addMenuItem(Item("Green_Salad", 12, 434));
rest1.removeMenuItem(1);
rest1.printMenu();
cout << "-------------------------------------\n";
rest1.addOrders(new Order("David", Time(10, 12, 17), rest1.getMenu(),
rest1.getMenuSize(), new int[4] {2, 4, 5, 6}, 4));
rest1.addOrders(new Order * [2] { new Order("Tali", Time(),
rest1.getMenu(), rest1.getMenuSize(), new int[3] {1, 3, 5}, 3),
new Order("Jim", Time(10, 15, 16), rest1.getMenu(), rest1.getMenuSize(),
new int[4] {1, 2, 3, 5}, 4) }, 2);
rest1.printOrders();
cout << "-------------------------------------\n";
cout << rest1.toString() << endl;
cout << "-------------------------------------\n";
cout << minCalories(rest1)->toString() << endl;
cout << "-------------------------------------\n";
Resturant rest2 = Resturant(rest1);
rest2.setName("BurgerSheva");
cout << rest2.toString() << endl;
return 0;
}