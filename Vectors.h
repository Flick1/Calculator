#ifndef VECTORS_H
		/***Define which type of input/output being used***/
	//	#define IOSTREAM_H
	//	#define CURSES_H
	#define VECTORS_H

	#include <initializer_list>
	#include <vector>
	#include <string>
	#include <list>
	using std::list;
	using std::initializer_list;
	using std::vector;
		//To be modular, Vectors will not support other user-defined types
	namespace Vectors{
		class VectorData;

		void Square(list<list<double>>&, unsigned&, bool=false);
		double Determinant(list<list<double>>&, unsigned=0);

		double Magnitude(double[]);
		double Magnitude(const initializer_list<double>&);
		   //Calculate direction of a vector relative to a specific plane
		double Direction(double[], int=1,int=2);
		double Direction(const initializer_list<double>&, int=1,int=2);

		double Dot(const initializer_list<double>&, const initializer_list<double>&);
		double Dot(const initializer_list<double>&,const VectorData&);
		double Dot(const VectorData&,const initializer_list<double>&);
		double Dot(const VectorData&,const VectorData&);
		double Dot(const double[],const double[]);

		VectorData Cross(const initializer_list<initializer_list<double>>&);
		VectorData Cross(const initializer_list<VectorData>&);

		double AngleBetween(const initializer_list<double>&, const initializer_list<double>&);
		double AngleBetween(const VectorData&, const VectorData&);
		   //Create vector class for storage and multiple analyses
		   //All overloaded operators return type equivalent to left-hand value
		class VectorData{
			public:
				double Magnitude()const;
				double Direction(int=0)const;
				double RDirection(int=0)const;
				size_t NumDirection()const;
				virtual std::string String()const;
				VectorData Unit()const;

				virtual double Component(unsigned)const;
				double& operator[](size_t);
				double& operator[](size_t)const;
				virtual size_t size()const;
				virtual void Add(double);
				virtual void Replace(unsigned,double);
				virtual void Truncate(unsigned);
				virtual void Erase(unsigned);

				virtual void Empty();

				VectorData& operator=(const VectorData&);
				VectorData& operator+=(const VectorData&);
				VectorData& operator-=(const VectorData&);
				VectorData& operator*=(double);
				VectorData& operator/=(double);
				VectorData& operator%=(int);
				VectorData& operator++();
				VectorData& operator++(int=0);
				VectorData& operator--();
				VectorData& operator--(int=0);

				VectorData& operator>>=(int);
				VectorData& operator<<=(int);
				   //Arbitrarily assign component values
				void operator() (const VectorData&);
				void operator() (const initializer_list<double>&);
				void operator() (double,double);
				   //Construct VectorData with two components assigned 0
				VectorData();
				   //Construct VectorData with component parameters
				VectorData(const initializer_list<double>&);
				   //Construct VectorData with magnitude and direction (radians)
				VectorData(double,double);
				   //Construct VectorData with an array of components
				VectorData(const vector<double>&);
				   //Copy constructor
				VectorData(const VectorData&);

				virtual ~VectorData();
			private:
					//Vector will always have at least two components
				std::vector<double> components, directions, r_directions;
				double magnitude;
				//Garbage collector
				double Zero__;
			protected:
				virtual void Update();
				virtual void Transfer(const VectorData&);
		};
		bool Parallel(const VectorData&,const VectorData&);
		bool Orthogonal(const VectorData&,const VectorData&);
		VectorData operator+(const VectorData&,const VectorData&);
		VectorData operator-(const VectorData&,const VectorData&);
		VectorData operator*(const VectorData&,double);
		VectorData operator*(double,const VectorData&);
		VectorData operator/(const VectorData&,double);
		VectorData operator%(const VectorData&,int);
		VectorData operator>>(const VectorData&, int);
		VectorData operator<<(const VectorData&, int);
		bool operator!(const VectorData&);
		bool operator==(const VectorData&,const VectorData&);
		bool operator!=(const VectorData&,const VectorData&);

	#ifdef IOSTREAM_H
		inline std::ostream& operator<<(std::ostream& output, const Vectors::VectorData& rightside){return (output << rightside.String());}
	#elif CURSES_H
		inline void printw(const Vectors::VectorData& todisplay){printw(todisplay.String());}
	#endif
	}

#endif
