#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    Item(int w, int p) {
        weight = w;
        profit = p;
    }
};

bool cmp(Item &a, Item &b) {
    double apw = (double)a.profit / a.weight;
    double bpw = (double)b.profit / b.weight;
    return apw > bpw;
}

double fractionalKnapsack(int cap, vector<Item> &v) {
    sort(v.begin(), v.end(), cmp);
    double total_profit = 0.0;
    for (auto &i : v) {
        if (cap == 0) break;
        if (i.weight <= cap) {
            total_profit += i.profit;
            cap -= i.weight;
        } else {
            total_profit += ((double)cap / i.weight) * i.profit;
            cap = 0;
        }
    }
    return total_profit;
}

int main() {
    int n;
    cin >> n;
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int w, p;
        cin >> w >> p;
        items.push_back(Item(w, p));
    }
    int cap;
    cin >> cap;
    double ans = fractionalKnapsack(cap, items);
    cout << ans << endl;
    return 0;
}
