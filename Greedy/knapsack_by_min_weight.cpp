#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
};

bool compareWeight(Item &a, Item &b) {
    return a.weight < b.weight;
}

double knapsackByMinWeight(int cap, vector<Item> &items) {
    sort(items.begin(), items.end(), compareWeight);
    double total_profit = 0.0;

    for (int i = 0; i < items.size() && cap > 0; i++) {
        if (items[i].weight <= cap) {
            total_profit += items[i].profit;
            cap -= items[i].weight;
        } else {
            total_profit += ((double)cap / items[i].weight) * items[i].profit;
            cap = 0;
        }
    }

    return total_profit;
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    int cap;
    cin >> cap;

    double ans = knapsackByMinWeight(cap, items);

    cout << ans;

    return 0;
}
