#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={9,5,3,1,14,2,20,5};
    int len=sizeof(arr)/sizeof(arr[0]);

    cout<<"Array-->";
    for (int i = 0; i <len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Ascending Order-->";
    sort(arr,arr+len);
        for (int i = 0; i <len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Descending Order-->";
    sort(arr,arr+len,greater<int>());
        for (int i = 0; i <len; i++)
    {
        cout<<arr[i]<<" ";
    }
        cout<<endl;
    cout<<"Middle-->";
    sort(arr+2,arr+6,greater<int>());
        for (int i = 0; i <len; i++)
    {
        cout<<arr[i]<<" ";
    }



}