#include "Operations.h"
#include <cmath>

double operations::Logarithm_Natural(double number){return log(number);}
double operations::Logarithm_Base10(double number){return log10(number);}
double operations::Logarithm(double base, double number){return (log(number))/(log(base));}
