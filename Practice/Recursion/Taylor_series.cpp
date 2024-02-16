#include<iostream>
using namespace std;
double taylor(int x,int n){
    static double p = 1;
    static double f = 1;
    double r;
    if (n==0){
        return 1;
    }else{
        r = taylor(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }   
  
     
}

int main(){
int x,n;
cin>>x>>n;
cout<<taylor(x,n);
}