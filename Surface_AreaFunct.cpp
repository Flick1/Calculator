#include "Geometry.h"
#include "Constants.h"

#include <cmath>

double Surface_Area::Sphere(double radius){return 4*PI__*radius*radius;}
double Surface_Area::RPrism(double length, double width, double height){return (2*length*width + 2*height*length + 2*height*width);}
double Surface_Area::Cube(double edgelength){return 6*edgelength*edgelength;}
double Surface_Area::Cyl(double radius,double height){return 2*PI__*radius*(radius + height);}
double Surface_Area::Pyramid(double base_square, double base_triangle, double height) {return (base_square*base_square)+(2*base_triangle*height);}
double Surface_Area::GeneralPrism(double side_length, double height, long int num_side){return 2 * Area::EquilateralShape(side_length, num_side) + (side_length * height * num_side);}
   //Process:
   //   1) Calculate base area with Area::EquilateralShape()
   //   2) Break up base into isoceles triangles
   //   3) Calculate height of isoceles triangle
   //   4) height parameter and isoceles triangle height form a right triangle
   //      a) Use pythagorean theorem to calculate hypotenuse, which is the pyramid's slant height
   //   5) Calculate the area of pyramid triangle faces with slant height
   //   6) Multiply area by the number of sides and add result to base area
double Surface_Area::GeneralPyramid(double side_length, double height, long int num_side){return Area::EquilateralShape(side_length, num_side) + (0.5*side_length*sqrt(height*height + 0.25*side_length*side_length/tan(PI__/num_side)/tan(PI__/num_side))*num_side);}
double Surface_Area::Capsule(double radius, double lateral_height){return Surface_Area::Sphere(radius) + 2*PI__*radius*lateral_height;}