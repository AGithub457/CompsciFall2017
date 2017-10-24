/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 09
 * Program: Pr09x-Round1.cpp.cpp
 * Author: Agopian, Armand
 * Date: October 24, 2017
 */

//Preprocessor Directives
#include <iomanip>
#include<iostream>

using namespace std;

//Main Routine
int main()
{
  //Declare Variables
  double x;

  //Output Program Headings
  cout << endl
       << "Round-off Program 2" << endl
       << "-------------------" << endl
       << endl;

  //Format Output
  cout << fixed << showpoint << setprecision(16);

  //Loop does not stop properly
  for(x = 0; x != 1; x += .1)
  {
    cout << x << endl;

    if(x > 1.5)
    {
      break;
    }
  }
}