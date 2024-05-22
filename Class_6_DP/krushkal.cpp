#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n_edge;
int n_vertex;
int p[100], rankk[100];

void makeSet()
{

    for (int i = 0; i < n_vertex; i++)
    {
        p[i] = i;
        rankk[i] = 0;
    }
}

int findSet(int i)
{
    if (p[i] == i)
    {
        return i;
    }
    else
    {
        return p[i] = findSet(p[i]);
    }
}

int unionSet(int i, int j)
{
    int r1 = findSet(i);
    int r2 = findSet(j);
    if (r1 == r2)
    {
        return 0;
    }
    if (rankk[r1] > rankk[r2])
    {
        p[r2] = r1;
    }
    else
    {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2])
        {
            rankk[r2]++;
        }
    }
    return 1;
}

int main()
{
    vector<pair<int, pair<int, int>>> graph1;
    int i, u, v, w;
    cout << "Enter the number of vertices: \n";
    cin >> n_vertex;
    cout << "Enter the number of edges: \n";
    cin >> n_edge;
    cout << "Enter the graph : \n";
    for (i = 0; i < n_edge; i++)
    {
        cin >> u >> v >> w;
        graph1.push_back({w, {u, v}});
    }
    sort(graph1.begin(), graph1.end());
}