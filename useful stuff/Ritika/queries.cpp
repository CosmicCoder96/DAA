#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int q;
	int n1,v,i;
	int a[100000];
	int n=0;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n1);
		if(n1==1)
		{
			scanf("%d",&v);
			a[n++]=v;

		}
		if(n1==2)
		{
			scanf("%d",&v);
			for(i=0;i<n;i++)
			{
				if(a[i]==v)
				{
					a[i]=a[n-1];
					n=n-1;
				
				}
			}
		}
		if(n1==3)
		{
			
			if(n1==3)
			  {
				  int min;
				  min=a[0];
				  for(i=1;i<n;i++)
				  {
					  if(a[i]<min)
						  min=a[i];
				  }
				  printf("%d\n",min);
			  }
									
		  }
		
	}
}
