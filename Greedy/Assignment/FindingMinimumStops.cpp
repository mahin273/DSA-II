#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> gas_stops(int D, int m, int n, vector<int> &gas_stations)
{
    vector<pair<int, int>> stops;
    int current_position = 0;
    int last_stop = 0;

    for (int i = 0; i < n; i++)
    {
        if (gas_stations[i] - current_position > m)
        {
            if (i == 0 || gas_stations[i - 1] - last_stop > m)
            {
                return {};
            }
            stops.push_back(make_pair(i, gas_stations[i - 1]));
            last_stop = gas_stations[i - 1];
            current_position = gas_stations[i - 1];
        }
    }

    if (D - current_position > m)
    {
        return {};
    }

    return stops;
}

int main()
{
    int D, m, n;
    cout << "Enter the total distance to travel (D): ";
    cin >> D;
    cout << "Enter the gas tank capacity (m): ";
    cin >> m;
    cout << "Enter the number of gas stations (n): ";
    cin >> n;

    vector<int> gas_stations(n);
    cout << "Enter the distances to gas stations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> gas_stations[i];
    }

    vector<pair<int, int>> result = gas_stops(D, m, n, gas_stations);

    if (result.empty())
    {
        cout << "Can't reach destination" << endl;
    }
    else
    {
        cout << "Gas station stops needed:" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << "Stop at gas station " << result[i].first << " (" << result[i].second << " miles)" << endl;
        }
    }

    return 0;
}
