/*
 * balanced_paranthesis.c
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

int isbalanced(char exp[])
{
	struct node *stack = NULL;
	int i = 0;
	while(exp[i] != '\0')
	{
		char ch = exp[i];
		if(ch == '{' || ch == '[' || ch == '(')
		{
			push(&stack, ch);
			i++;
		}
		else if(ch == '}' || ch == ']' || ch == ')')
		{
			if(stack == NULL)
			{
				return 0;
			}
			else
			{
				char data = pop(&stack);
				if((data == '(' && ch == ')')
						|| (data == '{' && ch == '}')
						|| (data == '[' && ch == ']'))
				{
					i++;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}
	if(stack == 0)
	{
		return 1; // Balanced
	}
	else
	{
		return 0; // Not Balanced
	}
}


int main()
{
	char exp[100] = "{[()]}";
	if(isbalanced(exp) == 1)
	{
		printf("The given expression is balanced.\n");
	}
	else
	{
		printf("The given expression is not balanced.\n");
	}
	return 0;
}
