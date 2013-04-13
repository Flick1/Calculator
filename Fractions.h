  //GAL - Get Array Length
template < typename T, size_t N >
inline constexpr size_t GAL( T(&)[N] ){ return N; }
namespace operations{
	//Conversion from Frac to double unavailable due to C++11 standard
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
		private:
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
