#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct Edge {
    int weight, src, dest;
};

struct Node {
    int vertex, key;
};

bool operator<(const Node &n1, const Node &n2) {
    return n1.key > n2.key;
}

void prim(vector<vector<Edge>>& graph, int V) {
    priority_queue<Node> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    int start = 0;

    pq.push({start, 0});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        inMST[u] = true;

        for (auto &next : graph[u]) {
            int v = next.dest;
            int weight = next.weight;

            if (inMST[v] == false && weight < key[v]) {
                key[v] = weight;
                pq.push({v, key[v]});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("Edge: %d - %d \t Weight: %d \n", parent[i], i, graph[i][parent[i]].weight);
}

int main() {
    int V, E;
    cout << "Enter the number of nodes: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter the edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({weight, src, dest});
        graph[dest].push_back({weight, dest, src});
    }

    prim(graph, V);

    return 0;
}