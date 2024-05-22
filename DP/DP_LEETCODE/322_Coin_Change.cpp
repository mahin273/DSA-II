#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> dp;

int solveUsingRec(vector<int>&coins,int amount){
    //base case
    if(amount==0){
        return 0;
    }

    // return if already calculated
    if(dp[amount] != -1) {
        return dp[amount];
    }

    //recursion relation
    int mini = INT_MAX;
    for (int i = 0; i < coins.size();i++){
        if(amount-coins[i]>=0){
            int recursionAns = solveUsingRec(coins,amount-coins[i]);
            if(recursionAns != INT_MAX) {
                mini = min(mini, 1 + recursionAns);
            }
        }
    }

    // store the result
    dp[amount] = mini;
    return mini;
}

int main(){
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    vector<int> coins = {1, 2, 5};
    dp.resize(amount + 1, -1);

    int result = solveUsingRec(coins, amount);
    if(result == INT_MAX) {
        cout << "No solution" << endl;
    } else {
        cout << "The minimum number of coins is: " << result << endl;
    }

    return 0;
}