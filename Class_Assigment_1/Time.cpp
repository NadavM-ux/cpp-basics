#include "Time.h"
#include <iostream>

Time::Time() {
    this->hours = 23;
    this->minutes = 59;
    this->seconds = 59;
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