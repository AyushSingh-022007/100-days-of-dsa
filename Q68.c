#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX], indegree[MAX], n;
void kahn()
{
    int queue[MAX], front = 0, rear = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }
    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }
    if (count != n)
    {
        printf("\nCycle exists! Topological sort not possible.\n");
    }
}
int main()
{
    int e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    printf("Topological Order:\n");
    kahn();
    return 0;
}