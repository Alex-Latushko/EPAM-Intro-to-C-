#include <stdio.h>
#include "fract_func.h"
#include "fract_struct.h"
#include "fract_class.h"

int main() {
	{
		printf("+++++Fractions with functions+++++\n");
		int numerator1 = 6;
		int denominator1 = 24 ;

		int numerator2 = -1;
		int denominator2 = 3;

		int numerator_res = 0;
		int denominator_res = 1;

		add_fraction(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res);
		print_result(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res, '+');

		substr_fraction(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res);
		print_result(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res, '-');

		multipl_fraction(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res);
		print_result(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res, '*');

		divide_fraction(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res);
		print_result(numerator1, denominator1, numerator2, denominator2, numerator_res, denominator_res, '/');
	}
	{
		printf("\n+++++Fractions with structures+++++\n");
		struct fract fract_1 {6, 24};
		struct fract fract_2 {-1, 3};
		struct fract result;
		add_fraction(fract_1, fract_2, result);
		print_result(fract_1, fract_2, result, '+');

		substr_fraction(fract_1, fract_2, result);
		print_result(fract_1, fract_2, result, '-');

		multipl_fraction(fract_1, fract_2, result);
		print_result(fract_1, fract_2, result, '*');

		divide_fraction(fract_1, fract_2, result);
		print_result(fract_1, fract_2, result, '/');
	}
	{
		printf("\n+++++Fractions with classes+++++\n");
		fraction fraction_1(6, 24);
		fraction fraction_2(-1, 3);
		fraction_1.print_result(fraction_2, '+');
		fraction_1.print_result(fraction_2, '-');
		fraction_1.print_result(fraction_2, '*');
		fraction_1.print_result(fraction_2, '/');
	}
	return 0;
}
