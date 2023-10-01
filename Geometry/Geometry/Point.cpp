#include <Geometry/Point.h>

#include <cmath>

double distance(const Point&p1, const Point&p2) {
    return std::sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.x << " " << p.y;
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
