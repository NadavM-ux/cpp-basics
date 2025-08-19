#pragma once
#include <string>

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time();
        Time(int seconds);
        Time(int hours, int minutes);
        Time(int hours, int minutes, int seconds);
 
        // Getters
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        // Setters
        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);

        int toSecond() const;
        void fromSecond(int seconds);
        void next(int seconds = 1);

        void print() const;
        void printAmPm() const;
        void printTime() const;

        std::string toString() const;
        int compare(const Time& time) const;
};