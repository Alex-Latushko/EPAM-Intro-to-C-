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
void enter_array(T array[][SIZE], size_t size_i, size_t size_j ){

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			std::cout << "[" << i << "]["<< j <<"] = ";
			safe_array_input(array, i, j);
			//printf("[%d] = ", i);
			//scanf("%d", &array[i]);
		}
	}
}

template <typename T>
void print_array(T array[][SIZE], size_t size_i, size_t size_j){
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

/*	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; j < size_j; ++j){
			std::cout << "[" << i << "]["<< j <<"] = " << array[i][j] << std::endl;
		}
	}*/
}

template <typename T>
T sum_diagonal_array(T array[][SIZE], size_t size_i, size_t size_j){
	T sum;
	int i = 0;
	for (int j = 0; (i < size_j) && (j < size_j); ++i, ++j){
		sum += array[i][j];
	}
	return sum;
}
template <typename T>
int max_element_above_diagonal(T array[][SIZE], size_t size_i, size_t size_j){
	int max_i = 0;
	int max_j = 1;

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = i + 1; j < size_j; ++j){
			if (array[max_i][max_j] < array[i][j]){
				max_i = i;
				max_j = j;
			}
		}
	}

	return ( (max_i * size_i) + max_j);
}

template <typename T>
int min_element_below_diagonal(T array[][SIZE], size_t size_i, size_t size_j){
	int min_i = 1;
	int min_j = 0;

	for (size_t i = 0; i < size_i; ++i){
		for (size_t j = 0; (j < i) && (j < size_j) ; ++j){
			if (array[min_i][min_j] > array[i][j]){
				min_i = i;
				min_j = j;
			}
		}
	}

	return ( (min_i * size_i) + min_j);
}

int main() {
	const size_t size_i = 5;
	int array [size_i][SIZE] = {0};/*, 1, 2,
								3, 4, 5,
								6, 7, 8,
								9, 10, 11,
								12, 13, 14};*/

	std::cout << "Enter integer array [" << size_i << "][" << SIZE << "]:" << std::endl;
	enter_array(array, size_i, SIZE);
	std::cout << "Sum of diagonal elements is: " << sum_diagonal_array(array, size_i, SIZE) << std::endl;
	std::cout << "Position of the max element above the diagonal: [" << max_element_above_diagonal(array, size_i, SIZE) / size_i << "]["
																	 << max_element_above_diagonal(array, size_i, SIZE) % size_i << "]" << std::endl;

	std::cout << "Position of the min element below the diagonal: [" << min_element_below_diagonal(array, size_i, SIZE) / size_i << "]["
																	 << min_element_below_diagonal(array, size_i, SIZE) % size_i << "]" << std::endl;
	std::cout << std::endl;
	print_array(array, size_i, SIZE);
	return 0;
}
