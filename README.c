#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[])
{

    int count = 0, hcount = 0, ecount = 0, lcount = 0, ocount = 0;
    string input;
    unsigned search;

    while (input != "0")
    {
        cout << "Enter Something:\n";
        getline (cin, input);

          search = input.find("h");
          if (search!=string::npos)
          hcount++;
          /*
                //Initialize search
             search = input.find('h');
            while(search != string::npos){
                hcount++;
                    //Find next 'h' in string starting one position after that last 'h'
                search = input.find('h', search+1);
            }
          */
          search = input.find("e");
          if (search!=string::npos)
          ecount++;
          search = input.find("l");
          if (search!=string::npos)
          lcount++;
          search = input.find("o");
          if (search!=string::npos)
          ocount++;


    }


      cout << "H got repeated " << hcount << " times!\n";
      cout << "E got repeated " << ecount << " times!\n";
      cout << "L got repeated " << lcount << " times!\n";
      cout << "O got repeated " << ocount << " times!\n";



}
