#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> set_rank;

void makeSet(int n){
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
        set_rank.push_back(0);
    }
    
}

int findSet(int i){
    if(parent[i] == i){
        return i;
    }
    else{
        parent[i] = findSet(parent[i]);
        return parent[i];
    }
}

void unionSet(int i,int j){
    int i_id =findSet(i);
    int j_id = findSet(j);
    if(i_id != j_id){
        if (set_rank[i_id < set_rank[j_id]])
        {
            parent[i_id] = j_id;
        }
        else if (set_rank[i_id > set_rank[j_id]])
        {
            parent[j_id] = i_id;
        }
        else
        {
            parent[i_id] = j_id;
            set_rank[j_id]++;
        }
    }

}

int main()
{
    int n = 10;
    makeSet(n);
    unionSet(0, 1);
    unionSet(0, 2);
    unionSet(3, 4);
    unionSet(6, 7);
    unionSet(6, 8);
    unionSet(7, 8);
    unionSet(0, 4);

    int element = 10;
    cout << "Element: " << element << " Set: " << findSet(element) << endl;


    for (int i = 0; i < n; i++)
    {
        cout << "Element: " << i << " Set: " << findSet(i) << endl;
    }

    return 0;
}