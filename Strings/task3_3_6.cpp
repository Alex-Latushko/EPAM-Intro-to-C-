#include <stdio.h>

#define SIZE 100

char* prisv_str(char* str1, const char* str2){
	size_t i = 0;
	for (i = 0; (str2[i] != '\n') && (str2[i] != '\0'); ++i){
		str1[i] = str2[i];
	}

	str1[i] = '\0';

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

	result = prisv_str(str1, str2);

	printf("Result: %s", result);
	return 0;
}
