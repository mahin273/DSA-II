#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    int lo = *max_element(v.begin(), v.end()), hi = accumulate(v.begin(), v.end(), 0), ans = -1;

    auto ok = [&](int mid)
    {
        int curr = 1;
        int sum = 0;
        for (int &x : v)
        {
            if (sum + x > mid)
            {
                curr++;
                sum = x;
            }
            else
                sum += x;
        }
        return curr <= m;
    };

    while (hi >= lo)
    {
        int mi = (hi + lo) / 2;
        if (ok(mi))
            ans = mi, hi = mi - 1;
        else
            lo = mi + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cout << "Case " << tt << ": ";
        test();
    }
    return 0;
}