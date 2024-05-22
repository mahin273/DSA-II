#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

void makeSet(vector<int>&parent,vector<int>&rankk,int n){
    for(int i =0;i<n;i++){
        parent[i]=i;
        rankk[i]=0;
    }
}

int findParent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }else{
        return parent[node]=findParent(parent,parent[node]);
    }
}

void unionSet(int u,int v,vector<int>&parent,vector<int>rankk){
    u =findParent(parent,u);
    v = findParent(parent,v);

    if(rankk[u]<rankk[v]){
        parent[u]=v;

    }else if(rankk[v]<rankk[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rankk[u]++;
    }
}

int mst(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
     vector<int>parent(n);
     vector<int>rankk(n);
     makeSet(parent,rankk,n);

     int minWeight = 0;

     for(int i = 0;i<edges.size();i++){
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];

        if(u!=v){
            minWeight+=wt;
            unionSet(u,v,parent,rankk);
        }

     }
     return minWeight;


}

// Solving Procedure:
// 1. The code implements Kruskal's algorithm to find the minimum spanning tree (MST) of a graph.
// 2. The function `cmp` is a custom comparator used to sort the edges in ascending order of their weights.
// 3. The function `makeSet` initializes the parent and rank arrays for the disjoint set data structure.
// 4. The function `findParent` finds the parent of a node in the disjoint set.
// 5. The function `unionSet` performs the union operation on two sets in the disjoint set.
// 6. The function `mst` takes a vector of edges and the number of nodes in the graph as input.
//    It sorts the edges based on their weights, initializes the disjoint set, and then iterates over the sorted edges.
//    For each edge, it finds the parent of the two nodes, checks if they are already in the same set,
//    and if not, adds the weight of the edge to the minimum weight and performs the union operation.
//    Finally, it returns the minimum weight of the MST.
