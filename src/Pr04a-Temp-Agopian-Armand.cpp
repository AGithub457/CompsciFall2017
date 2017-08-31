/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 04
 * Program: Pr04a-Temp-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: August 31, 2017
 *
 * Purpose: Learn about arithmetic expressions with
 *          several operations.
 *
 *          Consider whether to use parentheses to
 *          override default operator precedence.
 *
 *          When dividing, learn to avoid truncation.
 *
 *          Learn to format output neatly and with
 *          a specific number of decimal places.
 *
 * Practice
 * Problem: Convert Fahrenheit temperatures shown
 *          on the classroom screen to Celcius.
 *
 *          Output numeric results with one digit
 *          to the right of a decimal point
 *          (see textbook section 4.2).
 *
 * Real
 * Problem: Do the above, plus convert additional
 *          temperatures shown on the big screen the
 *          other way around, from Celsius to Fahrenheit.
 */

//Preprocessor directives
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  //Declare variables
  double c;  //Celsius     temperature;
  double f;  //Fahrenheit  temperature;

  //Format floating-point output
  cout << fixed << showpoint << setprecision(1);
  cout << right;

  //To the console, output a program title
  cout << endl;
  cout << "Temperature Program" << endl;
  cout << "-------------------" << endl;

  //Sample Problem

  //To the console, output some column headings
  cout << endl;
  cout << "Fahrenheit  Celsius" << endl;
  cout << "----------  -------" << endl;

  //Convert 3 Fahrenheit temperatures to Calsius
  //and, to the console, output results

  //Temperature 1 of 3
  f = 212.0;
  c = 5.0 / 9.0 * (f - 32);

  cout << setw(10) << f << "  " << setw(7) << c << endl;

  //Temperature 2 of 3
  f = 72.0;
  c = 5.0 / 9.0 * (f - 32);

  cout << setw(10) << f << "  " << setw(7) << c << endl;

  //Temperature 1 of 3
  f = 32.0;
  c = 5.0 / 9.0 * (f - 32);

  cout << setw(10) << f << "  " << setw(7) << c << endl;

  //Real Problem
  
  //To the console, output some column headings
  cout << endl;
  cout << "Celsius  Fahrenheit" << endl;
  cout << "-------  ----------" << endl;

  //Convert 8 Celsius temperatures to Fahrenheit
  //and, to the console, output results

  //Temperature 1 of 8
  c = 100.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 2 of 8
  c = 40.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 3 of 8
  c = 30.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 4 of 8
  c = 22.2;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 5 of 8
  c = 20.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 6 of 8
  c = 10.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 7 of 8
  c = 0.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;

  //Temperature 8 of 8
  c = -40.0;
  f = (9.0 / 5.0 * c) + 32;

  cout << setw(7) << c << "  " << setw(10) << f << endl;
}
