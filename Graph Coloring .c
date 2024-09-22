#include <stdio.h>

#define V 4
int graph[V][V] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
int color[V];

int isSafe(int v, int c) {
	int i;
    for (i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c) return 0;
    return 1;
}

int graphColoring(int v, int m) {
	int c;
    if (v == V) return 1;
    for ( c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1, m)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int m = 3;
    if (graphColoring(0, m)) {
        printf("Solution exists");
    } else {
        printf("No solution");
    }
    return 0;
}

