#pragma once

#include <vector>

#include <Geometry/Point.h>

class BoundingBox {
    Point _LowerLeft;
    Point _UpperRight;
    friend std::istream& operator>>(std::istream& is, BoundingBox& bb);
public:
    explicit BoundingBox(const Point& lowerLeft, const Point& upperRight);
    static BoundingBox create(const std::vector<Point>& points);
    Point LowerLeft() const { return _LowerLeft; }
    Point UpperRight() const { return _UpperRight; }
    bool operator==(const BoundingBox& other) const;
};

std::ostream& operator<<(std::ostream&, const BoundingBox&);
std::istream& operator>>(std::istream&, BoundingBox&);
