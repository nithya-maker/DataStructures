//B171381
//Implemenataion of quicksort using functions

#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
	//return a;
}
void sort(int a[29],int start,int end)
{
	int i,j;
	if(start<end)
	{
		i=start;
		j=end;
		while(i<j)
		{
			while(a[start]>a[i] && i<j)
			{
				i++;
			}
			while(a[start]<a[j])
			{
				j--;
			}
			if(i<j)
			{
				swap(&a[i],&a[j]);
			}
		}
		swap(&a[start],&a[j]);
		sort(a,start,j-1);
		sort(a,j+1,end);
	}
	//return a;
}
void main()
{
	int a[29],*q;
	int n;
	q=a;
	printf("no of elements:\n");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",(a+i));
	}
	sort(a,0,n-1);
	printf("output\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",*(a+i));
	}
}
