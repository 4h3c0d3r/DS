#include<stdio.h>
#include<string.h>

#define size 100

int main()
{
	char *s=(char *)malloc(size*sizeof(char));
	char *p=(char *)malloc(size*sizeof(char));
	char ch;
	int i,j,l,k,t;
	printf("Enter the string: ");
	scanf("%[^\n]",s);
	l=strlen(s);
	k=0;
	for(i=0;i<l;i++)
	{
		ch=*(s+i);
		p[k++]=ch;
		t=(int)ch%5;
		for(j=0;j<t;j++)
			p[k++]=ch;
	}
	p[k]='\0';
	
	printf("%s",p);
	
}
