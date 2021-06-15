//B171381
//Implementation of bubble sort using function
#include<stdio.h>
#include<stdlib.h>
int * bubble(int a[29],int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return a;
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
	bubble(a,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",a[i] );
	}
}
