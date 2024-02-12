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

void knapsack(vector<Item> &items, double capacity)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (auto &i : items)
    {
        if (capacity == 0)
        {
            break;
        }
        if (i.weight <= capacity)
        {
            capacity -= i.weight;
            totalValue += i.value;
            cout << "item: " << (&i - &items[0] + 1) << ": " << i.weight << " kg " << i.value << " taka " << endl;
        }
        else
        {
            double fraction = capacity / i.weight;
            totalValue += i.value * fraction;
            cout << "item " << (&i - &items[0] + 1) << ": " << i.weight << " kg " << i.value * fraction << " taka" << endl;
            capacity = 0;
        }
    }
    cout << "profit: " << totalValue << " taka" << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    int W;
    cin >> W;

    knapsack(items, W);

    return 0;
}
