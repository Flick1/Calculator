#include "Geometry.h"
#include <cmath>

double volume::vol_cube(double edgelength){  //Function for passing a single length
    return edgelength*edgelength*edgelength; //Avoid pow() to efficate runtime
}

double volume::vol_rectC(double rectHeight, double rectWidth, double rectLength)
{
    double rectSum;
    
    try
    {
        if (rectHeight != rectWidth || rectHeight != rectLength) //Test if this is indeed a cuboid.
        {
            rectSum = rectHeight * rectWidth * rectLength;
            return rectSum;
        }
        else
            throw 98;
    } catch(int err) { }
    
    return 1;
     
}

double volume::vol_cylin(double radius, double height)
{
    double cylinSum;
    
    cylinSum = PI__ * pow(radius, 2) * height;
    return cylinSum;   
}
    
    

