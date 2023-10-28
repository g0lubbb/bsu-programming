#include <cstdint>
#include <gtest/gtest.h>
#include <type_traits>
#include "visibilityWindow.h"
#include "fileIOData.h"


/*
* 4 test group - visability window
*/
TEST(PointSegmentTests, caclCodeAllPointsTest) {
	//std::map<Point, uint8_t> caclCode(const std::array<Point, 3> &screen,const std::vector<Point>& points) noexcept;

}

TEST(PointSegmentTests, caclCodePointTest) {
	//uint8_t caclCode(const std::array<Point, 3>& screen, const Point& point) noexcept;
}
TEST(PointSegmentTests, findPointsInWindowTest) {
	//std::set<Point> findPointsInWindow(const std::map<Point, uint8_t>& codePoints) noexcept;

}
TEST(PointSegmentTests, findPointsOutsideWindowTest) {
	//std::set<Point> findPointsOutsideWindow(const std::map<Point, uint8_t>& codePoints) noexcept;
}
TEST(PointSegmentTests, segmentIsInsideTest) {
	//bool segmentIsInside(const Segment& segment, const std::map<Point, uint8_t>& codePoints) noexcept;
}
TEST(PointSegmentTests, segmentIsOutsideTest) {
	//bool segmentIsOutside(const Segment& segment, const std::map<Point, uint8_t>& codePoints) noexcept;
}
TEST(PointSegmentTests, findSegmentsInWindowTest) {
	//std::set<Segment> findSegmentsInWindow(const std::set<Segment>& segments, const std::map<Point, uint8_t>& codePoints) noexcept;
}
TEST(PointSegmentTests, findSegmentsOutsideWindow) {
	//std::set<Segment> findSegmentsOutsideWindow(const std::set<Segment>& segments, const std::map<Point, uint8_t>& codePoints) noexcept;
}
