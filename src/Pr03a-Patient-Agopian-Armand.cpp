/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120, Introduction to Programming with C++
 *
 * Chapter: 03
 * Program: Pr03a-Patient-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: August 24, 2017
 *
 * Purpose: Get familiar with:
 * -- declaring variables of different types
 * -- assigning values to variables
 * -- outputting labels and variable values
 * -- coding conventions (see a separate
 *    document on the courese web site)
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Declare variables
  string name;      //Patient name    (Last, First)
  char   gender;    //Patient gender  (M or F)
  int    age;       //Patient age     (years)
  int    height;    //Patient height  (inches)

  //Assign values to variables for patient 1

  name   = "Washington, George";
  gender = 'M';
  age    = 57;
  height = 74;

  //To the console, output labels and
  //output values for the patient 1 variables

  cout << endl;
  cout << "Name  : " << name   << endl;
  cout << "Gender: " << gender << endl;
  cout << "Age   : " << age    << endl;
  cout << "Height: " << height << endl;
}
