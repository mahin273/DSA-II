#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int &x : v)
        cin >> x;
    vector<int> answer;
    int lo = *max_element(v.begin(), v.end()), hi = accumulate(v.begin(), v.end(), 0), ans = -1;

    auto ok = [&](int mid)
    {
        vector<int> now;
        int curr = 0;
        int walked = 0;
        for (int &x : v)
        {
            if (walked + x > mid)
            {
                now.push_back(walked);
                if (++curr > k)
                    return false;
                walked = x;
            }
            else
                walked += x;
        }
        now.push_back(walked);
        answer = now;
        return true;
    };

    while (hi >= lo)
    {
        int mi = (hi + lo) >> 1;
        if (ok(mi))
            ans = mi, hi = mi - 1;
        else
            lo = mi + 1;
    }
    ok(ans);
    cout << ans << '\n';
    int df = k + 1 - answer.size();
    while (df > 0)
    {
        if (answer.back() > 1)
        {
            answer.push_back(1);
            answer[answer.size() - 2]--;
        }
        else
        {
            answer.push_back(answer.back());
            answer.erase(answer.end() - 3);
        }
        df--;
    }
    for (int &x : answer)
        cout << x << '\n';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cout << "Case " << tt << ": ";
        test();
    }
    return 0;
};