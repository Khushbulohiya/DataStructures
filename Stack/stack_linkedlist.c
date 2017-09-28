/*
 * stack_linkedlist.c
 *
 *  Created on: Jul 31, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *link;
	int data;
};

void push(struct node **top, int num)
{
	struct node *temp;
	if(*top == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*top = temp;
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = *top;
		*top = temp;
	}
}

void display(struct node *top)
{
	struct node *temp = top;
	while(temp != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int pop(struct node **top)
{
	struct node *temp =  *top;
	if(*top == NULL)
	{
		printf("Stack is empty.\n");
		return;
	}
    int value = (*top)->data;
	*top = (*top)->link;
	free(temp);
	return value;
}


int main()
{
	struct node *new = NULL;
	push(&new, 6);
	push(&new, 5);
	push(&new, 4);
	push(&new, 3);
	push(&new, 2);
	push(&new, 1);
	printf("Stack before deletion: \n");
	display(new);
	int value = pop(&new);
	printf("Stack after deletion: \n");
	display(new);
	value = pop(&new);
	printf("Stack after deletion: \n");
	display(new);
}
