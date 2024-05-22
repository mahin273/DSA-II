/*
TopDown --> Recursion + Memoization
its a recursive approach with memoization 
Step 1 ->Create DP array
Step 2 ->Store ans in  DP array
Step 3 ->if ans already exist then return
*/

#include <iostream>
#include <vector>
using namespace std;

int usingDp(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    // step3:if ans already exist then return ans
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step 2: store and return using dp array
    dp[n] = usingDp(n - 1, dp) + usingDp(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // step 1:create dp array
    vector<int> dp(n + 1, -1);

    int ans = usingDp(n, dp);
    cout << "The Fibonacci number at position " << n << " is: " << ans << endl;
    return 0;
}