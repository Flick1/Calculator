#ifndef GEOMETRY_H
#define GEOMETRY_H

  namespace area{
      Area_R(double,double);  //Calculate rectangular area given height and width
      Area_C(double);   //Calculate circular area given radius
      Area_Tri(double,double);  //Calculate triangular area given height and base width
      Area_ETri(double); //Calculate equilateral triangular area given height or base width
      Area_Trap(double,double,double); //Calculate trapizoidal area given height and widths of bases
  }
  
  namespace volume{
      double vol_cube(double, double, double);
      double vol_rectC(double, double, double);
      double vol_cylin(double, double);
  }
  
#endif
