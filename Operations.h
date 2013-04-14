#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include <string>

namespace operations
{
   double add(double, double); //return sum
   double subtract(double,double); //return sum
   double multiply(double,double);//return product
   double divide(double, double); // Returns sum.
   int factorial_int(double);
   double factorial_dec(double); //Uses gamma function for decimal factorials; complex number implementation not updated
   double Logarithm_Natural(double);
   double Logarithm_Base10(double);
   double E_pow(double);

	double Sine(double);
	double Cosine(double);
	double Tangent(double);
	double Tangent2(double,double);

	class Frac{
		public:
		/*	Other functions to include:
				-Boolean operators
				-Conversion from Frac to char*
		*/

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
			Frac& operator() (int=0, int=0);
			Frac();
			Frac(int,int);
			Frac(double);
			Frac(const Frac&);
		protected:
			int numerator, denominator;
            void Simplify();
	};
	Frac operator+(const Frac&,double);
	Frac operator+(const Frac&,const Frac&);
	Frac operator-(const Frac&,double);
	Frac operator-(const Frac&,const Frac&);
	Frac operator*(const Frac&,double);
	Frac operator*(const Frac&,const Frac&);
	Frac operator/(const Frac&,double);
	Frac operator/(const Frac&,const Frac&);
};


#endif
