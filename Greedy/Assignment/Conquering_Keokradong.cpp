#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int> &dist, int K)
{
    vector<int> now;
    int curr = 0;
    int walked = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        int &x = dist[i];
        if (walked + x > mid)
        {
            now.push_back(walked);
            if (++curr > K)
                return false;
            walked = x;
        }
        else
            walked += x;
    }
    now.push_back(walked);
    return true;
}

int main()
{

    int T = 1;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n + 1);
        for (int i = 0; i < v.size(); i++)
        {
            cin >> v[i];
        }
        vector<int> answer;
        int lo = *max_element(v.begin(), v.end()), hi = accumulate(v.begin(), v.end(), 0), ans = -1;

        while (hi >= lo)
        {
            int mi = (hi + lo) >> 1;
            if (check(mi, v, k))
                ans = mi, hi = mi - 1;
            else
                lo = mi + 1;
        }
        check(ans, v, k);
        cout << ans << '\n';
        int df = k + 1 - answer.size();
        vector<int> vec;
        while (df > 0)
        {
            int b = v.back();
            v.pop_back();
            vec.push_back(b);
            answer.back() -= b;
            if (answer.back() == 0)
                answer.pop_back();
            else
                --df;
        }
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++)
        {
            answer.push_back(vec[i]);
        }
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << '\n';
        }
    }
    return 0;
}