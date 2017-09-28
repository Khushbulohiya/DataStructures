/*
 * queue_linked.c
 *
 *  Created on: Aug 8, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void insert(int array[], int *front, int*rear, int num)
{
	if(*rear == MAX - 1)
	{
		return;
	}
	array[++(*rear)] = num;
	if(*front == -1)
	{
		(*front)++;
	}
}

int delete(int array[], int *front, int*rear)
{
	if(*rear == -1 && *front == -1)
	{
		return -1;
	}
	int data = array[*front];
	if(*front == *rear)
	{
		*front = *rear = -1;
	}
	else
	{
		(*front)++;
	}
	return data;
}

void display(int array[], int front, int rear)
{
	for(int i = front; i < MAX; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}
int main()
{
	int array[MAX];
	int front = -1;
	int rear = -1;
	insert(array,&front, &rear, 2);
	insert(array,&front, &rear, 4);
	insert(array,&front, &rear, 6);
	insert(array,&front, &rear, 8);
	insert(array,&front, &rear, 10);
	display(array, front, rear);
	int data = delete(array,&front, &rear);
	printf("%d\n", data);
	display(array, front, rear);
}


