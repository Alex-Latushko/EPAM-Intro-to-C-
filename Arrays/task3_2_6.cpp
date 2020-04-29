#include "array_func.h"

int main() {
	const size_t size = 10;
	int array[size] = {0}; //, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Enter " << size << " elements of array." << std::endl;
	enter_array(array, size, 0, size);

	int position = 0;
	int new_value = 0;

	do {
	std::cout << "Enter position of the element (integer from 0 to " << size - 1 << "): ";
	std::cin >> position;
	} while ((position < 0) || (position+1 > size));

	std::cout << "Enter new value for position ¹" << position << ": ";
	std::cin >> new_value;

	right_shift_array(array, size, position);
	array[position] = new_value;
	print_array(array, size, 0, size);

	return 0;
}
