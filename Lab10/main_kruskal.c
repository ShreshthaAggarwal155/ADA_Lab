#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[10][10],parent[10];
int main()
{
	printf("Enter the no. of vertices :- ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	while(ne < n){
		for(i=1,min=999;i<=n;i++){
			for(j=1;j <= n;j++){
				if(cost[i][j] < min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u])
            u=parent[u];
		while(parent[v])
            v=parent[v];
		if(u!=v){
			printf("Edge %d:(%d,%d) Cost:%d\n",ne++,a,b,min);
			mincost+=min;
			parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum cost = %d\n",mincost);
	return 0;
}
