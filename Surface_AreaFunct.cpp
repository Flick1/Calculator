#include "Operation.h"

double Surface_Area::SArea_S(double radius){
    const double pi = 3.14159;  //Explicitly declare pi to allow future editing for further accuracy
    return 4*pi*radius*radius*radius/3;  //Ignore pow() since exponent is constant
}
double Surface_Area::SArea_R(double length, double width, double height){return (2*length*width + 4*height*width);}
double Surface_Area::SArea_C(double edgelength){return 6*edgelength*edgelength;}
