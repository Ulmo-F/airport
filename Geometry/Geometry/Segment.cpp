#include <Geometry/Segment.h>

bool Segment::operator==(const Segment& other) const {
    return (p1 == other.p1 && p2 == other.p2)
        || (p1 == other.p2 && p2 == other.p1);
}

// TODO: check for smarter implementations:
// https://bryceboe.com/2006/10/23/line-segment-intersection-algorithm/
// https://algorithmtutor.com/Computational-Geometry/Check-if-two-line-segment-intersect/
bool Segment::doIntersect(const Segment& other) const {
    double v1[2] = { p2.x - p1.x, p2.y - p1.y };
    double v2[2] = { other.p2.x - other.p1.x, other.p2.y - other.p1.y };
    double determinant = v1[0] * v2[1] - v2[0] * v1[1]; // Note: this is an integer with the provided data
    if (determinant == 0)
        // In this problem, colinear vector won't count as intersect
        // because "the landing strip may run along the boundary"
        return false;

    // Compute intersection point as p1 + t.(p2-p2) = other.p1 + s (other.p2-other.p1)
    // intersection <=> 0<t<1 && 0<s<1
    double d[2] = { other.p1.x-p1.x, other.p1.y - p1.y };
    double t_num = d[0]*v2[1] - d[1]*v2[0];
    double s_num = -d[0]*v1[1] + d[1]*v1[0];
    // t = t_num / determinant && s = s_num / determinant
    if (t_num * determinant <= 0) return false; // different sign, so t < 0
    if (std::abs(t_num) >= std::abs(determinant)) return false; // t >= 1

    if (s_num * determinant < 0) return false; // different sign, so s < 0
    if (std::abs(s_num) >= std::abs(determinant)) return false; // t >= 1

    return true;
}
