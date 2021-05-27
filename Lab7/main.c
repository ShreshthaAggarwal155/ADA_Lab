#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int mid,int r)
{
    int c[10000],i,j,k;
    i=k=l;
    j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            c[k]=a[i];
            ++k;
            ++i;
        }
        else{
            c[k]=a[j];
            ++k;
            ++j;
        }
    }
    if(i>mid){
        while(j<=r){
            c[k]=a[j];
            ++k;
            ++j;
        }
    }
    if(j>r){
        while(i<=mid){
            c[k]=a[i];
            ++k;
            ++i;
        }
    }
    for(i=l;i<=r;i++)
        a[i]=c[i];
}
void mergeSort(int a[],int l,int r)
{
    int mid;
    if(l<r){
        mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int a[10000],n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter array elements :\n");
    for(i=0;i<n;i++)
        a[i]=rand();
    clock_t begin=clock();
    mergeSort(a,0,n-1);
    clock_t end=clock();
    double m_time=0.0;
    m_time+=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n\nTime taken for %d numbers is %f",n,m_time);
    return 0;
}

