#include "array_func.h"

int main() {
	const size_t size = 20;
	double array[size] = {0};/*, 3, 2, 5, 1, 4, 9, 8, 6, 7,
			 	 		  10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; */

	std::cout << "Enter real array [" << size << "]:" << std::endl;
	enter_array(array, size, 0, size);
	insertion_sort_ascending(array, size, 0, size / 2);
	bubble_sort_descending(array, size, (size / 2), size);

	std::cout<< std::endl << "Sorted array:" << std::endl;
	print_array(array, size, 0, size);

	return 0;
}
