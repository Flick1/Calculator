#include "Operations.h"
#include "Storing.h"

double operations::subtract(double first,double second)
{
    double sum = first - second;

    Storage::store(0, sum);

    return sum;
}
