#include "Geometry.h"

double Surface_Area::SArea_S(double radius){return 4*PI__*radius*radius;}
double Surface_Area::SArea_R(double length, double width, double height){return (2*length*width + 2*height*length + 2*height*width);}
double Surface_Area::SArea_C(double edgelength){return 6*edgelength*edgelength;}
double Surface_Area::SArea_Cyl(double radius,double height){return (2*PI__*radius*radius + 2*PI__*radius*height);}
