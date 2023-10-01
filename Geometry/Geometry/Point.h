#pragma once

#include <iostream>

struct Point {
    double x = 0.;
    double y = 0.;

    bool operator==(const Point& other) const;
};

std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream&, Point&);
double distance(const Point&p1, const Point&p2);
