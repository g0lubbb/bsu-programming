#include <cstdint>
#include <gtest/gtest.h>
#include <type_traits>
#include <visibilityWindow.h>
#include <fileIOData.h>


TEST(PointSegmentTests, buildScreenTest) {
	//std::array<Point, 3> buildScreen(const std::vector<Point>& list);
	std::vector<Point> list;
	Point point0{1920, 1080};
	Point point1{1500, 500};
	Point point2{400, 1850};
	list.push_back(point0);
	list.push_back(point1);
	list.push_back(point2);

	std::array<Point, 3> screenReal{std::make_pair(1920, 1080),std::make_pair(400, 500),std::make_pair(1500, 1080)};
	std::array<Point, 3> screen = buildScreen(list);
	EXPECT_EQ(screenReal, screen);
}

TEST(PointSegmentTests, compareTest) {
	//int compare(const Point & point1, const Point & point2) noexcept
}

TEST(PointSegmentTests, parserTest) {
	//std::vector<int> parser(const std::string & str) noexcept;
}

TEST(PointSegmentTests, parserPointsTest) {
	//std::vector<Point> parserPoints(const std::vector<std::string>& container);
}

TEST(PointSegmentTests, parserSegmentsTest) {
	//std::vector<Segment> parserSegments(const std::vector<std::string>& container);
}
TEST(PointSegmentTests, getPointsTest) {
	//std::vector<Point> getPoints(const std::vector<Segment>&segments) noexcept;

}

TEST(PointSegmentTests, findUniquePointsTest) {
	//std::set<Point> findUniquePoints(const std::vector<Point>&points) noexcept;

}

TEST(PointSegmentTests, findUniqueSegmentsTest) {
	//std::set<Segment> findUniqueSegments(const std::vector<Segment>&segments) noexcept;
}
