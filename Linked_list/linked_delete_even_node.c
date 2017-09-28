/*
 * linked_delete_alternate_node.c
 *
 *  Created on: Aug 3, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *link;
};

void insert(struct node **new, int num)
{
	struct node *current, *temp;
	if(*new == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*new = temp;
	}
	else
	{
		current = *new;
		while(current->link != NULL)
		{
			current = current->link;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		current->link = temp;
	}

}

void display(struct node *new)
{
	while(new != NULL)
	{
		printf("%d\t",new->data);
		new = new->link;
	}
	printf("\n");
}

void delete(struct node **head)
{
	struct node *current = *head;
	struct node *delnode = current;
	struct node *temp = current->link;
	if(*head == NULL)
	{
		return;
	}
	else
	{
		while(temp != NULL)
		{
			delnode = temp;
			current->link = temp->link;
			temp = temp->link->link;
			current = current->link;
		}
	}
	free(delnode);
}
int main()
{
	struct node *new = NULL;
	insert(&new, 1);
	insert(&new, 2);
	insert(&new, 3);
	insert(&new, 4);
	insert(&new, 5);
	display(new);
	delete(&new);
	display(new);

}
