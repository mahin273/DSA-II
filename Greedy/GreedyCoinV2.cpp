#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_change(int N, vector<int> &coins)
{
    sort(coins.begin(), coins.end(), greater<int>());

    vector<int> counts(coins.size(), 0);
    int total = 0;

    for (int i = 0; i < coins.size(); ++i)
    {
        counts[i] = N / coins[i];
        N %= coins[i];
        total += counts[i];
    }

    for (int i = 0; i < coins.size(); ++i)
    {
        if (counts[i] > 0)
        {
            cout << coins[i] << " cents --- " << counts[i] << "\n";
        }
    }

    cout << "Total " << total << " coins\n";
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> coins(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> coins[i];
    }

    make_change(N, coins);

    return 0;
}