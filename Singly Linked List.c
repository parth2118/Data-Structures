#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);
struct node *reverse(struct node *start);

int main()
{
	int option;
	do
	{
		printf("\n1) Create a List");
		printf("\n2) Display List");
		printf("\n3) Add node at the beginning");
		printf("\n4) Add node at the end");
		printf("\n5) Add node before given node");
		printf("\n6) Add node after given node");
		printf("\n7) Delete node from the beginning");
		printf("\n8) Delete node from the end");
		printf("\n9) Delete given node");
		printf("\n10) Delete node after given node");
		printf("\n11) Delete the entire list");
		printf("\n12) Reverse list");
		printf("\n13) Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start=create_ll(start);
				printf("\nLinked List Created");
			break;
			case 2:
				start=display(start);
			break;
			case 3:
				start=insert_beg(start);
			break;
			case 4:
				start=insert_end(start);
			break;
			case 5:
				start=insert_before(start);
			break;
			case 6:
				start=insert_after(start);
			break;
			case 7:
				start=delete_beg(start);
			break;
			case 8:
				start=delete_end(start);
			break;
			case 9:
				start=delete_node(start);
			break;
			case 10:
				start=delete_after(start);
			break;
			case 11:
				start=delete_list(start);
				printf("\nLinked List Deleted");
			break;
			case 12:
				start=reverse(start);
			break;
		}
	}while(option!=13);
	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter data: ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nEnter data: ");
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("start");
	while(ptr!=NULL)
	{
		printf("->%d",ptr->data);
		ptr=ptr->next;
	}
	printf("->Null");
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	return start;
}

struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num,val;
	printf("\nEnter data: ");
	scanf("%d",&num);
	printf("\nEnter the value before which the data has to be inserted: ");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num,val;
	printf("\nEnter data: ");
	scanf("%d",&num);
	printf("\nEnter the value after which the data has to be inserted: ");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr!=NULL)
	{
		start=start->next;
		free(ptr);
	}
	else
	{
		printf("\nLinked List is empty");
	}
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}

struct node *delete_node(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\nEnter value of the node which has to be deleted: ");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val)
	{
		start=delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}

struct node *delete_after(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\nEnter the value after which the node has to be deleted: ");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	if(start!=NULL)
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n%d is to be deleted next",ptr->data);
			start=delete_beg(ptr);
			ptr=start;
		}
	}
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *prev=NULL, *nextnode=NULL;
	while(start)
	{
		nextnode=start->next;
		start->next=prev;
		prev=start;
		start=nextnode;
	}
	return prev;
}
