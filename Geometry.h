#ifndef GEOMETRY_H
#define GEOMETRY_H

  namespace {
    const double PI__ = 3.14159;  //Place pi in global namespace due to use in multiple modules
  }

  namespace Area{
      double Area_R(double, double);  //Calculate rectangular area given height and width
      double Area_C(double);   //Calculate circular area given radius
      double Area_Tri(double, double);  //Calculate triangular area given height and base width
      double Area_ETri(double); //Calculate equilateral triangular area given side
      double Area_Trap(double, double, double); //Calculate trapizoidal area given height and widths of bases
  }

  namespace Volume{
      double Vol_Cube(double); //Calculate volume of cube. Passed one value representing width, length and height.
      double Vol_RectC(double, double, double); //Calculate volume of cuboid given height, width and length. One variable must be different in value.
      double Vol_Cylin(double, double); //Calculate volume of cylinder given radius and height.
      double Vol_Pyra(double); //Calculate volume of pyramid given height. Calculation for base (Area of square) is requested within the definition.
      double Vol_Cone(double); //Calculate volume of cone given height. Calculation for base (Area of circle) is requested within the definition.
      double Vol_Sphe(double); //Calculate volume of sphere given radius.
  }

  namespace Surface_Area{
    double SArea_S(double);  //Calculate surface area of a sphere given radius
    double SArea_R(double, double, double); //Calculate surface area of a rectangular prism given length, width, and height
    double SArea_C(double);   //Calculate the surface area of a cube given length, width, or height
    double SArea_Cyl(double,double);  //Calculate surface area of a cylinder given radius and height
  }

#endif
