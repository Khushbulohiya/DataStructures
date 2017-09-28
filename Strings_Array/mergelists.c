/*
 * mergesort.c
 *
 *  Created on: Jul 12, 2017
 *      Author: khushbu
 */
#include<stdio.h>
#include<stdlib.h>

void merge_lists(int *a1, int *a2, int len1, int len2)
{
	int i = 0, j = 0, k = 0;
	int *array;
	int length = len1 + len2;
	array = (int *) malloc(sizeof(int) * length);
	while(i < len1 && j < len2)
	{
		if(a1[i] > a2[j])
		{
			array[k] = a2[j];
			k++;
			j++;
		}
		else
		{
			array[k] = a1[i];
			k++;
			i++;
		}
	}
	while(i < len1)
	{
		array[k] = a1[i];
		k++;
		i++;
	}
	while(j < len2)
	{
		array[k] = a2[j];
		k++;
		j++;
	}
	for(k = 0; k < length; k++)
	{
		printf("%d\t", array[k]);
	}
	printf("\n");
}

int main()
{
	int my_list[] = { 3, 4, 6, 10, 11, 15 };
	int alices_list[] = { 1, 5, 8, 12, 14, 19 };

	//To find length/size of
	int len1 = (sizeof(my_list)/sizeof(int));
	int len2 = (sizeof(alices_list)/sizeof(int));
	printf("Length: %d, %d\n", len1, len2);

	merge_lists(my_list, alices_list, len1, len2);

}

