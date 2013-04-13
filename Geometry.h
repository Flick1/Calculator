#ifndef GEOMETRY_H
#define GEOMETRY_H

  namespace Geometry{
      double Area_R(double,double);  //Calculate rectangular area given height and width
      double Area_C(double);   //Calculate circular area given radius
      double Area_Tri(double,double);  //Calculate triangular area given height and base width
      double Area_ETri(double); //Calculate equilateral triangular area given height or base width
      double Area_Trap(double,double,double); //Calculate trapizoidal area given height and widths of bases
  }
  
  namespace volume{
      double vol_cube(double);
      double vol_rectC(double, double, double);
      double vol_cylin(double, double);
  }
  
  #define PI__ 3.14159;  //Place pi in global namespace due to use in multiple modules
  namespace Surface_Area{
    double SArea_S(double);  //Calculate surface area of a sphere given radius
    double SArea_R(double, double, double); //Calculate surface area of a rectangular prism given length, width, and height
    double SArea_C(double);   //Calculate the surface area of a cube given length, width, or height
    double SArea_Cyl(double,double);  //Calculate surface area of a cylinder given radius and height
  }
  
#endif
