#include "Geometry.h"
#include "Handler.h"
#include <iostream>

double Volume::Cube(double edgelength) //Function for passing a single length
{
    return edgelength*edgelength*edgelength; //Avoid pow() to efficate runtime
}

double Volume::RPrism(double height, double width, double length)
{
    
        //This test condition may be unnecessary because you are disallowing this function to calculate a cube's volume
        //even though this function should be for general cases
        
        //I figure it would be better to separate them completely for an accurate menu. Would there be a way to rerun 
        //this function if the condition fails?

        if (height != width || height != length) //Test if this is indeed a cuboid.
        {
            return height * width * length;
        }
        else
            throw 98;
     //I suppose this works?

    return -1;  //To let other programmers know that there was an error, return a -1 instead because logically volume cannot be negative
               //Returning a possible answer will obfuscate the error message

}

double Volume::Cyl(double radius, double height)
{

    return radius*radius * PI__ * height;
}

double Volume::Pyra(double height, double length, double width)
{
        //Please read below:
        //   The point of Flick's I/O element is to gather all the information to be passed into these functions.
        //His portion of the program will ask the user to enter in the height, length, and width and pass these parameters
        //into your function. There is no need to create another I/O point within the function. Instead, have the function take
        //three parameters: height, length, and width (depending on which order you want them).
        //   Another reason to avoid creating multiple I/O points is the conflict they will create if they use different
        //I/O methods, e.g. your iostream methods might clash with the curses methods. Debugging or modifying code will
        //also become really difficult because there are so many different points to look for and change whereas
        //choking all points into a single method will make modifications a lot simpler and less time-consuming.
        //   For example, you do no type checking in your input functions. The user could enter in letters, and the
        //local variables would then be assigned the ASCII values of the characters, which would illogically compute.
        //If height = 1:
        //      Calculating area of base. Enter length: a
        //      Enter width: j     /*** How does 1*a*j sound to you? It becomes 1*97*106 ***/
        //      The volume of your Pyramid is: 10,282 cubic units.
        //   Now, instead of revamping two or more input methods at different locations, we could fix one central input method.
        //Same goes for your cone function.
        //I hope this didn't sound too harsh.
        
        //Not at all daleth. Thanks for the explanation I actually understand why there's a need for flick to make custom
        //output and input now. Just going to leave the comment here for the time being.

    return Area::Rect(length, width) * height * 1/3;
}

double Volume::Cone(double height, double baseRadius)
{
    return Area::Circ(baseRadius) * height * 1/3;
}

double Volume::Sphe(double radius)
{
    return radius*radius*radius * PI__ * 4/3;
}
