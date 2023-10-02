#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include <Geometry/algorithm.h>
#include <Geometry/BoundingBox.h>
#include <Geometry/Point.h>

void help(const char* exeName) {
    std::cerr << exeName << " dataFileName [1|2|...]\n"
              << "    dataFile is a text file, first line indicates number of entries, then each line has 'X Y' integer coordinates\n"
              << "    the following number tells the quality of the algorithm\n"
              << "      0: Display the bounding box of all points\n"
              << "      1: search most distant points, allowing crossings\n"
              << "      2: search most distant points among the given points, without considering crossing boundaries\n"
              << "      3: search most distant points, not crossing boundaries\n"
        ;
}

std::vector<Point> readPoints(const std::filesystem::path& filepath) {
    std::ifstream input(filepath);
    if (!input)
        throw std::runtime_error("Can't read file: " + filepath.string());
    size_t count;
    input >> count;
    if (!input)
        throw std::runtime_error("Error in file: " + filepath.string());

    std::vector<Point> result(count);
    for (size_t i = 0; i < count; ++i) {
        input >> result[i];
        if (!input)
            throw std::runtime_error("Error in file: " + filepath.string());
    }

    return result;
}

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        help(argv[0]);
        return 0;
    }

    try {
        std::vector<Point> points = readPoints(argv[1]);
        switch (argv[2][0]) {
        case '0':
            std::cout << "Bounding box: " << BoundingBox::create(points) << "\n";
            break;
        case '1':
            std::cout << "Greatest distance: " << greatestDistance(points) << "\n";
            break;
        case '2':
            std::cout << "Longest strip: " << greatestDistanceWithoutIntersect(points) << "\n";
            break;
        case '3':
            std::cout << "TODO\n";
            break;
        default:
            help(argv[0]);
            return 1;
        }
    } catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    } catch(...) {
        std::cerr << "unhandled error\n";
    }

    return 0;
}
