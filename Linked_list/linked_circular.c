/*
 * linked_circular.c
 *
 *  Created on: Jul 13, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void append(struct node **front,struct node **rear, int num)
{
	struct node *current;
	if( *front == NULL)
	{
		current = (struct node*)malloc(sizeof(struct node));
		current->data = num;
		*front = current;
		*rear = current;
	}
	else
	{
		current->link = (struct node*)malloc(sizeof(struct node));
		current = current->link;
		current->data = num;
		*rear = current;
		(*rear)->link = *front;
	}
}
void display(struct node *front)
{
	struct node *current = front, *rear = NULL;
	while(current != rear)
	{
		printf("%d\t",current->data);
		current = current->link;
		rear = front;
	}
	printf("\n");
}

int main()
{
	struct node *front= NULL;
	struct node *rear = NULL;

	append(&front,&rear, 1);
	append(&front,&rear, 15);
	append(&front,&rear, 2);
	append(&front,&rear, 6);
	append(&front,&rear, 0);

	display(front);
}
