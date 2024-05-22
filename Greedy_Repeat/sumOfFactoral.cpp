#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> factorials;

void precompute()
{
    factorials.push_back(1);
    long long k = 1;
    for (int i = 1; i <= 20; i++)
    {
        factorials.push_back(i * k);
        k = factorials[i];
    }
}

void solve(int caseNum, long long n)
{
    vector<int> used;
    for (int i = factorials.size() - 1; i >= 0; i--)
    {
        if (factorials[i] <= n)
        {
            n -= factorials[i];
            used.push_back(i);
        }
    }
    cout << "Case " << caseNum << ": ";
    if (n == 0)
    {
        for (int i = used.size() - 1; i > 0; i--)
        {
            cout << used[i] << "!+";
        }
        cout << used[0] << "!\n";
    }
    else
    {
        cout << "impossible\n";
    }
}

int main()
{
    precompute();
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long n;
        cin >> n;
        solve(i, n);
    }

    return 0;
}

// litte bit problem