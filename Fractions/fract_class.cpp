#include "fract_class.h"

static int gcd(int x, int y);

fraction::fraction(int x, int  y) : numerator(x), denominator(y){
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
	fraction_reducing();
}

void fraction::fraction_reducing(){
	int sign = 1;
	if (numerator < 0){
		sign = -1;
	}
	int gcd_value = gcd(sign * numerator, denominator);

	if (gcd_value != 1){
		numerator /= gcd_value;
		denominator /= gcd_value;
	}
}

int fraction::get_numerator() const{
	return numerator;
}

int fraction::get_denominator() const{
	return denominator;
}

void fraction::set_numerator(int x){
	numerator = x;
}
void fraction::set_denominator(int x){
	denominator = x;
}

std::ostream& operator<<(std::ostream& os, const fraction& fr){
	os << "(" << fr.get_numerator() << "/" << fr.get_denominator() << ")";
	return os;
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

fraction fract_operation::add_fraction(const fraction& lh, const fraction& rh) const{
	return (fraction{lh.get_numerator() * rh.get_denominator() + rh.get_numerator() * lh.get_denominator(),
					 lh.get_denominator() * rh.get_denominator()});
}

fraction fract_operation::substr_fraction(const fraction& lh, const fraction& rh) const{
	return(add_fraction(lh, fraction{ - rh.get_numerator(), rh.get_denominator()}));
}

fraction fract_operation::multipl_fraction(const fraction& lh, const fraction& rh) const{
	return ( fraction{lh.get_numerator() * rh.get_numerator(),
					  lh.get_denominator() * rh.get_denominator()});
}

fraction fract_operation::divide_fraction(const fraction& lh, const fraction& rh) const{
	int sign = 1;
	if (rh.get_numerator() < 0){
		sign = -1;
	}
	return ( multipl_fraction( lh, fraction{sign * rh.get_denominator(), sign * rh.get_numerator()}) );
}

void fract_operation::print_result
(const fraction& lh, const fraction& rh, const fraction& result, char action) const{
	std::cout << lh
			  << " "<< action << " "
			  << rh
			  << " = " << result << std::endl;
}
