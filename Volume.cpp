#include "Geometry.h"
#include "Constants.h"

double Volume::Cube(double edgelength)
{      //Avoid pow() to efficate runtime
    return edgelength*edgelength*edgelength;
}

double Volume::RPrism(double height, double width, double length)
{

        if (height != width || height != length) //Test if this is indeed a cuboid.
        {
            return height * width * length;
        }
        else
            throw 98;
			
    return -1;
     //Just another little note. Your function will either return the answer or throw an exception. The "return -1;"
     //line will never execute. But keep in mind that I am not telling you to remove this line. How you want your function
     //to... well... function is up to you.
}

double Volume::Cyl(double radius, double height)
{

    return radius*radius * PI__ * height;
}

double Volume::Pyra(double height, double length, double width)
{
    return Area::Rect(length, width) * height * 1/3;
}

double Volume::Cone(double height, double baseRadius)
{
    return Area::Circ(baseRadius) * height * 1/3;
}

double Volume::Sphe(double radius)
{
    return radius*radius*radius * PI__ * 4/3;
}
double Volume::GeneralPrism(double side_length, double height, long int num_side){return Area::EquilateralShape(side_length,num_side) * height;}
double Volume::GeneralPyramid(double side_length, double height, long int num_side){return Area::EquilateralShape(side_length,num_side) * height / 3;}
double Volume::PlatonicPolyhedron(double side_length, double radius, long int num_sides, long int num_facets){return Volume::GeneralPyramid(side_length, radius, num_sides) * num_facets;}