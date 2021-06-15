//B171381
//Implemenataion of selectionsort using functions

 #include<stdio.h>
#include<stdlib.h>
void selection(int a[29],int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j >0; j--)
		{
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
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
	selection(a,n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",a[i] );
	}
}
