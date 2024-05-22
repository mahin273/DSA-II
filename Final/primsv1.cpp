#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>>calculatePrimsMst(int n,int m,vector<pair<pair<int,int>,int>>&g){
    //create adj list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i =0;i<g.size();i++){ 
        int u = g[i].first.first;
        int v =g[i].first.second;
        int w =g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); 
    }
    vector<int>key(n+1, INT_MAX);
    vector<bool>mst(n+1, false);
    vector<int>parent(n+1, -1);

    key[1]=0;
    parent[1]=-1;
    for(int i = 0;i<n;i++){
        int mini = INT_MAX;
        int u;
        
        for(int v =1;v<=n;v++){
           if(mst[v]==false && key[v]<mini){
            u =v;
            mini = key[v];
           }
        }
        mst[u]=true;

        for(auto it: adj[u]){
            int v =it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    vector<pair<pair<int,int>,int>>result;
    for(int i = 2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> g(m);
    for(int i = 0; i < m; i++) {
        cin >> g[i].first.first >> g[i].first.second >> g[i].second;
    }

    vector<pair<pair<int,int>,int>> result = calculatePrimsMst(n, m, g);

    for(auto &edge : result) {
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";
    }

    return 0;
}

// Solve Procedure:
// 1. Read the number of vertices (n) and number of edges (m) from input.
// 2. Create a vector of pairs to store the edges (g) with their weights.
// 3. Read the edges and their weights from input and store them in the vector g.
// 4. Call the calculatePrimsMst function passing n, m, and g as arguments.
// 5. The calculatePrimsMst function calculates the minimum spanning tree using Prim's algorithm.
// 6. The function returns a vector of pairs representing the edges in the minimum spanning tree.
// 7. Iterate over the result vector and print the edges and their weights.
// 8. The minimum spanning tree is now printed.
// 9. End of the program.