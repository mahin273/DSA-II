#include <iostream>
#include <vector>
#include <algorithm>

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

vector<Item> knapsack(vector<Item> &items, double capacity)
{
    sort(items.begin(), items.end(), compare);
    vector<Item> stolenItems;
    double totalValue = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            stolenItems.push_back(items[i]);
            capacity -= items[i].weight;
            totalValue += items[i].value;
            items.erase(items.begin() + i);
            i--;
        }
        else
        {
            Item fraction = items[i];
            fraction.weight = capacity;
            fraction.value *= (capacity / items[i].weight);
            stolenItems.push_back(fraction);
            items[i].weight -= capacity;
            totalValue += fraction.value;
            break;
        }
    }

    return stolenItems;
}

int main()
{
    int numItems, numThieves;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);
    for (int i = 0; i < numItems; i++)
    {
        cout << "Enter name, Value, and weight for item " << i + 1 << ": ";
        cin >> items[i].name >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    cout << "Enter the number of thieves: ";
    cin >> numThieves;

    vector<double> thieves(numThieves);
    for (int i = 0; i < numThieves; i++)
    {
        cout << "Enter capacity for thief " << i + 1 << ": ";
        cin >> thieves[i];
    }

    int thief_count = 0;
    for (double capacity : thieves)
    {
        vector<Item> stolenItems = knapsack(items, capacity);
        double totalValue = 0;
        for (Item item : stolenItems)
        {
            totalValue += item.value;
        }
        cout << "Thief " << thief_count + 1 << " profit: " << totalValue << " taka" << endl;
        for (Item item : stolenItems)
        {
            cout << "Taking " << item.name << ": " << item.weight << " kg" << endl;
        }
        thief_count++;
    }

    cout << "Total " << thief_count << " thieves stole from the warehouse." << endl;
    if (!items.empty())
    {
        cout << "Still following items are left" << endl;
        for (Item item : items)
        {
            cout << item.name << " " << item.weight << " kg " << item.value << " taka" << endl;
        }
    }
    else
    {
        cout << "No items left in the warehouse." << endl;
    }

    return 0;
}

// wrong aoutput at some case