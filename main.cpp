#include <iostream>
#include <iomanip>
#include "functions.h" //reference the header file 

using namespace std;

int main() 
{
  string option = ""; //the option local to int main()
  string color = "\x1b[" + to_string(46) + ";1m";
  string reset = "\x1b[0m";
  //loop until the user provides "e" or (&&) "E" as exit condition
  
  do
  {
    showMenu(); //call a menu void function here
    cout << "\nPlease enter an option: ";
    //cin >> option; //getline(cin,option); //get the entire line
    cout << color; //change text to green 
    option = validateString(option); 
    cout << reset; //reset back to standard
    handleOption(option); //call handleOption and pass the user option as an argument
    
  
  }while(option != "E" && option != "e"); 
   
  return 0; 
}