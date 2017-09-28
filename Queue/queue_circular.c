/*
 * linked_circular.c
 *
 *  Created on: Jul 14, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data ;
	struct node *link;
};

struct queue
{
	struct node *front;
	struct node *rear;
};

void initqueue(struct queue *new)
{
	new->front = new->rear = NULL;
}

void addqueue(struct queue *new, int num)
{
	struct node *current;
	current = (struct node*)malloc(sizeof(struct node));
	if(new->front == NULL && new->rear == NULL)
	{
		current->data = num;
		new->rear = current;
		new->front = current;
		current->link = NULL;
	}
	else
	{
		current->data = num;
		new->rear->link = current;
		new->rear = current;
		new->rear->link = new->front;
	}
}

void delete(struct queue *new)
{
	struct node *current = new->front;
	if(new->front == NULL && new->rear == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	else
	{
		if(new->front == new->rear)
		{
			new->front = new->rear = NULL;
			free(current);
			return;
		}
		else
		{
			new->front = new->front->link;
			new->rear->link = new->front;
			free(current);
			return;
		}
	}
}

void display(struct queue *new)
{
	struct node *current = new->front, *rear = NULL;
	while(current != rear)
	{
		printf("%d\t",current->data);
		current = current->link;
		rear = new->front;
	}
	printf("\n");
}

int main()
{
	struct queue new;
	initqueue(&new);
	addqueue(&new, 1);
	addqueue(&new, 2);
	addqueue(&new, 3);
	addqueue(&new, 4);
	addqueue(&new, 5);
	printf("Queue before deletion: \n");
	display(&new);
	delete(&new);
	printf("Queue after deletion: \n");
	display(&new);
}
