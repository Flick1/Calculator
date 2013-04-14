#include "Operations.h"
#include "Geometry.h"
#include <cmath>

double operations::Sine(double Number) {return (sin (Number*PI__/180));}
double operations::Cosine(double Number) {return (cos (Number*PI__/180));}
double operations::Tangent(double Number) {return (tan (Number*PI__/180));}
double operations::Tangent2(double Opposite, double Adjacent) {return (tan ((Opposite/Adjacent)*PI__/180));}
