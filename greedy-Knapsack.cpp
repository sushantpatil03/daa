#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    double valuePerWeight;
};

bool compareItems(const Item &a, const Item &b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

double greedyKnapsack(int capacity, vector<Item> items)
{
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    for (const Item &item : items)
    {
        if (item.weight <= capacity)
        {
            totalValue += item.profit;
            capacity -= item.weight;
        }
        else
        {
            double fraction = (double)(capacity) / item.weight;
            totalValue += fraction * item.profit;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity = 20;
    vector<Item> items = {
        {3, 10, 0.0},
        {5, 20, 0.0},
        {5, 21, 0.0},
        {8, 30, 0.0},
        {4, 16, 0.0}};

    for (Item &item : items)
    {
        item.valuePerWeight = (double)(item.profit) / item.weight;
    }

    double result = greedyKnapsack(capacity, items);

    cout << "Maximum total profit using greedy approach: " << result << std::endl;

    return 0;
}

