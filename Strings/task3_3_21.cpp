#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 5

template <typename T>
bool is_less(T x, T y){
	return (x < y);
}

template <typename T>
void print_array_cout(T** array, size_t size_i, size_t size_j){
	printf("\t");
	for (size_t j = 0; j < size_j; ++j){
		printf("%d\t", j);
	}
	printf("\n\n");
	for (size_t i = 0; i < size_i; ++i){
		printf("%d", i);
		for (size_t j = 0; j < size_j; ++j){
			printf("\t%.2f", *(*(array+i)+j));
		}
		printf("\n");
	}
}

template <typename T>
T calc_sum_array(T** array, size_t size_i, size_t size_j, bool func(T x, T y)){
	T sum = 0;
	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			if (func(j, i)){
				sum += *(*(array+i)+j);
			}
		}
	}
	return sum;
}

template <typename T>
T calc_prod_array(T** array, size_t size_i, size_t size_j, bool func(T x, T y)){
	T prod = 1;
	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			if (func(j, i)){
				prod *= *(*(array+i)+j);
			}
		}
	}
	return prod;
}

int main() {
	double** array =(double**) calloc(SIZE, sizeof(double*));
	for (size_t i = 0; i < SIZE; ++i){
		*(array+i) = (double*) calloc(SIZE, sizeof(double));
	}

	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j){
			*(*(array+i)+j) = 2;
		}
	}

	print_array_cout(array, SIZE, SIZE);
	printf("Sum of the elements bellow diagonal of the array: %.2f\n", calc_sum_array(array, SIZE, SIZE, is_less));
	printf("Product of the elements bellow diagonal of the array: %.2f\n", calc_prod_array(array, SIZE, SIZE, is_less));
	return 0;
}
