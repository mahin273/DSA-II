#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    double weight;
    double value;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

void knapsack(vector<Item> &item, double capacity)
{
    sort(item.begin(), item.end(), compare);

    double totalValue = 0;

    for (int i = 0; i < item.size(); i++)
    {
        if (capacity == 0)
        {
            break;
        }
        if (item[i].weight <= capacity)
        {
            capacity -= item[i].weight;
            totalValue += item[i].value;
            cout << item[i].weight << " " << item[i].value << endl;
        }
        else
        {
            double fraction = capacity / item[i].weight;
            totalValue += item[i].value * fraction;
            cout << item[i].weight << " " << item[i].value << endl;
            capacity = 0;
        }
    }
    cout << "Profit: " << totalValue << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Item> item(n);
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].value;
        item[i].ratio = item[i].value / item[i].weight;
    }
    int w;
    cin >> w;
    knapsack(item, w);
    return 0;
}
