#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *x, int *y)
{
    int temp;
    temp=(*x);
    (*x)=(*y);
    (*y)=temp;
}
void bubble(int a[],int n)
{
    int i=0,j=0;
    int swapped;
    while(i!=n-1){
        swapped = 0;
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                swapped = 1;
            }
        }
        i++;
        if(swapped==0)
            return;
    }
}
void selection(int a[],int n)
{
    int i,j,min;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(&a[min],&a[i]);
    }
}
void display(int a[],int n)
{
    int i;
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[5000],i,c,n=0,j,k;
    printf("1.Selection Sort\n2.Bubble Sort\n3.Exit\n");
    scanf("%d",&i);
    printf("Enter the no. of times u want sort : ");
    scanf("%d",&j);
    for(n;n<j;n=n+0){
        printf("\nEnter array size : ");
        scanf("%d",&k);
        for (c=0;c<k;c++){
            a[c]=rand();
        }
        double ss_time=0.0;
        clock_t begin=clock();
        if(i==1){
            printf("\n\n\n");
            printf("Selection Sort :-\n");
            selection(a,k);
        }
        else if(i==2){
            printf("\n\n\n");
            printf("Bubble Sort :-\n");
            bubble(a,k);
        }
        else{
            exit(0);
        }
        display(a,k);
        clock_t end=clock();
        ss_time+=(double)(end-begin)/CLOCKS_PER_SEC;
        printf("\nn=%d :%f\n",k,ss_time);
    }

    return 0;
}
