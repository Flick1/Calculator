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
}

namespace Volume{
	double Cube(double);
	double RPrism(double,double,double);
	double Cyl(double,double);
	double Pyr(double,double,double);
}

namespace Surface_Area{
	double Sphere(double);
	double RPrism(double, double, double);
	double Cube(double);
	double Cyl(double,double);
}

#endif // _GEOMETRY_H_
