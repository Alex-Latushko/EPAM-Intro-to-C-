#include "d_array.h"

D_array::D_array(int x): size(x >= 0 ? x : 0){
	arr = (double*) calloc (size, sizeof(double));
}

D_array::D_array(const D_array& obj): size(obj.size){
	arr = (double*) calloc (size, sizeof(double));
	if (arr){
		memcpy(arr, obj.arr, sizeof(double) * size);
	}
}

void D_array::set_elem(int index, double value){
	if (index >=0 && index < size){
		*(arr + index) = value;
	} else {
		std::cout << "Index out of range!" << std::endl;
		exit(1);
	}
}

double D_array::get_elem(int index) const{
	if (index >= size || index < 0 ){
		std::cout << "Index out of range" << std::endl;
		return 0;
	}
	return *(arr+index);
}

int D_array::get_size() const{
	return size;
}

void D_array::show() const {
	if (1){
		for(int i = 0; i < size; ++i){
			std::cout << "[" << i << "] = " << *(arr+i) << std::endl;
		}
	}
}

void D_array::reverse(){
	D_array temp_arr(*this);
	for (int i = 0; i < size; i++){
		*(arr + i) = temp_arr.get_elem(temp_arr.size - i - 1);
	}
}

void D_array::quick_sort(int begin, int end){
	if ( (begin >= 0 && begin < size) && (end >= 0 && end < size) ){
		qsort(arr, begin, end);
	}
}

D_array::~D_array(){
	free_p(&arr);
}

template <typename T>
void free_p(T** p){
	if (*p != NULL){
		free(*p);
		*p = NULL;
	}
}

static void qsort(double* array, int begin, int end){
	int left = begin;
	int right = end;
	double pivot = array[(begin+end) / 2];
	double temp = 0;

	while (left <= right){
		while (array[left] < pivot) {
			++left;
		};
		while (array[right] > pivot) {
			--right;
		};
		if (left <= right){
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;

			++left;
			--right;
		}
	}

	if (right > begin){
		qsort(array, begin, right);
	}
	if (left < end){
		qsort(array, left, end);
	}
}
