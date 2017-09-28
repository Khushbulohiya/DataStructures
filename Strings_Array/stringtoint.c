
///ALSO KNOW AS ATOI

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int result = 0;
	char s[] = "1234";
	for(int index = 0; s[index] != '\0'; index++)
	//for (int index = 0; index != strlen(s); index++) //OR for (index = 0; s[index] != '\0'; i++)
	{
    	result = result * 10 + s[index] - '0';
	}
	printf("%d\n",result);
}




#To reverse a number
num = 1234
ans = 0
while num != 0:
data = num % 10
ans = ans * 10 + data
num = num / 10
print ans
