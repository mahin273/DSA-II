#include <iostream>
using namespace std;

int F[10000];

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (F[n - 1] == -1)
        F[n - 1] = fib(n - 1);
    if (F[n - 2] == -1)
        F[n - 2] = fib(n - 2);
    return F[n - 1] + F[n - 2];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        F[i] = -1;
        F[0] = 0;
        F[1] = 1;
    cout << fib(n) << endl;
    return 0;
}