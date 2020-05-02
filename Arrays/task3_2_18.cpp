#include <iostream>

#define SIZE 3

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
void enter_array_cin(T array[][SIZE], size_t size_i, size_t size_j ){

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			do {
			std::cout << "[" << i << "]["<< j <<"] = ";
			} while ( !valid_input_cin(array[i][j]) );
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
bool is_saddle(T array[][SIZE], size_t size_i, size_t size_j, int pos_i,int pos_j){
	for (size_t i = 0; i < size_i; ++i){
		if (array[pos_i][pos_j] < array[i][pos_j]){
			return false;
		}
	}
	for (size_t j = 0; j < size_j; ++j){
		if (array[pos_i][pos_j] > array[pos_i][j]){
			return false;
		}
	}
	return true;
}

template <typename T>
void print_saddle_points(T array[][SIZE], size_t size_i, size_t size_j){
	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			if (is_saddle(array, size_i, size_j, i, j)){
				std::cout << "[" << i << "][" << j << "]" << std::endl;
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

	std::cout << "Saddle points are: " << std::endl;
	print_saddle_points(array, size_i, SIZE);

	return 0;
}
