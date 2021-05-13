#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion(int a[],int n){
    for(int i=1;i<n;i++){
        int j,key;
        key=a[i];
        j=i-1;
        while(key<a[j]&&j>=0){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}
void display(int a[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n,i,a[10];
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("Enter values of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    double is_time=0.0;
    clock_t begin=clock();
    insertion(a,n);
    clock_t end=clock();
    is_time+=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("Sorted array : \n");
    display(a,n);
    printf("\nn=%d\tTime:%f\n",n,is_time);
    return n;
}
