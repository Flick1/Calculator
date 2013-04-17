#include "Operations.h"
#include "Storing.h"
    //Storing.h or Storage.h? :3

double operations::subtract(double first,double second)
{
    double sum = first - second;

    Storage::store(0, sum);

    return sum;
}
