/*
 * bounded_queue.c
 *
 *  Created on: Aug 1, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>

#define MAX 4


void push(int array[], int *front, int *rear, int num)
{
	if(*front == -1)
	{
		array[++(*rear)] = num;
		(*front)++;
	}
	else
	{
		*rear = (*rear + 1) % MAX;
		array[*rear] = num;
		if(*rear == *front) // Queue is full
		{
			*front = (*front + 1) % MAX;
		}
	}
}

void display(int array[])
{
	for(int i = 0; i < MAX; i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}

int pop(int array[],int *front, int *rear )
{
	int data;
	if(*rear == -1 && *front == -1)
	{
		printf("Queue is empty.\n");
		return -1;
	}
	else
	{
		data = array[*front];
		array[*front] = 0;
		if(*front == *rear)
		{
			*front = *rear = -1;
		}
		else
		{
			*front = (*front + 1) % MAX;
		}
	}
	return data;
}
int main()
{
	int array[MAX];
	int front = -1, rear = -1;
	push(array, &front, &rear, 1);
	push(array, &front, &rear, 2);
	push(array, &front, &rear, 3);
	push(array, &front, &rear, 4);
	display(array);
	push(array, &front, &rear, 5);
	display(array);
	int data = pop(array, &front, &rear);
	printf("Data popped is %d.\n", data);
	display(array);
	data = pop(array, &front, &rear);
	printf("Data popped is %d.\n", data);
	data = pop(array, &front, &rear);
	printf("Data popped is %d.\n", data);
	display(array);
	push(array, &front, &rear, 6);
	display(array);
	push(array, &front, &rear, 7);
	push(array, &front, &rear, 8);
	display(array);
	data = pop(array, &front, &rear);
	printf("Data popped is %d.\n", data);
	display(array);
}
