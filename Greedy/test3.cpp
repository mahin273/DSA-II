#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void smallest_unit_intervals(vector<double> &points, vector<double> &start_points, vector<double> &end_points)
{
    sort(points.begin(), points.end()); // Sort the points in ascending order
    int i = 0;

    while (i < points.size())
    {
        double start = points[i];
        double end = start + 1;
        while (i + 1 < points.size() && points[i + 1] <= end)
        {
            i++;
        }
        start_points.push_back(start);
        end_points.push_back(end);
        i++;
    }
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<double> points(n);
    cout << "Enter the points: ";
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    vector<double> start_points;
    vector<double> end_points;
    smallest_unit_intervals(points, start_points, end_points);

    cout << "Smallest set of unit-length closed intervals:" << endl;
    for (int i = 0; i < start_points.size(); i++)
    {
        cout << "[" << start_points[i] << ", " << end_points[i] << "]" << endl;
    }

    return 0;
}

// All okk