//B171381
//Implementation of inseertion sort using function
#include<stdio.h>
#include<stdlib.h>
void insertion(int a[29],int n)
{
	int temp,ummy;
	for (int i = 0; i < n; i++)
	{
		ummy=a[i];
		for (int j = i+1; j<n ; j++)
		{
			if(ummy>a[j]){
				temp=ummy;
				ummy=a[j];
				a[j]=temp;
			}
		}
		a[i]=ummy;
	}
}
void main()
{
	int a[29],n;
	printf("no of elements:\n");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&a[i]);
	}
	insertion(a,n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",a[i] );
	}
}
