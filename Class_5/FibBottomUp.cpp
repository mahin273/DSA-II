#include <iostream>
using namespace std;

int F[10000];
int fib(int n)
{

    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
        F[i] = F[i - 1] + F[i - 2];
    return F[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}