#include "fract_struct.h"
#include <stdio.h>

void fraction_reducing(fract& fr){
	int negative = 1;
	if (fr.numerator < 0){
		negative = -1;
	}
	for (int i = 2; i <= (negative * fr.numerator); ++i){
		if (((negative * fr.numerator) % i == 0) && (fr.denominator % i == 0)){
			fr.numerator /= i;
			fr.denominator /= i;
			fraction_reducing(fr);
		}
	}
}

void add_fraction(const fract& lh, const fract& rh, fract& result){
	result.numerator = lh.numerator * rh.denominator + rh.numerator * lh.denominator;
	result.denominator = lh.denominator * rh.denominator;
	fraction_reducing(result);
}

void substr_fraction(const fract& lh, const fract& rh, fract& result){
	add_fraction(lh, fract{-rh.numerator, rh.denominator}, result);
}

void multipl_fraction(const fract& lh, const fract& rh, fract& result){
	result.numerator = lh.numerator * rh.numerator;
	result.denominator = lh.denominator * rh.denominator;
	fraction_reducing(result);
}

void divide_fraction(const fract& lh, const fract& rh, fract& result){
	int negative = 1;
	if (rh.numerator < 0){
		negative = -1;
	}
	multipl_fraction(lh, fract{negative * rh.denominator, negative * rh.numerator}, result);
}

void print_result(fract& lh, fract& rh, fract& result, char action){
	switch (action) {
	case '+': add_fraction(lh, rh, result);
			  break;
	case '-': substr_fraction(lh, rh, result);
			  break;
	case '*': multipl_fraction(lh, rh, result);
			  break;
	case '/': divide_fraction(lh, rh, result);
			  break;
	}
	printf("(%d/%d) %c (%d/%d) = (%d/%d)\n", lh.numerator, lh.denominator, action,
											 rh.numerator, rh.denominator,
											 result.numerator, result.denominator);
}




