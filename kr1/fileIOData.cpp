#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "fileIOData.h"


std::string toString(const std::string& obj)  {
	throw std::runtime_error{"Not implemented"};
}

std::string toString(const Point& obj) {
	throw std::runtime_error{"Not implemented"};
}

std::string toString(const Segment& obj) {
	throw std::runtime_error{"Not implemented"};
}

std::string toString(const std::pair<Point, uint8_t>& codePoint) {
	throw std::runtime_error {"Not implemented"};
}


std::vector<std::string> read(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::invalid_argument("File name is wrong: " + filePath);
        }
        return read (file);
    }
std::vector<std::string> read(std::istream& theStream) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(theStream, line))
{
    lines.push_back(line);
}
    return lines;
}

