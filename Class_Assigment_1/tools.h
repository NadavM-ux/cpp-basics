#pragma once
#include "Time.h"

// --- Rocket Landing Functions ---
void printRocketLanding(const Time& launchTime, int durationSeconds);
void printRocketLanding(const Time& launchTime, const Time& duration);

// --- Time Difference Functions ---
void printTimeDifference(const Time& t1, const Time& t2);
void printTimeDifference(const Time& t1, const Time& t2, const Time& t3);

// --- Sorting Functions ---
void printSort(int a, int b);
void printSort(int a, int b, int c);
void printSort(const Time& t1, const Time& t2);
void printSort(const Time& t1, const Time& t2, const Time& t3);
