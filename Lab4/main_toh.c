#include<stdio.h>
#include<time.h>
#include<math.h>
void towers(int n,char s, char t, char d)
{
    if(n==1){
        printf("Move disk 1 from %c to %c\n",s,d);
        return;
    }
    towers(n-1,s,d,t);
    printf("Move disk %d from %c to %c\n",n,s,d);
    towers(n-1,t,s,d);
}
int main()
{
    int n;
    printf("Enter no. of disks : ");
    scanf("%d",&n);
    double toh_time=0.0;
    clock_t begin=clock();
    towers(n,'S','T','D');
    printf("\nTotal Steps : %lf",(pow(2,n)-1));
    clock_t end=clock();
    toh_time+=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nn=%d\tTime:%f\n",n,toh_time);
    return 0;
}
