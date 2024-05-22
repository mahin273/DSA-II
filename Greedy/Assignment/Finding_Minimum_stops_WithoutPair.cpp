#include <iostream>
#include <vector>

using namespace std;

void gas_stops(int D, int m, int n, vector<int> &gas_stations, vector<int> &stop_indices, vector<int> &stop_distances)
{
    int current_position = 0;
    int last_stop = 0;

    for (int i = 0; i < n; i++)
    {
        if (gas_stations[i] - current_position > m)
        {
            if (i == 0 || gas_stations[i - 1] - last_stop > m)
            {
                stop_indices.clear();
                stop_distances.clear();
                return;
            }
            stop_indices.push_back(i);
            stop_distances.push_back(gas_stations[i - 1]);
            last_stop = gas_stations[i - 1];
            current_position = gas_stations[i - 1];
        }
    }

    if (D - current_position > m)
    {
        stop_indices.clear();
        stop_distances.clear();
    }
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

    vector<int> stop_indices;
    vector<int> stop_distances;
    gas_stops(D, m, n, gas_stations, stop_indices, stop_distances);

    if (stop_indices.empty())
    {
        cout << "Can't reach destination" << endl;
    }
    else
    {
        cout << "Gas station stops needed:" << endl;
        for (int i = 0; i < stop_indices.size(); i++)
        {
            cout << "Stop at gas station " << stop_indices[i] << " (" << stop_distances[i] << " miles)" << endl;
        }
    }

    return 0;
}
