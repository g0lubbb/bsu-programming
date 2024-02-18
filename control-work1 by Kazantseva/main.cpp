#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<array>
#include<set>
#include<map>
#include "fileIOData.h"
//#include "consoleIOData.h"
#include "visibilityWindow.h"
using Point = std::pair<int, int>;
using Segment = std::pair<Point, Point>;
int main() {
    std::string screenFile = "data/screen.txt";
    std::string segmentsFile = "data/segments.txt";
    std::ostream& theOStream = std::cout;
    std::ofstream output("data/output.txt", std::ios::app);
    std::ostream& theOStream = output;
    try {
        // 1. Читаем из файла параметры экрана и окна видимости
        std::vector<std::string> strContainer = read(screenFile);
        write(theOStream, "It is read screen data as strings from the file " + screenFile, strContainer, "\n");
        std::vector<Point> pointList = parserPoints(strContainer);
        write(theOStream, "Initial screen data", pointList, ", ");
        // 2. Нормализация параметров окна видимости экрана (x1,y1) <= (x2, y2)
        std::array<Point, 3> screen = buildScreen(pointList);
        write(theOStream, "Screen normalization", screen, ", ");
        // 3. Читаем из файла все отрезки
        std::vector<std::string> strContainer1 = read(segmentsFile);
        write(theOStream, "It is read segments data as strings from the file " + segmentsFile, strContainer1, "\n");
        std::vector<Segment> segments = parserSegments(strContainer1);
        write(theOStream, "Initial segments",segments, ", ");
// 4. Получаем список точек - все концы отрезков
        std::vector<Point> points = getPoints(segments); write(theOStream, "Points - ends of the segments", points, ", ");
        // 5. Уникальные точки
        std::set<Point> uniquePoints = findUniquePoints(points);
        write(theOStream, "Unique points", uniquePoints, ", ");
// 6. Определяем код каждой точки. Код = код части плоскости, в которой расположена точка
        std::map<Point, uint8_t> codePoints = caclCode(screen, points);
        write(theOStream, "Code of points", codePoints, "\n");
// 7. Находим список точек (концов отрезков), лежащих в окне видимости
        std::set<Point> pointsInWindow = findPointsInWindow(codePoints); write(theOStream, "Points are in the visibility window", pointsInWindow, "\n");
// 8. Находим список точек (концов отрезков), лежащих вне окна видимости
        std::set<Point> pointsOutsideWindow = findPointsOutsideWindow(codePoints); write(theOStream, "Points are outside the visibility window", pointsOutsideWindow, "\n");
// 9. Находим коллекцию уникальных отрезков (x1, y1) - (x2, y2) == (x2, y2) - (x1, y1) - это один отрезок
        std::set<Segment> uniqueSegments = findUniqueSegments(segments);
        write(theOStream, "Unique segments ", uniqueSegments, "\n");
        // 10. Находим коллекцию отрезков внутри области видимости
        std::set<Segment> segmentsInWindow = findSegmentsInWindow(uniqueSegments, codePoints); write(theOStream, "Segments are in the window", segmentsInWindow, "\n");
// 11. Находим коллекцию отрезков вне области видимости
        std::set<Segment> segmentsOutsideWindow = findSegmentsOutsideWindow(uniqueSegments,
                                                                            codePoints);
        write(theOStream, "Segments are outside the window", segmentsOutsideWindow, "\n"); }
    catch (std::invalid_argument& ex) {
        std::cout << "ERROR: " << ex.what();
    }
    // output.close();
    return 0; }