#include "array_func.h"

template <typename T>
T sum_positive_elements_array(T* array, size_t size, int step = 1){
	T sum;
	for (size_t i = 0; i < size; i += step){
		if (array[i] > 0){
			sum += array[i];
		}
	}
	return sum;
}

template <typename T>
int amount_negative_elements_array(T* array, size_t size, int step = 1){
	int amount = 0 ;
	for (size_t i = 0; i < size; i += step){
		if (array[i] < 0){
			++amount;
		}
	}
	return amount;
}

template <typename T>
T product_odd_elements_array(T* array, size_t size){
	T product = array[1];
	for (size_t i = 3; i < size; i += 2){
			product *= array[i];
	}
	return product;
}

int main() {
	const int size = 5;
	double array [size] = {0};

	std::cout << "Enter " << size << " real elements of array." << std::endl;
	enter_array(array, size, 0, size);

	std::cout << "Amount of negative elements in the array is: " << amount_negative_elements_array(array, size);
	std::cout << std::endl;

	std::cout << "Sum of positive elements in the array is: " << sum_positive_elements_array(array, size);
	std::cout << std::endl;

	std::cout << "Product of elements with odd position in the array: "
			  << ( ( (sizeof(array)/sizeof(double) ) > 1 ) ? product_odd_elements_array(array, size) : 0);
	std::cout << std::endl;
	return 0;
}
