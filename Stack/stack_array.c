/*
 * stsck_array.c
 *
 *  Created on: Jul 31, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct stack
{
	int array[MAX];
	int top;
};

void initstack(struct stack *new)
{
	new->top = -1;
}
void push(struct stack *new, int num)
{
	if(new->top == MAX - 1)
	{
		printf("Stack is full.\n");
		return;
	}
	else
	{
		//new->top++;
		new->array[++new->top] = num; //new->array[new->top]
		return;
	}
}

int pop(struct stack *new)
{
	if(new->top == -1)
	{
		printf("Stack is empty.\n");
		return;
	}
    int value = array[new->top];
	//new->array[new->top] = 0;
	new->top--;
    return value;
}

void display(struct stack *new)
{
	for(int i = 0; i < (new->top + 1); i++)
	{
		printf("%d\t",new->array[i]);
	}
	printf("\n");
}

int main()
{
	struct stack new;
	initstack(&new);
	push(&new, 1);
	push(&new, 2);
	push(&new, 3);
	push(&new, 4);
	push(&new, 5);
	push(&new, 6);
	display(&new);
	int value = pop(&new);
	display(&new);
}


