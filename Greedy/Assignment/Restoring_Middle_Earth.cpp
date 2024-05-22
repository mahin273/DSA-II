 #include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

long long minCost(int n, int k, vector<int> &capacities)
{
    priority_queue<int> pq(capacities.begin(), capacities.end());
    long long totalCost = 0;

    while (pq.size() > 1)
    {
        int largestGroup = pq.top();
        pq.pop();
        int numberOfGroups = min(k, (int)pq.size() + 1);
        int newSize = largestGroup / numberOfGroups;
        int remainder = largestGroup % numberOfGroups;

        for (int i = 0; i < numberOfGroups; i++)
        {
            if (i < remainder)
                pq.push(newSize + 1);
            else
                pq.push(newSize);
        }

        totalCost += largestGroup;
    }

    return totalCost;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> capacities(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> capacities[i];
        }

        long long cost = minCost(n, k, capacities);
        cout << "Case " << t << ": " << cost << endl;
    }

    return 0;
}