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
int find_first_negative(T array[][SIZE], size_t size_i, size_t size_j){
	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			if (array[i][j] < 0){
				return (i* size_i) + j;
			}
		}
	}
	return -1;
}

template <typename T>
int find_last_negative(T array[][SIZE], size_t size_i, size_t size_j){
	int result = -1;
	for (int i = size_i -1 ; i >= 0; --i){
		for (int j = size_j - 1; j >= 0 ; --j){
			if (array[i][j] < 0){
				return (i* size_i) + j;
			}
		}
	}
	return -1;
}

template <typename T>
T calc_product(T array[][SIZE], size_t size_i, size_t size_j, int& pos_of_first_negative, int& pos_of_last_negative){
	T product = 1;
	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			if ( ((size_i * i) + j > pos_of_first_negative) &&
				 ((size_i * i) + j < pos_of_last_negative) ){
				product *= array[i][j];
			}
		}
	}
	return product;
}

int main() {
	int pos_of_first_negative = -1;
	int pos_of_last_negative = -1;

	const size_t size_i = 5;
	int array [size_i][SIZE] = {0}; /*5, 1, 1,
								1, 1, 2,
								-3, 2, 1,
								1, -4, 1,
								1, 0, 0};*/

	std::cout << "Enter integer array [" << size_i << "][" << SIZE << "]:" << std::endl;
	enter_array_cin(array, size_i, SIZE);

	pos_of_first_negative = find_first_negative(array, size_i, SIZE);
	if (pos_of_first_negative < 0) {
		std::cout << "There is no negative elements in the array.";
		exit(0);
	}

	pos_of_last_negative = find_last_negative(array, size_i, SIZE);
	if (pos_of_first_negative == pos_of_last_negative) {
		std::cout << "There is only one negative element in the array.";
		exit(0);
	}

	std::cout << "Product of elements between first negative and last negative is: "
			  << calc_product(array, size_i, SIZE, pos_of_first_negative, pos_of_last_negative) << std::endl;
	return 0;
}
