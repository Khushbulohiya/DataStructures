/*
 * linked_double.c
 *
 *  Created on: Jul 14, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>


struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void append(struct node **new, int num)
{
	struct node *current = *new, *temp;
	if(*new == NULL)
	{
		current = (struct node*)malloc(sizeof(struct node));
		current->data = num;
		current->prev = NULL;
		current->next = NULL;
		*new = current;
	}

	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = num;
			temp->next = NULL;
			temp->prev = current;
			current->next = temp;
	}
}

void addatbeg(struct node **new, int num)
{
	struct node* current;
	if(*new == NULL)
	{
		(*new) = (struct node*)malloc(sizeof(struct node));
		(*new)->data = num;
		(*new)->prev = NULL;
		(*new)->next = NULL;
	}

	else
	{
		current = (struct node*)malloc(sizeof(struct node));
		current->data = num;
		current->next = *new;
		(*new)->prev = current;
		(*new) = current;
	}
}

void delete(struct node **new, int num)
{
	struct node *current = *new, *old;
	if(*new == NULL)
	{
		printf("Linked list is empty.\n");
		return;
	}

	while(current != NULL)
	{
		if(current->data == num)
		{
			if(current == *new)
			{
				current = current->next;
				current->prev = NULL;
				*new = current;
			}
			else
			{
				old->next  = current->next;
				current = current->next;
				current->prev = old;
			}

			//free(current);
			return;
		}

		else
		{
			old = current;
			current = current->next;
		}
	}
}

void addafter(struct node **new, int loc, int num)
{
	struct node *current = *new, *new_node;
	for(int i = 0; i < loc; i++)
	{
		current = current->next;
		if(current == NULL)
		{
			printf("There are less that %d elements in the list.\n");
			return;
		}
	}
	current = current->prev;//Add at position 2 then use this else after position 2 remove it
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->prev = current;
	new_node->next = current->next;
	current->next = new_node;
	current = new_node;
}
void display(struct node *new)
{
	while(new != NULL)
	{
		printf("%d\t",new->data);
		new = new->next;
	}
	printf("\n");
}

int main()
{
	struct node *new = NULL;
	append(&new, 1);
	append(&new, 15);
	append(&new, 0);
	append(&new, 2);
	append(&new, 6);
	printf("Doubly Linked list before deletion: \n");
	display(new);
	addatbeg(&new, -1);
	addatbeg(&new, -2);
	printf("Doubly Linked list before deletion and after add_at_beg: \n");
	display(new);
	delete(&new, -2);
	delete(&new, 0);
	printf("Doubly Linked list after deletion: \n");
	display(new);
	addafter(&new, 2, 5);
	printf("Doubly Linked list after deletion and addafter: \n");
	display(new);
}
