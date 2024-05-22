/**
 * Case1 -> include --> dp[i] = dp[i-2] + nums[i]
 * Case2 -> exclude --> dp[i] = dp[i-1]
*/

// Include the necessary headers
#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header

using namespace std;
/*
int solveUsingRecursion(vector<int>& nums, int idx) {
   //base case
   if (idx >= nums.size()) {
       return 0;
   }

   //recursion relation
   int include = nums[idx] + solveUsingRecursion(nums, idx + 2);
   int exclude = solveUsingRecursion(nums, idx + 1);
   int ans = max(include, exclude);
   return ans;
}
int main()
{
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the amount of money in each house: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = solveUsingRecursion(nums, 0);
    cout << "The maximum amount of money that can be robbed is: " << result << endl;
    return 0;
}
*/

int solveUdingDp(vector<int> &nums, int idx,vector<int>&dp)
{
    // base case
    if (idx >= nums.size())
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    // recursion relation
    int include = nums[idx] + solveUdingDp(nums, idx + 2,dp);
    int exclude = solveUdingDp(nums, idx + 1,dp);
    dp[idx] = max(include, exclude);
    return dp[idx];
}

int solveUsingTdp(vector<int>&nums){
    int n = nums.size();
    // step 1
    vector<int> dp(n , -1);
    //step 2
    dp[n - 1] = nums[n - 1];
}

int main()
{
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the amount of money in each house: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(n, -1);
    int result = solveUdingDp(nums, 0, dp);
    cout << "The maximum amount of money that can be robbed is: " << result << endl;
    return 0;
}
