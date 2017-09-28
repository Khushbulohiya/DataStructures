/*
 * queue_array.c
 *
 *  Created on: Jul 14, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void addqueue(int array[], int *front, int *rear, int num)
{
	if(*rear == MAX -1)
	{
		printf("Queue is full.\n");
		return;
	}
	else
	{
		(*rear)++; //array[++*rear] and not (*rear++)
		//OR array[++(*rear)] = num;
		array[*rear] = num;
		if(*front == -1)
		{
			*front = 0;
		}
	}
}

void delete(int array[], int *front, int *rear)
{
	if(*rear == -1 && *front == -1)
	{
		printf("Queue is empty.\n");
		return;
	}
	else
	{
		array[*front] = 0;
		if(*front == *rear)
		{
			*front = *rear = -1;
		}
		else
		{
			(*front)++;
		}
	}
}
void display(int array[])
{
	for(int i = 0; i < 5; i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}

int main()
{
	int array[MAX];
	int front = -1, rear = -1;
	addqueue(array, &front, &rear, 1);
	addqueue(array, &front, &rear, 2);
	addqueue(array, &front, &rear, 3);
	addqueue(array, &front, &rear, 4);
	addqueue(array, &front, &rear, 5);
	printf("Queue before deletion: \n");
	display(array);
	delete(array, &front, &rear);
	printf("Queue after deletion: \n");
	display(array);
}
