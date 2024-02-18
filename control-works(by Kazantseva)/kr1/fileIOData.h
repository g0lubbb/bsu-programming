#ifndef FILEIODATA_H_
#define FILEIODATA_H_

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
std::vector<std::string> read(std::istream& theStream) noexcept {
    std:: ifstream customin(std::istream& theStream);
    if (customin.is_open()) {
        std::string line;
        std::vector<std::string> strings;
        while (getline(customin, line)) {
            strings.push_back(line);
        }

    }
}
std::map<Point, uint8_t>
caclCode(const std::array<Point, 3>& screen, const std::vector<Point>& points) noexcept {
    throw std::runtime_error{"Not implemented"};
}

using Point = std::pair<int, int>;
using Segment = std::pair<Point, Point>;

std::string toString(const std::string& obj) noexcept;
std::string toString(const Point& obj) noexcept;
std::string toString(const Segment& obj) noexcept;
std::string toString(const std::pair<Point, uint8_t>& codePoint) noexcept;

std::vector<std::string> read(const std::string& filePath);
std::vector<std::string> read(std::istream& theStream) noexcept;

// void write(...) noexcept

#endif // !FILEIODATA_H_
