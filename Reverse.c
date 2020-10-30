
//Reverse the array//
#include<stdio.h>
int *reverse(int *a,int n)
{
    int *first= a,*last= a+(n-1),temp;
    for(first=a;first<last;first++)
    {
        temp=*first;
        *first= *last;
        *last= temp;
        first++;
        last--;
    }
    return a;
}

int main()
{
    int a[10],n,i;
    int *p;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    printf("enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    p=reverse(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",*p++);
    }
    return 0;
}
