#include "fract_class.h"

static int gcd(int x, int y);

fraction::fraction(int x, int  y) : numerator(x), denominator(y){
	fraction_reducing();
}

void fraction::fraction_reducing(){
	int gcd_value = gcd(numerator, denominator);

	if (gcd_value != 1){
		numerator /= gcd_value;
		denominator /= gcd_value;
	}
}

fraction fraction::add_fraction(const fraction& rh) const{
	return (fraction{numerator * rh.denominator + rh.numerator * denominator,
					 denominator * rh.denominator});
}

fraction fraction::substr_fraction(const fraction& rh) const{
	return(add_fraction(fraction{ - rh.numerator, rh.denominator}));
}

fraction fraction::multipl_fraction(const fraction& rh) const{
	return ( fraction{numerator * rh.numerator,
					  denominator * rh.denominator});
}

fraction fraction::divide_fraction(const fraction& rh) const{
	int sign = 1;
	if (rh.numerator < 0){
		sign = -1;
	}
	return ( multipl_fraction( fraction{sign * rh.denominator, sign * rh.numerator}) );
}

void fraction::print_result(const fraction& rh, char action) const{
	fraction result(1,1);
	switch (action) {
	case '+': result = add_fraction(rh);
			  break;
	case '-': result = substr_fraction(rh);
			  break;
	case '*': result = multipl_fraction(rh);
			  break;
	case '/': result = divide_fraction(rh);
			  break;
	}

	std::cout << *this
			  << " "<< action << " "
			  << rh
			  << " = " << result << std::endl;
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

