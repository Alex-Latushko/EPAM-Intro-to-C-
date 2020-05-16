#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 5

template <typename T>
void check_ptr(T* ptr, int line){
	if ( ptr == NULL){
		printf("NULL pointer in line %d!\n", line);
		exit(1);
	}
}

template <typename T>
void check_ptr_ptr(T** array, size_t size, int line){
	check_ptr(array, line);
	for (size_t i = 0; i < size; ++i){
		check_ptr( *(array + i), line );
	}
}

template <typename T>
void free_ptr(T* ptr){
	free(ptr);
	ptr = NULL;
}

template <typename T>
void free_ptr_ptr(T** array, size_t size){
	for (size_t i = 0; i < size; ++i){
		free_ptr( *(array + i) );
	}
	free_ptr(array);
}

template <typename T>
bool is_less(T x, T y){
	return (x < y);
}

template <typename T>
void print_array_cout(T** array, size_t size_i, size_t size_j){
	check_ptr_ptr(array, size_i, __LINE__);
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
	check_ptr_ptr(array, size_i, __LINE__);
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
	check_ptr_ptr(array, size_i, __LINE__);
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
	double** array = (double**) calloc(SIZE, sizeof(double*));
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

	free_ptr_ptr(array, SIZE);
	return 0;
}
