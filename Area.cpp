#include "Geometry.h"
#include <cmath>

double Area::Area_R(double width, double length)
{
    return width * length;
}

double Area::Area_C(double radius)
{
    return PI__ * pow(radius, 2);
}

double Area::Area_Tri(double base, double height)
{
    return base * height * 1/2;
}

double Area::Area_ETri(double side)
{
    return pow(side, 2) * sqrt(3) / 4;
}

double Area::Area_Trap(double upperLength, double bottomLength, double height)
{
    return (upperLength + bottomLength) * height * 1/2;
}
