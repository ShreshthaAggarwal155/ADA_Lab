#include<stdio.h>
#include<stdlib.h>
const int MAX = 100;
void Warshall(int graph[MAX][MAX],int n)
{
    int i,j,k;
    for (k=0; k<n; k++){
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                if (graph[i][j] || (graph[i][k] && graph[k][j]))
                    graph[i][j] = 1;
            }
        }
    }
}
int main()
{
    int i,j,n;
    int graph[MAX][MAX];
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix :-\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&graph[i][j]);
    Warshall(graph,n);
    printf("\nThe transitive closure for the given graph is :-\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            printf("%d\t",graph[i][j]);
        printf("\n");
    }
    return 0;
}
