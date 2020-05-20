#pragma once
#include <iostream>

class fraction{
	private:
		int numerator;
		int denominator;

	public:
	fraction (int x, int y);
	void fraction_reducing();
	fraction add_fraction(const fraction& fr) const;
	fraction substr_fraction(const fraction& fr)  const;
	fraction multipl_fraction(const fraction& fr)  const;
	fraction divide_fraction(const fraction& fr)  const;
	void print_result(const fraction& fr, char action)  const;

	int get_numerator() const;
	int get_denominator() const;
};

std::ostream& operator<<(std::ostream& os,const fraction& fr);



