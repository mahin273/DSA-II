#include <bits/stdc++.h>
using namespace std;

int Scarecrow(string field, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (field[i] == '.')
        {
            i += 2;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
   
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        int n;
        string field;
        cin >> n;
        cin >> field;

        int cnt = Scarecrow(field, n);

        cout << "Case " << cs << ": " << cnt << "\n";
    }

    return 0;
}