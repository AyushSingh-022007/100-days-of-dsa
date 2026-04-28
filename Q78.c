#include <stdio.h>
#define MAX 100
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // initialize matrix with INF
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    // input edges
    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[MAX], visited[MAX];

    for(int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int total_weight = 0;

    for(int count = 1; count <= n; count++) {
        int min = INF, u = -1;

        // pick minimum key node not visited
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        total_weight += key[u];

        // update neighbors
        for(int v = 1; v <= n; v++) {
            if(adj[u][v] < key[v] && !visited[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}