#include<iostream>
#include<vector>
#include<algorithm>
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
    u=findParent(parent,u);
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
int mst(vector<vector<int>>&edges,int n)
{
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
