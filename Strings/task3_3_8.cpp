#include <stdio.h>

#define SIZE 100

int str_length(const char* str){
	int length = 0;
	for (length = 0; (str[length] != '\n') && (str[length] != '\0') ; ++length){
	}
	return length;
}

int main() {
	char str[SIZE] = {0};

	puts("Enter string:");
	fgets(str, SIZE - 2, stdin);

	printf("Length of string is: %d", str_length(str));
	return 0;
}
