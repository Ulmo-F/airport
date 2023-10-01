#include <Geometry/algorithm.h>

#include <numeric>

double greatestDistance(const std::vector<Point>& points) {
    double result = 0.;
    // Quadratic algorithm, we could do better (google mentions n.log(n))
    // But as the number of points stays low (<= 200) we don't need to be smart
    for(auto iter = std::begin(points); iter != std::end(points); ++iter)
        result = std::accumulate(
                iter + 1,
                std::end(points),
                result,
                [&p1=*iter](double val, const Point& p2) { return std::max(val, distance(p1, p2)); }
            );

    return result;
}
