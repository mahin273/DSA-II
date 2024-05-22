#include <bits/stdc++.h>
using namespace std;

int monkey(int m, int a[])
{
    int b[100000] = {0}, tt = 0, i, x, p = 1;
    b[0] = a[0];
    for (i = 1; i < m; i++)
    {
        b[p++] = a[i] - a[i - 1];
    }
    sort(b, b + p);
    x = b[p - 1] - 1;
    for (i = p - 2; i >= 0; i--)
    {
        if (x == b[i])
            x--;
        else if (x < b[i])
        {
            tt = 1;
            break;
        }
    }
    if (tt == 1)
    {
        return b[p - 1] + 1;
    }
    else
    {
        return b[p - 1];
    }
}

int main()
{
    int n, m;
    cin >> n;
    for (int i1 = 0; i1 < n; i1++)
    {
        int a[100000] = {0};
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i];

        int result = monkey(m, a);

        printf("Case %ld: %ld\n", i1 + 1, result);
    }
    return 0;
}