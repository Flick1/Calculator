#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

namespace{
	const double PI__ = 3.141593;	//Pi rounded and placed in global namespace for use in multiple modules
}
namespace Area
{
    double Rect(double, double);
    double Circ(double);
    double Tri(double, double);
    double EquiTri(double);
    double Trap(double, double, double);
	double Parallelogram(double, double);
	   //Calculate area of an equilateral shape given the length of one side and the number of sides
	double EquilateralShape(double,long int);
}

namespace Volume{
	double Cube(double);
	double RPrism(double,double,double);
	double Cyl(double,double);
	double Pyra(double,double,double);
	double Cone(double, double);
	double Sphe(double);
}

namespace Surface_Area{
	double Sphere(double);
	double RPrism(double, double, double);
	double Cube(double);
	double Cyl(double,double);
	   //Calculate surface area of a prism with equilateral base faces given the length of one base side, the height, and the number of base sides
	double GeneralPrism(double,double,long int);
}

#endif // _GEOMETRY_H_
