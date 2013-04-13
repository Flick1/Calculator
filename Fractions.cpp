#include "Operations.h"

#include <sstream>
#include <cmath>

  //GAL - Get Array Length
template < typename T, size_t N >
inline constexpr size_t GAL( T(&)[N] ){ return N; }

void operations::Frac::Simplify(){
  if(numerator == denominator){
		numerator = denominator = 1;
		return;
	}	//Modify copies to avoid complications with the originals
	int whole = 0, ncatalyst = numerator, dcatalyst = denominator;
	while(ncatalyst > dcatalyst){
		ncatalyst -= dcatalyst;
		whole++;
	}
		//List of prime numbers for simplifying the fraction
	int divisor[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59};
	const unsigned divisor_size = GAL(divisor);
	for(int i = 0; i < divisor_size; i++){
		while(((ncatalyst%divisor[i]) == 0) && ((dcatalyst%divisor[i]) == 0)){
			ncatalyst /= divisor[i];
			dcatalyst /= divisor[i];
		}
	}
	denominator = dcatalyst;
	numerator = (ncatalyst + whole*denominator);
}
int operations::Frac::Numerator(){return (*this).numerator;}
int operations::Frac::Denominator(){return (*this).denominator;}
std::string operations::Frac::String(){
	std::stringstream ss;
	std::string toreturn = "";
		ss << numerator;
	toreturn += ss.str();
		ss.str(std::string());
	if(denominator != 1){
		toreturn += '/';
			ss << denominator;
		toreturn += ss.str();
	}
	return toreturn;
}
double operations::Frac::Dbl(){
	return (numerator/denominator);
}
operations::Frac& operations::Frac::operator=(double decimal){
	std::stringstream ss;
	std::string convert;
		ss << decimal;
		ss >> convert;
	int pos = convert.find('.');
	if(pos != -1){
		convert[pos] = convert[pos+1];
		convert[pos+1] = '\0';
	}
		//strange glitch of subtracting 1 from the result when converting decimals
	numerator = decimal * pow(10,convert.length()-1);
	denominator = pow(10,convert.length()-1);
		if(numerator != decimal * pow(10,convert.length()-1))	numerator++;
		if(denominator != pow(10,convert.length()-1))	denominator++;
	Simplify();
}
operations::Frac& operations::Frac::operator=(const operations::Frac& original_fraction){
	if(this != &original_fraction){
		numerator = original_fraction.numerator;
		denominator = original_fraction.denominator;
	}
	return *this;
}
operations::Frac::Frac(){}
operations::Frac::Frac(int top, int bottom){
	if(bottom != 0){
		numerator = top;
		denominator = bottom;
	}else throw "Error. Division by zero attempt in operations::Frac::Frac(int, int).";
	Simplify();
}
operations::Frac::Frac(double decimal){*this = decimal;}
operations::Frac& operations::Frac::operator+=(const Frac& original_fraction){
	if(this == &original_fraction)
		numerator << 1;
	else{
		numerator = numerator*original_fraction.denominator + denominator*original_fraction.numerator;
		denominator *= original_fraction.denominator;
	}
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator+=(double decimal){
	Frac catalyst = decimal;
	*this += catalyst;
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator-=(const operations::Frac& original_fraction){
	if(this == &original_fraction){
		numerator = 0;
		denominator = 1;
	}else{
		numerator = numerator*original_fraction.denominator - denominator*original_fraction.numerator;
		denominator *= original_fraction.denominator;
	}
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator-=(double decimal){
	operations::Frac catalyst = decimal;
	*this -= catalyst;
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator*=(const operations::Frac& original_fraction){
	if(this == &original_fraction){
		numerator *= numerator;
		denominator *= denominator;
	}else{
		numerator *= original_fraction.numerator;
		denominator *= original_fraction.denominator;
	}
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator*=(double decimal){
	operations::Frac catalyst = decimal;
	*this *= catalyst;
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator/=(const operations::Frac& original_fraction){
	if(this == &original_fraction)
		numerator = denominator = 1;
	else{
		numerator *= original_fraction.denominator;
		denominator *= original_fraction.numerator;
	}
	(*this).Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator/=(double decimal){
	operations::Frac catalyst = decimal;
	*this /= catalyst;
	(*this).Simplify();
	return *this;
}
operations::Frac operations::operator+(const operations::Frac& leftside, const operations::Frac& rightside){
	operations::Frac catalyst = rightside;
	catalyst += leftside;
	return catalyst;
}
operations::Frac operations::operator+(const operations::Frac& Fraction, double decimal){
	operations::Frac catalyst = decimal;
	catalyst += Fraction;
	return catalyst;
}
operations::Frac operations::operator-(const operations::Frac& Fraction, double decimal){
	operations::Frac catalyst = decimal;
	catalyst -= Fraction;
	return catalyst;
}
operations::Frac operations::operator-(const operations::Frac& leftside, const operations::Frac& rightside){
	operations::Frac catalyst = leftside;
	catalyst -= rightside;
	return catalyst;
}
operations::Frac operations::operator*(const operations::Frac& Fraction, double decimal){}
operations::Frac operations::operator*(const operations::Frac& leftside, const operations::Frac& rightside){}
operations::Frac operations::operator/(const operations::Frac& Fraction, double decimal){}
operations::Frac operations::operator/(const operations::Frac& leftside, const operations::Frac& rightside){}
std::ostream& operator<<(std::ostream& output,operations::Frac& Fraction){
	return (output << Fraction.operations::Frac::String());	//Discards any qualifier
	//Error with binding when trying to stream operation, e.g. std::cout << (Frac1 + Frac2) << std::endl;
}
