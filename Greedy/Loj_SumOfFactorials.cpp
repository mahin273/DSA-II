#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Pre-calculating value of factorials of all numbers from 0 to 19

    long long int factorial[20] = {}, k = 1;
    factorial[0] = 1;

    for (long long int i = 1; i <= 20; i++)
    {
        factorial[i] = i * k;
        k = factorial[i];
    }

    // start of actual solution
    int testcase;
    cin >> testcase;
    for (int j = 1; j <= testcase; j++)
    {
        long long int n;
        cin >> n;

        vector<int> answer;
        for (int i = 20; i >= 0; i--)
        {
            if (factorial[i] <= n)
            {
                n -= factorial[i];
                answer.push_back(i);
            }
        }

        // Output
        cout << "Case " << j << ": ";
        if (n == 0)
        {
            for (int i = answer.size() - 1; i > 0; i--)
            {
                cout << answer[i] << "!+";
            }
            cout << answer[0] << "!\n";
        }
        else
            cout << "impossible\n";
    }
    return 0;
}