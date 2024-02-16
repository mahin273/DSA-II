#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void closestPairOfPoints(std::vector<Point>& points) {
    int n = points.size();
    double minDistance = INT_MAX;
    Point closestP1, closestP2;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestP1 = points[i];
                closestP2 = points[j];
            }
        }
    }

    std::cout << "Closest pair of points: (" << closestP1.x << ", " << closestP1.y << ") and (" << closestP2.x << ", " << closestP2.y << ")" << std::endl;
    std::cout << "Distance: " << minDistance << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of points: ";
    std::cin >> n;

    std::vector<Point> points(n);
    std::cout << "Enter the coordinates of the points:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << ": ";
        std::cin >> points[i].x >> points[i].y;
    }

    closestPairOfPoints(points);

    return 0;
}
