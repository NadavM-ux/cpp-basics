#include "Time.h"
#include <iostream>
#include <ctime>


Time::Time() {
    std::time_t t = std::time(nullptr);
    std::tm * tm_ptr = std::localtime(&t);

    if (tm_ptr) {
        hours   = tm_ptr->tm_hour;
        minutes = tm_ptr->tm_min;
        seconds = tm_ptr->tm_sec;
    } else {
        hours = minutes = seconds = 0;
    }
}

Time::Time(int hours, int minutes) {
    if (hours >= 0 && hours < 24) {
        this->hours = hours;
    } else {
        this->hours = 0;
    }

    if (minutes >= 0 && minutes < 60) {
        this->minutes = minutes;
    } else {
        this->minutes = 0;
    }

    this->seconds = 0; 
}

Time::Time(int h, int m, int s) {
    if (h >= 0 && h < 24) {
        this->hours = h;
    } else {
        this->hours = 0;
    }

    if (m >= 0 && m < 60) {
        this->minutes = m;
    } else {
        this->minutes = 0;
    }

    if (s >= 0 && s < 60) {
        this->seconds = s;
    } else {
        this->seconds = 0;
    }
}

Time::Time(int totalSeconds) {
    totalSeconds %= 86400;
    
    this->hours = totalSeconds / 3600; // An hour contains 3600 seconds.

   int remainingSeconds = totalSeconds % 3600; // Remaining Seconds
 
   this->minutes = remainingSeconds / 60; // Minutes
 
   this->seconds = remainingSeconds % 60; // Seconds
}

std::string Time::toString() const {
    std::string str;
    str.reserve(8);

    str = str + (this->hours < 10 ? "0" : "");
    str = str + std::to_string(this->hours);
    str = str + ":";

    str = str + (this->minutes < 10 ? "0" : "");
    str = str + std::to_string(this->minutes);
    str = str + ":";

    str = str + (this->seconds < 10 ? "0" : "");
    str = str + std::to_string(this->seconds);

    return str;
}

int Time::compare(const Time& secondTime) const {
    if (this->hours != secondTime.getHours()) return (this->hours < secondTime.getHours()) ? -1 : 1;
    if (this->minutes != secondTime.getMinutes()) return (this->minutes < secondTime.getMinutes()) ? -1 : 1;
    if (this->seconds != secondTime.getSeconds()) return (this->seconds < secondTime.getSeconds()) ? -1 : 1;

    // If the time is equal - returning 0.
    return 0;
}

/* Getters */
int Time::getHours() const {
    return this->hours;
}

int Time::getMinutes() const {
    return this->minutes;
}

int Time::getSeconds() const {
    return this->seconds;
}
// ----- ----- ----- // 

/* Setters */
void Time::setHours(int hour) {
    this->hours = hour;
}

void Time::setMinutes(int minutes) {
    this->minutes = minutes;
}

void Time::setSeconds(int seconds) {
    this->seconds = seconds;
}
// ----- ----- ----- // 

int Time::toSecond() const {
    return (this->hours * 3600) + (this->minutes * 60) + this->seconds;
}

void Time::fromSecond(int seconds) {
    if (seconds < 0) {
        seconds = 0;
    }
    seconds %= 86400;

    this->hours = seconds / 3600; // An hour contains 3600 seconds.

    int remainingSeconds = seconds % 3600; // Remaining Seconds
 
    this->minutes = remainingSeconds / 60; // Minutes
 
    this->seconds = remainingSeconds % 60; // Seconds
}

void Time::next(int seconds) {
    int total = this->toSecond();
    total += seconds;
    this->fromSecond(total);
}

void Time::print() const {
    if (this->hours < 10) std::cout << "0";
    std::cout << this->hours << ":";

    if (this->minutes < 10) std::cout << "0";
    std::cout << this->minutes << ":";

    if (this->seconds < 10) std::cout << "0";
    std::cout << this->seconds;
}

void Time::printAmPm() const {
    int hours = this->hours;
    int minutes = this->minutes;

    if (this->seconds >= 30) minutes++;
    if (minutes == 60) {
        minutes = 0;
        hours++;
    }
    if (hours == 24) hours = 0;

    const char* time;

    int hoursToPrint;

    if (hours >= 12) {
        time = "_PM";
        hoursToPrint = hours - 12;
    } else {
        time = "_AM";
        hoursToPrint = hours;
    }

    if (hoursToPrint == 0) hoursToPrint = 12;

    if (hoursToPrint < 10) std::cout << "0";
    std::cout << hoursToPrint << ":";

    if (minutes < 10) std::cout << "0";
    std::cout << minutes;
    std::cout << time;
}

void Time::printTime() const { 
    std::cout << "Time(" << this->hours << "," << this->minutes << "," << this->seconds << ")";
}