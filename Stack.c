#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int st[MAX];
int top=-1;

void push();
void pop();
void display();

void main()
{
	int ch;
	while(1)
	{
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) Display\n");
		printf("4) Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				push();
			break;
			case 2:
				pop();
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("Invalid Choice\n");
			break;
		}
	}
}

void push()
{
	int a;
	if(top>=MAX-1)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter Value: ");
		scanf("%d",&a);
		printf("\n\n");
		top++;
		st[top]=a;
	}
}

void pop()
{
	if(top<0)
	{
		printf("Underflow\n");
	}
	else
	{
		printf("Popped Value: %d",st[top]);
		printf("\n");
		top--;
	}
}

void display()
{
	int a;
	if(top<0)
	{
		printf("Underflow\n");
	}
	else
	{
		for(a=top;a>=0;a--)
		{
			printf("%d\n",st[a]);
		}
		printf("\n");
	}
}
