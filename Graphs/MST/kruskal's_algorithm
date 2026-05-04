#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

struct Edge edges[100];
int parent[100];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    int mstWeight = 0;
    printf("Edges in MST (Kruskal's):\n");
    for (int i = 0; i < E; i++) {
        int uSet = find(edges[i].u);
        int vSet = find(edges[i].v);
        if (uSet != vSet) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(uSet, vSet);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}
