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
  cout << endl;

  //Convert 3 Fahrenheit temperatures to Calsius
  //and, to the console, output results

  //Temperature 1 of 3
  f = 21200000.0;
  c = 5.0 / 9 * (f - 32);

    cout << setw(10) << f << "  " << setw(7) << c << endl;
}
