#include <bits/stdc++.h>
using namespace std;

void solve(int testCaseNum)
{
    int n, ans = 0;
    cin >> n;

    int a[n + 1] = {};    
    bool vis[n + 1] = {};

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int k = i, cycle = 0; 
        if (!vis[k]) 
        {
            
            while (!vis[k])
            {
                cycle++;
                vis[k] = true;
                k = a[k];
            }

            ans += cycle - 1; 
        }
    }
    cout << "Case " << testCaseNum << ": " << ans << '\n';
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int testCaseNum = 1; testCaseNum <= numTestCases; testCaseNum++)
    {
        solve(testCaseNum);
    }
    return 0;
}