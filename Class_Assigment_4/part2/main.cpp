#include <iostream>
#include <string>

#include "Point.h"   // <-- You need this for the Point class
#include "List.h"    // <-- You need this for the List class
#include "Utility.h" // <-- You need this for doTwice and maxT

using namespace std;

int main() {
cout << "<<< List<int> >>>" << endl;
List<int> list1;
cout << "list1: " << list1 << endl;
cout <<"append{1,2,3}: "<<list1.append(1).append(2).append(3)<< endl;
cout << "length(): " << list1.length() << endl;
List<int> list2(list1);
cout << "list2(list1): " << list2 << endl;
cout << "list1.extend(list2).remove(0): "
<< list1.extend(list2).remove(0) << endl;;
cout << "count(3): " << list1.count(3) << endl;
list2 = list1;
cout << "list2=list1: " << list2 << endl;
list2[0] = 100;
list2[-1] = 200;
cout << "list2{[0]=100,[-1]=200}: " << list2 << endl;
cout << "index(2): " << list2.index(2) << endl;
cout << "list2 slicing: " << list2["2:"] + list2[":3"] +
list2["1:-1"] << endl;
cout << "list1: " << list1 << endl;
list1 += list2["2:"];
cout << "list1{+= & slicing}: " << list1 << endl;
list1.clear();
cout << "list1.clear(): " << list1 << endl;
cout << "\n<<< List<string> >>>" << endl;
List<string> list3, list4, list5;
cout << "list3,list4,list5: " <<list3<<","<<list4<<","<<list5<<endl;
cout << "list3.append(): " << list3.append("London").append("is").
append("the").append("capital").append("of") << endl;
cout << "list4.append(): "
<< list4.append("Great").append("Britian")<<endl;
cout << "list5.append(): "
<< list5.append("Paris").append("France") <<endl;
list3 += list4;
cout << "list3 += list4: " << list3 << endl;
cout << "slicing & [index]:" << endl;
cout << list3 << endl << list3[":4"] << endl << list3["-2:"]
<< " - " << list3[0] << endl;
cout << list5[":1"] + list3["1:-2"] + list5["1:"] << endl;
cout << "\n<<< Functions >>>" << endl;
cout <<"list2,doTwice(list2): " <<list2<<","<< doTwice(list2)<<endl;
cout << "list5,doTwice(list5): " <<list5<<","<<doTwice(list5)<< endl;
int arr1[] = { 7,2,14,5,10 };
cout << "maxT<int>: " << maxT(arr1, 5) << endl;
string arr2[] = { "aaa","abcd","aaaaa","qwerty","qaz"};
cout << "maxT<string>: " << maxT(arr2, 5) << endl;
Point arr3[] = { Point(1,0),Point(),Point(7,2),Point(3,12),
Point(5,6)};
cout << "maxT<Point>: " << maxT(arr3, 5).toString() << endl;
return 0;
}

