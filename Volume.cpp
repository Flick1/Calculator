#include "Geometry.h"
#include "Handler.h"
#include <cmath>
#include <iostream>

double Volume::Vol_Cube(double edgelength) //Function for passing a single length
{
    return edgelength*edgelength*edgelength; //Avoid pow() to efficate runtime
}

double Volume::Vol_RectC(double height, double width, double length)
{
    try
    {
        if (height != width || height != length) //Test if this is indeed a cuboid.
        {
            return height * width * length;
        }
        else
            throw 98;
    } catch(int err) { }

    return 1;

}

double Volume::Vol_Cylin(double radius, double height)
{

    return PI__ * pow(radius, 2) * height;
}

double Volume::Vol_Pyra(double height)
{
    double length, width;

    output::print("Calculating area of base. Enter length: ");
    std::cin >> length;
    output::print("Enter width: ");
    std::cin >> width;

    return Area::Area_R(length, width) * height * 1/3; //Calling function to calculate area of square for base.
}

double Volume::Vol_Cone(double height)
{
    double baseRadius;

    output::print("Calculating area of base. Enter radius: ");
    std::cin >> baseRadius;

    return Area::Area_C(baseRadius) * height * 1/3; //Calling function to calculate area of circle for base.
}

double Volume::Vol_Sphe(double radius)
{
    return PI__ * pow(radius, 3) * 4/3;
}
