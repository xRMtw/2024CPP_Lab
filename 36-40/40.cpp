#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

class Point {
    public:
        double x, y;
        Point(double x, double y) : x(x), y(y) {}
};

class Path {
    private:
        vector<Point> points;
        int pointCount;
        
    public:

        Path(int pointCount) : pointCount(pointCount) {
            points.reserve(pointCount);
        }
        
        void addPoint(double x, double y) {
            points.push_back(Point(x, y));
        }
        
        void sortPoints() {
            for (int i = 0; i < pointCount; i++) {
                for (int j = i + 1; j < pointCount; j++) {
                    if ( points[i].x < points[j].x) {
                        swap(points[i].x, points[j].x);
                        swap(points[i].y, points[j].y);
                }
            }
        }
        }
        
    double calculateSunnySide() {
        
        sortPoints();

        int prev_point_y = 1;
        double sum = distance(points[0], points[1]);
        
        for (int i = 2; i < pointCount; i++) {
            if (points[i].y > points[prev_point_y].y) {
                double ae = distance(points[i], points[i - 1]);
                double ab = abs(points[i].y - points[prev_point_y].y);
                double ad = abs(points[i].y - points[i - 1].y);
                sum += ae * (ab / ad);
                prev_point_y = i;
            }
        }
        
        return sum;
    }
    
    static double distance(const Point &a, const Point &b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
};

int main() {
    
    int T, t = 0;
    cin >> T;
            
     while (t++ < T) {
        int points;
        cin >> points;

        Path path(points);
                
        for (int i = 0; i < points; i++) {
            double x, y;
            cin >> x >> y;
            path.addPoint(x, y);
        }
                
        cout << fixed << setprecision(2) << path.calculateSunnySide() << endl;
    }
        
    return 0;
}

