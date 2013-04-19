#include "Geometry.h"

#include <cmath>

double Area::Rect(double width, double length)
{
    return width * length;
}

double Area::Circ(double radius)
{
    return PI__ * radius*radius;	//Avoiding pow() to efficate runtime
}

double Area::Tri(double base, double height)
{
    return base * height * 1/2;
}

double Area::EquiTri(double side)
{
    return side*side * sqrt(3) / 4; //Removed use of pow.
}

double Area::Trap(double upperLength, double bottomLength, double height)
{
    return (upperLength + bottomLength) * height * 1/2;
}

double Area::Parallelogram(double base, double height) {return base*height;}

	//Process:
	//   1) Break up shape into isoceles triangles by cutting from corners to their opposites
	//   2) Split isoceles triangles into two halves
	//   3) Find height of triangle
	//      a) height = 0.5 * opposite[side_length]/tan(theta)
	//         i) theta = PI__ radians / number of sides[num_side] / 2
	//   4) Calculate area of full isoceles triangle
	//      a) Area Partition = 2/2 * (0.5*side_length) * height
	//   5) Now multiply by number of sides, which is also the number of triangle partitions
	//      a) Final Area = Area Partition * number of sides
double Area::EquilateralShape(double side_length, long int num_side){
	if(num_side < 3)	throw "Error. Impossible shape with less than three sides.";
	return 0.25 * side_length/tan(PI__/num_side) * side_length * num_side;
}