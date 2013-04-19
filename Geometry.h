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
	   //Calculate surface area of a sphere given radius
	double Sphere(double);
	   //Calculate surface area of a rectangular prism given length, width, and height
	double RPrism(double, double, double);
	   //Calculate surface area of a cube given the length of one edge
	double Cube(double);
	   //Calculate surface area of a cylinder given radius of base and height
	double Cyl(double,double);
	   //Calculate surface area of a prism with equilateral base faces given:
	   // the length of one base side, the height, and the number of base sides
	double GeneralPrism(double,double,long int);
	   //Calculate the surface area of a pyramid with an equilateral base given:
	   // the length of one base side, the height, and the number of base sides
	double GeneralPyramid(double, double, long int);
	   //Calculate surface area of a capsule given radius and length of straight side, not total height
	double Capsule(double, double);
}

#endif // _GEOMETRY_H_
