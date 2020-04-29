#include <iostream>
#include <ctime>

struct marks {
	int five = 0;
	int four = 0;
	int three = 0;
	int two = 0;
};

void generate_marks(int* array, const size_t size){
	std::srand(std::time(0));
	for (size_t i = 0; i < size; ++i){
		array[i] = 2 + rand() % 4;
	}
}

struct marks count_marks(int* array, const size_t size){
	struct marks m;
	for (size_t i = 0; i < size; ++i){
		switch (array[i]) {
		case 2: ++(m.two);
				break;
		case 3: ++(m.three);
				break;
		case 4: ++(m.four);
				break;
		case 5: ++(m.five);
				break;
		}
	}
	return m;
}

int main() {
	const size_t size = 20;
	int array[size] ={0};

	generate_marks(array, size);
	struct marks m = count_marks(array, size);

	std::cout << "Amount of 5: " << m.five << std::endl
			  << "Amount of 4: " << m.four << std::endl
			  << "Amount of 3: " << m.three << std::endl
			  << "Amount of 2: " << m.two;

	return 0;
}
