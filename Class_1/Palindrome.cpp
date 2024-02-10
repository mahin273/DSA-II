#include<iostream>
#include<string>
using namespace std;

int reverseNumber(int num,int rev=0) {
    if(num==0)
        return rev;
    else{
        return reverseNumber(num/10,rev*10+num%10);
    }
        
}

string isPalindrome(int n){
    int reversedNum=reverseNumber(n);
    if(n==reversedNum){
        return "Yes";
    }
        
    else{
        return "No";
    }
        
}
int main() {
    int num;
    cin>>num;
    string result=isPalindrome(num);
    cout<<result;
    return 0;
}
