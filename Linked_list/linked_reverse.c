/*
 * linked_reverse.c
 *
 *  Created on: Jul 12, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void display(struct node *new)
{
	while(new != NULL)
	{
		printf("%d\t",new->data);
		new = new->link;
	}
	printf("\n");
}

void append(struct node **new, int num)
{
	struct node *temp, *new_node;
	if(*new == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*new = temp;
	}
	else
	{
		temp = *new;
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		new_node->link = NULL;
		temp->link = new_node;
	}
}

void reverse(struct node **new)
{
	struct node *current, *prev, *next;
	current = *new;
	prev = NULL;
	while(current != NULL)
	{
		next = current -> link;
		current -> link = prev;
		prev = current;
		current = next;
	}
	*new = prev;
}

int main()
{
	struct node *new = NULL;
	append(&new, 1);
	append(&new, 2);
	append(&new, 3);
	append(&new, 4);
	append(&new, 5);
	display(new);
	reverse(&new);
	display(new);
}
