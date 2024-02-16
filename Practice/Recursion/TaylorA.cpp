#include<iostream>
using namespace std;

double taylor(int x,int n){

    static double s;
    if(n==0){
        return s;
    }else{
        s = 1 + x*s/n;
        return taylor(x,n-1);
    }

}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<taylor(x,n);  
}