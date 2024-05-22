#include <bits/stdc++.h>
using namespace std;

vector<int> g[10000];
int boys[10000];
int moves[10000];

int dfs(int v, int parent)
{
    vector<int> arr;
    for (auto u : g[v])
    {
        if (u != parent)
        {
            moves[u] = dfs(u, v);
            arr.push_back(moves[u] - boys[u]);
        }
    }
    sort(arr.begin(), arr.end());
    while (arr.size() > 1)
    {
        moves[v] += arr.back();
        arr.pop_back();
        moves[v] += arr.back();
        arr.pop_back();
    }
    if (arr.size() == 1)
    {
        moves[v] += arr.back();
    }
    return moves[v] + boys[v];
}

int main()
{

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            cin >> i >> boys[i];
            int d;
            cin >> d;
            while (d--)
            {
                int u;
                cin >> u;
                g[i].push_back(u);
                g[u].push_back(i);
            }
        }
        cout << "Case " << t << ": " << dfs(1, 0) << "\n";
    }

    return 0;
}