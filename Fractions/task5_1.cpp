#include <stdio.h>
#include "fract_func.h"
#include "fract_struct.h"
#include "fract_class.h"

# define FIRST_NUMERATOR 6
# define FIRST_DENOMINATOR 24
# define SECOND_NUMERATOR -1
# define SECOND_DENOMINATOR 3

int main() {
	{
		printf("+++++Fractions with functions+++++\n");
		int numerator1 = FIRST_NUMERATOR;
		int denominator1 = FIRST_DENOMINATOR ;

		int numerator2 = SECOND_NUMERATOR;
		int denominator2 = SECOND_DENOMINATOR;

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
		struct fract fract_1 {FIRST_NUMERATOR, FIRST_DENOMINATOR};
		struct fract fract_2 {SECOND_NUMERATOR, SECOND_DENOMINATOR};
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
		fraction fraction_1(FIRST_NUMERATOR, FIRST_DENOMINATOR);
		fraction fraction_2(SECOND_NUMERATOR, SECOND_DENOMINATOR);
		fraction result(1,1);
		fract_operation op;
		result = op.add_fraction(fraction_1, fraction_2);
		op.print_result(fraction_1, fraction_2, result, '+');

		result = op.substr_fraction(fraction_1, fraction_2);
		op.print_result(fraction_1, fraction_2, result, '-');

		result = op.multipl_fraction(fraction_1, fraction_2);
		op.print_result(fraction_1, fraction_2, result, '*');

		result = op.divide_fraction(fraction_1, fraction_2);
		op.print_result(fraction_1, fraction_2, result, '/');
	}
	return 0;
}
