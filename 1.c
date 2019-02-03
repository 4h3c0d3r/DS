#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

/*struct node * append(struct node *p)
{
	printf("Enter where you want to add:\n");
	printf("1 - Front of the list\n");
	printf*/
	
int input()
{
	int x;
	printf("\nEnter node data: ");
	scanf("%d",&x);
	return x;
}

int length(struct node *p)
{
	int l=0;
	while(p!=NULL)
	{
		l++;
		p=p->link;
	}
	return l;
	//printf("\nNo. of elements: %d\n",l);
}

void display(struct node *p)
{
	struct node *t;
	t=p;
	printf("\nLinked List : ");
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->link;
	}
	printf("\n\n");
}
	
int search(struct node *p,int d)
{
	int i,f;
	i=f=0;
	while(p!=NULL)
	{
		if(p->data==d)
		{
			f=1;
			break;
		}
		i++;
		p=p->link;
	}
	if(f==1)
		return i;
	else
		return -999;
}

struct node * appendbeg(struct node *p)
{
	struct node *q;
	q=p;
	if(q==NULL)
	{
		struct node *t;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=input();
		t->link=NULL;
		q=t;
		return q;
	}
		struct node *t;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=input();
		t->link=p;
		//p=t;
		return t;
}

void append(struct node *p)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	while(p->link!=NULL)
		p=p->link;
	q->data=input();
	q->link=NULL;
	p->link=q;
}

void ordered(struct node *p)
{
	int i,n,f=1;
	if(p==NULL)
		printf("List is empty\n");
	else
	{
		n=p->data;
		p=p->link;
		while(p!=NULL)
		{
			if(n>p->data)
			{
				f=0;
				break;
			}
			n=p->data;
			p=p->link;
		}
	}
	if(f==1)
		printf("List is ordered\n");
	else
		printf("List is not ordered\n");
}


void equality(struct node *p,struct node *q)
{
	int f=1,l1,l2;
	l1=length(p);
	l2=length(q);
	if(l1!=l2)
		printf("List are not equal\n");
	else
	{
		while(p!=NULL && q!=NULL)
		{
			if(p->data!=q->data)
			{
				f=0;
				break;
			}
			p=p->link;
			q=q->link;
		}
	}
	
	if(f==1)
		printf("List are equal\n");
	else
		printf("List are not equal\n");	
}

void addaftern(struct node *p,int loc)
{
	if(loc>(length(p)-1))
	{
		printf("\nWrong Location\n");
	}
	else
	{
		struct node *q;
		q=(struct node *)malloc(sizeof(struct node));
		int i;
		while(i!=loc)
		{
			p=p->link;
			i++;
		}
		q->data=input();
		q->link=p->link;
		p->link=q;
	}
}



void addafterdata(struct node *p)
{
	int loc,d,i;
	printf("Enter node data after which a new node is to be added: ");
	scanf("%d",&d);
	loc=search(p,d);
	if(loc==-999)
	{
		printf("\nNode data not found...\n");
	}
	else
	{
		struct node *q;
		q=(struct node *)malloc(sizeof(struct node));
		i=0;
		while(i!=loc)
		{
			p=p->link;
			i++;
		}
		q->data=input();
		q->link=p->link;
		p->link=q;
	}
}
		
void addbeforen(struct node *p,int loc)
{
	if(loc>(length(p)-1))
	{
		printf("\nWrong Location\n");
	}
	else if(loc==0)
	{
		printf("\nCan't add here... Some other function available for it\n");	
	}
	else
	{
		struct node *q;
		q=(struct node *)malloc(sizeof(struct node));
		int i;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q->data=input();
		q->link=p->link;
		p->link=q;
	}
}


void addbeforedata(struct node *p)
{
	int loc,d,i;
	printf("Enter node data before which a new node is to be added: ");
	scanf("%d",&d);
	loc=search(p,d);
	if(loc==-999)
	{
		printf("\nNode data not found...\n");
	}
	else if(loc==0)
	{
		printf("\nCan't add here... Some other function available for it\n");	
	}
	else
	{
		struct node *q;
		q=(struct node *)malloc(sizeof(struct node));
		i=0;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q->data=input();
		q->link=p->link;
		p->link=q;
	}
}

struct node * deletebeg(struct node *p)
{
	
	if(p==NULL)
	{
		printf("\nList already empty\n");
		return p;
	}
	else
	{
		struct node *q;
		q=p->link;
		p->link=NULL;
		free(p);
		printf("Modified list is\n");
		display(q);
		return q;
	}
}

struct node * delete(struct node *p)
{
	struct node *q;
	q=p;
	if(q==NULL)
		printf("List is empty\n");
	else if(q->link==NULL)
		q=NULL;
	else
	{
		while(q->link->link!=NULL)
		{
			q=q->link;
		}
		q->link=NULL;
		return p;
	}
	return q;
}

void delaftern(struct node *p,int loc)
{
	if(loc>(length(p)-1))
	{
		printf("\nWrong Location\n");
	}
	else if((loc+1)==length(p))
		printf("\nNo element after %d\n",loc);
	else
	{
		struct node *q,*r;
		int i=0;
		while(i!=loc)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		r=q->link;
		p->link=r;
		q->link=NULL;
		free(q);
	}
}

void delafterdata(struct node *p)
{
	int loc,d,i;
	printf("Enter node data after which a new node is to be added: ");
	scanf("%d",&d);
	loc=search(p,d);
	if(loc==-999)
	{
		printf("\nNode data not found...\n");
	}
	else
	{
		struct node *q,*r;
		i=0;
		while(i!=loc)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		r=q->link;
		p->link=r;
		q->link=NULL;
		free(q);
	}
}

void delbeforen(struct node *p,int loc)
{
	if(loc>(length(p)-1))
	{
		printf("\nWrong Location\n");
	}
	else if(loc==0)
	{
		printf("\nCan't delete here... No data available before root...\n");	
	}
	else
	{
		struct node *q,*r;
		int i=0;
		while(i<loc-2)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		r=q->link;
		p->link=r;
		q->link=NULL;
		free(q);
	}
}

void delbeforedata(struct node *p)
{
	int loc,d,i;
	printf("Enter node data before which a new node is to be added: ");
	scanf("%d",&d);
	loc=search(p,d);
	if(loc==-999)
	{
		printf("\nNode data not found...\n");
	}
	else if(loc==0)
	{
		printf("\nCan't delete here... No data available before root...\n");	
	}
	else
	{
		struct node *q,*r;
		q=(struct node *)malloc(sizeof(struct node));
		i=0;
		while(i<loc-2)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		r=q->link;
		p->link=r;
		q->link=NULL;
		free(q);
	}
}


void reverse(struct node *root)
{
	struct node *p,*q;
	int i,j,k,temp;
	j=length(root)-1;
	p=q=root;
	i=0;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		j--;
		i++;
		p=p->link;
		q=root;
	}
	printf("Reversed List: \n");
	display(root);
}
		
		

int main()
{
	struct node *root=NULL;
	struct node *p,*q;
	p=q=NULL;
	int i,loc,d,fi;
	//root=appendbeg(root);
	//display(root);
	do
	{
		printf("\n\n1 -  Create a linked list\n");
		printf("2 -  Print linked list\n");
		printf("3 -  Count of no. of elements in linked list\n");
		printf("4 -  Check for ordered linked list\n");
		printf("5 -  Equality of linked list\n");
		printf("6 -  Concatenate linked list\n");
		printf("7 -  Insert at front of linked list\n");
		printf("8 -  Insert at the end of linked list\n");
		printf("9 -  Insert 'm' after nth element in linked list\n");
		printf("10 - Insert 'm' after 'n' in linked list\n");
		printf("11 - Insert 'm' before nth element in linked list\n");
		printf("12 - Insert 'm' before 'n' in linked list\n");
		printf("13 - Delete at front of linked list\n");
		printf("14 - Delete at end of linked list\n");
		printf("15 - Delete 'm' after nth element in linked list\n");
		printf("16 - Delete 'm' after 'n' in linked list\n");
		printf("17 - Delete 'm' before nth element in linked list\n");
		printf("18 - Delete 'm' before 'n' in linked list\n");
		printf("19 - Reverse the  linked list\n");
		printf("20 - Search for an element\n");
		printf("21 - Merge two list\n");
		printf("\n\nEnter choice ( Enter 0 to exit...) : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: 
				printf("Linked List Created\n");
				printf("Enter 1st element: ");
				root=appendbeg(root);
					break;
			case 2:
				display(root);
					break;
			case 3: 
				printf("No. of nodes: %d\n",length(root));
					break;
			case 4:
				ordered(root);
				break;
			case 5:
				printf("\nEnter data into first list: \n");
				p=appendbeg(p);
				do
				{
					append(p);
					printf("Input -1 to exit and finish entering data (or otherwise) : ");
					scanf("%d",&fi);
				}while(fi!=-1);
				
				printf("\nEnter data into second list: \n");
				q=appendbeg(q);
				do
				{
					append(q);
					printf("Input -1 to exit and finish entering data (or otherwise) : ");
					scanf("%d",&fi);
				}while(fi!=-1);
				
				equality(p,q);
				break;
					
				
			case 7: 
				root=appendbeg(root);
					break;
			case 8:
				append(root);
					break;
			case 9:
				printf("Enter the location of nth element ( 0 - %d ) : " ,length(root)-1);
				scanf("%d",&loc);
				addaftern(root,loc);
					break;
			case 10:
				addafterdata(root);
					break;
			case 11: 
				printf("Enter the location of nth element ( 0 - %d ) : " ,length(root)-1);
				scanf("%d",&loc);
				addbeforen(root,loc);
					break;
			case 12: 
				addbeforedata(root);
					break;
			case 13:
				root=deletebeg(root);
				break;
			case 14:
				root=delete(root);
				break;
			case 15:
				printf("Enter the location of nth element ( 0 - %d ) : " ,length(root)-1);
				scanf("%d",&loc);
				delaftern(root,loc);
					break;
			case 16: 
				delafterdata(root);
					break;
			case 17:
				printf("Enter the location of nth element ( 0 - %d ) : " ,length(root)-1);
				scanf("%d",&loc);
				delbeforen(root,loc);
					break;
			case 18:
				delbeforedata(root);
					break;
			case 19:
				reverse(root);
				break;
			case 20:
				printf("Enter data to search : ");
				scanf("%d",&d);
				loc=search(root,d);
				if(loc>=0)
					printf("\nData found at node %d \n",loc);
				else
					printf("\nData Not found...\n");
				break;
			default: printf("Wrong Choice\n");
		}	
	}while(i!=0);	
}
	




		
		
		
