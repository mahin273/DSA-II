#include <iostream>
#include <vector>
using namespace std;


bool isSubsetSum(vector<int> &A, int N)
{
    int n = A.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(N + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][N];
}


int main()
{
    int n, N;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the target sum: ";
    cin >> N;

    if (isSubsetSum(A, N))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
