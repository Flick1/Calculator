#include "Constants.h"
/***To include
	-Need to Transfer changes from Cross(initializer_list<VectorData>) to Cross(initializer_list<initializer_list<double>>)
	-Optimize Cross and Determinant functions
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

void Vectors::Square(list<list<double>> &matrix, unsigned &componentnumber, bool complete){
	if(componentnumber == 0){
			//Check the maximum number of components in longest vector
		componentnumber = matrix.begin()->size();
		for(auto vl_iter = matrix.begin(); vl_iter != matrix.end(); vl_iter++){
			if(componentnumber < vl_iter->size())	componentnumber = vl_iter->size();
		}
	}
		//Fill vectors that are of a lower dimension
	for(auto vl_iter = matrix.begin(); vl_iter != matrix.end(); vl_iter++){
		while(vl_iter->size() < componentnumber)	vl_iter->push_back(0);
	}
		//Now check if the number of components of each row match with the number of columns
	if(matrix.size() > componentnumber){
		while(matrix.size() > componentnumber){
			for(auto iter = matrix.begin(); iter != matrix.end(); iter++)
				iter->push_back(0);
			componentnumber++;
		}
	}else if(matrix.size() < componentnumber && !complete)
		throw "Cannot square matrix built from vectors. Number of vector components does not match number of vectors.";
	else if(matrix.size() < componentnumber){
		list<double> filler;
		for(unsigned i = 0; i < componentnumber; i++)
			filler.push_back(0);
		while(matrix.size() < componentnumber)
			matrix.push_back(filler);
	}
}

double Vectors::Determinant(list<list<double>> &matrix, unsigned total_size){
	if(total_size== 0)		//Get size of matrix and ensure square matrix
		Vectors::Square(matrix,total_size,false);
	else if(total_size == 2)	//Break out of recursion
		return matrix.front().front() * matrix.back().back() - matrix.back().front() * matrix.front().back();
	if( matrix.size() == total_size){	//Calculate determinant
		double toreturn=0;
		{	//Limit scope further to encapsulate temporary variables
			list<list<double>> catalyst;
			unsigned column;
			int sign;
			auto iter=matrix.begin()->begin();
				//Create outside for loop according to number of components
			for(column=0, sign = 1; iter != matrix.begin()->end(); iter++, column++, sign *= -1){
				list<double> subcatalyst;
					//Now focusing on splicing the matrix
					//Start by pointing iterator to second row
				auto list_iter = matrix.begin();
				for(list_iter++; list_iter != matrix.end(); list_iter++){
						//Now iterator through each component of row
						//Component will be skipped according to which column is focused on
					for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
						auto itercatalyst = list_iter->begin();
						advance(itercatalyst,column);
						if(component_iter == itercatalyst)	continue;
						subcatalyst.push_back(*component_iter);
					}
					catalyst.push_back(subcatalyst);
					subcatalyst.clear();
				}
				toreturn += sign*(*iter)*Vectors::Determinant(catalyst, total_size-1);
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
	list<list<double>> vectorlist;
		//Check the number of components in longest vector
	unsigned componentnumber = veclist.begin()->size();
	for(auto vl_iter = veclist.begin(); vl_iter != veclist.end(); vl_iter++){
		if(componentnumber < vl_iter->size())	componentnumber = vl_iter->size();
	}
	{	//Push back surrogate i,j,k, vectors represented by an empty list<>.
		//List will be filled with 0's when Square is called
		list<double> subcatalyst;
		vectorlist.push_back(subcatalyst);
	}
	{	//Now transfer vectors from veclist to vectorlist
		list<double> catalyst;
		for(auto list_iter = veclist.begin(); list_iter != veclist.end(); list_iter++){
			for(auto iter = list_iter->begin(); iter != list_iter->end(); iter++)
				catalyst.push_back(*iter);
			vectorlist.push_back(catalyst);
			catalyst.clear();
		}
	}
		//Ensure all vectors have the same number of components
	Vectors::Square(vectorlist, componentnumber);
		//Perform Cross Product
	vector<double> toreturn;
	{	//Limit scope further to encapsulate temporary variables
		list<list<double>> catalyst;
		unsigned column;
		int sign;
			//Create outside for loop according to number of components
		for(column=0, sign = 1; column < vectorlist.begin()->size(); column++, sign *= -1){
			list<double> subcatalyst;
				//Now focusing on splicing the matrix
				//Start by pointing iterator to second row
			auto list_iter = vectorlist.begin();
			for(list_iter++; list_iter != vectorlist.end(); list_iter++){
					//Now iterate through each component of row
					//Component will be skipped according to which column is focused on
				for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
					auto itercatalyst = list_iter->begin();
					advance(itercatalyst,column);
					if(component_iter == itercatalyst)	continue;
					subcatalyst.push_back(*component_iter);
				}
				catalyst.push_back(subcatalyst);
				subcatalyst.clear();
			}
				//Explicity check for a result of 0 and push back 0 to avoid the -0 architect
				//Declare temporary variable to avoid calling Determinant twice and avoid overhead cost
			double coefficient = Vectors::Determinant(catalyst, componentnumber-1);
			if(coefficient == 0)	toreturn.push_back(0);
			else	toreturn.push_back(sign*coefficient);
			catalyst.clear();
		}
	}
	return toreturn;
}
Vectors::VectorData Vectors::Cross(initializer_list<Vectors::VectorData> veclist){
	list<list<double>> vectorlist;
		//Check the number of components in longest vector
	unsigned componentnumber = veclist.begin()->size();
	for(auto vl_iter = veclist.begin(); vl_iter != veclist.end(); vl_iter++){
		if(componentnumber < vl_iter->size())	componentnumber = vl_iter->size();
	}
	{	//Push back surrogate i,j,k, vectors represented by an empty list<>.
		//List will be filled with 0's when Square is called
		list<double> subcatalyst;
		vectorlist.push_back(subcatalyst);
	}
	{	//Now transfer vectors from veclist to vectorlist
		list<double> catalyst;
		for(auto list_iter = veclist.begin(); list_iter != veclist.end(); list_iter++){
			for(unsigned iter = 0; iter < list_iter->size(); iter++)
				catalyst.push_back((*list_iter)[iter]);
			vectorlist.push_back(catalyst);
			catalyst.clear();
		}
	}
		//Ensure all vectors have the same number of components
	Vectors::Square(vectorlist, componentnumber);
		//Perform Cross Product
	vector<double> toreturn;
	{	//Limit scope further to encapsulate temporary variables
		list<list<double>> catalyst;
		unsigned column;
		int sign;
			//Create outside for loop according to number of components
		for(column=0, sign = 1; column < vectorlist.begin()->size(); column++, sign *= -1){
			list<double> subcatalyst;
				//Now focusing on splicing the matrix
				//Start by pointing iterator to second row
			auto list_iter = vectorlist.begin();
			for(list_iter++; list_iter != vectorlist.end(); list_iter++){
					//Now iterator through each component of row
					//Component will be skipped according to which column is focused on
				for(auto component_iter = list_iter->begin(); component_iter != list_iter->end(); component_iter++){
					auto itercatalyst = list_iter->begin();
					advance(itercatalyst,column);
					if(component_iter == itercatalyst)	continue;
					subcatalyst.push_back(*component_iter);
				}
				catalyst.push_back(subcatalyst);
				subcatalyst.clear();
			}
				//Explicity check for a result of 0 and push back 0 to avoid the -0 architect
				//Declare temporary variable to avoid calling Determinant twice and avoid overhead cost
			double coefficient = Vectors::Determinant(catalyst, componentnumber-1);
			if(coefficient == 0)	toreturn.push_back(0);
			else	toreturn.push_back(sign*coefficient);
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
	for(;numtoerase > 0;numtoerase--)
		components.pop_back();
	Update();
}
void Vectors::VectorData::Truncate(int numtoerase){
	for(;numtoerase > 0;numtoerase--)
		components.pop_back();
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
	for(unsigned iter = 0; iter < left.size(); iter++)
		catalyst.push_back(left[iter] * right);
	return catalyst;
}
Vectors::VectorData Vectors::operator*(double left,const Vectors::VectorData& right){
	vector<double> catalyst;
	for(unsigned iter = 0; iter < right.size(); iter++)
		catalyst.push_back(right[iter] * left);
	return catalyst;
}
Vectors::VectorData Vectors::operator/(const Vectors::VectorData& left,double right){
	vector<double> catalyst;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		catalyst.push_back(left[l_iter] / right);
	return catalyst;
}
Vectors::VectorData Vectors::operator%(const Vectors::VectorData& left,int right){
	vector<double> catalyst;
	int convert;
	for(unsigned l_iter = 0; l_iter < left.size(); l_iter++)
		catalyst.push_back((convert = left[l_iter]) % right);
	return catalyst;
}
Vectors::VectorData Vectors::operator>>(const Vectors::VectorData& left, int right){
	vector<double> toreturn;
	for(unsigned i=0; i < left.size(); i++)
		toreturn.push_back(left[i] * pow(2,right));
	return toreturn;
}
Vectors::VectorData Vectors::operator<<(const Vectors::VectorData& left, int right){
	vector<double> toreturn;
	for(unsigned i=0; i < left.size(); i++)
		toreturn.push_back(left[i] / pow(2,right));
	return toreturn;
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
	while(components.back() == 0 && components.size() > 2)
		components.pop_back();
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