/*
bottomUp-->tabulation
its iterative approach 
Step 1 -> Create DP array
Step 2 -> Analyze the base case and fill up the DP array accordingly
Step 3 ->Fill remaining DP array using logic of recursive relation
*/

#include <iostream>
#include <vector>
using namespace std;
int solveBottomUp(int n)
{
    // Step 1 -> Create DP array
    vector<int> dp(n + 1, -1);

    // Step 2 -> Analyze the base case and fill up the DP array accordingly
    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }
    dp[1] = 1;

    // Step 3 ->Fill remaining DP array using logic of recursive relation
    // index -> 0=>n
    // index filled => 0 and 1
    // Remaining index = 2 to n
    for (int i = 2; i <= n; i++)
    {
        // copy paste the recursive logic
        // replace recursive calls with dp array
        // make sure dp array is using looping variable "i"
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // answer return
    return dp[n]; // whome to call return;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solveBottomUp(n);
    cout << "The Fibonacci number at position " << n << " is: " << result << endl;
    return 0;
}