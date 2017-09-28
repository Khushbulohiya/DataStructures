/*
 * strings.c
 *
 *  Created on: Jul 12, 2017
 *      Author: khushbu
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search (char *s1, char *s2)
{
	 int j = 0, k;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	printf("length of string 1 is %d\n",len1);
	printf("length of string 2 is %d\n",len2);


	for(int i = 0;i <= len1 - len2; i++)
	{
		k = i;
		j = 0;
		while((s1[k] == s2[j]) && (j < len2))
		{
			printf("J's value is %d\n",j);
			k++;
			j++;
			printf("J's value is %d\n",j);

		}
		if(j == len2)
		{
			return i;
		}
	}
	return -1;
}

int isequals(char *s1, char *s2)
{
	if(strlen(s1) == strlen(s2))
	{
		while(*s1 || *s2 )
		{
			if(*s1 == *s2)
			{
				s1++;
				s2++;
			}
			else
			{
				return -1;
			}
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int issmaller(char *s1, char *s2)
{
	while(*s1 || *s2 )
	{
		if(*s1 < *s2)
		{
			s1++;
			s2++;
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return -1;
}

char *getstring(char *s1, int pos, int total)
{
	char *s = s1 + pos;
	int num = total + 1;
	char *t = (char*)malloc (sizeof(char) * num);
	int i = 0;
	while( i < num )
	{
		t[i] = *s;
		i++;
		s++;
	}
	t[i]= '\0';
	return t;
}

char *getleft(char *s1, int total)
{
	char *s = s1;
	int num = total + 1;
	char *t = (char*)malloc (sizeof(char) * num);
	//char *ans = t;
	int i = 0;
	while( i < num )
	{
		t[i] = *s; //*t = *s;
		i++;
		s++;
		//t++;
	}
	t[i]= '\0';
	return t; //return ans;
}

char *getright(char *s1, int total)
{
	int len = strlen(s1);
	char *s = s1 + (len - total);
	int num = total + 1;
	char *t = (char*)malloc (sizeof(char) * (num));
	//char *ans = t;
	int i = 0;
	while( i < num )
	{
		t[i]= *s; //*t = *s;
		i++;
		s++;
		//t++;
	}
	t[i]= '\0';
	return t; //return ans;
}

void reversestring(char *s1)
{
	char *start = s1; //IMP point to note
	int len = strlen(s1);
	char *t = (s1 + len - 1); //-1 because of "\0"
	char ch;
	int i = 0;
	while(i < (len/2))
	{
		ch = *s1;
		*s1 = *t;
		*t = ch;
		s1++;
		t--;
		i++;
	}
	printf("The reversed string is %s\n", start);
}

void reversestring_1(char *s1)
{
	char *new = s1;
	int len = strlen(s1);
	char ch;
	int start = 0, end = len - 1;
	while (start < (len/2))
	{
		ch = s1[start];
		s1[start] = s1[end];
		s1[end] = ch;
		start++;
		end--;
	}
	printf("The reversed string is %s\n", new);
}

int main()
{
	char string1[] = "abbbabcdxyz";
	char string2[] = "abc";
	//char string3[] = "Find hundred numbers";
	char string4[] = "find you will pain only go you recordings security the into if";
	int pos = search(string1, string2);
	printf("String matches at position %d\n",pos);
	int equal = isequals(string1, string2);
	if(equal == -1)
	{
		printf("String 1 and 2 are not equal.\n");
	}
	else
	{
		printf("String 1 and 2 are equal.\n");
	}
	int small = issmaller(string1, string2);
	if(small == -1)
	{
		printf("String1 is not smaller than strin2.\n");
	}
	else
	{
		printf("String1 is smaller than string2.\n");
	}
	char *new = getstring(string1, 6, 6);
	printf("The extracted string is %s\n",new);

	char *left = getleft(string1,5);
	printf("The extracted string is %s\n",left);

	char *right = getright(string1,6);
	printf("The extracted string from right is %s\n",right);

	reversestring(string4);
	reversestring_1(string2);
}

