#pragma once

struct fract{
	int numerator = 1;
	int denominator = 1;
};

void fraction_reducing(fract& fr);
void add_fraction(const fract& lh, const fract& rh, fract& result);
void substr_fraction(const fract& lh, const fract& rh, fract& result);
void multipl_fraction(const fract& lh, const fract& rh, fract& result);
void divide_fraction(const fract& lh, const fract& rh, fract& result);
void print_result(fract& lh, fract& rh, fract& result, char action);
