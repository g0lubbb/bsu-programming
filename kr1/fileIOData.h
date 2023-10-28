#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>

using Point = std::pair<int, int>;
using Segment = std::pair<Point, Point>;

std::string toString(const std::string& obj);
std::string toString(const Point& obj);
std::string toString(const Segment& obj);
std::string toString(const std::pair<Point, uint8_t>& codePoint);

std::vector<std::string> read(const std::string& filePath);
std::vector<std::string> read(std::istream& theStream);


