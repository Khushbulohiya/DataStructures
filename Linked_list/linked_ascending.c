/*
 * linked_ascending.c
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

void ascending(struct node **new, int num)
{
	struct node *temp = *new, *new_node;
	if(*new == NULL || (*new)->data > num)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		*new = new_node;
		(*new)->link = temp;
		temp = *new;
	}
	else
	{
		while(temp != NULL)
		{
			if((temp->data <= num) && (temp->link == NULL || temp->link->data > num))
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->data = num;
				new_node->link = temp->link;
				temp->link = new_node;
				return;
			}
			else
			{
				temp = temp->link;
			}
		}
	}
}

int main()
{
	struct node *new = NULL;
	ascending(&new, 1);
	ascending(&new, 5);
	ascending(&new, 2);
	ascending(&new, 6);
	ascending(&new, 0);
	display(new);
}
