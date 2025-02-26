#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}

double polar_angle(const Point &p1, const Point &p2) {
    if (p1.y == p2.y) return -M_PI;
    return atan2(p1.y - p2.y, p1.x - p2.x);
}

int orientation(const Point &p, const Point &q, const Point &r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? -1 : 1;
}

bool compareMinElement(const Point &a, const Point &b) {
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

Point p0;
bool compareSort(const Point &a, const Point &b) {
    double angleA = polar_angle(p0, a);
    double angleB = polar_angle(p0, b);
    if (angleA == angleB)
        return dist(p0, a) < dist(p0, b);
    return angleA < angleB;
}

vector<Point> graham(vector<Point> &points) {
    p0 = *min_element(points.begin(), points.end(), compareMinElement);
    
    sort(points.begin(), points.end(), compareSort);
    
    vector<Point> hull;
    for (const auto &p : points) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), p) != 1) {
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = graham(points);
    
    cout << "Convex Hull Points:" << endl;
    for (const auto &p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    
    return 0;
}
