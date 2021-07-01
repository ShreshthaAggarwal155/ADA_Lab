#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10000
int n;
void display(int d[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j]==MAX)
                printf("%6s","INF");
            else
                printf ("%6d", d[i][j]);
        }
        printf("\n");
    }
}
void floyd(int graph[][n])
{
    int d[n][n], i, j, k;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(graph[i][j]==-1)
                d[i][j]=MAX;
            else
                d[i][j]=graph[i][j];
        }
    }
    printf(" D(0)Matrix :\n");
    display(d);
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(d[i][j] > d[i][k]+d[k][j])
                    d[i][j]=d[i][k] + d[k][j];
            }
        }
        printf("\nD(%d) Solution Matrix : \n",k+1);
        display(d);
    }
}
int main()
{
    printf("\n Enter the Number of vertices :- ");
    scanf("%d",&n);
    int D[n][n];
    printf("\nEnter the adjacency matrix (enter -1 if no direct path) :- \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&D[i][j]);
        }
    }
    floyd(D);
    return 0;
}
