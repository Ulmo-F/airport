#include <Geometry/BoundingBox.h>

#include <stdexcept>

BoundingBox::BoundingBox(const Point& lowerLeft, const Point& upperRight)
    : _LowerLeft(lowerLeft)
    , _UpperRight(upperRight)
{
    if (_LowerLeft.x > _UpperRight.x || _LowerLeft.y > _UpperRight.y)
        throw std::runtime_error("Invalid bounding box");
}

BoundingBox BoundingBox::create(const std::vector<Point>& points) {
    if (points.empty())
        throw std::runtime_error("No bounding box for an empty points vector");
    BoundingBox result(points[0], points[0]);
    for (const auto& point : points) {
        result._LowerLeft.x = std::min(result._LowerLeft.x, point.x);
        result._LowerLeft.y = std::min(result._LowerLeft.y, point.y);

        result._UpperRight.x = std::max(result._UpperRight.x, point.x);
        result._UpperRight.y = std::max(result._UpperRight.y, point.y);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const BoundingBox& bb) {
    os << bb.LowerLeft() << "-" << bb.UpperRight();
    return os;
}

std::istream& operator>>(std::istream& is, BoundingBox& bb) {
    is >> bb._LowerLeft;
    char c;
    is.get(c);
    if (c != '-')
        throw std::runtime_error("Invalid bounding box - missing separator");
    is >> bb._UpperRight;

    return is;
}

bool BoundingBox::operator==(const BoundingBox& other) const {
    return _LowerLeft == other._LowerLeft && _UpperRight == other._UpperRight;
}
