#include "tools.h"
#include "Time.h"
#include <iostream>
#include <cmath>

/**
 * @brief  Calculates and prints the absolute time difference between two Time objects.
 *
 * @param  t1 The first time point.
 * @param  t2 The second time point.
 */
void printTimeDifference(const Time& t1, const Time& t2) {
    int s1 = t1.toSecond();
    int s2 = t2.toSecond();

    int diff_seconds = std::abs(s1 - s2);
    Time diff_time(diff_seconds);

    std::cout << "Time Difference: " << diff_seconds << " / ";
    diff_time.print();
}

void printTimeDifference(const Time& t1, const Time& t2, const Time& t3) {
    printTimeDifference(t1, t2);
    printTimeDifference(t2, t3);
}

/**
 * @brief  Calculates and prints the landing time of a rocket.
 *
 * @param  launchTime The starting time of the launch.
 * @param  durationSeconds The flight duration in total seconds.
 */
void printRocketLanding(const Time& launchTime, int durationSeconds) {
    long totalSeconds = launchTime.toSecond();
    totalSeconds += durationSeconds;

    int days = totalSeconds / 86400;
    int landing_seconds_of_day = totalSeconds % 86400;

    Time landing_time(landing_seconds_of_day);


    std::cout << " Landing Time: ";
    if (days > 0) std::cout << "[+" << days << " day],";
    landing_time.print();
    std::cout << std::endl;
}

void printRocketLanding(const Time& launchTime, const Time& duration) {
    int durationSeconds = duration.toSecond();
    printRocketLanding(launchTime, durationSeconds);
}

void printSort(const Time& t1, const Time& t2) {
    if (t1.toSecond() > t2.toSecond()) {
        t2.print();
        std::cout << " ";
        t1.print();
    } else {
        t1.print();
        std::cout << " ";
        t2.print();    
    }
}

void printSort(int a, int b) {
    if (a > b) {
        std::cout << b << " " << a;
    } else {
        std::cout << a << " " << b;
    }
}

void printSort(int a, int b, int c) {
    if (a > b) {
        int temp = a; 
        a = b;
        b = temp;
    }

    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    std::cout << a << " " << b << " " << c << std::endl;
}

void printSort(const Time& t1, const Time& t2, const Time& t3) {
	Time times[] = {t1, t2, t3};

	// Simple bubble sort with manual swap
	if (times[0].toSecond() > times[1].toSecond()) {
		Time temp = times[0];
		times[0] = times[1];
		times[1] = temp;
	}
	if (times[1].toSecond() > times[2].toSecond()) {
		Time temp = times[1];
		times[1] = times[2];
		times[2] = temp;
	}
	if (times[0].toSecond() > times[1].toSecond()) {
		Time temp = times[0];
		times[0] = times[1];
		times[1] = temp;
	}

	times[0].print();
	std::cout << " ";
	times[1].print();
	std::cout << " ";
	times[2].print();
}