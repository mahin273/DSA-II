#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstra(vector<vector<int>> &vec, int vertices,int edges,int source){
    //create adjacency list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i = 0;i<edges ;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create distance vector
    vector<int>dist(vertices, INT_MAX);


    //creation of set on basis (distance, node)
    set<pair<int,int>>st;
    //initialize the distance of source node
    dist[source]=0;
    st.insert(make_pair(0,source)); 
    
    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now 
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour:adj[topNode]){
            if(nodeDistance + neighbour.second<dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                //if record found then remove it
                if(record!=st.end()){
                    st.erase(record);
                } 

                //update the distance
                dist[neighbour.first ]=nodeDistance + neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }

    return dist;
}

/*
Solving Procedure:
1. Create an adjacency list from the given vector of edges.
2. Create a distance vector and initialize all distances to infinity except for the source node, which is set to 0.
3. Create a set to store pairs of (distance, node) and insert the source node with distance 0.
4. While the set is not empty, do the following:
   - Get the top element from the set (the one with the smallest distance).
   - Remove the top element from the set.
   - Traverse the neighbors of the top node and update their distances if a shorter path is found.
   - If a neighbor's distance is updated, remove its previous record from the set (if it exists) and insert the updated record.
5. Return the distance vector, which contains the shortest distances from the source node to all other nodes.
*/