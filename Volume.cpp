#include "Geometry.h"

double Volume::Vol_Cube(double cubeHeight, double cubeWidth, double cubeLength)
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

double Volume::Vol_RectC(double rectHeight, double rectWidth, double rectLength)
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
