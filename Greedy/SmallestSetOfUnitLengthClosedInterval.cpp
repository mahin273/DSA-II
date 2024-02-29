#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<double, double>> smallest_unit_intervals(vector<double> &points)
{
    sort(points.begin(), points.end()); // Sort the points in ascending order
    vector<pair<double, double>> intervals;
    int i = 0;

    while (i < points.size())
    {
        double start = points[i];
        double end = start + 1;
        while (i + 1 < points.size() && points[i + 1] <= end)
        {
            i++;
        }
        intervals.push_back(make_pair(start, end));
        i++;
    }

    return intervals;
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

    vector<pair<double, double>> result = smallest_unit_intervals(points);

    cout << "Smallest set of unit-length closed intervals:" << endl;
    for (auto interval : result)
    {
        cout << "[" << interval.first << ", " << interval.second << "]" << endl;
    }

    return 0;
}