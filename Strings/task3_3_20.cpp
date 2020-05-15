#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 10
#define AMOUNT_OF_STRINGS 3

template <typename T>
void print_array_cout(T array[][SIZE], size_t size_i, size_t size_j){
	printf("\t");
	for (size_t j = 0; j < size_j; ++j){
		printf("%d\t", j);
	}
	printf("\n\n");
	for (size_t i = 0; i < size_i; ++i){
		printf("%d", i);
		for (size_t j = 0; j < size_j; ++j){
			printf("\t%d", array[i][j]);
		}
		printf("\n");
	}
}

void str_to_number(char str[], long long& number, char split){
	int i = 0;
	for (i = 0; str[i] != split && str[i] != '\0'; ++i ){
		if ( (str[i] >= '0') && (str[i] <= '9') ){
			number *= 10;
			number += str[i] - '0';
		}
	}
}

void number_to_int_array(long long number,int int_array[][SIZE], size_t i, size_t size_j){
	if ( (number / pow(10, SIZE)) > 1){
		puts("Number is too big!");
		exit(1);
	}
	for (size_t j = size_j - 1; number > 0; --j){
		int_array[i][j] = number % 10;
		number /= 10;
	}
}

int main() {
	char str_array[AMOUNT_OF_STRINGS][SIZE] = {0};
	int int_array[AMOUNT_OF_STRINGS][SIZE] = {0};

	long long number = 0;

	for (size_t i = 0; i < AMOUNT_OF_STRINGS; ++i){
		printf("Enter string ¹%d: ", i);
		scanf("%s", str_array[i]);
		str_to_number(str_array[i], number, '\0');
		number_to_int_array(number, int_array, i, SIZE);
		number = 0;
	}
	printf("\n");
	print_array_cout(int_array, AMOUNT_OF_STRINGS, SIZE);

	return 0;
}
