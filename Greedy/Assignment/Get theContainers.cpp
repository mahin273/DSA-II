#include <bits/stdc++.h>
using namespace std;

int cas = 0;
void solve()
{
    cout << "Case " << ++cas << ": ";
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int L = 0;
    int ans;
    int R = INT_MAX / 2;
    while (L < R)
    {
        int M = L + (R - L) / 2;
        int cnt = 0, sum = 0;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > M)
            {
                L = M + 1;
                ok = false;
                break;
            }

            sum += a[i];
            if (sum == M)
            {
                sum = 0;
                cnt++;
            }
            else if (sum > M)
            {
                cnt++;
                sum = a[i];
            }
        }
        if (!ok)
            continue;

        if (sum)
            cnt++;

        if (cnt > m)
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
        ans = M;
        if (L == R)
            ans = L;
    }

    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}