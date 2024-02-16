#include<iostream>
using namespace std;

int power(int m, int n){
    if (n==0)
    {
        return 1;
    }
    else
    {
        return power(m,n-1)*m;
    }

}

int main(){
    int x,y;
    cin>>x>>y;
    int p = power(x,y);
    cout<<p;
}