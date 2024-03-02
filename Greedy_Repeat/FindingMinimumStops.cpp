#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>>gas_stop(int D,int m,int n,vector<int> &gas_station){
    vector<pair<int,int>>stops;
    int current_position = 0;
    int last_stop = 0;
    for (int i = 0; i < n; i++)
    {
        if(gas_station[i]-current_position >m){
            if(i==0 || gas_station[i-1]-last_stop>m){
                return { };
            }else{
            stops.push_back(make_pair(i,gas_station[i-1]));
            last_stop = gas_station[i-1];
            current_position = gas_station[i-1];
            }
        
        }
    }if(D-current_position>m){
        return { };
    }else{
        return stops;
    }
    
}

int main(){
    int D,m,n;
    cin>>D;
    cin>>m;
    cin>>n;
    vector<int> gas_station(n);
    for (int i = 0; i < n; i++)
    {
        cin>>gas_station[i];
    }

    vector<pair<int ,int>>result = gas_stop(D,m,n,gas_station);
    if(result.empty()){
        cout<<"Can't reach Destination"<<endl;
    }else{
        cout<<"Gas station stops needed: "<<endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout<<"Stop at gas station "<<result[i].first<<"("<<result[i].second<<" miles)"<<endl;
        }
        
    }

    return 0;
    
}

/*

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>>gas_stop(int D,int max_stops,int n,vector<int> &gas_station){
    vector<pair<int,int>>stops;
    int current_position = 0;
    int last_stop = 0;
    int stop_count = 0; // Keep track of the number of stops

    for (int i = 0; i < n; i++)
    {
        if(gas_station[i]-current_position > max_stops){
            if(i==0 || gas_station[i-1]-last_stop>max_stops){
                return { };
            }
            stops.push_back(make_pair(i,gas_station[i-1]));
            last_stop = gas_station[i-1];
            current_position = gas_station[i-1];
            stop_count++;
            if(stop_count > max_stops) {
                return { };
            }
        }
    }
    if(D-current_position>max_stops){
        return { };
    }else{
        return stops;
    }
}

int main(){
    int D,max_stops,n;
    cin>>D;
    cin>>max_stops;
    cin>>n;
    vector<int> gas_station(n);
    for (int i = 0; i < n; i++)
    {
        cin>>gas_station[i];
    }

    vector<pair<int ,int>>result = gas_stop(D,max_stops,n,gas_station);
    if(result.empty()){
        cout<<"Can't reach Destination"<<endl;
    }else{
        cout<<"Gas station stops needed: "<<endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout<<"Stop at gas station "<<result[i].first<<"("<<result[i].second<<" miles)"<<endl;
        }
    }

    return 0;
}
*/