#include <stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W,int wt[],int val[],int n)
{
    int i, w;
    int K[n+1][W+1];
    for (i=0;i<=n;i++){
        for (w=0;w<=W;w++){
            if(i==0 || w==0)
                K[i][w]=0;
            else if(wt[i-1]<=w)
                K[i][w]=max(K[i-1][w],val[i-1]+K[i-1][w-wt[i-1]]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}
int main()
{
    int n,max;
    printf("\nEnter the No of Items: ");
    scanf("%d",&n);
    int val[n],wt[n];
    printf("\nEnter the Weight and Profit of Items :- \n");
    for(int i=0;i<n;i++){
        printf("Weight of Item %d :- ",(i+1));
        scanf("%d",&wt[i]);
        printf("Value of Item %d :- ",(i+1));
        scanf("%d",&val[i]);
        printf("\n");
    }
    printf("\nEnter the Capacity :- ");
    scanf("%d",&max);
    printf("Maximum Profit :- %d",knapSack(max,wt,val,n));
    return 0;
}
