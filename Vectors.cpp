#ifdef DEBUG_VECTORS

#include "Operations.h"
#include "Vectors.h"

#include <initializer_list>
#include <string>
#include <vector>
#include <cmath>
	
class operations::Frac;

double Magnitude(initializer_list<double> components){
	double square[];
	for(auto iter = component.begin(), int i=0; iter != component.end(); iter++, i++)
		square[i] = (*iter)*(*iter);
	double toreturn=0;
	const unsigned num_components = GAL(square);
	for(unsigned j=0; j < num_components; j++)
		toreturn += sqaure[j];
	return sqrt(toreturn);
}
double Magnitude(initializer_list<operations::Frac> components){
	double square[];
	for(auto iter = component.begin(), int i=0; iter != component.end(); iter++, i++)
		square[i] = (*iter).Dec()*(*iter).Dec();
	double toreturn=0;
	const unsigned num_components = GAL(square);
	for(unsigned j=0; j < num_components; j++)
		toreturn += sqaure[j];
	return sqrt(toreturn);
}

double Direction(initalizer_list<double>, std::string="xy");
double Direction(initalizer_list<operations::Frac>, std::string="xy");

double Dot(initializer_list<double> first,initializer_list<double> second){
	while(first.size() < second.size())	
}
double Dot(initializer_list<operations::Frac>,initializer_list<double>);
double Dot(initializer_list<double>,initializer_list<operations::Frac>);
double Dot(initializer_list<operations::Frac>,initializer_list<operations::Frac>);
double Dot(initializer_list<double>,Vectors::VectorData);
double Dot(initializer_list<operations::Frac>,Vectors::VectorData);
double Dot(Vectors::VectorData,initializer_list<operations::Frac>);
double Dot(Vectors::VectorData,initializer_list<double>);
double Dot(Vectors::VectorData,Vectors::VectorData);

Vectors::VectorData Cross(initializer_list<double>,initializer_list<double>);
Vectors::VectorData Cross(initializer_list<operations::Frac>,initializer_list<double>);
Vectors::VectorData Cross(initializer_list<double>,initializer_list<operations::Frac>);
Vectors::VectorData Cross(initializer_list<operations::Frac>,initializer_list<operations::Frac>);
Vectors::VectorData Cross(initializer_list<double>,Vectors::VectorData);
Vectors::VectorData Cross(initializer_list<operations::Frac>,Vectors::VectorData);
Vectors::VectorData Cross(Vectors::VectorData,initializer_list<operations::Frac>);
Vectors::VectorData Cross(Vectors::VectorData,initializer_list<double>);
Vectors::VectorData Cross(Vectors::VectorData,Vectors::VectorData);

double Vectors::VectorData::Magnitude()const;
double Vectors::VectorData::Direction(std::string="xy")const;
std::string Vectors::VectorData::String()const;

Vectors::VectorData Vectors::VectorData::Unit(){
	Vectors::Vector Data catalyst(*this);
		//List of prime numbers for simplifying the vector components
	int divisor[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59};
	
	for(int i=0; i < GAL(divisor); i++){
		for(size_t iter = 0; iter < components.size(); iter++){
			if(components[iter]%divisor[i] != 0){
				continue;
			}else if(iter == components.size()-1){
				for(size_t iter2 = 0; iter2 < components.size(); iter2++)
					catalyst.components[iter2] = components[iter2] / divisor[i];
			}
		}
	}
	return catalyst;
}

double Component(unsigned)const;
void Add(double);
void Add(operations::Frac);
void Replace(unsigned,double);
void Replace(unsigned,operations::Frac);

Vectors::VectorData& Vectors::VectorData::operator=(Vectors::VectorData);
Vectors::VectorData& Vectors::VectorData::operator+=(Vectors::VectorData);
Vectors::VectorData& Vectors::VectorData::operator-=(Vectors::VectorData);
Vectors::VectorData& Vectors::VectorData::operator*=(double);
Vectors::VectorData& Vectors::VectorData::operator/=(double);
Vectors::VectorData& Vectors::VectorData::operator%=(double);
Vectors::VectorData& Vectors::VectorData::operator++();
Vectors::VectorData& Vectors::VectorData::operator++(int=0);
Vectors::VectorData& Vectors::VectorData::operator--();
Vectors::VectorData& Vectors::VectorData::operator--(int=0);

Vectors::VectorData& Vectors::VectorData::operator>>=(int);
Vectors::VectorData& Vectors::VectorData::operator<<=(int);
Vectors::VectorData& Vectors::VectorData::operator~();
Vectors::VectorData& Vectors::VectorData::operator^=(int);
Vectors::VectorData& Vectors::VectorData::operator&=(int);
Vectors::VectorData& Vectors::VectorData::operator|=(int);

void Vectors::VectorData::operator() (Vectors::VectorData);
void Vectors::VectorData::operator() (initializer_list<double>);
void Vectors::VectorData::operator() (initializer_list<operations::Frac>);
void Vectors::VectorData::operator() (double,double);
void Vectors::VectorData::operator() (operations::Frac,double);

Vectors::VectorData::VectorData();
Vectors::VectorData::VectorData(initializer_list<double>);
Vectors::VectorData::VectorData(initializer_list<operations::Frac>);
Vectors::VectorData::VectorData(double,double);
Vectors::VectorData::VectorData(operations::Frac,double);
Vectors::VectorData::VectorData(Vectors::VectorData);

bool Parallel(Vectors::VectorData,Vectors::VectorData);
bool Orthogonal(Vectors::VectorData,Vectors::VectorData);
double& operator+=(double,Vectors::VectorData);
double& operator-=(double,Vectors::VectorData);
Vectors::VectorData operator+(Vectors::VectorData,Vectors::VectorData);
Vectors::VectorData operator-(Vectors::VectorData,Vectors::VectorData);
Vectors::VectorData operator*(Vectors::VectorData,double);
Vectors::VectorData operator*(double,Vectors::VectorData);
Vectors::VectorData operator/(Vectors::VectorData,double);
Vectors::VectorData operator%(Vectors::VectorData,double);
bool operator!(Vectors::VectorData);
bool operator==(Vectors::VectorData,Vectors::VectorData);
bool operator!=(Vectors::VectorData,Vectors::VectorData);

void Vectors::VectorData::Update();
		
#ifdef IOSTREAM_H
	std::ostream& operator<<(std::ostream&, const Vectors::VectorData&);
#endif
#ifdef CURSES_H
	void printw(const Vectors::VectorData&);
#endif

#endif