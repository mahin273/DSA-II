#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Item
{
    string name;
    double weight;
    double value;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

void knapsack(vector<Item> &items, double capacity, int thief)
{
    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (capacity == 0)
        {
            break;
        }
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            cout << "Taking " << items[i].name << ": " << items[i].weight << " kg " << items[i].value << " taka" << endl;
            items[i].weight = 0;
            items[i].value = 0;
        }
        else
        {
            double fraction = capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "Taking " << items[i].name << ": " << capacity << " kg " << items[i].value * fraction << " taka" << endl;
            items[i].weight -= capacity;
            items[i].value -= items[i].value * fraction;
            capacity = 0;
        }
    }
    cout << "Thief " << thief << " profit: " << totalValue << " taka" << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].name >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    sort(items.begin(), items.end(), compare);

    int k;
    cin >> k;
    vector<double> capacities(k);
    for (int i = 0; i < k; i++)
    {
        cin >> capacities[i];
    }

    for (int i = 0; i < k; i++)
    {
        knapsack(items, capacities[i], i + 1);
    }

    cout << "Total " << k << " thieves stole from the warehouse." << endl;
    cout << "Still following items are left" << endl;
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight > 0)
        {
            cout << items[i].name << " " << items[i].weight << " kg " << items[i].value << " taka" << endl;
        }
    }

    return 0;
}