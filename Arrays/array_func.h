#pragma once
#include <iostream>

template <typename T>
void my_swap_array(T array[], size_t size, int pos1, int pos2);

template <typename T>
int min_array(T array[], size_t size, int begin, int end);

template <typename T>
int max_array(T array[], size_t size, int begin, int end);

bool is_in_range(size_t size, int x);

template <typename T>
void safe_array_input(T array[], int i);

template <typename T>
void enter_array(T* array, size_t size, int begin, int end);

template <typename T>
void print_array(T* array, size_t size, int begin, int end);

template <typename T>
T sum_array(T* array, size_t size, int begin, int end, int step = 1);

template <typename T>
void right_shift_array(T* array, size_t size, int position);

template <typename T>
void shell_sort_descending(T* array, size_t size, int begin, int end);

template <typename T>
void simpe_choise_sort_ascending(T* array, size_t size, int begin, int end);

template <typename T>
void insertion_sort_ascending(T* array, size_t size, int begin, int end);

template <typename T>
void bubble_sort_descending(T* array, size_t size, int begin, int end);



bool is_in_range(size_t size, int x){
	return ( (x >= 0) &&
			 (x <= size) );
}

template <typename T>
void print_array(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (size_t i = begin; i < end; ++i){
			std::cout << "[" << i << "] = " << array[i] << std::endl;
		}
	} else {
		std::cout << "Index in \"print_array\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void print_reverse_array(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (int i = end - 1 ; i >= begin; --i){
			std::cout << "[" << i << "] = " << array[i] << std::endl;
		}
	} else {
		std::cout << "Index in \"print_reverse_array\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void safe_array_input(T array[], int i){
	std::cin >> array[i];
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "[" << i << "] = ";
		std::cin >> array[i];
	}
	std::cin.ignore(100, '\n');
}

template <typename T>
void enter_array(T* array, size_t size, int begin, int end){

	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (size_t i = begin; i < end; ++i){
			std::cout << "[" << i << "] = ";
			safe_array_input(array, i);
			//printf("[%d] = ", i);
			//scanf("%d", &array[i]);
		}
	} else {
		std::cout << "Index in \"enter_array\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
T sum_array(T* array, size_t size, int begin, int end, int step){
	T sum;
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (size_t i = begin; i < end; i += step){
			sum += array[i];
		}
	} else {
		std::cout << "Index in \"sum_array\" is out of range!" << std::endl;
		exit(0);
	}
	return sum;
}

template <typename T>
void my_swap_array(T array[], size_t size, int pos1, int pos2){
	if ( is_in_range(size - 1, pos1) && is_in_range(size - 1, pos2) ){
		T temp = array[pos1];
		array[pos1] = array[pos2];
		array[pos2] = temp;
	} else {
		std::cout << "Index in \"my_swap_array\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
int min_array(T array[], size_t size, int begin, int end){
	int min = begin;
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (int i = begin; i <= end; i++){
			if (array[min] > array[i]){
				min = i;
			}
		}
	} else {
		std::cout << "Index in \"min_array\" is out of range!" << std::endl;
		exit(0);
	}
	return min;
}

template <typename T>
int max_array(T array[], size_t size, int begin, int end){
	int max = begin;
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (int i = begin; i <= end; i++){
			if (array[max] < array[i]){
				max = i;
			}
		}
	} else {
		std::cout << "Index in \"max_array\" is out of range!" << std::endl;
		exit(0);
	}
	return max;
}

template <typename T>
void right_shift_array(T* array, size_t size, int position){
	if (is_in_range(size, position)){
		for (size_t i = size - 1; i > position; --i){
			array[i] = array [i - 1];
			array[i - 1] = 0;
		}
	} else {
		std::cout << "Index in \"right_shift_array\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void shell_sort_descending(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		int amount_of_swap = 0;
		int i = 0;
		int j = 0;
		for (int step = size / 2; step > 0; step /= 2){
			do {
				 amount_of_swap = 0;
				 for (i = 0, j = step; j < size; ++i, ++j){
					 if (array[i] < array[j]){
						 my_swap_array(array, size, i, j);
						 amount_of_swap++;
					 }
				 }
			} while (amount_of_swap);
		}

	} else {
		std::cout << "Index in \"shell_sort_descending\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void simpe_choise_sort_ascending(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (int i = begin; i < end; ++i){
			for (int j = i; j < end; ++j){
				if (array[i] > array[j]) {
					my_swap_array(array, size, i, j);
				}
			}
		}
	} else {
		std::cout << "Index in \"simpe_choise_sort_ascending\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void insertion_sort_ascending(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		for (int i = begin + 1; i < end; ++i){
			T key = array[i];
			for (int j = i - 1; (key < array[j]) && (j >= begin); --j){
				my_swap_array(array, size, j, j+1);
			}
		}
	} else {
		std::cout << "Index in \"insertion_sort_ascending\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void bubble_sort_descending(T* array, size_t size, int begin, int end){
	if ( is_in_range(size, begin) && is_in_range(size, end) ){
		int k = 0;
		for (int i = begin; i < end; ++i){
			for (int j = begin; j < end - k; ++j){
				if (array[j] < array[j+1]) {
					my_swap_array(array, size, j, j + 1);
				}
			}
			++k;
		}
	} else {
		std::cout << "Index in \"bubble_sort_descending\" is out of range!" << std::endl;
		exit(0);
	}
}
