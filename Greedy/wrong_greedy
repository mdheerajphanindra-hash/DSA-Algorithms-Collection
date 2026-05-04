#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int profit;
};

int compareProfit(const void *a, const void *b) {
    struct Item *i1 = (struct Item *)a;
    struct Item *i2 = (struct Item *)b;
    return i2->profit - i1->profit; 
}

double knapsackByProfit(int cap, int n, struct Item items[]) {
    qsort(items, n, sizeof(struct Item), compareProfit);
    double total_profit = 0.0;
    for (int i = 0; i < n && cap > 0; i++) {
        if (items[i].weight <= cap) {
            total_profit += items[i].profit;
            cap -= items[i].weight;
        } else {
            total_profit += (double)cap / items[i].weight * items[i].profit;
            cap = 0;
        }
    }
    return total_profit;
}

int main() {
    printf("start");
    int n;
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }
    int cap;
    scanf("%d", &cap);
    double ans = knapsackByProfit(cap, n, items);
    printf("%.2f\n", ans);
    return 0;
}
