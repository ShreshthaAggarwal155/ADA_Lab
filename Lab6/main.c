#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10][10],indegree[10],front=-1,rear=-1,stack[10],t[10],k,n;
void get(int n){
    int i,j;
    printf("Enter the adjacency matrix :\n");
    for(i=0;i<n;i++){
        printf("Enter row %d\n",(i+1));
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
}
void cal_indegree(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            indegree[i]=indegree[i]+a[j][i];
        }
    }
}
void push(int x){
    if(front==-1&&rear==-1)
        front=rear=0;
    else if(rear==n-1)
        return;
    else{
        rear++;
    }
    stack[rear]=x;
}
int pop()
{
    int x;
    if(front==-1||front>rear){
        return -1;
    }
    x=stack[front];
    if(front==rear||front>rear){
        front=-1;
        rear=-1;
    }
    else{
      front++;
    }
    return x;

}
int main(){
    int i,v;
    printf("Enter the no of vertices :\n");
    scanf("%d",&n);
    get(n);
    for(i=0;i<n;i++){
        indegree[i]=0;
    }
    double t_time=0.0;
    clock_t begin=clock();
    cal_indegree(n);
    printf("\nThe topological order is : ");
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            push(i);
        }
    }
    while(front!=-1){
        int u=pop();
        if(u==-1)
            break;
        t[k]=u;
        k++;
        for(v=0;v<n;v++){
            if(a[u][v]==1){
                ((indegree[v])--);
                if(indegree[v]==0){
                    push(v);
                }
            }
        }
    }
    clock_t end=clock();
    t_time+=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("Topological Order :\n");
    for(int i=0;i<k;i++){
        printf("%d\t",t[i]);
    }
    printf("\nFor matrix n=%d\tTime:%f\n",n,t_time);
    return 0;
}
