#include <stdio.h>
#define V 100
int parent[V];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int graph[V][V], int n) {
    int edgeCount = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (edgeCount < n - 1) {
        int min = 999999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && graph[i][j] && graph[i][j] < min) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionSets(a, b);
        printf("%d - %d  %d\n", a, b, min);
        total += min;
        edgeCount++;
    }
    printf("Total Weight: %d\n", total);
}

int main() {
    int n;
    scanf("%d", &n);
    int graph[V][V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    kruskal(graph, n);
    return 0;
}
