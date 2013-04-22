#ifndef CONSTANTS_H
	#define CONSTANTS_H
	
	namespace{
			//Pi rounded and placed in global namespace for use in multiple modules
		const double PI__ = 3.141593;
		
			//GAL - Get Array Length
		template < typename T, size_t N >
		inline constexpr size_t GAL( T(&)[N] ){ return N; }

			//List of prime numbers for general use
		const int divisor[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,71,73,79,83,87,89,97};
		const unsigned divisor_size = GAL(divisor);
	}
	
#endif