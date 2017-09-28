/*
 * linked_sort.c
 *
 *  Created on: Jul 13, 2017
 *      Author: khushbu
 */

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

int count(struct node *new)
{
	int count = 0;
	while(new != NULL)
	{
		new = new->link;
		count++;
	}
	return count;
}

void selection_sort(struct node *new, int total)
{
	struct node *current, *next;
	int i, j, temp;
	current = new;
	for(i = 0; i < total-1 ; i++)
	{
		next = current->link;
		for(j = i + 1; j < total; j++)
		{
			if(current->data > next->data)
			{
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->link;
		}
		current = current->link;
	}
}

int main()
{
	struct node *new = NULL;
	append(&new, 1);
	append(&new, 15);
	append(&new, 5);
	append(&new, 2);
	append(&new, 6);

	display(new);
	int c = count(new);
	printf("Total nodes in the linked list is %d.\n",c);
	selection_sort(new, c);
	display(new);

}


