#include<bits/stdc++.h>
using namespace std;

int solveUsingRec(int capacity,int wt[],int profit[],int index,int n){
    //base case
    if(index >=n){
        
            return 0;
        
    }    

    //rec
    int include = 0;
    if(wt[index]<=capacity){
        include = profit[index] + solveUsingRec(capacity - wt[index], wt, profit, index+1, n);
    }
    int exclude = solveUsingRec(capacity, wt, profit, index + 1, n);

    int ans = max(include, exclude);
    return ans;
}




int main(){
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int index = 0;
    int n = 3;

    int ans = solveUsingRec(capacity,wt,profit,index,n);
    cout << "max profit: " << ans << endl;
    /*
    int capacity;
    cin>>capacity;

    */
}
