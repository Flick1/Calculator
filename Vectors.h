#ifdef DEBUG_VECTORS

#ifndef VECTORS_H
	#define VECTORS_H
	#include <initializer_list>
	#include <string>
	#include <vector>
	
	class operations::Frac;
	
	namespace Vectors{
		double Magnitude(initializer_list<double>);
		double Magnitude(initializer_list<operations::Frac>);
		   //Calculate direction of a vector relative to a specific plane
		double Direction(initalizer_list<double>, std::string="xy");
		double Direction(initalizer_list<operations::Frac>, std::string="xy");
		
		double Dot(initializer_list<double>,initializer_list<double>);
		double Dot(initializer_list<operations::Frac>,initializer_list<double>);
		double Dot(initializer_list<double>,initializer_list<operations::Frac>);
		double Dot(initializer_list<operations::Frac>,initializer_list<operations::Frac>);
		double Dot(initializer_list<double>,VectorData);
		double Dot(initializer_list<operations::Frac>,VectorData);
		double Dot(VectorData,initializer_list<operations::Frac>);
		double Dot(VectorData,initializer_list<double>);
		double Dot(VectorData,VectorData);

		VectorData Cross(initializer_list<double>,initializer_list<double>);
		VectorData Cross(initializer_list<operations::Frac>,initializer_list<double>);
		VectorData Cross(initializer_list<double>,initializer_list<operations::Frac>);
		VectorData Cross(initializer_list<operations::Frac>,initializer_list<operations::Frac>);
		VectorData Cross(initializer_list<double>,VectorData);
		VectorData Cross(initializer_list<operations::Frac>,VectorData);
		VectorData Cross(VectorData,initializer_list<operations::Frac>);
		VectorData Cross(VectorData,initializer_list<double>);
		VectorData Cross(VectorData,VectorData);
		
		   //Create vector class for storage and multiple analyses
		   //All overloaded operators return type equivalent to left-hand value
		class VectorData{
			public:
				double Magnitude()const;
				double Direction(std::string="xy")const;
				std::string String()const;
				VectorData Unit()const;
				
				double Component(unsigned)const;
				void Add(double);
				void Add(operations::Frac);
				void Replace(unsigned,double);
				void Replace(unsigned,operations::Frac);
				
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
			protected:
				void Update();
		};
		bool Parallel(VectorData,VectorData);
		bool Orthogonal(VectorData,VectorData);
		double& operator+=(double,VectorData);
		double& operator-=(double,VectorData);
		VectorData operator+(VectorData,VectorData);
		VectorData operator-(VectorData,VectorData);
		VectorData operator*(VectorData,double);
		VectorData operator*(double,VectorData);
		VectorData operator/(VectorData,double);
		VectorData operator%(VectorData,double);
		bool operator!(VectorData);
		bool operator==(VectorData,VectorData);
		bool operator!=(VectorData,VectorData);
		
	#ifdef IOSTREAM_H
		std::ostream& operator<<(std::ostream&, const VectorData&);
	#endif
	#ifdef CURSES_H
		void printw(const VectorData&);
	#endif
	}
	
#endif

#endif