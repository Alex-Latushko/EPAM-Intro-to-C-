#include <iostream>

#include "array_func.h"

int main() {
	const size_t size = 20;
	/*int array [size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
			 	 		  10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; */
	int array[size] = {0};

	std::cout << "Enter real array [" << size << "]:" << std::endl;
	enter_array(array,size, 0, size);

	my_swap_array(array, size,
				  max_array(array, size, 0, size / 2),
				  min_array(array, size, (size / 2) + 1, size));

	std::cout << "Array after swap" << std::endl;
	print_array(array, size, 0, size);

	return 0;
}
