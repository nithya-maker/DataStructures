//B171381
//Implemenataion of mergrsort using functions
#include<stdio.h>
#include<stdlib.h>
int * merge(int a[29],int start,int mid, int end)
{
	int b[29],c=0,i,j;
	i=start;
	j=mid+1;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			b[c]=a[i];
			c++;i++;
		}
		else
		{
			b[c]=a[j];
			c++;j++;
		}
	}
	while(i<=mid)
	{
		b[c]=a[i];
		i++;c++;
	}
	while(j<=end)
	{
		b[c]=a[j];
		j++;c++;
	}
	for (i = 0; i <end; i++)
	{
		a[start+i]=b[i];
	}
	return a;
}
int * mergesort(int a[29],int start,int end)
{
	int mid;
	if(start<end)
	{
		mid= (start+end-1)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
	return a;
}
void main()
{
	int a[29],*q;
	q=a;
	int n;
	printf("no of elements:\n");
	scanf("%d",&n);
	for (int i = 0; i <n; i++)
	{
		scanf("%d",(a+i));
	}
	mergesort(a,0,n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",a[i]);
	}
} 
