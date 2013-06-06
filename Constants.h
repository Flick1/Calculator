#ifndef CONSTANTS_H
	#define CONSTANTS_H
	#include <cstddef>

	namespace{
			//Literal constants
		const double
			PI__ = 3.14159265358979323846,
			e__  = 2.71828182845904523536,
			epsilon__ = 1e-15
		;

			//GAL - Get Array Length
		template < typename T, size_t N >
		inline constexpr size_t GAL( T(&)[N] ){ return N; }

			//List of prime numbers for general use, including -1
		const int divisor[] = {
			-1,2,3,5,7,11,13,17,19,23,
			29,31,37,41,43,47,53,57,59,
			61,67,71,73,79,83,87,89,97
		};
		const unsigned divisor_size = GAL(divisor);

		//String literal functions
		inline constexpr double operator"" _PI(long double literal){return literal*PI__;}
		inline constexpr double operator"" _e(long double literal){return literal*e__;}
		inline constexpr double operator"" _Per(long double literal){return literal/100;}
	}

#endif
