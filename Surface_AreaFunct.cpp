#include "Geometry.h"

double Surface_Area::Sphere(double radius){return 4*PI__*radius*radius;}
double Surface_Area::RPrism(double length, double width, double height){return (2*length*width + 2*height*length + 2*height*width);}
double Surface_Area::Cube(double edgelength){return 6*edgelength*edgelength;}
double Surface_Area::Cyl(double radius,double height){return (2*PI__*radius*radius + 2*PI__*radius*height);}
double Surface_Area::Pyramid(double base_square, double base_triangle, double height) {return (base_square*base_square)+(2*base_triangle*height);}
