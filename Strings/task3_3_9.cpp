#include <stdio.h>

#define SIZE 100

int str_length(const char* str){
	int length = 0;
	for (length = 0; (str[length] != '\n') && (str[length] != '\0'); ++length){
	}
	return length;
}

int str_comp(const char* str1, const char* str2){
	int length1 = str_length(str1);
	int length2 = str_length(str2);

	int min_length = length1;
	if (length2 < min_length){
		min_length = length2;
	}

	for (int i = 0; i < min_length; ++i){
		if (str1[i] != str2[i]){
			if (str1[i] > str2[i]){
				return 1;
			} else {
				return -1;
			}
		}
	}
	if (length1 == length2){
		return 0;
	}

	return (length1 < length2) ? -1 : 1;
}

int main() {
	char str1[SIZE] = {0};
	char str2[SIZE] = {0};

	puts("Enter first string:");
	fgets(str1, SIZE - 2, stdin);
	puts("Enter second string:");
	fgets(str2, SIZE - 2, stdin);

	printf("Result: %d", str_comp(str1, str2));
	return 0;
}
