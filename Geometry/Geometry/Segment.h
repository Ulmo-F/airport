#pragma once

#include <Geometry/Point.h>

struct Segment {
    Point p1;
    Point p2;

    bool operator==(const Segment& other) const;
    bool doIntersect(const Segment& other) const;
};
