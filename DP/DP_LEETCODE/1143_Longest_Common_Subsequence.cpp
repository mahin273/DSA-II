#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingMem(string a, string b, int i, int j, vector<vector<int>>& dp)
{
    // base case
    if (i >= a.length() | j >= b.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // recursive all
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingMem(a, b, i + 1, j + 1,dp);
    }
    else
    {
        ans = max(solveUsingMem(a, b, i, j + 1,dp), solveUsingMem(a, b, i + 1, j,dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
    
}

int main() {
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    int i = 0;
    int j = 0;
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length()+1,-1));
    int ans = solveUsingMem(text1, text2, i, j,dp);

    cout << "The length of the longest common subsequence is: " << ans << endl;

    return 0;
}