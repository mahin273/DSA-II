#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long>factorials;

void precompute(){
    factorials.push_back(1);
    for (int i = 0; i < 20; i++)
    {
        factorials.push_back(factorials.back()*i);
    }
    
}
void solve(int caseNum,long long n){
    vector<int>used;
    for (int i=factorials.size()-1;i>=0;i--)
    {
        if(factorials[i]<=n){
            n-+factorials[i];
            used.push_back(i);
        }
    }
    cout<<"Case "<<caseNum<<": ";
    if(n!=0){
        cout<<"Impossible"<<endl;
    }else{
        for(int i  = used.size();i>=0;i--){
            cout<<used[i]<<"!";
            if(i!=0){
                cout<<"+";
            }
        }
        cout<<endl;

    }
    
}

int main(){
    int T;
    cin>>T;
    for (int i = 0; i <=T; i++)
    {
        cin>>n;
        solve(i,n);
    }

    return 0;
    
}