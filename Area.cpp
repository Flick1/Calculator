#include "Geometry.h"
#include <cmath>

double Area::Rect(double width, double length)
{
    return width * length;
}

double Area::Circ(double radius)
{
    return PI__ * radius*radius;	//Avoiding pow() to efficate runtime
}

double Area::Tri(double base, double height)
{
    return base * height * 1/2;
}

double Area::EquiTri(double side)
{
    return pow(side, 2) * sqrt(3) / 4;
}

double Area::Trap(double upperLength, double bottomLength, double height)
{
    return (upperLength + bottomLength) * height * 1/2;
}

double Area::Parallelogram(double base, double height) {return base*height;}
