#include "Operation.h"

double Surface_Area::SArea_S(double radius){return 4*PI__*radius*radius;}
  /*
          --------------------
        /                   / |
      /                   /   |
    /                   /     |
    -------------------       /
    |                 |     / <- width
    |        height-> |   /
    |                 | /
    -------------------
        ^ length
  */
double Surface_Area::SArea_R(double length, double width, double height){return (2*length*width + 4*height*length);}
double Surface_Area::SArea_C(double edgelength){return 6*edgelength*edgelength;}
double Surface_Area::SArea_Cyl(double radius,double height){return (2*PI__*radius*radius + 2*PI__*radius*height);}
