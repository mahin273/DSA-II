#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Event{
    char id;
    int start;
    int end;
};

bool compare( Event &a, Event &b){
    return a.end<b.end;
}

vector<char> maxEvents(int N,int X, vector<Event> &events){
    
    sort(events.begin(),events.end(),compare);

    vector<char>chosen_events;
    int last_end = -1;
    for(int i=0;i<events.size();i++){
        if(events[i].start >= last_end+X){
            chosen_events.push_back(events[i].id);
            last_end=events[i].end;
        }
    }

    return chosen_events;


}

int main(){
    int N,X;
    cin>>N;
    vector<Event> events(N);
    for (int  i = 0; i < N; i++)
    {
        cin>>events[i].id>>events[i].start>>events[i].end;
        events[i].end+=events[i].start;
    }
    cin>>X;

    vector<char>chosen_events = maxEvents(N,X,events);
    cout<<"Chosen Club:"<<endl;
    for (int i = 0; i < chosen_events.size(); i++)
    {
        cout<<chosen_events[i]<<" "<<endl;
    }

    return 0;
    
    
}

