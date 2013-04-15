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
				//Read-only Get functions
			int Numerator()const;
			int Denominator()const;
			double Dec()const;
			std::string String()const;
				//Emulate real variables by overloading most operators
			Frac& operator=(double);          // Frac = double
			Frac& operator=(const Frac&);     // Frac = Frac
			Frac& operator+=(double);         // Frac += double
			Frac& operator+=(const Frac&);    // Frac += Frac
			Frac& operator-=(double);         // Frac -= double
			Frac& operator-=(const Frac&);    // Frac -= Frac
			Frac& operator*=(double);         // Frac *= double
			Frac& operator*=(const Frac&);    // Frac *= Frac
			Frac& operator/=(double);         // Frac /= double
			Frac& operator/=(const Frac&);    // Frac /= Frac
			Frac& operator%=(const Frac&);    // Frac %= Frac     [will return an entire fraction]
			Frac& operator%=(double);         // Frac %= double   [a.k.a remainder]
			Frac& operator-();                // -Frac
			Frac& operator++();               // ++Frac
			Frac& operator++(int=0);          // Frac++
			Frac& operator--();               // --Frac
			Frac& operator--(int=0);          // Frac--
			Frac& operator() (int=0, int=0);  //Function for arbitrarily changing member variables:
			                                  //numerator and/or denominator
			                                  /// Syntax: Frac_Object(first_num,second_number)
			void Zero();                      //Convert Fraction to zero
			Frac();                           //Default constructor: set fraction equal to zero
			Frac(int,int);                    //Construct object with integer parameters
			Frac(double);                     //Construct object with decimal parameter
			Frac(const Frac&);                //Copy constructor calls overloaded assignment operator: operator=(const Frac&)
		protected:
			int numerator, denominator;
			void Simplify();
	};
	Frac operator+(const Frac&,double);       // Frac + double
	Frac operator+(const Frac&,const Frac&);  // Frac + Frac
	Frac operator-(const Frac&,double);       // Frac - double
	Frac operator-(const Frac&,const Frac&);  // Frac - Frac
	Frac operator*(const Frac&,double);       // Frac * double
	Frac operator*(const Frac&,const Frac&);  // Frac * Frac
	Frac operator/(const Frac&,double);       // Frac / double
	Frac operator/(const Frac&,const Frac&);  // Frac / Frac
	Frac operator%(const Frac&, const Frac&); // Frac % Frac		[will return remainder fraction]
	Frac operator%(double, const Frac&);      // double % Frac	[converts double to Frac]
	Frac operator%(const Frac&, double);      // Frac % double	[also returns remainder fraction]
	double& operator+=(double&, const Frac&); // double += Frac
	double& operator-=(double&, const Frac&); // double -= Frac
	double& operator*=(double&, const Frac&); // double *= Frac
	double& operator/=(double&, const Frac&); // double /= Frac
	double& operator%=(double&, const Frac&); // double %= Frac  [Returns an integer converted to decimal]
	double operator+(double, const Frac&);    // double + Frac
	double operator-(double, const Frac&);    // double - Frac
	double operator*(double, const Frac&);    // double * Frac
	double operator/(double, const Frac&);    // double / Frac
	bool operator!(const Frac&);              // !Frac			[Returns true if Frac has a numerator of 0]
	bool operator==(const Frac&, const Frac&);// Frac == Frac
	bool operator==(const Frac&, double);     // Frac == double
	bool operator==(double, const Frac&);     // double == Frac
	bool operator!=(const Frac&, const Frac&);// Frac != Frac
	bool operator!=(const Frac&, double);     // Frac != double
	bool operator!=(double, const Frac&);     // double != Frac
	bool operator>(const Frac&, const Frac&); // Frac > Frac
	bool operator>(const Frac&, double);      // Frac > double
	bool operator>(double, const Frac&);      // double > Frac
	bool operator<(const Frac&, const Frac&); // Frac < Frac
	bool operator<(const Frac&, double);      // Frac < double
	bool operator<(double, const Frac&);      // double < Frac
	bool operator<=(const Frac&, const Frac&);// Frac <= Frac
	bool operator<=(const Frac&, double);     // Frac <= double
	bool operator<=(double, const Frac&);     // double <= Frac
	bool operator>=(const Frac&, const Frac&);// Frac >= Frac
	bool operator>=(const Frac&, double);     // Frac >= double
	bool operator>=(double, const Frac&);     // double >= Frac
};


#endif
