#include<stdio.h>
#include<stdlib.h>
int a,b,u,t,m,n,i,j;
int v[10],c=1,min=0,cost[10][10];
int main(){
    printf("Enter the number of vertices :- ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    v[1]=1;
    while(c<n){
        for (i=1,m=999;i<=n;i++){
            for (j=1;j<=n;j++){
                if(cost[i][j]<m){
                    if(v[i]!=0){
                        m=cost[i][j];
                        a=u=i;
                        b=t=j;
                    }
                }
            }
        }
        if(v[u]==0 || v[t]==0){
            printf("\nEdge %d:(%d %d) cost:%d",c++,a,b,m);
            min+=m;
            v[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimun cost=%d\n",min);
    return 0;
}
