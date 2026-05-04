#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> parent;

int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

void unionSet(int i, int j) {
    int a = findSet(i);
    int b = findSet(j);
    parent[a] = b;
}

bool compare(Edge &a, Edge &b) {
    return a.weight < b.weight;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    parent.resize(V);

    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), compare);

    int mstWeight = 0;

    for (int i = 0; i < E; i++) {
        int uSet = findSet(edges[i].u);
        int vSet = findSet(edges[i].v);

        if (uSet != vSet) {
            cout << edges[i].u << " " << edges[i].v << " " << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            unionSet(uSet, vSet);
        }
    }

    cout << mstWeight;

    return 0;
}
