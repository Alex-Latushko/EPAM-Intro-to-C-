#include "array_func.h"

int main() {
	const int size = 10;
	double array[size] = {0};

	std::cout << "Enter 10 real numbers" << std::endl;
	enter_array(array, size, 0, size);

	std::cout << std::endl;
	std::cout << "Reverse array is :" << std::endl;
	print_reverse_array(array, size, 0, size);
	return 0;
}
