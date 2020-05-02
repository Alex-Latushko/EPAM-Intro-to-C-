#include <iostream>

#define SIZE 5
#define SIZE_2 2

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
void enter_array_SIZE_2_cin(T array[][SIZE_2], size_t size_i, size_t size_j ){

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			do {
			std::cout << "[" << i << "]["<< j <<"] = ";
			} while ( !valid_input_cin(array[i][j]) );
		}
	}
}

template <typename T>
void print_result_array_cout(T array[][SIZE_2], size_t size_i, size_t size_j){
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

int main() {
	const size_t size_i = 3;

	int array_A [size_i][SIZE] = {0};/*1, 1, 1, 1, 1,
			 	 	 	 	 	  2, 2, 2, 2, 2,
								  3, 3, 3, 3, 3};*/

	int array_B[SIZE][SIZE_2] = {0};/*1, 2,
								 1, 2,
								 1, 2,
								 1, 2,
								 1, 2};*/

	int result [size_i][SIZE_2] = {0};

	std::cout << "Enter integer array_A [" << size_i << "][" << SIZE << "]:" << std::endl;
	enter_array_cin(array_A, size_i, SIZE);

	std::cout << "Enter integer array_B [" << SIZE << "][" << SIZE_2 << "]:" << std::endl;
	enter_array_SIZE_2_cin(array_B, SIZE, SIZE_2);

	for(int i = 0; i < size_i; ++i){
		for(int j = 0; j < SIZE_2; ++j){
			for(int k = 0; k < SIZE; ++k){
				result[i][j] += array_A[i][k] * array_B[k][j];
			}
		}
	}

	print_result_array_cout(result, size_i, SIZE_2);

	return 0;
}
