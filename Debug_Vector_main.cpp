#ifdef DEBUG_VECTOR
#include <iostream>
#define IOSTREAM_H
using namespace std;
#include "Constants.h"
#include "Vectors.h"

using namespace Vectors;

int main()
{
	try{
		cout << "Hello world!" << endl;
		VectorData Testrun({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}),
			TestAddend = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1},
			Assignment = {0}
		;
		
		cout << "Vector Testrun: " << Testrun.String() << '\n'
			<< "Vector TestAddend: " << TestAddend.String() << '\n'
			<< "Vector Assignment: " << Assignment << '\n'
			<< "Vector Testrun + TestAddend: " << (Testrun + TestAddend).String() << '\n'
			<< "Testrun[0] == " << Testrun[0] << '\n'
			<< "Testrun * 4: " << Testrun*4 << '\n'
			<< "Vector Testrun Check: " << Testrun << '\n'
			<< "Vector Testrun - TestAddend: " << Testrun-TestAddend << '\n'
			<< "Vector Testrun / 5: " << Testrun/5 << '\n'
			<< "Vector Testrun % 5: " << Testrun%5 << '\n'
			<< "Magnitude (Testrun % 5).Magnitude(): " << (Testrun%5).Magnitude() << '\n'
			<< "Dot Product Dot(Testrun,TestAddend): " << Dot(Testrun,TestAddend) << '\n'
		;
		Assignment = Testrun;
		cout << "Vector Assignment = Testrun: " << Assignment << '\n'
		<< endl
		<< "Direction tests (Direction vs. RDirection): " << endl;
		int convert = Testrun.NumDirection();
		for(int i = 0; i < convert; i++)
			cout << "Direction " << i+1 << ": " << Testrun.Direction(i) << 'v' << Testrun.RDirection(i) << '\n';
			Assignment += Testrun;
		cout << "Assignment += Testrun: " << Assignment << '\n';
			Assignment -= Testrun;
		cout << "Assignment -= Testrun: " << Assignment << '\n';
			Assignment *= 2;
		cout << "Assignment *= 2: " << Assignment << '\n';
			Assignment /= 2;
		cout << "Assignment /= 2: " << Assignment << '\n';
			Assignment %= 2;
		cout << "Assignment %= 2: " << Assignment << '\n';
			Assignment <<= 4;
		cout << "Assignment <<= 4: " << Assignment << '\n';
			Assignment >>= 3;
		cout << "Assignment >>= 3: " << Assignment << '\n';
			Assignment({1,1,1,1,1,1,1,1});
		cout << "Assignment({1,1,1,1,1,1,1,1}): " << Assignment << '\n';
		VectorData Comparison({2,2,2,2,2,2,2,2});
		cout << "Vector Comparison: " << Comparison << endl;
		cout << "Assignment parallel to Comparison: ";
		if(Parallel(Assignment,Comparison))	cout << "True" << '\n';
		else	cout << "False" << '\n';
		Comparison = Cross({Assignment,Comparison});
		cout << "Comparison = Cross(Assignment,Comparison): " << Comparison << '\n';
		cout << "Assignment orthogonal to Comparison: ";
		if(Orthogonal(Assignment,Comparison))	cout << "True" << '\n';
		else	cout << "False" << '\n';
	}catch(const char* msg){cout << '\n' << msg << endl;}
	catch(...){cout << "\nCaught unknown error." << endl;}
    return 0;
}
#endif