/*
 * addlinked.c
 *
 *  Created on: Jul 12, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


void rem_odd(struct node** head)
{
    struct node* curr = *head;
    struct node* l_even;

    // iterate until the first even element, or the end
    while (curr != NULL && curr->data % 2 != 0)
    {
        curr = curr->next;
    }

    // the new head is the first even element, or the end
    *head = curr;

    // if no more elements, we're done here
    if (curr == NULL) {
        return;
    }

    // the last even element is the current element, naturally
    l_even = curr;

    // we know the current element is even, and not null, so moving on
    curr = curr->next;

    // iterate until the end
    while (curr != NULL)
    {
        // is the current element even?
        if (curr->data % 2 == 0) {

            // -> yes, it's even, so the last even element should point to it
            l_even->next = curr;

            // ... and this is the new last-even-element now
            l_even = curr;
        }
        curr = curr->next;
    }
    l_even->next = NULL;
}
void append(struct node **new, int num)
{
	struct node *temp, *new_node;
	if(*new == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = NULL;
		*new = temp;
	}
	else
	{
		temp = *new;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		new_node->next = NULL;
		temp->next = new_node;
	}
}

void addatbeg(struct node **new, int num)
{
	struct node *temp, *new_node;
	if(*new == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = NULL;
		*new = temp;
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = *new;
		*new = temp;
	}
}

void delete(struct node**new, int num)
{
	struct node *temp, *old;
	temp = *new;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp == *new)
			{
				temp = temp->link;
				*new = *new->link;
			}
			else
			{
				old->link = temp->link;
			}

			free(temp);
			return;
		}
		else
		{
			old = temp;
			temp = temp->link;
		}
	}
	printf("Number %d is not found in the linked list.\n",num);
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
	append(&new, 2);
	append(&new, 3);
	append(&new, 4);
	append(&new, 5);
	display(new);
	addatbeg(&new, 0);
	addatbeg(&new, -1);
	printf("Linked list before deleting.\n");
	display(new);
    delete(new, 2)
	rem_odd(&new);
	printf("Linked list after deleting.\n");
	display(new);


}
