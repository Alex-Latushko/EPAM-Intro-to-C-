#pragma once
#include <iostream>

class fraction{
	private:
		int numerator;
		int denominator;

	public:
	fraction (int x, int y);
	void fraction_reducing();

	int get_numerator() const;
	int get_denominator() const;
	void set_numerator(int x);
	void set_denominator(int x);
};

class fract_operation{
	public:
	fraction add_fraction(const fraction& lh, const fraction& rh) const;
	fraction substr_fraction(const fraction& lh, const fraction& rh)  const;
	fraction multipl_fraction(const fraction& lh, const fraction& rh)  const;
	fraction divide_fraction(const fraction& lh, const fraction& rh)  const;
	void print_result(const fraction& lh, const fraction& rh, const fraction& result, char action)  const;
};

std::ostream& operator<<(std::ostream& os,const fraction& fr);



