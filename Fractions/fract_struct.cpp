#include "fract_struct.h"
#include <stdio.h>

static int gcd(int x, int y);

void fraction_reducing(fract& fr){
	int gcd_value = gcd(fr.numerator, fr.denominator);

	if (gcd_value != 1){
		fr.numerator /= gcd_value;
		fr.denominator /= gcd_value;
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
	int sign = 1;
	if (rh.numerator < 0){
		sign = -1;
	}
	multipl_fraction(lh, fract{sign * rh.denominator, sign * rh.numerator}, result);
}

void print_result(const fract& lh, const fract& rh, const fract& result, char action){
	printf("(%d/%d) %c (%d/%d) = (%d/%d)\n", lh.numerator, lh.denominator, action,
											 rh.numerator, rh.denominator,
											 result.numerator, result.denominator);
}

static int gcd(int x, int y) { //GCD by algorithm of Euclid
	int max = x;
	int min = y;
	int rest = 1;

	if (x<y) {
		max = y;
		min = x;
	};

	while ( (rest = max % min) !=0 ){
		max = min;
		min = rest;
	};
	return min;     		//when rest==0, then min is GCD of x and y
}


