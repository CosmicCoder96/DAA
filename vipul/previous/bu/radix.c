#include <stdio.h>
#define sc(x) scanf("%d",&x)
void cs(int arr[],int n,int d)
{
    int i,j,p=1;
    while(d>0)
    {
        d--;
        p*=10;
    }
    int *c=(int *)calloc(15,sizeof(int));
    int *op=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        c[(arr[i]/p)%10]++;
    }
    for(i=1;i<=9;i++)
    {
        c[i]+=c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        op[c[(arr[i]/p)%10]-1]=arr[i];
        c[(arr[i]/p)%10]--;
    }
    for(i=0;i<n;i++)
    {
    	arr[i]=op[i];
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void rs(int arr[],int n)
{
    int i,k;
    int mx=0;
    for(i=0;i<n;i++)
    {
        if(mx<arr[i])
        {
            mx=arr[i];
        }
    }
    i=0;k=mx;
    while(mx>0)
    {
        cs(arr,n,i);
        mx/=10;
        i++;
    }
}
int main()
{
    int j,i,n;
    sc(n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i]);
    }
    rs(arr,n);
    return 0;
}



