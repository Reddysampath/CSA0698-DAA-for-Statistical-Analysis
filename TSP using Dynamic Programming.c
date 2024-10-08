#include <stdio.h>
#define INF 999999
#define N 4

int tsp(int graph[N][N], int pos, int visited, int dp[N][1 << N]) {
    if (visited == (1 << N) - 1)
        return graph[pos][0];
    
    if (dp[pos][visited] != -1)
        return dp[pos][visited];

    int answer = INF,city;
    for (city = 0; city < N; city++) {
        if (!(visited & (1 << city))) {
            int newAnswer = graph[pos][city] + tsp(graph, city, visited | (1 << city), dp);
            answer = newAnswer < answer ? newAnswer : answer;
        }
    }
    return dp[pos][visited] = answer;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[N][1 << N],i,j;
    for ( i = 0; i < N; i++)
        for ( j = 0; j < (1 << N); j++)
            dp[i][j] = -1;

    printf("The minimum cost is %d\n", tsp(graph, 0, 1, dp));
    return 0;
}

