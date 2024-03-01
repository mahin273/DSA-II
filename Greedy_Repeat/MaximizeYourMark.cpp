#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct Ques{
double ratio;
int mark;
int time;
int index;

};
bool compare(Ques &a, Ques &b){
    return a.ratio>b.ratio;
}

vector<Ques> maxMarks(int N,int T,vector<int>&m, vector<int>&t){
    vector<Ques> ques(N);
    for (int i = 0; i < N; i++)
    {
        double ratio =(m[i])/t[i];
        ques[i]={ratio, m[i], t[i], i + 1};
    }
    sort(ques.begin(),ques.end(),compare);

    vector<Ques>answeredQues;
    for(int i =0;i<ques.size();i++){
        if(T>=ques[i].time){
            T-=ques[i].time;
            answeredQues.push_back({100.0,ques[i].mark,ques[i].time,ques[i].index});

        }else if(T>0){
         double parcentage = T*100/ques[i].time;
         ques[i].mark=ques[i].mark*parcentage/100;
         ques[i].time=T;
         T=0;
         answeredQues.push_back({parcentage,ques[i].mark,ques[i].time,ques[i].index});


        }
    }
    return answeredQues;
    
}

vector<Ques> maxMarkGroup(int N,int T,vector<int> &m, vector<int>&t){
    return maxMarks(N,T*2,m,t);
}

int main(){
    int M,T,N;
    cin>>M>>T>>N;
    vector<int> m(N),t(N);
    for(int i=0;i<N;i++){
        cin>>m[i]>>t[i];
    }
    vector<Ques> solo = maxMarks(N,T,m,t);
    vector<Ques> group = maxMarkGroup(N,T,m,t);
    int soloMarks = 0;
    int groupMarks = 0;
    for (int i = 0; i < solo.size(); i++)
    {
        soloMarks+=solo[i].mark;
    }
    for(int i=0;i<group.size();i++){
        groupMarks+=group[i].mark;

    }
    cout<<"Maximum: "<<soloMarks<<" Marks answered alone"<<endl;
    for (int i = 0; i < solo.size(); i++)
    {
        cout<<"Ques "<<solo[i].index<<" "<<solo[i].ratio<<"% done -- "<<solo[i].mark<<" Marks"<<endl;
    }
    cout<<"Maximum: "<<groupMarks<<" Marks answered in group"<<endl;
    return 0;
    
    
}

