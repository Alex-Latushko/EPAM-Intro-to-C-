#include <stdio.h>


#define SIZE 100

int main() {
	char str[SIZE] = {0};
	char temp = 0;
	int amount_a = 0;

	puts("Enter string:");
	fgets(str, SIZE - 2, stdin);

	size_t length = 0;
	for (length = 0; str[length] != '\0'; ++length){
		if (str[length] == 'a'){
			++amount_a;
		}
	}

	if (length > 0){
		temp = str[0];
		str[0] = str[length - 1];
		str[length - 1] = temp;
	}

	printf("Amount of 'a' is: %d\n", amount_a);
	printf("New string: %s", str);
	return 0;
}
