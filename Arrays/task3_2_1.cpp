#include "array_func.h"

int main() {

	const int size = 7;
	double array[size] = {0};

	std::cout << "Enter real array [" << size << "]:" << std::endl;
	enter_array_cin(array, size, 0, size);

	std::cout << std::endl;
	std::cout << "Sum of the array is: " << sum_array(array, size, 0, size);
	return 0;
}
