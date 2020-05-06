#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

static bool is_in_range(size_t size, int x){
	return ( (x >= 0) &&
			 (x <= size) );
}

void delete_char_in_str(char* str, int position){
	if (!is_in_range(strlen(str), position)){
		printf("Index in \"delete_char_in_str\" is out of range!\n");
		exit(0);
	}

	size_t i = 0;
	for (i = position; i < strlen(str) - 1; ++i){
		str[i] = str [i + 1];
	}
	str[i] = '\0';
}

int main() {
	char str[SIZE] = {0};

	puts("Enter string:");
	scanf("%s", str);

	if (strlen(str) > 10){
		delete_char_in_str(str, strlen(str) - 1);
		delete_char_in_str(str, strlen(str) - 1);
	} else if (strlen(str) < 10) {
		delete_char_in_str(str, 0);
		delete_char_in_str(str, 0);
	} else {
		delete_char_in_str(str, 5);
	}

	printf("New string: %s", str);

	return 0;
}
