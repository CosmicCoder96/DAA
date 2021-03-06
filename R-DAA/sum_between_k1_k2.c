/*Sum of all elements between k1 and k2 th smallest elements*/
#include<stdio.h>
#include<stdlib.h>
void max_heapify(int a[],int index,int n)
{
	
//	while(1)
//	{
		int left,right,i;
		left = (2*index)+1;
		right = (2*index)+2;
		int largest=index;
		
		if(left<n && a[left]>a[largest])
			largest=left;
		if(right<n && a[right]>a[largest])
			largest = right;
	//	if(index==largest)
	//		break;
		if(index!=largest)
		{
			int tmp;
			tmp=a[largest];
			a[largest]=a[index];
			a[index]=tmp;
			max_heapify(a,largest,n);
		}
//	}
}
void build_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		max_heapify(a,i,n);
	
}
int extract_max(int a[],int n)
{
	int t=a[0];
	a[0]=a[(n)-1];
	n--;
	max_heapify(a,0,n);
	int i;
	return t;
}
		
int main()
{
	int i,n,a[1000]={0},k1,k2,j,b[1000],sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d %d",&k1,&k2);
	build_heap(a,n);
		
	for(i=0;i<n;i++)
		printf("%d   ",a[i]);
	printf("\n");
	int k=n;
	j=n;
	for(i=0;i<j;i++)
	{
		int max;  
		max = extract_max(a,n);
		n--;
		b[k--]=max;
		printf("%d\n",max);
	}
	for(i=1;i<=j;i++)
	{
		printf("%d   ",b[i]);
	}
	for(i=k1+1;i<k2;i++)
		sum=sum+b[i];
	printf("%dijh",sum);
	return 0;
}
