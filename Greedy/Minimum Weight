#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int profit;
};

int compareWeight(const void *a, const void *b) {
    struct Item *i1 = (struct Item *)a;
    struct Item *i2 = (struct Item *)b;
    return i1->weight - i2->weight;  // ascending order of weight
}

double knapsackByMinWeight(int cap, int n, struct Item items[]) {
    qsort(items, n, sizeof(struct Item), compareWeight);
    double total_profit = 0.0;
    for (int i = 0; i < n && cap > 0; i++) {
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
    printf("Start=");
    int n;
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }
    int cap;
    scanf("%d", &cap);
    double ans = knapsackByMinWeight(cap, n, items);
    printf("%.2f\n", ans);
    return 0;
}
