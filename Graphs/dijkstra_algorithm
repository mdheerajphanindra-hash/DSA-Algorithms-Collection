#include <iostream>
#include <climits>
using namespace std;

#define V 6

struct MinHeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
};

MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* node = new MinHeapNode;
    node->vertex = v;
    node->dist = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = new MinHeap;
    heap->pos = new int[capacity];
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = new MinHeapNode*[capacity];
    return heap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;
    if (smallest != idx) {
        MinHeapNode* smallestNode = heap->array[smallest];
        MinHeapNode* idxNode = heap->array[idx];
        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

void build_heap(MinHeap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}

MinHeapNode* extract_min(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    MinHeapNode* root = heap->array[0];
    MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

void decrease_key(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;
    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(MinHeap *heap, int v) {
    return heap->pos[v] < heap->size;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    MinHeap* heap = createMinHeap(V);
    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }
    dist[src] = 0;
    heap->array[src]->dist = 0;
    heap->size = V;
    build_heap(heap);
    while (heap->size > 0) {
        MinHeapNode* node = extract_min(heap);
        int u = node->vertex;
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && isInMinHeap(heap, v) &&
                dist[u] != INT_MAX &&
                graph[u][v] + dist[u] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decrease_key(heap, v, dist[v]);
            }
        }
    }
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 10},
        {4, 0, 3, 0, 0, 0},
        {0, 3, 0, 4, 0, 0},
        {0, 0, 4, 0, 2, 8},
        {0, 0, 0, 2, 0, 5},
        {10, 0, 0, 8, 5, 0}
    };
    int source = 0;
    dijkstra(graph, source);
    return 0;
}
