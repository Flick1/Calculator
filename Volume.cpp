#include "Geometry.h"
#include "Handler.h"
#include <iostream>   //<--Don't forget to remove this

double Volume::Cube(double edgelength)
{      //Avoid pow() to efficate runtime
    return edgelength*edgelength*edgelength;
}

double Volume::RPrism(double height, double width, double length)
{
    
        //This test condition may be unnecessary because you are disallowing this function to calculate a cube's volume
        //even though this function should be for general cases
        
        //I figure it would be better to separate them completely for an accurate menu. Would there be a way to rerun 
        //this function if the condition fails?
        
        //   I see this function like a rectangle (or a quadrilateral shape if you want to use the  correct classification)
        //because it covers a broad range as a general case. Then the Cube function above is like a square, a special case 
        //of a rectangle that happens to have four sides of equal length. A rectangle can be a square but the opposite 
        //is untrue. Sometimes, letting the general case be general is better than restricting its functionality.
        //   To answer your question, yes there is. Take the following code inside a main function into consideration:
        //do{
        //   try{
        //      int x,y,z;
        //      std::cout << "Please enter the dimensions of a rectangular prism, pressing ENTER after each one: "
        //         << "\n\nFirst dimension: ";
        //         std::cin >> x;
        //         std::cout << "\n\nSecond dimension: ";
        //         std::cin >> y;
        //         std::cout << "\n\nThird dimension: ";
        //         std::cin >> z;
        //      double volume = Volume::RPrism(x,y,z);
        //      std::cout << "\n\nVolume is: " << volume << std::endl;
        //   }catch(int err){
        //      std::cout << "Uh-oh, looks like you entered in a cube! Please enter in the dimensions of "
        //         << "a rectangular prism that is NOT a cube..." << std::endl;
        //      //return err;
        //   }
        //}while(true);
        //   Here, when x, y, and z are equivalent, Volume::RPrism will throw an exception to be caught and displayed.
        //However, because the try/catch block is within a do/while block, the code will run another iteration. The 
        //program does not terminate even though an exception was thrown. The user can enter in another three numbers,
        //and the function will execute as normally. On the other hand, if the "return err;" line is uncommented, 
        //then the program will terminate.

        if (height != width || height != length) //Test if this is indeed a cuboid.
        {
            return height * width * length;
        }
        else
            throw 98;
     //I suppose this works?
     //This calculator is going to have some kind of exception handler, so yes, it will.
    return -1;  //To let other programmers know that there was an error, return a -1 instead because logically volume cannot be negative
               //Returning a possible answer will obfuscate the error message
     //Just another little note. Your function will either return the answer or throw an exception. The "return -1;"
     //line will never execute. But keep in mind that I am not telling you to remove this line. How you want your function
     //to... well... function is up to you.
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
