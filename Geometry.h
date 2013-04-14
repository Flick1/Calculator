#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <cmath>
namespace Area
{
    double Area_R(double width, double length);

    double Area_C(double radius);

    double Area_Tri(double base, double height);

    double Area_ETri(double side);

    double Area_Trap(double upperLength, double bottomLength, double height);
}

#endif // _GEOMETRY_H_
