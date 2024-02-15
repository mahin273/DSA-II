#include<iostream>
using namespace std;
int power(int x,int y){
    if(y==0){
        return 1;
    }
    int p = power(x, y / 2);
    if(y%2==0){  //power Even
        return p * p; 
    }else{
        return x * p * p;
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << "Result = " << power(x, y) << endl;
}