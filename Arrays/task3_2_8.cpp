#include "array_func.h"

int main() {
	const size_t size = 10;
	int array [size] = {0}; //, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Enter integer array [" << size << "]:" << std::endl;
	enter_array(array, size, 0, size);

	int pos1 = 0;
	int pos2 = 0;

	do {
	std::cout << "Enter first position (from 0 to " << size - 1 << "): ";
	std::cin >> pos1;
	} while ( !is_in_range(size - 1, pos1) );

	do {
	std::cout << "Enter second position (from 0 to " << size - 1 << "): ";
	std::cin >> pos2;
	} while ( !is_in_range(size - 1, pos2) );

	my_swap_array(array, size, pos1, pos2);
	std::cout << "Position " << pos1 << " and " << pos2 << " are swapped!" << std::endl;
	print_array(array, size, 0, size);

	return 0;
}
