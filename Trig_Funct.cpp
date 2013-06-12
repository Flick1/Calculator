#include "Operations.h"
#include "Geometry.h"
#include "Constants.h"
#include <cmath>

double operations::Sine(double Number) {return (sin (Number*PI__/180));}
double operations::Cosine(double Number) {return (cos (Number*PI__/180));}
double operations::Tangent(double Number) {return (tan (Number*PI__/180));}
double operations::Tangent2(double Opposite, double Adjacent) {return (tan ((Opposite/Adjacent)*PI__/180));}
double operations::Square_Root(double Number) {return (sqrt(Number)); }
/**
 * Square root is not a trigonomic expression.
 *    Trigonomic expressions deal with angles
 *    such as the following trigonomic identities:
 *    (sin(x))^2 + (cos(x))^2 = 1
 *    cos(2x) = (cos(x))^2 - (sin(x))^2
 *    where x is an angle.
 *    Trigonomic expressions are usually associated
 *    with sine, cosine, tangent, cotangent, etc.
 * Also, Dreamer already wrote a square root
 *    function in his Power & Square.cpp
 *    file. Yes, I agree that his file's name
 *    isn't so clear about its contents.
**/
