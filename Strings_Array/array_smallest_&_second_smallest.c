#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void numbers(int *array, int length)
{
	int i;
	if(length < 2)
	{
		return;
	}
	int first = INT_MAX;
	int second = INT_MAX;
	for (i = 0; i < length; i++)
	{
		if(array[i] < first)
		{
			second = first;
			first = array[i];
		}
		else if (array[i] < second && array[i] != first)
		{
            second = array[i];
		}
	}
	printf("The smallest and second smallest number is %d and %d.\n", first, second);

}
int main()
{
	int array[] = {12, 13, 1, 10, 34, 2};
	int length = sizeof(array)/sizeof(int);
	numbers(array, length);
}