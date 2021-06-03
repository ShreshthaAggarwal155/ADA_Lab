#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int r)
{
    int pivot=a[r];
    int pindex=l;
    for(int i=l;i<r;i++){
        if(a[i]<=pivot){
            swap(&a[pindex],&a[i]);
            pindex++;
        }
    }
    swap(&a[pindex],&a[r]);
    return pindex;
}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main()
{
    int n,a[100];
    printf("Enter the number of the elements in the array :- ");
    scanf("%d",&n);
    printf("Enter The Elements of the array :-\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    double q=0.0;
    clock_t begin=clock();
    quicksort(a,0,n-1);
    clock_t end=clock();
    q=((double)end-begin)/CLOCKS_PER_SEC;
    printf("Elements of the sorted array :-\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n\nTime taken for %d elements = %f\n",n,q);
    return 0;
}
