#include <stdio.h>
#include <string.h>

#define SIZE 20
int main() {
	char str[SIZE] = {0};
	bool is_first_digit = true;

	puts("Enter number:");
	scanf("%s", str);

	for (size_t i = 0; i < strlen(str); i = i + 1){
		if (is_first_digit){
			printf("%c", str[0]);
			is_first_digit = false;
			continue;
		}
		printf("  %c", str[i]);
	}

	return 0;
}
