#include<stdio.h>

void strcat(char t[], char s[]){
	int i=0, j=0;
	while (t[i] != '\0')
	{
		i++;
	}
	
	for(j=0; s[j] != '\0'; j++){
		t[i++] = s[j];
	}
	t[i] = '\0';
}

int main()
{
	char t[1000] = "1234560";
	char s[] = "abcdefg";
	printf("Cat %s to %s , ", s, t);
	strcat(t, s);
	printf("result is %s .\n", t);
	return 0;
}