#include<stdio.h>
#include<time.h>
int a[10][10],q[10],visited[10],n,f=0,r=-1;
void bfs(int v){
    int i;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
int main() {
	int v,i,j;
	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter matrix: \n");
	for (i=1;i<=n;i++){
      printf("Enter row %d : \n",i);
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	}
	for (i=1;i<=n;i++){
		q[i]=0;
		visited[i]=0;
	}
	printf("\nEnter the beginning vertex : ");
	scanf("%d",&v);
    double bfs_time=0.0;
    clock_t begin=clock();
	bfs(v);
	clock_t end=clock();
	bfs_time+=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Visitable Nodes are : \n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d ",i);
      else
	   printf("\nBfs is not possible");
    printf("\nn=%d\tTime:%f\n",n,bfs_time);
	return 0;
}
