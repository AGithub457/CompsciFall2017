/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 09
 * Program: Pr09a-Max-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 17, 2017
 *
 * Purpose: Learn about bits, bytes, and the maximum
 *          capacity of short integer variables.
 *
 *          Introduce a second level function.
 *
 *          Review looping, validation, conditions,
 *          type casting, and arithmetic.
 *
 * Problem: Use a level one function to input,
 *          validate, and process short integers.
 *
 *          Use a level two function to output program
 *          footings that include a sum, count, and average.
 *
 *          Watch and listen in class, and refer to
 *          a console document for more information.
 *
 *          Submit just a source program (.cpp) file.
 */

//Preprocessor Directives
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

//Function Prototypes
void putHead();
void procData();
void calcAvg(short, short);

//Main Routine
int main()
{
  //Call level one functions
  putHead();

  procData();
}

//Level One Functions
void putHead()
{
  cout << endl
       << "Maximum Program"                  << endl
       << "--------------------------------" << endl
       << endl
       << "This program demonstrates the"    << endl
       << "maximum capacity of positive"     << endl
       << "short integers."                  << endl
       << endl
       << "Enter positive integers that are" << endl
       << "less than or equal to"            << endl
       << SHRT_MAX << ". To quit, enter 0."  << endl;
}

void procData()
{
  //Process data: Get, validate, accumulate, and count
  //numbers, then call a function to output footings

  //Declare Variables
  short   num;  //Number (input)
  short   sum;  //Total  (accumulated)
  short count;  //Count  (counted)

  //Initialize Variables
  sum   = 0;
  count = 0;

  //Get and validate number, accumulate count
  while(true)
  {
    cout << "Number ? ";
    cin >> num;

    if(cin.fail())
    {
      cout << "Error: Not a number        \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not a short integer \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(num < 0)
    {
      cout << "Error: Negative            \a" << endl;
    }
    else if(num == 0)
    {
      break;
    }
    else
    {
      sum += num;
      count++;
    }
  }

  calcAvg(sum, count);
}

//Level two functions
void calcAvg(short sum, short count)
{
  //Validate statistics and output footings

  //Declare Variables
  string msg;  //Message

  float avg;   //Average

  //Format Output
  cout << fixed << showpoint << setprecision(1);

  //Validate and output statistics
  if(count == 0)
  {
    msg =  "Warning: count is zero";
    msg += ", so average set to zero \a";

    avg = 0.0;
  }
  else if(sum < 0)
  {
    msg =  "Warning: sum overflowed";
    msg += ", so average set to zero \a";

    avg = 0.0;
  }
  else
  {
    avg = (float)sum / count;
    msg = "Done";
  }

  cout << endl
       << "Sum    : " << sum   << endl
       << "Count  : " << count << endl
       << "Avergae: " << avg   << endl
       << endl
                      << msg << endl;
}