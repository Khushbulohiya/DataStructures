/*
 * linked_merge.c
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

void ascending(struct node **new, int num)
{
	struct node *temp = *new, *new_node;
	if(*new == NULL || (*new)->data > num)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		*new = new_node;
		(*new)->link = temp; // Important step
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

//Merge two linked list plus avoid the duplicate number as well
void merge(struct node *first, struct node *second, struct node **third)
{
	struct node *current;
	if(first == NULL && second == NULL)
	{
		printf("Linked list first and second is empty.\n");
		return;
	}

	while(first != NULL && second != NULL)
	{
		if(*third == NULL)
		{
			*third = (struct node*)malloc(sizeof(struct node));
			current = *third;
		}
		else
		{
			current->link = (struct node*)malloc(sizeof(struct node));
			current = current->link;
		}

		if(first->data > second->data)
		{
			current->data = second -> data;
			second = second->link;
		}
		else if(first->data < second->data)
		{
			current->data = first -> data;
			first = first->link;
		}
		else if(first->data == second->data)
		{
			current->data = first -> data;
			first = first->link;
			second = second->link;
		}
	}

	while(first != NULL)
	{
		current->link = (struct node*)malloc(sizeof(struct node));
		current = current->link;
		current->data = first -> data;
		first = first->link;
	}

	while(second != NULL)
	{
		current->link = (struct node*)malloc(sizeof(struct node));
		current = current->link;
		current->data = second -> data;
		second = second->link;
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

int main()
{
	struct node *first= NULL;
	struct node *second = NULL;
	struct node*third = NULL;
	ascending(&first, 1);
	ascending(&second, 5);
	ascending(&first, 15);
	ascending(&first, 2);
	ascending(&first, 6);
	ascending(&first, 0);

	display(first);
	ascending(&second, 11);
	ascending(&second, 9);
	ascending(&second, 7);
	ascending(&second, 10);
	ascending(&second, 15);
	ascending(&second, -1);

	display(second);
	merge(first, second, &third);
	display(third);
}
