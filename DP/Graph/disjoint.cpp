#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int>& left, vector<int>& right) {
    return left[2] < right[2];
}

void makeSet(vector<int>&parent,vector<int>&rank,int n){
    for (int i = 0; i < n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findParent(parent, parent[node]);
}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

int mst(vector<vector<int>>&edges,int n){
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), compare);

    int cost = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int x = findParent(parent, u);
        int y = findParent(parent, v);

        if (x != y) {
            cost += w;
            unionSet(x, y, parent, rank);
        }
    }

    return cost;
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(3));
    cout << "Enter the edges (node1 node2 weight):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int result = mst(edges, n);
    cout << "The weight of the minimum spanning tree is: " << result << "\n";

    return 0;
}