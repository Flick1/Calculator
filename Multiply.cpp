#include "Operations.h"

double operations::multiply(double firstnumber, double secondnumber){return firstnumber*secondnumber;}
	//Create initializer list so user can enter in as many factors as he/she wants
double operations::multiply_T(std::initializer_list<double> factors){
	double product = 1;
	for(std::initializer_list<double>::iterator iter = factors.begin(); iter != factors.end(); iter++)
		product *= *iter;
	return product;
}
