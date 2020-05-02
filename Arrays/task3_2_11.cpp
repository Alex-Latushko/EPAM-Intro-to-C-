#include "array_func.h"

struct pair_of_points{
	int first = 0;
	int second = 0;
};

double calc_dist(int x1, int y1, int x2, int y2){
	return ( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}

struct pair_of_points calculate_the_farthest(int coord[], int size){
	int max_dist = 0;
	struct pair_of_points result;

	for (int i = 0; i < size; i += 2){
		for (int j = i; j < size; j += 2){
			if (max_dist < calc_dist(coord[i], coord[i+1], coord[j], coord[j+1]) ){
				result.first = i;
				result.second = j;
				max_dist = calc_dist(coord[i], coord[i+1], coord[j], coord[j+1]);
			}
		}
	}
	return result;
}

int main() {
	const size_t size = 20;
	int coord [size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
							  10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	std::cout << "Enter integer coordinates of points [" << size << "]:" << std::endl;
	enter_array_cin(coord, size, 0, size);

	struct pair_of_points farthest_points = calculate_the_farthest(coord, size);

	std::cout << "Coordinates of the farthest points are: {"
			  << coord[farthest_points.first] << ", " << coord[farthest_points.first + 1] << "} & {"
			  << coord[farthest_points.second] << ", " << coord[farthest_points.second + 1] << "}";

	return 0;
}
