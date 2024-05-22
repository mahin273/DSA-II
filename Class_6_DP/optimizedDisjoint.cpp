#include <iostream>
#include <vector>
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
    int i;
    n_vertex = 10;
    n_edge = 7;

    makeSet();
    unionSet(0, 1);
    unionSet(0, 2);
    unionSet(3, 4);
    unionSet(6, 7);
    unionSet(6, 8);
    unionSet(7, 8);
    unionSet(7, 9);

    cout << findSet(9) << endl;
    cout << findSet(8) << endl;
    cout << findSet(7) << endl;
    cout << findSet(6) << endl;

    cout << findSet(1) << endl;
    cout << findSet(2) << endl;
    cout << findSet(0) << endl;

    cout << findSet(5) << endl;

    cout << findSet(3) << endl;
    cout << findSet(4) << endl;

    return 0;
}