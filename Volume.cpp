#include "Geometry.h"
#include <cmath>

double volume::vol_cube(double cubeHeight, double cubeWidth, double cubeLength)
{
    double cubeSum;

    try
    {
        if (height == width && height == length) //Test if this is indeed a cube.
        {
            cubeSum = height * width * length;
            return cubeSum;
        }
        else
            throw 99;
    } catch(int err) { }

    return 1;
}

double volume::vol_rectC(double rectHeight, double rectWidth, double rectLength)
{
    double rectSum;
    
    try
    {
        if (height != width || height != length) //Test if this is indeed a cuboid.
        {
            rectSum = height * width * length;
            return cubeSum;
        }
        else
            throw 98;
    } catch(int err) { }
    
    return 1;
     
}

double volume::vol_cylin(double radius, double height)
{
    double cylinSum;
    const double pi = 3.14;
    
    cylinSum = pi * pow(radius, 2) * height;
    return cylinSum;   
}
    
    

