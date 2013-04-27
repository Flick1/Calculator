#include "Constants.h"
/***To include
	-Fix Cross functions
	-Test and fix determinant function
	-overloaded functions for other STL container parameters
		-Perhaps use a templated function since most containers work the same
		-If template is used, figure out how to handle non-container parameters
	-Overloaded functions for array parameters
		-Both 1 and 2D
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
using std::stringstream;

void Vectors::Square(list<list<double>> &matrix, unsigned &toreturn, bool complete){
	toreturn = (*(matrix.begin())).size();
	for(auto vl_iter = matrix.begin(); vl_iter != matrix.end(); vl_iter++){
		if((*vl_iter).size() < (*(vl_iter++)).size())	toreturn = (*(vl_iter)).size();
		vl_iter--;
	}
	for(auto vl_iter = matrix.begin(); vl_iter != matrix.end(); vl_iter++){
		while((*vl_iter).size() < toreturn)	(*vl_iter).push_back(0);
	}
		//Now check if the number of components of each row match with the number of columns
	if(matrix.size() > toreturn){
		while(matrix.size() > toreturn){
			for(auto iter = matrix.begin(); iter != matrix.end(); iter++)
				(*iter).push_back(0);
			toreturn++;
		}
	}else if(matrix.size() < toreturn && !complete)	throw "Cannot square matrix built from vectors. Number of vector components does not match number of vectors.";
	else{
		list<double> filler;
		for(unsigned i = 0; i < toreturn; i++)
			filler.push_back(0);
		while(matrix.size() < toreturn)
			matrix.push_back(filler);
	}
}

double Vectors::Determinant(list<list<double>> &matrix, unsigned total_size){
		if(total_size== 0)		//Get size of matrix and ensure square matrix
			Vectors::Square(matrix,total_size,false);
		else if(total_size == 4)	//Break out of recursion
			return (*(matrix.begin()->begin())) * (*((matrix.end()--)->end()--)) - (*((matrix.begin()++)->begin())) * (*((matrix.end()--)->begin()));
	if( matrix.size() == total_size){	//Calculate determinant
		double toreturn=0;
		int sign=-1;
		total_size--;
		{	//Limit scope further to encapsulate for loop variables
			list<list<double>> catalyst;
			auto iter=matrix.begin()->begin();
			int column;
			for(column=0; iter != matrix.begin()->end(); iter++, column++){
				list<double> subcatalyst;
				sign *= -1;
				for(auto list_iter = matrix.begin(); list_iter != matrix.end(); list_iter++){
					for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
						auto itercatalyst = list_iter->begin();
						advance(itercatalyst,column);
						if(component_iter == itercatalyst)	continue;
						subcatalyst.push_back(*component_iter);
					}
					catalyst.push_back(subcatalyst);
					subcatalyst.clear();
				}
				toreturn += sign*(*iter)*Vectors::Determinant(catalyst, total_size);
				catalyst.clear();
			}
		}
		return toreturn;
	}else	throw "Matrix is not of square size. Unable to calculate determinant.";
}

double Vectors::Magnitude(initializer_list<double> components){
	double toreturn=0;
	{
		auto iter = components.begin();
		int i;
		for(i=0; iter != components.end(); iter++, i++)
			toreturn += (*iter)*(*iter);
	}
	return sqrt(toreturn);
}

double Vectors::Direction(initializer_list<double> v, int axis1, int axis2){
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
double Vectors::Dot(initializer_list<double> f,const Vectors::VectorData& s){
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
double Vectors::Dot(const Vectors::VectorData& f,initializer_list<double> s){
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
double Vectors::Dot(const Vectors::VectorData& f,const Vectors::VectorData& s){
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

Vectors::VectorData Vectors::Cross(initializer_list<initializer_list<double>> veclist){
	list<double> catalyst;
	list<list<double>> vectorlist;
	for(auto list_iter = veclist.begin(); list_iter != veclist.end(); list_iter++){
		for(auto iter = list_iter->begin(); iter != list_iter->end(); iter++)
			catalyst.push_back(*iter);
		vectorlist.push_back(catalyst);
	}
	unsigned maximum_size = 0;
		//Ensure all vectors have the same number of components
	Vectors::Square(vectorlist,maximum_size);
		//Perform Cross Product
	vector<double> toreturn;
	{	//Limit scope further to encapsulate temporary variables
		list<list<double>> catalyst;
		auto iter=vectorlist.begin()->begin();
		int column, sign;
		for(column=0, sign = -1; iter != vectorlist.begin()->end(); iter++, column++, sign *= -1){
			list<double> subcatalyst;
			for(auto list_iter = vectorlist.begin(); list_iter != vectorlist.end(); list_iter++){
				for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
					auto itercatalyst = list_iter->begin();
					advance(itercatalyst,column);
					if(component_iter == itercatalyst)	continue;
					subcatalyst.push_back(*component_iter);
				}
				catalyst.push_back(subcatalyst);
				subcatalyst.clear();
			}
			toreturn.push_back(sign*Vectors::Determinant(catalyst, catalyst.size()));
			catalyst.clear();
		}
	}
	return toreturn;
}
Vectors::VectorData Vectors::Cross(initializer_list<Vectors::VectorData> veclist){
	list<double> catalyst;
	list<list<double>> vectorlist;
	for(auto list_iter = veclist.begin(); list_iter != veclist.end(); list_iter++){
		for(unsigned iter = 0; iter < (*list_iter).size(); iter++)
			catalyst.push_back((*list_iter)[iter]);
		vectorlist.push_back(catalyst);
	}
	unsigned maximum_size = 0;
		//Ensure all vectors have the same number of components
	Vectors::Square(vectorlist,maximum_size);
		//Perform Cross Product
	vector<double> toreturn;
	{	//Limit scope further to encapsulate temporary variables
		list<list<double>> catalyst;
		auto iter=vectorlist.begin()->begin();
		int column, sign;
		for(column=0, sign = -1; iter != vectorlist.begin()->end(); iter++, column++, sign *= -1){
			list<double> subcatalyst;
			for(auto list_iter = vectorlist.begin(); list_iter != vectorlist.end(); list_iter++){
				for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
					auto itercatalyst = list_iter->begin();
					advance(itercatalyst,column);
					if(component_iter == itercatalyst)	continue;
					subcatalyst.push_back(*component_iter);
				}
				catalyst.push_back(subcatalyst);
				subcatalyst.clear();
			}
			toreturn.push_back(sign*Vectors::Determinant(catalyst, catalyst.size()));
			catalyst.clear();
		}
	}
	return toreturn;
}

	//Member functions
double Vectors::VectorData::Magnitude()const{return magnitude;}
double Vectors::VectorData::Direction(int index)const{
	int convert = directions.size()-1;
	if(index < 0 || index > convert)	throw "Invalid dimension.";
	return directions[index];
}
double Vectors::VectorData::RDirection(int index)const{
	int convert = r_directions.size()-1;
	if(index < 0 || index > convert)	throw "Invalid dimension.";
	return r_directions[index];
}
size_t Vectors::VectorData::NumDirection()const{	return directions.size();}
std::string Vectors::VectorData::String()const{
	std::string toreturn = "< ";
	for(auto iter = components.begin(); iter != components.end(); iter++){
		std::stringstream ss;
			ss << (*iter);
		toreturn += ss.str();
		if(iter != components.end()-1)	toreturn += ", ";
	}
	toreturn += " >";
	if(Zero__ != 0){
		toreturn += "\tOut-of-bounds Garbage collector: ";
		stringstream ss;
			ss << Zero__;
		toreturn += ss.str();
	}
	return toreturn;
}
Vectors::VectorData Vectors::VectorData::Unit()const{
	Vectors::VectorData catalyst = (*this);
	for(unsigned i=0; i < divisor_size; i++){
		for(size_t iter = 0; iter < components.size(); iter++){
			int componentcatalyst = components[iter];
			if(componentcatalyst%divisor[i] != 0)	break;
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
	else if(dimension > components.size())	return Zero__;
	return components[dimension-1];
}
double& Vectors::VectorData::operator[](size_t dimension){
	if(dimension < 0)	throw "Error. Invalid dimension chosen.";
	else if(dimension > components.size()-1)	return Zero__;
	return components[dimension];
}
double& Vectors::VectorData::operator[](size_t dimension)const{
	if(dimension < 0 || dimension > components.size()-1)	throw "Error. Invalid dimension chosen.";
	static double hold;
		hold = components[dimension];
	return hold;
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
	int convert = components.size();
	if(index < 0 || index > convert)	throw "Error. Invalid dimension parameter.";
	else if(index == convert)	components.push_back(newvalue);
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
	if(index < 0 || index >= components.size())	throw "Error. Index out of bounds.";
	components[index] = 0;
	Update();
}
void Vectors::VectorData::Erase(int index){
	int convert = components.size();
	if(index < 0 || index >= convert)	throw "Error. Index out of bounds.";
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
	if(this == &rightside){
		for(auto iter = components.begin(); iter != components.end(); iter++)
			(*iter) *= 2;
	}else{
		while(components.size() < rightside.size())	components.push_back(0);
		{
			auto t_iter = components.begin();
			unsigned s_iter;
			for(s_iter = 0; t_iter != components.end(), s_iter < rightside.size(); t_iter++, s_iter++)
				(*t_iter) += rightside[s_iter];
		}
	}
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator-=(const Vectors::VectorData& rightside){
	if(this == &rightside){
		*this = {0};
	}else{
		while(components.size() < rightside.size())	components.push_back(0);
		{
			auto t_iter = components.begin();
			unsigned s_iter;
			for(s_iter = 0; t_iter != components.end(), s_iter < rightside.size(); t_iter++, s_iter++)
				(*t_iter) -= rightside[s_iter];
		}
	}
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator*=(double factor){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) *= factor;
	magnitude *= factor;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator/=(double factor){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) /= factor;
	magnitude /= factor;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator%=(int factor){
	int convert;
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) = (convert = (*iter))%factor;
	magnitude = (convert = magnitude)%factor;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator++(){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) += 1;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator++(int dummy){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) += 1;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator--(){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) -= 1;
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator--(int dummy){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) -= 1;
	Update();
	return *this;
}

Vectors::VectorData& Vectors::VectorData::operator>>=(int multiple){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) /= pow(2,multiple);
	magnitude /= pow(2,multiple);
	Update();
	return *this;
}
Vectors::VectorData& Vectors::VectorData::operator<<=(int multiple){
	for(auto iter = components.begin(); iter != components.end(); iter++)
		(*iter) *= pow(2,multiple);
	magnitude *= pow(2,multiple);
	Update();
	return *this;
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
	Zero__ = 0;
	Update();
}
Vectors::VectorData::VectorData(initializer_list<double> li){
	components = li;
	while(components.size() < 2)	components.push_back(0);
	Zero__ = 0;
	Update();
}
Vectors::VectorData::VectorData(double x,double y){
	components.push_back(x);
	components.push_back(y);
	Zero__ = 0;
	Update();
}
Vectors::VectorData::VectorData(vector<double> input){
	for(auto iter = input.begin(); iter != input.end(); iter++)
		components.push_back(*iter);
	Zero__ = 0;
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
	vector<double> catalyst;
	list<double> leftside, rightside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);

	while(leftside.size() < rightside.size())	leftside.push_back(0);
	while(leftside.size() > rightside.size())	rightside.push_back(0);
	for(auto left_iter = leftside.begin(), right_iter = rightside.begin(); left_iter != leftside.end(); left_iter++, right_iter++)
		catalyst.push_back((*left_iter) + (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator-(const Vectors::VectorData& left,const Vectors::VectorData& right){
	vector<double> catalyst;
	list<double> leftside, rightside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);
		
	while(leftside.size() < rightside.size())	leftside.push_back(0);
	while(leftside.size() > rightside.size())	rightside.push_back(0);
	for(auto left_iter = leftside.begin(), right_iter = rightside.begin(); left_iter != leftside.end(); left_iter++, right_iter++)
		catalyst.push_back((*left_iter) - (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator*(const Vectors::VectorData& left,double right){
	vector<double> catalyst;
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
		
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.push_back((*left_iter) * right);
	return catalyst;
}
Vectors::VectorData Vectors::operator*(double left,const Vectors::VectorData& right){
	vector<double> catalyst;
	list<double> rightside;
	for(unsigned r_iter = 0; r_iter < right.size(); r_iter++)
		rightside.push_back(right[r_iter]);
		
	for(auto right_iter = rightside.begin(); right_iter != rightside.end(); right_iter++)
		catalyst.push_back(left * (*right_iter));
	return catalyst;
}
Vectors::VectorData Vectors::operator/(const Vectors::VectorData& left,double right){
	vector<double> catalyst;
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
		
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.push_back((*left_iter) / right);
	return catalyst;
}
Vectors::VectorData Vectors::operator%(const Vectors::VectorData& left,int right){
	vector<double> catalyst;
	list<double> leftside;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		leftside.push_back(left[l_iter]);
	int convert;
	for(auto left_iter = leftside.begin(); left_iter != leftside.end(); left_iter++)
		catalyst.push_back((convert = (*left_iter)) % right);
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
bool Vectors::operator!=(const Vectors::VectorData& leftside,const Vectors::VectorData& rightside){
	if(leftside.size() != rightside.size())	return true;
	for(unsigned iter=0; iter < leftside.size(); iter++){
		if(leftside[iter] != rightside[iter])	return true;
	}
	return false;
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
		//Directions -- Find angle between vector and axis
	directions.clear();
	for(auto axis = components.begin(); axis != components.end(); axis++)
		directions.push_back(acos((*axis)/magnitude));
		//R_directions -- Find angle between vector and plane
	r_directions.clear();
	for(auto axis = components.begin(); axis != components.end(); axis++)
		r_directions.push_back(asin((*axis)/magnitude));
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