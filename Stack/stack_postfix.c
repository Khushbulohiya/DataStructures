/*
 * stack_postfix.c
 *
 *  Created on: Aug 1, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
		printf("pushing 1st data %d.\n",temp->data);
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = *top;
		*top = temp;
		printf("pushing rest data %d.\n",(*top)->data);
	}
}

int pop(struct node **top)
{
	struct node *temp =  *top;
	if(*top == NULL)
	{
		printf("Stack is empty.\n");
		return -1;
	}
	int data = (*top)->data;
	*top = (*top)->link;
	free(temp);
	printf("popping %d.\n",data);
	return data;
}

int evaluatePostfix(char exp[])
{
	struct node *stack = NULL;
	int i = 0;
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
		{
			//// push(&stack, ('2' - '0' = 2) because exp[i] is some ascII value and to convert it to int(number 2) substract it from '0'
			push(&stack, exp[i] - '0');
			//i++;
		}
		else
		{
			int value1 = pop(&stack);
			int value2 = pop(&stack);
			printf("Expression is %c\n", exp[i]);
			switch(exp[i])
			{
			case '+': push(&stack, (value2 + value1));
					break;
			case '-': push(&stack, (value2 - value1));
					break;
			case '*': push(&stack, (value2 * value1));
					break;
			case '/': push(&stack, (value2 / value1));
					break;
			}
			//i++;
		}
		i++;
	}
	return(pop(&stack));
}
int main()
{
	char exp[] = "231*+9-";
    printf ("Value of %s is %d\n", exp, evaluatePostfix(exp));
    return 0;
}
