#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;	
}Node;

Node* head=NULL;

Node* createnode(int item)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=item;
	newnode->next=NULL;
	return newnode;
}

void insertAtFirst(int item)
{
	Node* newnode = createnode(item);
	newnode->next = head;
	head=newnode;
}

void insertAtLast(int item)
{
	Node* newnode = createnode(item);
	if(head==NULL)
	{
		head=newnode;	
	}
	else
	{
		Node* temp = head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void display()
{
	Node* temp=head;
	if(head==NULL)
	{
		printf("LINKED LIST EMPTY\n");
		return 0;
	}
	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		printf("%d -> ",temp->data);
		else
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	return;
}

int main()
{
	int i,term;
	for(i=0;i<5;i++)
	{
		printf("Enter a number : ");
		scanf("%d",&term);
		insertAtFirst(term);
	}
	display();
	return 0;
}