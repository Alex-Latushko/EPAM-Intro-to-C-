#include "array_func.h"

int main() {
	const int size = 6;
	int array[size] = {0};
	std::cout << "Enter " << size << " integer elements of array." << std::endl;
	enter_array(array, size, 0, size);
	std::cout << std::endl;
	std::cout << "Sum of the array with step 2 is: " << sum_array(array, size, 0, size, 2);

	return 0;
}
