#include "Operations.h"
#include "Storage.h"
    //Storing.h or Storage.h? :3
    //Should be Storage.h =p.

double operations::subtract(double first,double second)
{
    double sum = first - second;

    Storage::store(0, sum);

    return sum;
}
