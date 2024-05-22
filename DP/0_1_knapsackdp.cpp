#include <bits/stdc++.h>
using namespace std;



int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    // base case
    if (index >= n)
    {

        return 0;
    }


    if(dp[capacity][index]!=-1){
        return dp[capacity][index];
    } 

    // rec
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n,dp);
    }
    int exclude = solveUsingMem(capacity, wt, profit, index + 1, n,dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int main()
{
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;
    int n = 3;

    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(capacity, wt, profit, index, n,dp);
    cout << "max profit: " << ans << endl;
    
    /*
    int capacity;
    cin>>capacity;
    */
}
