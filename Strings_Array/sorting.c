/*
 * array.c
 *
 *  Created on: Jul 13, 2017
 *      Author: khushbu
 */

void selection_sort(int array[], int num)
{
	int j, temp;
	for(int i = 0; i < num; i++)
	{
		for(j = i + 1; j < num; j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void insertion_sort(int array[], int num)
{
	int i, j, k;
	for(i = 1; i < num; i++)
	{
		k = array[i];
		j = i-1;
		while(j >= 0 && array[j] > k)
		{
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = k;
	}
}

void bubble_sort(int *array, int num)
{
	int temp;
	int k = num;
	for(int i = 0; i < num; i++, k--)
	{
		for(int j = 0; j < k - 1 ; j++)
		{
			if(array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void bubble_sort_aniket(int *array, int num)
{
	int temp;
	int k = num;
	while(k > 0)
	{
		for(int j = 0; j < k -1; j++) //IMP  j = k -1 instead of j = k
		{
			if(array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		k--;
	}
}

void printarray(int array[], int num)
{
	int i;
	for (i=0; i < num; i++)
	printf("%d ", array[i]);
	printf("\n");
}

#include<stdio.h>
int main()
{
	int array[] = {5, 6, 1, 2, 4};
	int num = 5;
	selection_sort(array,num);
	printf("Array using Selection sort.\n");
	printarray(array, num);
	insertion_sort(array,num);
	printf("Array using Insertion sort.\n");
	printarray(array, num);
	bubble_sort(array,num);
	printf("Array using Bubble sort.\n");
	printarray(array, num);
	bubble_sort_aniket(array,num);
	printf("Array using Bubble sort.\n");
	printarray(array, num);
}
