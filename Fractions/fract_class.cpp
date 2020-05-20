#include "fract_class.h"

fraction::fraction(int x, int  y) : numerator(x), denominator(y){
	fraction_reducing();
}

void fraction::fraction_reducing(){
	int negative = 1;
	if (numerator < 0){
		negative = -1;
	}
	for (int i = 2; i <= (negative * numerator); ++i){
		if (((negative * numerator) % i == 0) && (denominator % i == 0)){
			numerator /= i;
			denominator /= i;
			fraction_reducing();
		}
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
	int negative = 1;
	if (rh.numerator < 0){
		negative = -1;
	}
	return ( multipl_fraction( fraction{negative * rh.denominator, negative * rh.numerator}) );
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

std::ostream& operator<<(std::ostream& os, const fraction& fr){
	os << "(" << fr.get_numerator() << "/" << fr.get_denominator() << ")";
	return os;
}



