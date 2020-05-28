#pragma once
#include <iostream>

class D_array{
	private:
	const int size;
	double* arr;

	public:
	D_array(int x = 10);
	D_array(const D_array& obj);

	void set_elem(int index, double value);
	double get_elem(int index) const;
	int get_size() const;

	void show() const;

	void quick_sort(int begin, int end);
	void reverse();
	~D_array();
};

template <typename T>
void free_p(T** p);

static void qsort(double* array, int begin, int end);
