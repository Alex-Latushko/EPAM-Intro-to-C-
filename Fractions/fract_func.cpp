#include "fract_func.h"
#include <stdio.h>

static int gcd(int x, int y);

void fraction_reducing(int& num, int& denom){
	int sign = 1;
	if (num < 0){
		sign = -1;
	}
	int gcd_value = gcd(sign * num, denom);

	if (gcd_value != 1){
		num /= gcd_value;
		denom /= gcd_value;
	}
}

void add_fraction(int n1, int dn1, int n2, int dn2, int& n_res, int& dn_res){
	n_res = n1 * dn2 + n2 * dn1;
	dn_res = dn1 * dn2;
	fraction_reducing(n_res, dn_res);
}

void substr_fraction(int n1, int dn1, int n2, int dn2, int& n_res, int& dn_res){
	add_fraction(n1, dn1, -n2, dn2, n_res, dn_res);
}

void multipl_fraction(int n1, int dn1, int n2, int dn2, int& n_res, int& dn_res){
	n_res = n1 * n2;
	dn_res = dn1 * dn2;
	fraction_reducing(n_res, dn_res);
}

void divide_fraction(int n1, int dn1, int n2, int dn2, int& n_res, int& dn_res){
	if (n2 < 0){
		n2 *= -1;
		dn2 *= -1;
	}
	multipl_fraction(n1, dn1, dn2, n2, n_res, dn_res);
}

void print_result(int n1, int dn1, int n2, int dn2, int n_res, int dn_res, char action){
	printf("(%d/%d) %c (%d/%d) = (%d/%d)\n", n1, dn1, action, n2, dn2, n_res, dn_res);
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



