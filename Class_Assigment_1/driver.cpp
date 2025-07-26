    #include "Time.h"
    #include "tools.h"
    #include <iostream>

    using namespace std;

    int main() {
        Time time1, time2(14, 23, 3), time3(200, -100, 60);
        
        cout << "<<< time1 >>> ";
        time1.print(); cout << " | ";
        time1.printAmPm(); cout << " | ";
        time1.printTime(); cout << " | ";
        cout << "time1 to sec.:" << time1.toSecond() << endl;
        
        cout << "<<< time2 >>> ";
        time2.print(); cout << " | ";
        time2.printAmPm(); cout << " | ";
        time2.printTime(); cout << " | ";
        cout << "time2 to sec.:" << time2.toSecond() << endl;
        
        cout << "<<< time3 >>> ";
        time3.printTime(); cout << " | ";
        time3.fromSecond(30000);
        time3.printTime(); cout << " | ";
        time3.printAmPm(); cout << endl;
        
        cout << "<<< time4 >>> ";
        Time time4(time2.toSecond() + 1000);
        time4.printTime(); cout << endl;
        
        cout << "<<< next second >>>\n";
        time1.print(); cout << " | ";
        for (int i = 0; i < 5; i++) {
            time1.next();
            time1.print(); cout << " | ";
        }
        cout << endl;
        
        cout << "<<< next minute >>>\n";
        time2.print(); cout << " | ";
        for (int i = 0; i < 5; i++) {
            time2.next(60);
            time2.print(); cout << " | ";
        }
        cout << endl;
        
        cout << "<<< printRocketLanding >>> \n";
        Time time5, time6(2, 15);
        printRocketLanding(time5, 10000);
        printRocketLanding(time6, 10000);
        printRocketLanding(time5, time6);
        printRocketLanding(time6, 216000);
        
        cout << "<<< printTimeDifference >>> \n";
        time1.print(); cout << " | ";
        time2.print(); cout << " | ";
        time3.print(); cout << endl;
        printTimeDifference(time1, time2); cout << endl;
        printTimeDifference(time2, time3); cout << endl;
        
        cout << "<<< printSort >>> \n";
        int x = 5, y = 3, z = 4;
        cout << x << " " << y << " " << z << endl;
        printSort(x, y); cout << endl;
        printSort(x, y, z); cout << endl;
        
        time2.print(); cout << " | ";
        time3.print(); cout << " | ";
        time1.print(); cout << endl;
        printSort(time2, time3); cout << endl;
        printSort(time2, time3, time1); cout << endl;
        
        return 0;
    }
