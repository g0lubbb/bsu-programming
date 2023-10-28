#ifndef VISIBILITY_WINDOW_H_
#define VISIBILITY_WINDOW_H_

#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>

using Point = std::pair<int, int>;
using Segment = std::pair<Point, Point>;

std::array<Point, 3> buildScreen(const std::vector<Point>& list);
int compare(const Point& point1, const Point& point2);

std::vector<int> parser(const std::string& str);
std::vector<Point> parserPoints(const std::vector<std::string>& container);
std::vector<Segment> parserSegments(const std::vector<std::string>& container);

std::vector<Point> getPoints(const std::vector<Segment>& segments);

std::map<Point, uint8_t> caclCode(const std::array<Point, 3> &screen,const std::vector<Point>& points);
uint8_t caclCode(const std::array<Point, 3>& screen, const Point& point);

std::set<Point> findPointsInWindow(const std::map<Point, uint8_t>& codePoints);
std::set<Point> findPointsOutsideWindow(const std::map<Point, uint8_t>& codePoints);

bool segmentIsInside(const Segment& segment, const std::map<Point, uint8_t>& codePoints) ;
bool segmentIsOutside(const Segment& segment, const std::map<Point, uint8_t>& codePoints);

std::set<Point> findUniquePoints(const std::vector<Point>& points);
std::set<Segment> findUniqueSegments(const std::vector<Segment>& segments);

std::set<Segment> findSegmentsInWindow(const std::set<Segment>& segments, const std::map<Point, uint8_t>& codePoints);
std::set<Segment> findSegmentsOutsideWindow(const std::set<Segment>& segments, const std::map<Point, uint8_t>& codePoints);


#endif // !VISIBILITY_WINDOW_H_
