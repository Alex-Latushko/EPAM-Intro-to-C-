#include <stdio.h>
#include <string.h>

#define SIZE 20
int main() {
	char str[SIZE] = {0};
	int product = 0;
	bool is_first_digit = true;

	puts("Enter string:");
	scanf("%s", str);

	for (size_t i = 0; i < strlen(str); i = i + 1){
		if ( (str[i] >= '0') && (str[i] <= '9') ){
			if (is_first_digit){
				product = 1;
				is_first_digit = false;
			}
			product *= (str[i] - '0');
		}
	}

	printf("Product of digits: %d", product);

	return 0;
}
