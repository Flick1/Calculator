#include "Geometry.h"

double Volume::Vol_Cube(double height, double width, double length)
{
    double sum;

    try
    {
        if (height == width && height == length) //Test if this is indeed a cube.
        {
            sum = height * width * length;
            return sum;
        }
        else
            throw 99;
    } catch(int err) { }

    return 1;
}
