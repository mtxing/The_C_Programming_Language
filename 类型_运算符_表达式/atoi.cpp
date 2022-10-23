#include<stdio.h>

int aoit(char x[]){
	int i=0, n=0;
	for(; x[i]!= '\0'; i++){
		n = n * 10 + x[i] - '0';
	}
	return n;
}

int main()
{
	char s[] = "1234560";
	printf("%s convert to int is %d !", s, aoit(s));
	return 0;
}