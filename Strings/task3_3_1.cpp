#include <stdio.h>

#define SIZE 100

int main() {
	char str[SIZE] = {0};

	puts("Enter string:");
	fgets(str, SIZE - 2, stdin);

	for (int i = 0; (str[i] != '\0'); i++){
		printf("%c\n", str[i]);
	}

	return 0;
}
