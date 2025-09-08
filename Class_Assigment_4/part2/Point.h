// Point.h
#pragma once
#include <string>
#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    std::string toString() const {
        return "Point(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

    bool operator>(const Point& other) const {
        return (this->x + this->y) > (other.x + other.y);
    }
};