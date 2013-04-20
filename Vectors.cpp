#ifdef DEBUG_VECTORS

#include "Operations.h"
#include "Geometry.h"
/***To include
	-overloaded functions for other STL container parameters
		-Perhaps use a templated function since most containers work the same
		-If template is used, figure out how to handle non-container parameters
***/
#include "Vectors.h"

#include <initializer_list>
#include <vector>
#include <cmath>
#include <list>
#include <iterator>
#include <sstream>

double Magnitude(initializer_list<double> components){
	double toreturn=0;
	for(auto iter = components.begin(), int i=0; iter != components.end(); iter++, i++)
		toreturn += (*iter)*(*iter);
	return sqrt(toreturn);
}

double Direction(initalizer_list<double> v, int axis1, int axis2){
	if(axis1 < 1 || axis2 < 1)	throw "Error. Invalid dimension selected.";
	else if(axis1 == axis2)	return 0;
	vector<double> vec(v);
	if(vec[axis1-1] == 0 && vec[axis2-1] > 0)	return PI__/2;
	else if(vec[axis2-1] < 0)	return -PI__/2;
	return atan(vec[axis2-1]/vec[axis1-1]);
}

double Dot(initializer_list<double> f,initializer_list<double> s){
	list<double> first(f), second(s);
		//Ensure both vectors have the same number of components
	while(first.size() < second.size())	first.push_back(0);
	while(first.size() > second.size()) second.push_back(0);
	double toreturn = 0;
	for(auto f_iter = first.begin(), s_iter = second.begin(); f_iter != first.end(), s_iter != second.end(); f_iter++, s_iter++)
		toreturn += (*f_iter) * (*s_iter);
	return toreturn;
}
double Dot(initializer_list<double> f,Vectors::VectorData s){
	list<double> first(f), second;
	for(unsigned s_iter = 0; s_iter < s.size(); s_iter++)
		second.push_back(s[s_iter]);
		//Ensure both vectors have the same number of components
	while(first.size() < second.size())	first.push_back(0);
	while(first.size() > second.size()) second.push_back(0);
	double toreturn = 0;
	for(auto f_iter = first.begin(), s_iter = second.begin(); f_iter != first.end(), s_iter != second.end(); f_iter++, s_iter++)
		toreturn += (*f_iter) * (*s_iter);
	return toreturn;
}
double Dot(Vectors::VectorData f,initializer_list<double> s){
	list<double> first, second(s);
	for(unsigned f_iter = 0; f_iter < f.size(); f_iter++)
		first.push_back(f[f_iter]);
		//Ensure both vectors have the same number of components
	while(first.size() < second.size())	first.push_back(0);
	while(first.size() > second.size()) second.push_back(0);
	double toreturn = 0;
	for(auto f_iter = first.begin(), s_iter = second.begin(); f_iter != first.end(), s_iter != second.end(); f_iter++, s_iter++)
		toreturn += (*f_iter) * (*s_iter);
	return toreturn;
}
double Dot(Vectors::VectorData f,Vectors::VectorData s){
	list<double> first, second;
	for(unsigned f_iter = 0; f_iter < f.size(); f_iter++)
		first.push_back(f[f_iter]);
	for(unsigned s_iter = 0; s_iter < s.size(); s_iter++)
		second.push_back(s[s_iter]);
		//Ensure both vectors have the same number of components
	while(first.size() < second.size())	first.push_back(0);
	while(first.size() > second.size()) second.push_back(0);
	double toreturn = 0;
	for(auto f_iter = first.begin(), s_iter = second.begin(); f_iter != first.end(), s_iter != second.end(); f_iter++, s_iter++)
		toreturn += (*f_iter) * (*s_iter);
	return toreturn;
}

Vectors::VectorData Cross(initializer_list<double> f,initializer_list<double> s){
	
}
Vectors::VectorData Cross(initializer_list<double>,Vectors::VectorData);
Vectors::VectorData Cross(Vectors::VectorData,initializer_list<double>);
Vectors::VectorData Cross(Vectors::VectorData,Vectors::VectorData);

double Vectors::VectorData::Magnitude()const{
	double toreturn=0;
	for(auto iter = components.begin(); iter != components.end(); iter++)
		toreturn += (*iter) * (*iter);
	return sqrt(toreturn);
}
double Vectors::VectorData::Direction(int axis1, int axis2)const{
	if(axis1 < 1 || axis2 < 1)	throw "Error. Invalid dimension selected.";
	else if(axis1 == axis2)	return 0;
	else if(components[axis1-1] == 0 && components[axis2-1] > 0)	return PI__/2;
	else if(components[axis2-1] < 0)	return -PI__/2;
	return atan(components[axis2-1]/components[axis1-1]);
}
std::string Vectors::VectorData::String()const{
	std::string toreturn = "< ";
	for(auto iter = components.begin(); iter != components.end(); iter++){
		std::stringstream ss;
			ss << (*iter);
		toreturn += ss.str();
		toreturn += ", ";
	}
	toreturn += " >";
	return toreturn;
}
Vectors::VectorData Vectors::VectorData::Unit(){
	Vectors::Vector Data catalyst(*this);
		//List of prime numbers for simplifying the vector components
	int divisor[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59};
	
	for(int i=0; i < GAL(divisor); i++){
		for(size_t iter = 0; iter < components.size(); iter++){
			if(components[iter]%divisor[i] != 0){
				break;
			}else if(iter == components.size()-1){
				for(size_t iter2 = 0; iter2 < components.size(); iter2++)
					catalyst.components[iter2] = components[iter2] / divisor[i];
			}
		}
	}
	return catalyst;
}

double Vectors::VectorData::Component(unsigned dimension)const{
	if(dimension < 1)	throw "Error. Invalid dimension chosen.";
	else if(dimension > components.size())	return 0;
	return components[dimension-1];
}
double Vectors::VectorData::operator[](unsigned dimension)const{
	if(dimension < 0)	throw "Error. Invalid dimension chosen.";
	else if(dimension >= components.size())	return 0;
	return components[dimension-1];
}
double Vectors::VectorData::operator[](int dimension)const{
	if(dimension < 0)	throw "Error. Invalid dimension chosen.";
	else if(dimension >= components.size())	return 0;
	return components[dimension-1];
}
size_t Vectors::VectorData::size()const{return components.size();}
void Vectors::VectorData::Add(double newdimension){components.push_back(newdimension);}
void Vectors::VectorData::Replace(unsigned index,double newvalue){
	if(index < 0 || index > components.size())	throw "Error. Invalid dimension parameter.";
	else if(index == components.size())	components.push_back(newvalue);
	else components[index] = newvalue;
}
void Vectors::VectorData::Replace(int index,double newvalue){
	if(index < 0 || index > components.size())	throw "Error. Invalid dimension parameter.";
	else if(index == components.size())	components.push_back(newvalue);
	else components[index] = newvalue;
}
void Vectors::VectorData::Truncate(unsigned numtoerase){components.erase(components.end()-numtoerase-1, components.end()-1);}
void Vectors::VectorData::Truncate(int numtoerase){components.erase(components.end()-numtoerase-1, components.end()-1);}
void Vectors::VectorData::Erase(unsigned index){
	if(index < 0 || index >= components.end())	throw "Error. Index out of bounds.";
	components[index] = 0;
}
void Vectors::VectorData::Erase(int index){
	if(index < 0 || index >= components.end())	throw "Error. Index out of bounds.";
	components[index] = 0;
}

Vectors::VectorData& Vectors::VectorData::operator=(const Vectors::VectorData& rightside){
	if(this
	while(components.size() < rightside.size())	components.push_back(0);
	while(components.size() > rightside.size())	rightside.Add(0);
	for(unsigned iter=0; iter < components.size(); iter++)
		components[iter] = rightside[iter];
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator+=(const Vectors::VectorData&);
Vectors::VectorData& Vectors::VectorData::operator-=(const Vectors::VectorData&);
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

void Vectors::VectorData::operator() (const Vectors::VectorData&);
void Vectors::VectorData::operator() (initializer_list<double>);
void Vectors::VectorData::operator() (double,double);

Vectors::VectorData::VectorData(){
	components.push_back(0);
	components.push_back(0);
}
Vectors::VectorData::VectorData(initializer_list<double> li){
	components = li;
	while(components.size() < 2)	components.push_back(0);
}
Vectors::VectorData::VectorData(double x,double y){
	components.push_back(x);
	components.push_back(y);
}
Vectors::VectorData::VectorData(const Vectors::VectorData& tocopy){
	if(
}

bool Parallel(const Vectors::VectorData&,const Vectors::VectorData&);
bool Orthogonal(const Vectors::VectorData&,const Vectors::VectorData&);
double& operator+=(double,const Vectors::VectorData&);
double& operator-=(double,const Vectors::VectorData&);
Vectors::VectorData operator+(const Vectors::VectorData&,const Vectors::VectorData&);
Vectors::VectorData operator-(const Vectors::VectorData&,const Vectors::VectorData&);
Vectors::VectorData operator*(const Vectors::VectorData&,double);
Vectors::VectorData operator*(double,const Vectors::VectorData&);
Vectors::VectorData operator/(const Vectors::VectorData&,double);
Vectors::VectorData operator%(const Vectors::VectorData&,double);
bool operator!(const Vectors::VectorData&);
bool operator==(const Vectors::VectorData&,const Vectors::VectorData&);
bool operator!=(const Vectors::VectorData&,const Vectors::VectorData&);

void Vectors::VectorData::Update(){
	auto iter = components.rbegin();
	while(iter != components.rend() + 2){
		if((*iter) == 0){
			iter++;
			components.erase(components.end()-1)
		}else	return;
	}	
}
		
#ifdef IOSTREAM_H
	std::ostream& operator<<(std::ostream&, const Vectors::VectorData&);
#endif
#ifdef CURSES_H
	void printw(const Vectors::VectorData&);
#endif

#endif