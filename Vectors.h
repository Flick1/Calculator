/*
#ifndef VECTORS_H
	#define VECTORS_H
	#include <initializer_list>
	#include <string>
	#include <vector>
	
	class operations::Frac;
	
	namespace Vectors{
		double Magnitude(initializer_list<double>);
		double Magnitude(initializer_list<operations::Frac>);
		double Dot(initializer_list<double>);
		double Dot(initializer_list<operations::Frac>);
		   //Calculate direction of a vector relative to a specific plane
		double Direction(initalizer_list<double>, std::string="xy");
		double Direction(initalizer_list<operations::Frac>, std::string="xy");
		   //Create vector class for storage and multiple analyses
		class VectorData{
			public:
				double Magnitude();
				double Direction(std::string="xy");
				double Dot();
				VectorData Cross(VectorData);
				std::string String();
				
				VectorData& operator=(VectorData);
				VectorData& operator+=(VectorData);
				VectorData& operator-=(VectorData);
				VectorData& operator*=(double);
				VectorData& operator/=(double);
				VectorData& operator%=(double);
				VectorData& operator++();
				VectorData& operator++(int=0);
				VectorData& operator--();
				VectorData& operator--(int=0);
				
				VectorData& operator>>=(int);
				VectorData& operator<<=(int);
				VectorData& operator~();
				VectorData& operator^=(int);
				VectorData& operator&=(int);
				VectorData& operator|=(int);
				   //Arbitrarily assign component values
				void operator() (VectorData);
				void operator() (initializer_list<double>);
				void operator() (initializer_list<operations::Frac>);
				void operator() (double,double);
				void operator() (operations::Frac,double);
				   //Construct VectorData with two components assigned 0
				VectorData();
				   //Construct VectorData with component parameters
				VectorData(initializer_list<double>);
				   //Construct VectorData with Fraction component parameters
				VectorData(initializer_list<operations::Frac>);
				   //Construct VectorData with magnitude and direction (radians)
				VectorData(double,double);
				   //Construct VectorData with Fraction magnitude and direction (radians)
				VectorData(operations::Frac,double);
				   //Copy constructor
				VectorData(VectorData);
			private:
				std::vector<double> components, directions;
				double magnitude;
		};
		
	}
	
#endif
*/