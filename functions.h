/* A header file to hold the 
main defintions of the program
Student: You
Teacher: Dr_T 10-17-2019, updated 3-24-2020 (clear screen methods for Ubuntu)
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//put libraries here
#include <iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include "Input_Validation_Extended.h" 
using namespace std;

//put prototypes here
void handleOption(string); //function prototype 
void showMenu();
void motionMenu(); 
int choice;
void velocityEquation();
void accelerationEquation();
void NewtonEquation();
void momentumEquation();
void WeightEarth();
void motionOne();
void motionTwo();
void motionThree();
void motionFour();
string color = "\x1b[" + to_string(31) + ";1m";
string reset = "\x1b[0m";


const int motionVchoice = 1,
          motionsChoice = 2,
          motionvChoice = 3,
          motionVbarChoice = 4;
          
//put definitions here
void handleOption(string userOption)
{
    int rows = 0, num = 0;
    char theChar = '\0'; //null char '\0' 
    double num1 = 0.0, num2 = 0.0, num3 = 0.0; 
    if(userOption == "A" || userOption == "a")
    { 
      velocityEquation();
      cout << reset;
    }
    else if(userOption == "B" || userOption == "b")
    {
      accelerationEquation();
      cout << reset;
    }
    else if(userOption == "C" || userOption == "c")
    {
      cout << "\nDo you want to solve for motion?"; 
      motionMenu();
      cout << "\nChoose which equation would you like to solve for: ";
      cin >> choice;
      if(choice == motionVchoice)
      {
        motionOne();
        cout << reset;
      }
      else if(choice == motionsChoice)
      {
        motionTwo();
        cout << reset;
      }
      else if(choice == motionvChoice)
      {
        motionThree();
        cout << reset;
      }
      else if(choice == motionVbarChoice)
      {
        motionFour();
        cout << reset;
      }
    
    }
    else if(userOption == "D" || userOption == "d")
    { 
      NewtonEquation();
      cout << reset;
    }
    else if(userOption == "E" || userOption == "e")
    {
    cout << "Thank you for using the physics calculator. Goodbye!" << endl;
    exit(0);
    }
    else if(userOption == "F" || userOption == "f")
    {
      WeightEarth();
      cout << reset;
    }
    else if(userOption == "G" || userOption == "g")
    {
      momentumEquation();
      cout << reset;
    }
    else if(userOption == "X" || userOption == "x")
    {
      string reset = "\x1b[0m";
      //Linux Umbunu
      cout << reset; 
      cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
      //Windows: system("cls"); 
      system("clear"); //for ubuntu Linux Option 2 of 2
    }
    

}

void showMenu()
{
  cout << "\nMENU" << endl;
  cout << "----------------" << endl; 
  cout << "A: Velocity" << endl; 
  cout << "B: Acceleration" << endl; 
  cout << "C: Motion" << endl; 
  cout << "D: Newton's Second Law" << endl; 
  cout << "E: Exit" << endl;
  cout << "F: Weight" << endl;
  cout << "G: Momentum" << endl;
  cout << "X: Clear The Screen" << endl;  
}

void motionMenu()
{
  cout << "\n\t\tEquations of Motion" << endl;
  cout << "\t\t-------------------" << endl;
  cout << "\t\t1: v = v0 + at" << endl;
  cout << "\t\t2: s = s0 + v0t + 0.5at^2" << endl;
  cout << "\t\t3: v0^2 = v^2 + 2a(s-s0)" << endl;
  cout << "\t\t4: v_bar = 0.5(v + v0)" << endl;
}

//definintion 
void velocityEquation()
{
  double ds;
  double dt;
  string dsUnits;
  string dtUnits;
  double velocityResult;

  cout << "\nPlease enter the value for ds: ";
  ds = validateDouble(ds);//cin >> ds;
  cout << "\nPlease enter the unit of measure for ds: ";
  dsUnits = validateString(dsUnits);//cin >> dsUnits;
  cout << "\nPlease enter the value for dt: ";
  dt = validateDouble(dt);//cin >> dt;
  cout << "\nPlease enter the unit of measure for dt: ";
  dtUnits = validateString(dtUnits);//cin >> dtUnits;

  velocityResult =  ds / dt;

  cout << color;

  cout << "\nThe calculated velocity is: " << velocityResult << dsUnits << "/" << dtUnits << endl;
}

void accelerationEquation()
{
  double dv;
  double dt;
  double accelerationResult;
  string dvUnits;
  string dtUnits;
  
  cout << "\nPlease enter the value for dv: ";
  dv = validateDouble(dv);//cin >> dv;
  cout << "\nPlease enter the unit of measure for dv: ";
  dvUnits = validateString(dvUnits);//cin >> dvUnits;
  cout << "\nPlease enter the value for dt: ";
  dt = validateDouble(dt);//cin >> dt;
  cout << "\nPlease enter the unit of measure for dt: ";
  dtUnits = validateString(dtUnits);//cin >> dtUnits;

  accelerationResult = dv / dt;

  cout << color;

  cout << "\nThe calculated acceleration is: " << accelerationResult << "(" << dvUnits << ")" << "/" << dtUnits << endl;
}

void motionOne()
{
  double velocityResult;
  double velocityZero;
  double Acceleration;
  double Time;

  cout << "\nPlease enter the value for the initial velocity: ";
  velocityZero = validateDouble(velocityZero);//cin >> velocityZero;
  cout << "\nPlease enter the value for acceleration: ";
  Acceleration = validateDouble(Acceleration);//cin >> Acceleration;
  cout << "\nPlease enter the value for time: ";
  Time = validateDouble(Time);//cin >> Time;

  velocityResult = velocityZero + (Acceleration * Time);

  cout << color;

  cout << "\nThe calculated motion velocity is " << velocityResult << endl;
}

void motionTwo()
{
  double sResult;
  double sZero;
  double velocityZero;
  double Acceleration;
  double Time;

  cout << "\nPlease enter the value for the initial displacement: ";
  sZero = validateDouble(sZero);//cin >> sZero;
  cout << "\nPlease enter the value for the initial velocity: ";
  velocityZero = validateDouble(velocityZero);//cin >> velocityZero;
  cout << "\nPlease enter the value for time: ";
  Time = validateDouble(Time);//cin >> Time;
  cout << "\nPlease enter the value for acceleration: ";
  Acceleration = validateDouble(Acceleration);//cin >> Acceleration;

  sResult = sZero + (velocityZero * Time) + (0.5 * Acceleration) * pow(Time, 2.0);

  cout << color;
  
  cout << "\nThe calculated displacement with positive acceleration is " << sResult << endl;
}

void motionThree()
{
  double velocitySquaredResult;
  double velocityZero;
  double Acceleration;
  double Speed;
  double SpeedZero;

  cout << "\nPlease enter the value for the initial velocity: ";
  velocityZero = validateDouble(velocityZero);//cin >> velocityZero;
  cout << "\nPlease enter the value for acceleration: ";
  Acceleration = validateDouble(Acceleration); //cin >> Acceleration;
  cout << "\nPlease enter the value for speed: ";
  Speed = validateDouble(Speed); //cin >> Speed;
  cout << "\nPlease enter the value for the initial speed: ";
  SpeedZero = validateDouble(SpeedZero); //cin >> SpeedZero;

  velocitySquaredResult = pow(velocityZero, 2.0) + (2.0 * Acceleration) * (Speed - SpeedZero);

  cout << color;

  cout << "\nThe calculated velocity squared is " << velocitySquaredResult << endl;
}

void motionFour()
{
  double velocityBarResult;
  double velocity;
  double velocityZero;

  cout << "\nPlease enter the value for velocity: ";
  velocity = validateDouble(velocity); //cin >> velocity;
  cout << "\nPlease enter the value for the initial velocity: ";
  velocityZero = validateDouble(velocityZero); //cin >> velocityZero;

  velocityBarResult = 0.5 * (velocity + velocityZero);

  cout << color;

  cout << "\nThe calculated velocity bar is " << velocityBarResult << endl;
}

void NewtonEquation()
{
  double mass;
  double acceleration;
  double NewtonResult;
  string massUnits;
  string accelerationUnits;

  cout << "\nPlease enter the value for mass: ";
  mass = validateDouble(mass); //cin >> mass;
  cout << "\nPlease enter the unit of measure for mass: ";
  massUnits = validateString(massUnits); //cin >> massUnits;
  cout << "\nPlease enter the value for acceleration: ";
  acceleration = validateDouble(acceleration); //cin >> acceleration;
  cout << "\nPlease enter the unit of measure for acceleration: ";
  accelerationUnits = validateString(accelerationUnits); //cin >> accelerationUnits;

  NewtonResult = mass * acceleration;

  cout << color;

  cout << "\nThe calculated Newton's Second Law is " << NewtonResult << massUnits << " " << accelerationUnits << endl;
}

void WeightEarth()
{
 double mass;
 double gravity;
 string massUnits;
 double WeightResult;

 cout << "\nPlease enter the value for mass: ";
 mass = validateDouble(mass); //cin >> mass;
 cout << "\nPlease enter the unit of measurement for the weight: ";
 massUnits = validateString(massUnits); //cin >> massUnits;
 cout << "\nPlease enter the value for gravity: ";
 gravity = validateDouble(gravity); //cin >> gravity;
 

 WeightResult = mass * gravity;

 cout << color;

 cout << "\nThe calculated weight (on Earth) is: " << WeightResult << massUnits << endl;
}

void momentumEquation()
{
  double momentumResult;
  double Mass;
  double Velocity;
  string unitsMass;
  string unitsVelocity;

  cout << "\nPlease enter the value for mass: ";
  Mass = validateDouble(Mass); //cin >> Mass;
  cout << "\nPlease enter the unit of measure for mass: ";
  unitsMass = validateString(unitsMass); //cin >> unitsMass;
  cout << "\nPlease enter the value for velocity: ";
  Velocity = validateDouble(Velocity); //cin >> Velocity;
  cout << "\nPlease enter the unit of measure for velocity: ";
  unitsVelocity = validateString(unitsVelocity); //cin >> unitsVelocity;

  momentumResult = Mass * Velocity;

  cout << color;

  cout << "\nThe calculated momentum is: " << momentumResult << unitsMass << " " << unitsVelocity << endl; 
}

#endif