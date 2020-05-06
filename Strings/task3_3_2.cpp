#include <stdio.h>

#define SIZE 100

int main() {
	char str[SIZE] = {0};
	char rev_str[SIZE] = {0};

	puts("Enter string:");
	fgets(str, SIZE - 2, stdin);

	size_t length = 0;
	for (length = 0; (str[length] != '\0'); ++length){
	}

	for (size_t i = 0; i < length ; ++i){
		rev_str[i] = str[length - 1 - i];
	}
	rev_str[length] = '\0';

	printf("%s", rev_str);
	return 0;
}
