/*
 * stack_stringreverse.c
 *
 *  Created on: Jul 31, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *link;
	char data;
};

void push(struct node **top, char num)
{
	struct node *temp;
	if(*top == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*top = temp;
		printf("pushing 1st data %c.\n",temp->data);
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = *top;
		*top = temp;
		printf("pushing rest data %c.\n",(*top)->data);
	}
}

char pop(struct node **top)
{
	struct node *temp =  *top;
	if(*top == NULL)
	{
		printf("Stack is empty.\n");
		return -1;
	}
	char data = (*top)->data;
	*top = (*top)->link;
	free(temp);
	printf("popping %c.\n",data);
	return data;
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

int main()
{
	struct node *stack = NULL;
	char exp[100] = "khushbu";
	int i = 0;
	while(exp[i] != '\0')
	{
		push(&stack, exp[i]);
		i++;
	}
	printf(" value of i is %d\n",i);
	i = 0; //IMP
	while(stack != NULL)
	{
		exp[i] = pop(&stack); //exp[i] = u
		i++;
	}
	printf("Reverse string is %s",exp);

}
