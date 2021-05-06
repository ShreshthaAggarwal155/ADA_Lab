#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int G[10][10],v[10],n,a[1][10];
void dfs(int i)
{
    int j;
    printf("\n%d",i);
    v[i]=1;
    for(j=0;j<n;j++){
       if(!v[j]&&G[i][j]==1)
            dfs(j);
	}
}
void dfs_c(int n,int G[10][10],int m,int s[])
{
    int y;
    s[m]=1;
    for(y=0;y<n;y++){
        if((G[m][y]==1)&&(!s[y]))
            dfs_c(n,G,y,s);
    }
}
int main()
{
    int i,j,con,s[10],flag;
    printf("Enter number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter adjecency matrix of the graph :\n");
	for(i=0;i<n;i++)
    {
        printf("Enter row %d : -\n",i+1);
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }
   for(i=0;i<n;i++)
        v[i]=0;
   printf("DFS Traversal order :-\n");
   double dfs_time=0.0;
   clock_t begin=clock();
   dfs(0);
   con=0;
   for(j=0;j<n;j++){
        for(i=0;i<n;i++)
            s[i]=0;
        dfs_c(n,G,j,s);
        flag=0;
        for(i=0;i<n;i++){
            if(s[i]==0)
                flag=1;
        }
        if(flag==0)
            con=1;
   }
   if(con==1)
      printf("\nGraph is connected\n");
    else
      printf("\nGraph is not connected\n");
   clock_t end=clock();
   dfs_time+=(double)(end-begin)/CLOCKS_PER_SEC;
   printf("\nn=%d\tTime:%f\n",n,dfs_time);
   return 0;
}
