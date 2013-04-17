#include "Operations.h"

#include <sstream>
#include <cmath>

  //GAL - Get Array Length
template < typename T, size_t N >
inline constexpr size_t GAL( T(&)[N] ){ return N; }

operations::Frac Fract(0.0);
void operations::Frac::Simplify(){
	if(numerator == denominator){
		numerator = denominator = 1;
		return;
	}else if(numerator == 0){
		denominator = 1;
		return;
	}else if(denominator < 0){
		numerator *= -1;
		denominator *= -1;
	}
		//Modify copies to avoid complications with the originals
	int whole = 0, ncatalyst = numerator, dcatalyst = denominator;
	if(ncatalyst > 0){
		while(ncatalyst > dcatalyst){
			ncatalyst -= dcatalyst;
			whole++;
		}
	}else{
		while(ncatalyst < dcatalyst*-1){
			ncatalyst += dcatalyst;
			whole--;
		}
	}
		//List of prime numbers for simplifying the fraction
	int divisor[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59};
	const unsigned divisor_size = GAL(divisor);
	for(unsigned i = 0; i < divisor_size; i++){
		while(((ncatalyst%divisor[i]) == 0) && ((dcatalyst%divisor[i]) == 0)){
			ncatalyst /= divisor[i];
			dcatalyst /= divisor[i];
		}
	}
	denominator = dcatalyst;
	numerator = (ncatalyst + whole*denominator);
}
int operations::Frac::Numerator()const{return numerator;}
int operations::Frac::Denominator()const{return denominator;}
std::string operations::Frac::String()const{
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
double operations::Frac::Dec()const{return (numerator/denominator);}
void operations::Frac::Zero(){numerator = 0; denominator = 1;}
operations::Frac& operations::Frac::operator=(double decimal){
	std::stringstream ss;
	std::string convert;
		ss << decimal;
		ss >> convert;	//String variable to find the number of digits in the parameter
	int pos = convert.find('.'), sign = convert.find('-');
	if(pos != -1){	//Truncate decimal; useful for cases where decimal has many digits
		for(unsigned index = pos; index < convert.length()-1; index++)
			convert[index] = convert[index+1];
		convert.erase(convert.length()-1,1);
	}
	if(sign != -1){
		for(unsigned index = 0; index < convert.length()-1; index++)
			convert[index] = convert[index+1];
		convert.erase(convert.length()-1,1);
	}
	numerator = decimal * pow(10,convert.length()-1);
	denominator = pow(10,convert.length()-1);
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator=(const operations::Frac& original_fraction){
	if(this != &original_fraction){
		numerator = original_fraction.Numerator();
		denominator = original_fraction.Denominator();
	}
	Simplify();
	return *this;
}
operations::Frac::Frac(){numerator = 0; denominator = 1;}
operations::Frac::Frac(int top, int bottom){
	if(bottom != 0){
		numerator = top;
		denominator = bottom;
	}else throw "Error. Division by zero attempt in operations::Frac::Frac(int, int).";
	Simplify();
}
operations::Frac::Frac(double decimal){*this = decimal;}
operations::Frac::Frac(const Frac& original_fraction){(*this) = original_fraction;}
operations::Frac& operations::Frac::operator() (int newnum, int newdenom){
	if(newnum != 0)	numerator = newnum;
	if(newdenom != 0)	denominator = newdenom;
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator() (double newdecimal){
	(*this) = newdecimal;
	return *this;
}
operations::Frac& operations::Frac::operator+=(const operations::Frac& original_fraction){
	if(this == &original_fraction)
		numerator *= 2;
	else{
		numerator = numerator*original_fraction.denominator + denominator*original_fraction.numerator;
		denominator *= original_fraction.denominator;
	}
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator+=(double decimal){
	Frac catalyst = decimal;
	*this += catalyst;
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
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator-=(double decimal){
	operations::Frac catalyst = decimal;
	*this -= catalyst;
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
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator*=(double decimal){
	operations::Frac catalyst = decimal;
	*this *= catalyst;
	return *this;
}
operations::Frac& operations::Frac::operator/=(const operations::Frac& original_fraction){
	if(this == &original_fraction)
		numerator = denominator = 1;
	else{
		numerator *= original_fraction.Denominator();
		denominator *= original_fraction.Numerator();
	}
	Simplify();
	return *this;
}
operations::Frac& operations::Frac::operator/=(double decimal){
	operations::Frac catalyst = decimal;
	*this /= catalyst;
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
operations::Frac operations::operator*(const operations::Frac& Fraction, double decimal){
	operations::Frac catalyst = decimal;
	catalyst *= Fraction;
	return catalyst;
}
operations::Frac operations::operator*(const operations::Frac& leftside, const operations::Frac& rightside){
	operations::Frac catalyst = rightside;
	catalyst *= leftside;
	return catalyst;
}
operations::Frac operations::operator/(const operations::Frac& Fraction, double decimal){
	operations::Frac catalyst = decimal;
	operations::Frac leftcopy = Fraction;
	leftcopy /= catalyst;
	return leftcopy;
}
operations::Frac operations::operator/(const operations::Frac& leftside, const operations::Frac& rightside){
	operations::Frac leftcopy = leftside;
	leftcopy /= rightside;
	return leftcopy;
}
double& operations::operator+=(double& decimal, const operations::Frac& Fraction){
	decimal += Fraction.Dec();
	return decimal;
}
double& operations::operator-=(double& decimal, const operations::Frac& Fraction){
	decimal -= Fraction.Dec();
	return decimal;
}
double& operations::operator*=(double& decimal, const operations::Frac& Fraction){
	decimal *= Fraction.Dec();
	return decimal;
}
double& operations::operator/=(double& decimal, const operations::Frac& Fraction){
	decimal /= Fraction.Dec();
	return decimal;
}
double operations::operator+(double decimal, const operations::Frac& Fraction){return decimal + Fraction.Dec();}
double operations::operator-(double decimal, const operations::Frac& Fraction){return decimal - Fraction.Dec();}
double operations::operator*(double decimal, const operations::Frac& Fraction){return decimal * Fraction.Dec();}
double operations::operator/(double decimal, const operations::Frac& Fraction){return decimal / Fraction.Dec();}
bool operations::operator!(const operations::Frac& Fraction){
	if(Fraction.Numerator() == 0)	return true;
	else	return false;
}
bool operations::operator==(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() == rightside.Dec())	return true;
	else return false;
}
bool operations::operator==(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() == rightside)	return true;
	else return false;
}
bool operations::operator==(double leftside, const operations::Frac& rightside){
	if(leftside == rightside.Dec())	return true;
	else return false;
}
bool operations::operator!=(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() != rightside.Dec())	return true;
	else return false;
}
bool operations::operator!=(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() != rightside)	return true;
	else return false;
}
bool operations::operator!=(double leftside, const operations::Frac& rightside){
	if(leftside != rightside.Dec())	return true;
	else return false;
}
bool operations::operator>(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() > rightside.Dec())	return true;
	else return false;
}
bool operations::operator>(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() > rightside)	return true;
	else return false;
}
bool operations::operator>(double leftside, const operations::Frac& rightside){
	if(leftside > rightside.Dec())	return true;
	else return false;
}
bool operations::operator<(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() < rightside.Dec())	return true;
	else return false;
}
bool operations::operator<(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() < rightside)	return true;
	else return false;
}
bool operations::operator<(double leftside, const operations::Frac& rightside){
	if(leftside < rightside.Dec())	return true;
	else return false;
}
bool operations::operator<=(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() <= rightside.Dec())	return true;
	else return false;
}
bool operations::operator<=(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() <= rightside)	return true;
	else return false;
}
bool operations::operator<=(double leftside, const operations::Frac& rightside){
	if(leftside <= rightside.Dec())	return true;
	else return false;
}
bool operations::operator>=(const operations::Frac& leftside, const operations::Frac& rightside){
	if(leftside.Dec() >= rightside.Dec())	return true;
	else return false;
}
bool operations::operator>=(const operations::Frac& leftside, double rightside){
	if(leftside.Dec() >= rightside)	return true;
	else return false;
}
bool operations::operator>=(double leftside, const operations::Frac& rightside){
	if(leftside >= rightside.Dec())	return true;
	else return false;
}
operations::Frac& operations::Frac::operator-(){
	numerator *= -1;
	return *this;
}
operations::Frac& operations::Frac::operator++(){
	(*this) += 1;
	return *this;
}
operations::Frac& operations::Frac::operator++(int dummy){
	(*this) += 1;
	return *this;
}
operations::Frac& operations::Frac::operator--(){
	(*this) -= 1;
	return *this;
}
operations::Frac& operations::Frac::operator--(int dummy){
	(*this) -= 1;
	return *this;
}
operations::Frac& operations::Frac::operator%=(const operations::Frac& rightside){
	(*this) /= rightside;
	if(numerator > 0){
		while(numerator > denominator)	numerator -= denominator;
	}else{
		while(numerator < (denominator*-1))	numerator += denominator;
	}
	return *this;
}
operations::Frac& operations::Frac::operator%=(double decimal){
	operations::Frac catalyst(decimal);
	(*this) /= catalyst;
	if(numerator > 0){
		while(numerator > denominator)	numerator -= denominator;
	}else{
		while(numerator < (denominator*-1))	numerator += denominator;
	}
	return *this;
}
double& operations::operator%=(double& decimal, const operations::Frac& rightside){
	operations::Frac leftside(decimal);
	leftside /= rightside;
	int numcopy = leftside.Numerator(), denomcopy = leftside.Denominator();
	if(numcopy > 0){
		while(numcopy > denomcopy)	numcopy -= denomcopy;
	}else{
		while(numcopy < (denomcopy*-1))	numcopy += denomcopy;
	}
	decimal = numcopy;
	return decimal;
}
operations::Frac operations::operator%(const operations::Frac& leftside, const operations::Frac& rightside){
	operations::Frac catalyst = leftside;
	catalyst %= rightside;
	return catalyst;
}
operations::Frac operations::operator%(double leftside, const operations::Frac& rightside){
	operations::Frac catalyst(leftside);
	catalyst %= rightside;
	return catalyst;
}
operations::Frac operations::operator%(const operations::Frac& leftside, double rightside){
	operations::Frac catalyst(rightside);
	operations::Frac leftcopy(leftside);
	leftcopy %= catalyst;
	return leftcopy;
}
/*
operations::Frac& operations::Frac::operator~(){
	double num_copy = numerator;	//Save a copy of the numerator
	numerator = denominator;
	denominator = num_copy;
	return *this;
}
std::string operations::Frac::Mixed()const{
	int whole=0, num_copy=numerator;
	if(numerator > 0){
		while(num_copy > denominator){
			num_copy -= denominator;
			whole++;
		}
	}else{
		while(num_copy < denominator*-1){
			num_copy += denominator;
			whole++;
		}
	}
	stringstream ss;
		ss << whole;
	operations::Frac catalyst(num_copy,denominator);
	return (ss.str() + catalyst.String());
}
double operations::pow(double base, const operations::Frac& exponent){
	return pow(base, exponent.Dec());
}
double operations::pow(const operations::Frac& base, double exponent){
	return pow(base.Dec(), exponent);
}
double operations::pow(const operations::Frac& base, const operations::Frac& exponent){
	return pow(base.Dec(), exponent.Dec());
}
*/
#ifdef IOSTREAM_H
	std::ostream& operations::operator<<(std::ostream& output, const operations::Frac& Fraction){return (output << Fraction.String());}
#endif
#ifdef CURSES_H
	void operations::printw(const Frac& Fraction){
		const char* todisplay = Fraction.String().c_str();
		output::print(todisplay);
	}
#endif
