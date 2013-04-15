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
			int Numerator()const;	//Surrogate get functions
			int Denominator()const;
			double Dec()const;
			std::string String()const;
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
			Frac& operator%=(const Frac&);
			Frac& operator%=(double);
			Frac& operator-();
			Frac& operator++();
			Frac& operator++(int=0);
			Frac& operator--();
			Frac& operator--(int=0);
			Frac& operator() (int=0, int=0); //Function for arbitrarily changing member vairables:
											//	numerator, denominator or both 
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
	double& operator+=(double&, const Frac&);
	double& operator-=(double&, const Frac&);
	double& operator*=(double&, const Frac&);
	double& operator/=(double&, const Frac&);
	double operator+(double, const Frac&);
	double operator-(double, const Frac&);
	double operator*(double, const Frac&);
	double operator/(double, const Frac&);
	bool operator!(const Frac&);
	bool operator==(const Frac&, const Frac&);
	bool operator==(const Frac&, double);
	bool operator==(double, const Frac&);
	bool operator!=(const Frac&, const Frac&);
	bool operator!=(const Frac&, double);
	bool operator!=(double, const Frac&);
	bool operator>(const Frac&, const Frac&);
	bool operator>(const Frac&, double);
	bool operator>(double, const Frac&);
	bool operator<(const Frac&, const Frac&);
	bool operator<(const Frac&, double);
	bool operator<(double, const Frac&);
	bool operator<=(const Frac&, const Frac&);
	bool operator<=(const Frac&, double);
	bool operator<=(double, const Frac&);
	bool operator>=(const Frac&, const Frac&);
	bool operator>=(const Frac&, double);
	bool operator>=(double, const Frac&);
	double& operator%=(double&, const Frac&);
	Frac operator%(const Frac&, const Frac&);
	Frac operator%(double, const Frac&);
	Frac operator%(const Frac&, double);
};


#endif
