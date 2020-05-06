#include <stdio.h>

#define SIZE 100

char* add_str(char* str1, const char* str2){
	size_t length = 0;
	for (length = 0; str1[length] != '\n'; ++length){
	}

	size_t i = 0;
	for (i = 0; str2[i] != '\n'; ++i){
		str1[length + i] = str2[i];
	}
	str1[length + i] = '\0';

	return str1;
}

int main() {
	char str1[SIZE] = {0};
	char str2[SIZE] = {0};
	char* result = 0;

	puts("Enter first string:");
	fgets(str1, SIZE - 2, stdin);
	puts("Enter second string:");
	fgets(str2, SIZE - 2, stdin);

	result = add_str(str1, str2);

	printf("Result: %s", str1);
	return 0;
}
