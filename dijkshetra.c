#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices (A, B, C, D)

// Function to find the unvisited vertex with the minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // Output array: shortest distances from src
    int visited[V]; // Visited vertices

    // Initialize all distances as infinite and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; // Distance to self is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        // Update distance of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from A:\n");
    for (int i = 0; i < V; i++) {
        printf("A -> %c: %d\n", 'A' + i, dist[i]);
    }
}

int main() {
    // Graph represented as an adjacency matrix
    //   A   B   C   D
    int graph[V][V] = {
        { 0, 2, 1, 0 }, // A
        { 0, 0, 0, 3 }, // B
        { 0, 0, 0, 1 }, // C
        { 0, 0, 0, 0 }  // D
    };

    dijkstra(graph, 0); // Start from A (index 0)
    return 0;
}
