#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsackBottomUp(int val[], int wt[], int n, int w)
{
    int table[1000][1000];
    for (int w = 0; w <= w; w++)
    {
        table[0][w] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 0;
        for (w = 0; w <= w; w++)
        {
            if (wt[i] <= w)
            {
                if (val[i] + table[i - 1][w - wt[i]] > table[i - 1][w])
                {
                    table[i][w] = val[i] + table[i - 1][w - wt[i]];
                }
                else
                {
                    table[i][w] = table[i - 1][w];
                }
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    int i = n;
    int j = w;
    vector<int> takenItems;
    while (i > 0 && j > 0)
    {
        if (table[i][j] == val[i] + table[i - 1][j - wt[i]])
        {
            takenItems.push_back(i);
            j = j - wt[i];
            i--;
        }
        else
        {
            i--;
        }
    }
    for (int j = takenItems.size() - 1; j >= 0; j--)
    {
        cout << takenItems[j] << " ";
        cout << endl;
    }
    return table[n][w];
}

int main()
{
    int profit[] = {0, 12, 10, 20, 15};
    int weight[] = {0, 2, 1, 3, 2};
    int w = 5;
    int n = 4;

    cout << knapsackBottomUp(profit, weight, n, w) << endl;
    return 0;
}
