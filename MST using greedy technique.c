#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minWeight(int w[], bool vis[]) {
    int min = INT_MAX, idx;
    for (int v = 0; v < V; v++)
        if (!vis[v] && w[v] < min)
            min = w[v], idx = v;
    return idx;
}
void printMST(int p[], int g[V][V]) {
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", p[i], i, g[i][p[i]]);
        totalCost += g[i][p[i]];
    }
    printf("Total cost: %d\n", totalCost);
}
void primMST(int g[V][V]) {
    int p[V], w[V];
    bool vis[V];
    for (int i = 0; i < V; i++)
        w[i] = INT_MAX, vis[i] = false;
    w[0] = 0, p[0] = -1;
    for (int i = 0; i < V - 1; i++) {
        int u = minWeight(w, vis);
        vis[u] = true;
        
        for (int v = 0; v < V; v++)
            if (g[u][v] && !vis[v] && g[u][v] < w[v])
                p[v] = u, w[v] = g[u][v];
    }
    printMST(p, g);
}
int main() {
    int g[V][V] = { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 }, { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 }, { 0, 5, 7, 9, 0 } };
    primMST(g);
    return 0;
}
