#include "Time.h"
#include <iostream>

Time::Time() {
    this->hours = 23;
    this->minutes = 59;
    this->seconds = 59;
}

Time::Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
    this->hours = hours; 
    this->minutes = minutes;
    this->seconds = seconds;
}

Time::Time(int totalSeconds) {
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
void Time::setHours(int& hour) {
    this->hours = hour;
}

void Time::setMinutes(int& minutes) {
    this->minutes = minutes;
}

void Time::setSeconds(int& seconds) {
    this->seconds = seconds;
}
// ----- ----- ----- // 

int Time::toSecond() const {
    return (this->hours * 3600) + (this->minutes * 60) + this->seconds;
}

void Time::fromSecond(int seconds) {
    this->hours = seconds / 3600; // An hour contains 3600 seconds.

   int remainingSeconds = seconds % 3600; // Remaining Seconds
 
   this->minutes = remainingSeconds / 60; // Minutes
 
   this->seconds = remainingSeconds % 60; // Seconds
}

void next(int seconds) {
    
}