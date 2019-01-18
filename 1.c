#include<stdio.h>
#include<string.h>

#define range 100

int main()
{
	int i,j,l,k,t;
	char ch,ch1,ch2;
	char *s=(char *)malloc(range*sizeof(char));
	char *p=(char *)malloc(range*sizeof(char));
	char *q=(char *)malloc(range*sizeof(char));
	printf("Enter the string: ");
	scanf("%[^\n]",s);
	l=strlen(s);
	k=0;
	for(i=0;i<l;i++)
	{
		ch=*(s+i);
		if(ch==*(s+i+1))
			continue;
		else
		{
			p[k]=ch;
			k++;
		}
	}
	p[k]='\0';
	t=1;
	k=0;
	for(i=0;i<l;i++)
	{
		ch=*(s+i);
		ch1=*(s+i+1);
		if(ch==ch1)
		{
			t++;
			continue;
		}
		else
		{
			if(t%2==0)
			{
				for(j=0;j<t+1;j++)
					q[k++]=ch;
			}
			else if(t%2!=0 && t>1)
			{
				for(j=0;j<t-1;j++)
					q[k++]=ch;
			}
			else if(t==1)
				q[k++]=ch;
			t=1;
		}
		
	}
	q[k]='\0';
	printf("%s\n%s\n%s",s,p,q);
}
