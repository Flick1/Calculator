#ifdef DEBUG_VECTORS

#ifndef VECTORS_H
	#define VECTORS_H
	#include <initializer_list>
	#include <vector>
		//To be modular, Vectors will not support other user-defined types
	namespace Vectors{
		double Magnitude(initializer_list<double>);
		   //Calculate direction of a vector relative to a specific plane
		double Direction(initalizer_list<double>, int=1,int=2);
		
		double Dot(initializer_list<double>,initializer_list<double>);
		double Dot(initializer_list<double>,const VectorData&);
		double Dot(const VectorData&,initializer_list<double>);
		double Dot(const VectorData&,const VectorData&);

		VectorData Cross(initializer_list<double>,initializer_list<double>);
		VectorData Cross(initializer_list<double>,const VectorData&);
		VectorData Cross(const VectorData&,initializer_list<double>);
		VectorData Cross(const VectorData&,const VectorData&);
		
		   //Create vector class for storage and multiple analyses
		   //All overloaded operators return type equivalent to left-hand value
		class VectorData{
			public:
				double Magnitude()const;
				double Direction(int=1,int=2)const;
				std::string String()const;
				VectorData Unit()const;
				
				double Component(unsigned)const;
				size_t size()const;
				void Add(double);
				void Replace(unsigned,double);
				void Replace(int,double);
				void Truncate(unsigned);
				void Truncate(int);
				void Erase(unsigned);
				void Erase(int);
				
				VectorData& operator=(const VectorData&);
				VectorData& operator+=(const VectorData&);
				VectorData& operator-=(const VectorData&);
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
				void operator() (const VectorData&);
				void operator() (initializer_list<double>);
				void operator() (double,double);
				   //Construct VectorData with two components assigned 0
				VectorData();
				   //Construct VectorData with component parameters
				VectorData(initializer_list<double>);
				   //Construct VectorData with magnitude and direction (radians)
				VectorData(double,double);
				   //Copy constructor
				VectorData(const VectorData&);
			private:
					//Vector will always have at least two components
				std::vector<double> components;
			protected:
				void Update();
		};
		bool Parallel(const VectorData&,const VectorData&);
		bool Orthogonal(const VectorData&,const VectorData&);
		double& operator+=(double,const VectorData&);
		double& operator-=(double,const VectorData&);
		VectorData operator+(const VectorData&,const VectorData&);
		VectorData operator-(const VectorData&,const VectorData&);
		VectorData operator*(const VectorData&,double);
		VectorData operator*(double,const VectorData&);
		VectorData operator/(const VectorData&,double);
		VectorData operator%(const VectorData&,double);
		bool operator!(const VectorData&);
		bool operator==(const VectorData&,const VectorData&);
		bool operator!=(const VectorData&,const VectorData&);
		
	#ifdef IOSTREAM_H
		std::ostream& operator<<(std::ostream&, const VectorData&);
	#endif
	#ifdef CURSES_H
		void printw(const VectorData&);
	#endif
	}
	
#endif

#endif