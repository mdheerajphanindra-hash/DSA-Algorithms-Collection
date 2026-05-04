#include <stdio.h>
#include <limits.h>

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int selected[100] = {0};
    selected[0] = 1;
    int edgeCount = 0, mstWeight = 0;

    printf("Edges in MST (Prim's):\n");
    while (edgeCount < V - 1) {
        int min = INT_MAX, x = 0, y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, graph[x][y]);
        mstWeight += graph[x][y];
        selected[y] = 1;
        edgeCount++;
    }

    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}
