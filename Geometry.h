#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

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
	   //Calculate volume of a general prism with equilateral bases given:
	   // the length of one base side, the height of the prism, and the number of base sides
	double GeneralPrism(double, double, long int);
	   //Calculate volume of a general pyramid with equilateral bases given:
	   // the length of one base side, the height of the pyramid, and the number of base sides
	double GeneralPyramid(double, double, long int);
	   //Calculate the volume of a general platonic polyhedron with equilateral facets and spherical form given:
	   // the length of one facet side, the radius of the polyhedron, the number of facet sides, and the number of facets
	double PlatonicPolyhedron(double, double, long int, long int);
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
	double Pyramid(double, double, double);
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
