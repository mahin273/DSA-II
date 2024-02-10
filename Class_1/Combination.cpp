#include<iostream>
using namespace std;
int combination(int n,int r){
    if (n<r)
    {
        return 0;
    }
    if (r==1)
    {
       return n;
    }
    
    if(r==0||n==r){
        return 1;
    }else{
        return combination(n-1,r)+combination(n-1,r-1);
    }
}

int main(){
    int n,r;
    cin>>n>>r;
    cout<<combination(n,r);
}