#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <map>
#include <set>

#include "visibilityWindow.h"

using Point = std::pair<int, int>;
using Segment = std::pair<Point, Point>;
//Функция создания «экрана» на основе набора точек и нормализация параметров окна видимости
std::array<Point, 3> buildScreen(const std::vector<Point>& list) {
    if (list.size() != 3) {
        throw std::invalid_argument("It is not enough screen data");
    }
    Point p1 = list[0];
    Point p2 = list[1];
    Point p3 = list[2];
    if (p1.first < 0 or p1.second < 0) {
        throw std::invalid_argument("Window dimensions must be positive");
    }
    if (p1.first >= p2.first or  p1.second >= p2.second) {
        std::swap(p1, p2);
    }
    if (p1.first < p2.first && p1.second < p2.second) {
        throw std::invalid_argument("Visisbility window is out the screen");
    }
    else if (p1.first < p3.first) {
        p3.first = p1.first;
    }
    else if (p1.second < p3.second) {
        p3.second = p1.first;
    }
    return {p1, p2, p3};
}
//Функция парсинг строки в числа
std::vector<int> parser(const std::string& str) {
    std::istringstream s(str);
    std::vector<int> result;
    int num;
        while (s >> num) {
            result.push_back(num);
}
    return result;
}
//Функция парсинга коллекции строк в коллекцию точек
std::vector<Point> parserPoints(const std::vector<std::string>& container) {
    std::vector<Point> points;
    for (const std::string& str : container) {
        std::vector<int> data = parser(str);
        if (data.size() != 2) {
            throw std::invalid_argument("It is not a point");
        }
        points.emplace_back(data[0], data[1]);
    }
    return points;
    }
//и в коллекцию отрезков
std::vector<Segment> parserSegments(const std::vector<std::string>& container) {
    std::vector <Segment> segments;
    for (const std::string &str: container) {
        std::vector<int> data = parser(str);
        if (data.size() != 4) {
            throw std::invalid_argument("It is not a segment");
        }
    }
}

std::vector<Point> getPoints(const std::vector<Segment>& segments) noexcept {
    throw std::runtime_error{"Not implemented"};
}
//Перегрузка функции п.6. Функция определения кода всех точек концов отрезков
std::map<Point, uint8_t> caclCode(const std::array<Point, 3>& screen, const std::vector<Point>& points) noexcept {
    std::map<Point, uint8_t> codeMap;
    for (const Point& point : points) {
        codeMap[point] = caclCode(screen, point);
    }
    return codeMap;
}
// Функция определения кода точки
uint8_t caclCode(const std::array<Point,3>& screen, const Point& point) noexcept {
     uint8_t code = 0;
    if (point.first < screen[0].first) code |= 0x1; // 0001
    if (point.first > screen[1].first) code |= 0x2; // 0010
    if (point.second < screen[0].second) code |= 0x4; // 0100
    if (point.second > screen[1].second) code |= 0x8; // 1000
    return code;
}

//Функции нахождения списка точек лежащих в окне видимости и вне окна видимости

std::set<Point> findPointsInWindow(const std::map<Point, uint8_t>& codePoints) noexcept {
    std::set<Point> pointsInWindow;
    for (const auto& pointCodePair : codePoints) {
        if (pointCodePair.second == 0) {
            pointsInWindow.insert(pointCodePair.first);
        }
    }
    return pointsInWindow;
}
//Функции нахождения списка точек лежащих вне окна видимости и вне окна видимости
std::set<Point> findPointsOutsideWindow(const std::map<Point, uint8_t>& codePoints) noexcept {
    std::set<Point> pointsOutsideWindow;
    for (const auto& pointCodePair : codePoints) {
        if (pointCodePair.second != 0) {
            pointsOutsideWindow.insert(pointCodePair.first);
        }
    }
    return pointsOutsideWindow;
}

// true, если лежит внутри окна видимости

//Функции определения того, что отрезок находится в окне видимости
bool segmentIsInside(const Segment& segment, const std::map<Point, uint8_t>& codePoints) noexcept {
    uint8_t code1 = codePoints.at(segment.first);
    uint8_t code2 = codePoints.at(segment.second);
    return (code1 | code2) == 0;
}
// true, если лежит вне окна видимости

//Функции определения того, что отрезок находится вен окна видимости
bool segmentIsOutside(const Segment& segment, const std::map<Point, uint8_t>& codePoints) noexcept {
    uint8_t code1 = codePoints.at(segment.first);
    uint8_t code2 = codePoints.at(segment.second);
    return (code1 & code2) != 0;
}

// Сначала сделаем отрезки ориентированными, началом отрезка будем считать "меньшую точку" - точку у которой абсцисса меньше, если абсциссы равны, то сравниваем ординаты для этого используем compare(const Point&, const Point&)
// Вырожденные отрезки исключаем из списка уникальных.


//Функция определения уникальных отрезков
std::set<Segment> findUniqueSegments(const std::vector<Segment>& segments) noexcept {

}

//Возвращаемое значение будет -1, 0 или 1, если первый аргумент меньше, равен или больше второго соответственно.
int compare(const Point& point1, const Point& point2) noexcept{
    throw std::runtime_error{"Not implemented"};
}
//Функция определения уникальных точек
std::set<Point> findUniquePoints(const std::vector<Point>& points) noexcept {
    std::set<Point> uniquePoints(points.begin(), points.end());
    return uniquePoints;
}

std::set<Segment> findSegmentsInWindow(const std::set<Segment>& segments, const std::map<Point, uint8_t>& codePoints) noexcept {
}

std::set<Segment> findSegmentsOutsideWindow(const std::set<Segment>& segments,
        const std::map<Point, uint8_t>& codePoints) noexcept {
}
