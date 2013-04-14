#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include <string>

namespace operations
{
   double add(double, double);
   double subtract(double,double); //return sum
   double multiply(double,double);//return product
   double divide(double, double); // Returns sum.
   int factorial_int(double);
   double factorial_dec(double); //Uses gamma function for decimal factorials; complex number implementation not updated
   double Logarithm_Natural(double);
   double Logarithm_Base10(double);
   double E_pow(double);

	class Frac{
		public:
		/*	Other functions to include:
				-Bitwise operators
				-Other compound assignment operators
				-Boolean operators
				-Binary operators for double [operator] Frac
				-Conversion from Frac to char*
		*/
			void Simplify();
			int Numerator();	//Surrogate get functions
			int Denominator();
			double Dec();
			std::string String();
			Frac& operator=(double);
			Frac& operator=(const Frac&);
			Frac& operator+=(double);
			Frac& operator+=(const Frac&);
			Frac& operator-=(double);
			Frac& operator-=(const Frac&);
			Frac& operator*=(double);
			Frac& operator*=(const Frac&);
			Frac& operator/=(double);
			Frac& operator/=(const Frac&);
			Frac();
			Frac(int,int);
			Frac(double);
		protected:
			int numerator, denominator;
	};
	Frac operator+(const Frac&,double);
	Frac operator+(const Frac&,const Frac&);
	Frac operator-(const Frac&,double);
	Frac operator-(const Frac&,const Frac&);
	Frac operator*(const Frac&,double);
	Frac operator*(const Frac&,const Frac&);
	Frac operator/(const Frac&,double);
	Frac operator/(const Frac&,const Frac&);
}


#endif
