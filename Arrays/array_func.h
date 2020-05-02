#pragma once
#include <iostream>

template <typename T>
void swap_element_array(T array[], size_t size, int pos1, int pos2);

template <typename T>
int min_array(T array[], size_t size, int begin, int end);

template <typename T>
int max_array(T array[], size_t size, int begin, int end);

static bool is_in_range(size_t size, int x);

static void check_positions(size_t size, int begin, int end, const char* name);

template <typename T>
bool valid_input_cin(T& x);

template <typename T>
void safe_array_input_cin(T array[], int i);

template <typename T>
void enter_array_cin(T* array, size_t size, int begin, int end);

template <typename T>
void print_array_cout(T* array, size_t size, int begin, int end);

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



static bool is_in_range(size_t size, int x){
	return ( (x >= 0) &&
			 (x <= size) );
}

static void check_positions(size_t size, int begin, int end, const char* name){
	if ( !(is_in_range(size, begin) && is_in_range(size, end)) ){
		std::cout << "Index in \"" << name << "\" is out of range!" << std::endl;
		exit(0);
	}
}

template <typename T>
void print_array_cout(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "print_array_cout");
	for (size_t i = begin; i < end; ++i){
		std::cout << "[" << i << "] = " << array[i] << std::endl;
	}
}

template <typename T>
void print_reverse_array_cout(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "print_reverse_array_cout");
	for (int i = end - 1 ; i >= begin; --i){
		std::cout << "[" << i << "] = " << array[i] << std::endl;
	}
}

template <typename T>
bool valid_input_cin(T& x){
	bool valid_input = true;
	std::cin >> x;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		valid_input = false;
	}
	return valid_input;
}

template <typename T>
void enter_array_cin(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "enter_array_cin");
	for (size_t i = begin; i < end; ++i){
		do {
		std::cout << "[" << i << "] = ";
		} while ( !valid_input_cin(array[i]) );
	}
}

template <typename T>
T sum_array(T* array, size_t size, int begin, int end, int step){
	T sum;
	check_positions(size, begin, end, "sum_array");
		for (size_t i = begin; i < end; i += step){
			sum += array[i];
		}
	return sum;
}

template <typename T>
void swap_element_array(T array[], size_t size, int pos1, int pos2){
	check_positions(size - 1, pos1, pos2, "swap_element_array");
	T temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

template <typename T>
int min_array(T array[], size_t size, int begin, int end){
	int min = begin;
	check_positions(size, begin, end, "min_array");
	for (int i = begin; i <end; i++){
		if (array[min] > array[i]){
			min = i;
		}
	}
	return min;
}

template <typename T>
int max_array(T array[], size_t size, int begin, int end){
	int max = begin;
	check_positions(size, begin, end, "max_array");
	for (int i = begin; i < end; i++){
		if (array[max] < array[i]){
			max = i;
		}
	}
	return max;
}

template <typename T>
void right_shift_array(T* array, size_t size, int position){
	if (!is_in_range(size, position)){
		std::cout << "Index in \"right_shift_array\" is out of range!" << std::endl;
		exit(0);
	}
	for (size_t i = size - 1; i > position; --i){
		array[i] = array [i - 1];
		array[i - 1] = 0;
	}
}

template <typename T>
void shell_sort_descending(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "shell_sort_descending");
	int amount_of_swap = 0;
	int i = 0;
	int j = 0;
	for (int step = size / 2; step > 0; step /= 2){
		do {
			 amount_of_swap = 0;
			 for (i = 0, j = step; j < size; ++i, ++j){
				 if (array[i] < array[j]){
					 swap_element_array(array, size, i, j);
					 amount_of_swap++;
				 }
			 }
		} while (amount_of_swap);
	}
}

template <typename T>
void simpe_choise_sort_ascending(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "simple_choise_sort_ascending");
	for (int i = begin; i < end; ++i){
		for (int j = i; j < end; ++j){
			if (array[i] > array[j]) {
				swap_element_array(array, size, i, j);
			}
		}
	}
}

template <typename T>
void insertion_sort_ascending(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "insertion_sort_ascending");
	for (int i = begin + 1; i < end; ++i){
		T key = array[i];
		for (int j = i - 1; (key < array[j]) && (j >= begin); --j){
			swap_element_array(array, size, j, j+1);
		}
	}
}

template <typename T>
void bubble_sort_descending(T* array, size_t size, int begin, int end){
	check_positions(size, begin, end, "buuble_sort_descending");
	int k = 0;
	for (int i = begin; i < end; ++i){
		for (int j = begin; j < end - k; ++j){
			if (array[j] < array[j+1]) {
				swap_element_array(array, size, j, j + 1);
			}
		}
		++k;
	}
}
