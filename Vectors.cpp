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

using std::initializer_list;
using std::list;
using std::vector;

double Vectors::Magnitude(initializer_list<double> components){
	double toreturn=0;
	for(auto iter = components.begin(), int i=0; iter != components.end(); iter++, i++)
		toreturn += (*iter)*(*iter);
	return sqrt(toreturn);
}

double Vectors::Direction(initalizer_list<double> v, int axis1, int axis2){
	if(axis1 < 1 || axis2 < 1)	throw "Error. Invalid dimension selected.";
	else if(axis1 == axis2)	return 0;
	vector<double> vec(v);
	if(vec[axis1-1] == 0 && vec[axis2-1] > 0)	return PI__/2;
	else if(vec[axis2-1] < 0)	return -PI__/2;
	return atan(vec[axis2-1]/vec[axis1-1]);
}

double Vectors::Dot(initializer_list<double> f,initializer_list<double> s){
	list<double> first(f), second(s);
		//Ensure both vectors have the same number of components
	while(first.size() < second.size())	first.push_back(0);
	while(first.size() > second.size()) second.push_back(0);
	double toreturn = 0;
	for(auto f_iter = first.begin(), s_iter = second.begin(); f_iter != first.end(), s_iter != second.end(); f_iter++, s_iter++)
		toreturn += (*f_iter) * (*s_iter);
	return toreturn;
}
double Vectors::Dot(initializer_list<double> f,Vectors::VectorData s){
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
double Vectors::Dot(Vectors::VectorData f,initializer_list<double> s){
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
double Vectors::Dot(Vectors::VectorData f,Vectors::VectorData s){
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

Vectors::VectorData Vectors::Cross(initializer_list<double> f,initializer_list<double> s){
	
}
Vectors::VectorData Vectors::Cross(initializer_list<double>,Vectors::VectorData);
Vectors::VectorData Vectors::Cross(Vectors::VectorData,initializer_list<double>);
Vectors::VectorData Vectors::Cross(Vectors::VectorData,Vectors::VectorData);
	//Member functions
double Vectors::VectorData::Magnitude()const{return magnitude;}
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
			if(components[iter]%divisor[i] != 0)	break;
			else if(iter == components.size()-1){
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
double& Vectors::VectorData::operator[](unsigned dimension)const{
	if(dimension < 0)	throw "Error. Invalid dimension chosen.";
	else if(dimension >= components.size())	return 0;
	return components[dimension-1];
}
double& Vectors::VectorData::operator[](int dimension)const{
	if(dimension < 0)	throw "Error. Invalid dimension chosen.";
	else if(dimension >= components.size())	return 0;
	return components[dimension-1];
}
size_t Vectors::VectorData::size()const{return components.size();}
void Vectors::VectorData::Add(double newdimension){
	components.push_back(newdimension);
	Update();
}
void Vectors::VectorData::Replace(unsigned index,double newvalue){
	if(index < 0 || index > components.size())	throw "Error. Invalid dimension parameter.";
	else if(index == components.size())	components.push_back(newvalue);
	else components[index] = newvalue;
	Update();
}
void Vectors::VectorData::Replace(int index,double newvalue){
	if(index < 0 || index > components.size())	throw "Error. Invalid dimension parameter.";
	else if(index == components.size())	components.push_back(newvalue);
	else components[index] = newvalue;
	Update();
}
void Vectors::VectorData::Truncate(unsigned numtoerase){
	components.erase(components.end()-numtoerase-1, components.end()-1);
	Update();
}
void Vectors::VectorData::Truncate(int numtoerase){
	components.erase(components.end()-numtoerase-1, components.end()-1);
	Update();
}
void Vectors::VectorData::Erase(unsigned index){
	if(index < 0 || index >= components.end())	throw "Error. Index out of bounds.";
	components[index] = 0;
	Update();
}
void Vectors::VectorData::Erase(int index){
	if(index < 0 || index >= components.end())	throw "Error. Index out of bounds.";
	components[index] = 0;
	Update();
}

void Vectors::VectorData::Empty(){
	components.clear();
	directions.clear();
	r_directions.clear();
	magnitude = 0;
}

Vectors::VectorData& Vectors::VectorData::operator=(const Vectors::VectorData& rightside){
	if(this != &rightside){
		Empty();
		Transfer(rightside);
		Update();
	}
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator+=(const Vectors::VectorData& rightside){
	while(components.size() < rightside.size())	components.push_back(0);
	for(auto t_iter = components.begin(), unsigned s_iter = 0; t_iter != components.end(), s_iter < rightside.size(); t_iter++, s_iter++)
		(*t_iter) += rightside[s_iter];
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator-=(const Vectors::VectorData& rightside){
	while(components.size() < rightside.size())	components.push_back(0);
	for(auto t_iter = components.begin(), unsigned s_iter = 0; t_iter != components.end(), s_iter < rightside.size(); t_iter++, s_iter++)
		(*t_iter) -= rightside[s_iter];
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator*=(double factor){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) *= factor;
	magnitude *= factor;
}
Vectors::VectorData& Vectors::VectorData::operator/=(double factor){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) /= factor;
	magnitude /= factor;
}
Vectors::VectorData& Vectors::VectorData::operator%=(double){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) %= factor;
	magnitude %= factor;
}
Vectors::VectorData& Vectors::VectorData::operator++(){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) += 1;
	Update();
}
Vectors::VectorData& Vectors::VectorData::operator++(int dummy){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) += 1;
	Update();
}
Vectors::VectorData& Vectors::VectorData::operator--(){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) -= 1;
	Update();
}
Vectors::VectorData& Vectors::VectorData::operator--(int dummy){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) -= 1;
	Update();
}

Vectors::VectorData& Vectors::VectorData::operator>>=(int multiple){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) *= pow(2,multiple);
	magnitude *= pow(2,multiple);
}
Vectors::VectorData& Vectors::VectorData::operator<<=(int multiple){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) *= pow(2,multiple);
	magnitude *= pow(2,multiple);
}

void Vectors::VectorData::operator() (const Vectors::VectorData& newvec){
	Empty();
	Transfer(newvec);
	Update();
}
void Vectors::VectorData::operator() (initializer_list<double> newcomponents){
	Empty();
	components = newcomponents;
	Update();
}
void Vectors::VectorData::operator() (double x,double y){
	Empty();
	components.push_back(x);
	components.push_back(y);
	Update();
}

Vectors::VectorData::VectorData(){
	components.push_back(0);
	components.push_back(0);
	Update();
}
Vectors::VectorData::VectorData(initializer_list<double> li){
	components = li;
	while(components.size() < 2)	components.push_back(0);
	Update();
}
Vectors::VectorData::VectorData(double x,double y){
	components.push_back(x);
	components.push_back(y);
	Update();
}
Vectors::VectorData::VectorData(const Vectors::VectorData& tocopy){Transfer(tocopy);}

Vectors::VectorData::~VectorData(){Empty();}
	//End member functions
bool Vectors::Parallel(const Vectors::VectorData& first,const Vectors::VectorData& second){
	if(first.Unit() == second.Unit())	return true;
	else return false;
	/*	Alternative instructions:
		if(Cross(first,second).Magnitude() == 0)	return true;
		else return false;
	*/
}
bool Vectors::Orthogonal(const Vectors::VectorData& first,const Vectors::VectorData& second){
	if(Dot(first,second) == 0)	return true;
	else return false;
}
Vectors::VectorData Vectors::operator+(const Vectors::VectorData& left,const Vectors::VectorData& right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> leftside, rightside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);
		
	while(leftside.size() < rightside.size())	leftside.push_back(0);
	while(leftside.size() > rightside.size())	rightside.push_back(0);
	for(auto left_iter = leftside.begin(), auto right_iter = rightside.begin(); left_iter != leftside.end(); left_iter++, right_iter++)
		catalyst.Add((*left_iter) + (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator-(const Vectors::VectorData& left,const Vectors::VectorData& right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> leftside, rightside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);
		
	while(leftside.size() < rightside.size())	leftside.push_back(0);
	while(leftside.size() > rightside.size())	rightside.push_back(0);
	for(auto left_iter = leftside.begin(), auto right_iter = rightside.begin(); left_iter != leftside.end(); left_iter++, right_iter++)
		catalyst.Add((*left_iter) - (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator*(const Vectors::VectorData& left,double right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
		
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.Add((*left_iter) * right));
	return catalyst;
}
Vectors::VectorData Vectors::operator*(double left,const Vectors::VectorData& right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> rightside;
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);
		
	for(auto right_iter = rightside.begin(); right_iter != rightside.end(); right_iter++)
		catalyst.Add(left * (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator/(const Vectors::VectorData& left,double right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
		
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.Add((*left_iter) / right));
	return catalyst;
}
Vectors::VectorData Vectors::operator%(const Vectors::VectorData& left,double right){
	Vectors::VectorData catalyst;
		catalyst.Empty();
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
		
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.Add((*left_iter) % right));
	return catalyst;
}
bool Vectors::operator!(const Vectors::VectorData& testee){
	for(unsigned iter = 0; iter < testee.size(); iter++){
		if(testee[iter] != 0)	return false;
	}
	return true;
}
bool Vectors::operator==(const Vectors::VectorData& leftside,const Vectors::VectorData& rightside){
	if(leftside.size() != rightside.size())	return false;
	for(unsigned iter=0; iter < leftside.size(); iter++){
		if(leftside[iter] != rightside[iter])	return false;
	}
	return true;
}
bool Vectors::operator!=(const Vectors::VectorData&,const Vectors::VectorData&){
	if(leftside.size() != rightside.size())	return true;
	for(unsigned iter=0; iter < leftside.size(); iter++){
		if(leftside[iter] == rightside[iter])	return false;
	}
	return true;
}

void Vectors::VectorData::Update(){
		//Components
	while(*(components.end()-1) == 0 && components.size() > 2)
		components.erase(components.end()-1);
		//Magnitude
	double sum=0;
	for(auto iter = components.begin(); iter != components.end(); iter++)
		sum += (*iter) * (*iter);
	magnitude = sqrt(sum);
		//Directions -- Find angle between vector and plane
	directions.clear();
	for(auto axis = components.begin(); axis != components.end(); axis++)
		directions.push_back(asin((*axis)/magnitude));
		//R_directions -- Find angle between vector and axis
	r_directions.clear()
	for(auto axis = components.begin(); axis != components.end(); axis++)
		r_directions.push_back(acos((*axis)/magnitude);
}
void Vectors::VectorData::Transfer(const Vectors::VectorData& original){
		//Transfer function assumes that container members are empty
	for(auto iter = original.components.begin(); iter != original.components.end(); iter++)
		components.push_back(*iter);
		
	for(auto iter = original.directions.begin(); iter != original.directions.end(); iter++)
		directions.push_back(*iter);
		
	for(auto iter = original.r_directions.begin(); iter != original.r_directions.end(); iter++)
		r_directions.push_back(*iter);
		
	magnitude = original.magnitude;
}
		
#ifdef IOSTREAM_H
	std::ostream& Vectors::operator<<(std::ostream& output, const Vectors::VectorData& rightside){return (output << rightside.String());}
#endif
#ifdef CURSES_H
	void Vectors::printw(const Vectors::VectorData& todisplay){printw(todisplay.String());}
#endif

#endif