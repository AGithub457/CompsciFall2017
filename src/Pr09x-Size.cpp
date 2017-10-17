/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 09
 * Program: Pr09x-Size.cpp
 * Author: Agopian, Armand
 * Date: October 17, 2017
 *
 * Purpose: Learn about the sizeof function.
 *
 * Problem: See the program description that this
 *          program outputs.
 */

//Preprocessor Directives
#include <iostream>

using namespace std;

//Main Routine
int main()
{
  //Declare Variables
  char   c;

  short  s;
  int    i;

  float  f;
  double d;

  //Output Title and Description
  cout << endl
       << "Size Program"                      << endl
       << "--------------------------------"  << endl
       << endl
       << "This program outputs the size (in" << endl
       << "bytes) of several variable types"  << endl
       << endl;

  //Output sizes of variables
  cout << "Char  : " << sizeof(c) << endl;
  cout << endl;
  cout << "Short : " << sizeof(s) << endl;
  cout << "Int   : " << sizeof(i) << endl;
  cout << endl;
  cout << "Float : " << sizeof(f) << endl;
  cout << "Double: " << sizeof(d) << endl;
}