#include<stdio.h>

//#define size 100

int fmax(int *a,int n)
{
	int i,m=*(a);
	for(i=0;i<n;i++)
	{
		if(*(a+i)>m)
			m=*(a+i);
	}
	
	return m;
}

int fmin(int *a,int n)
{
	int i,m=*a;
	for(i=0;i<n;i++)
	{
		if(*(a+i)<m)
			m=*(a+i);
	}
	
	return m;
}

int main()
{
	int n,i,j,t,max,min,f,k,p;
	printf("Enter n: ");
	scanf("%d",&n);
	int *arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",(arr + i));
	
	max=fmax(arr,n);
	min=fmin(arr,n);
	
	k=0;
	for(i=max;i>=min;i--)
	{
		f=0;
		for(j=0;j<(n/2);j++)
		{
			if(i==*(arr+j))
			{
				f=1;
				p=j;
			}
		}
		if(f==1)
		{
			t=*(arr+k);
			*(arr+k)=*(arr+p);
			*(arr+p)=t;
			k++;
		}
	}
	
	for(i=0;i<n;i++)
	printf("%d ",*(arr+i));
	
}
