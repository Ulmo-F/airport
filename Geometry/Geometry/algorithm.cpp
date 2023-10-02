#include <Geometry/algorithm.h>
#include <Geometry/Segment.h>

#include <algorithm>
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

double greatestDistanceWithoutIntersect(const std::vector<Point>& points) {
    double result = 0.;
    // Cubic algorithm
    // We check at most 199*100 * 200 intersections, probably still fast enough

    std::vector<Segment> borders(points.size());
    for (size_t i = 1; i < points.size(); ++i)
        borders[i-1] = { points[i-1], points[i] };
    borders[points.size()-1] = { points[points.size()-1], points[0] };
    auto filter = [&borders](const Segment& s){
            return ! std::any_of(
                std::begin(borders),
                std::end(borders),
                [&s](const Segment& b) { return b.doIntersect(s); }
            );
        };

    for(auto iter = std::begin(points); iter != std::end(points); ++iter)
        for(auto iter2 = iter + 1; iter2 != std::end(points); ++iter2)
            if (filter({*iter, *iter2}))
                result = std::max(result, distance(*iter, *iter2));

    // TODO :
    // - generator for segments for all pairs of points
    // - generator for segments of consecutive points
    // - filter for generated segment range (using )
    // borders = Consecutives(points);
    // filter = std::function<bool(Segment)>{}
    // maxDistance = max(AllSegments(points) | filter, segment.length());
    return result;
}
