
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *s)
{
	char *t = s;
	int i = 0;
	int j = 0;
	while(i < strlen(s)){
		while(s[j] != ' ' && s[j] != '\0'){
			j++;
		}
		int next = j;
		j--;
		while(i < j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
		while(s[next] == ' '){
			next++;
		}
		i = next;
		j = next;
}
printf("%s\n",s);
printf("%s\n",t);
}


int main()
{
	char word[] = "Khushbu Lohiya";
	reverse(word);
}
