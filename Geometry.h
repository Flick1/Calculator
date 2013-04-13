#ifndef GEOMETRY_H
#define GEOMETRY_H

  namespace Geometry{
      Area_R(double,double);  //Calculate rectangular area given height and width
      Area_C(double);   //Calculate circular area given radius
      Area_Tri(double,double);  //Calculate triangular area given height and base width
      Area_ETri(double); //Calculate equilateral triangular area given height or base width
      Area_Trap(double,double,double); //Calculate trapizoidal area given height and widths of bases
  }
  
  namespace volume{
      double vol_cube(double);
      double vol_rectC(double, double, double);
      double vol_cylin(double, double);
  }
  
  namespace Surface_Area{
    SArea_S(double);  //Calculate surface area of a sphere given radius
    SArea_R(double, double, double); //Calculate surface area of a rectangular prism given length, width, and height
    SArea_C(double);   //Calculate the surface area of a cube given length, width, or height
  }
  
#endif
