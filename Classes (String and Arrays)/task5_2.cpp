#include <iostream>
#include "string_class.h"
#include "d_array.h"

int main() {

	D_array arr;
	arr.show();

	double x = 0;
	for (int i = 0; i < arr.get_size(); ++i){
		std::cout << "[" << i << "] = ";
		std::cin >> x;
		arr.set_elem(i, x);
	}

	arr.show();

	arr.quick_sort(0, arr.get_size() - 1);
	std::cout << "After quick_sort" << std::endl;
	arr.show();

	arr.reverse();
	std::cout << "After reverse" << std::endl;
	arr.show();

	std::cout << arr.get_elem(100) << std::endl;

	int n = 0;
	std::cout << "Enter the size of the array: ";
	std::cin >> n;
	D_array arr1(n);
	arr1.show();

	std::cout << "***************Strings****************" << std::endl;

	String s1("Privet!!!!");
	s1.show();

	s1.set_str("Minsk!!!!!!");
	s1.show();

	String s2;
	s2.set_str("12345 7890");
	s2.show();

	String s3 = String("Da-Da");
	s3.show();

	String s4 = s3;
	s4.show();

	String *s;
	s = new String;

	s->set_str("123456");
	s->show();

	String *p;
	p = new String("No-No");

	delete s;
	delete p;

	return 0;
}
