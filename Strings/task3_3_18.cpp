#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 20

int main() {
	char str_number[SIZE] = {0};
	char* digit = NULL;
	int sum = 0;

	printf("Enter number\n");
	scanf("%s", str_number);


	for (digit = str_number; *digit != '\0'; ++digit){
		if ( (*digit >= '0') && (*digit <= '9') ){
			sum += (*digit - '0');
		}
	}

	printf("Sum of digits of the entered number: %d\n", sum);
	return 0;
}
