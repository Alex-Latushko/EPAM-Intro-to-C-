#include <iostream>

#define SIZE 3


template <typename T>
void safe_array_input(T array[][SIZE], int i, int j){
	std::cin >> array[i][j];
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "[" << i << "][ "<< j <<"] = ";
		std::cin >> array[i][j];
	}
	std::cin.ignore(100, '\n');
}

template <typename T>
void enter_array_cin(T array[][SIZE], size_t size_i, size_t size_j ){

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			std::cout << "[" << i << "]["<< j <<"] = ";
			safe_array_input(array, i, j);
		}
	}
}

template <typename T>
void print_array_cout(T array[][SIZE], size_t size_i, size_t size_j){
	std::cout << "\t";
	for (size_t j = 0; j < size_j; ++j){
		std::cout << j << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < size_i; ++i){
		std::cout << i;
		for (size_t j = 0; j < size_j; ++j){
			std::cout << "\t" << array[i][j];
		}
		std::cout << std::endl;
	}
}

template <typename T>
void swap_raw(T array[][SIZE], size_t size_j, int pos1, int pos2){
	T temp;
	for (int j = 0; j < size_j; ++j){
		temp = array[pos1][j];
		array[pos1][j] = array[pos2][j];
		array[pos2][j] = temp;
	}
}

template <typename T>
void sort_2D_array(T array[][SIZE], size_t size_i, size_t size_j){
	for (int i = 0; i < size_i; ++i){
		for (int ii = i + 1; ii < size_i; ++ii){
			if (array[i][0] < array[ii][0]){
				swap_raw(array, size_j, i, ii);
			}
		}
	}
}

int main() {
	const size_t size_i = 5;
	int array [size_i][SIZE] = {0}; /*, 1, 2,
								3, 4, 5,
								6, 7, 8,
								9, 10, 11,
								12, 13, 14};*/
	std::cout << "Enter integer array [" << size_i << "][" << SIZE << "]:" << std::endl;
	enter_array_cin(array, size_i, SIZE);
	sort_2D_array(array, size_i, SIZE);

	std::cout << "Sorted array (descending first elements in the raw):" << std::endl;
	print_array_cout(array, size_i, SIZE);

	return 0;
}
