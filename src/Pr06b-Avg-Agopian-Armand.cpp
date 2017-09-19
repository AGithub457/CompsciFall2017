/*
 * School : Diablo Valley College
 * Term   : 2017 Fall
 * Course : ComSc-110-3120,
            Introduction to Programming (with C++)
 *
 * Chapter: 06
 * Program: Pr06b-Avg-Agopian-Armand.cpp
 * Author : Agopian, Armand
 * Date   : September 19, 2017
 *
 * Purpose: Learn about or review looping, console
 *          input, validation, initialization,
 *          incrementation, accumulation,
 *          sentinel processing, type casting,
 *          formatting, and console output.
 *
 * Initial
 * Problem: Loop to input a series of integers.
 *          Validate that the integers are positive
 *          and less than or equal to 99.
 *
 *          Count them and add their values.
 *
 *          Format the console for floating-point
 *          results.
 *
 *          Output the count and the sum of the
 *          entered integers, though as floating-point
 *          results.
 *
 *          See the course website for documents that
 *          show sample console interaction,
 *          and coding conventions.
 *
 *          For other details, watch the classroom
 *          screen, and listen to instructions.
 *
 * Next
 * Problem: Do several more things.
 *
 *          While validating entered vlues, make sure
 *          they are numeric, and integers.
 *
 *          When done inputting, and after outputting
 *          sum and cout, calculate and output a
 *          floating-point average of the entered values.
 */

 //Preprocessor Directives
#include<iomanip>
#include<iostream>

using namespace std;

//Main Routine
int main()
{
  //Declare variables
  int   num;    //Number  (input)
  int   sum;    //Sum     (accumulated)
  int   count;  //Count   (incremented)

  float avg;    //Average (calculated)

  //Initialize an accumulator and a counter
  sum   = 0;
  count = 0;

  //To the console, output title, description
  //and instructions
  cout << endl;
  cout << "Averaging Program" << endl;
  cout << "---------------------------" << endl;
  cout << endl;

  cout << "This program adds and counts" << endl
       << "positive integers less than or" << endl
       << "equal to 99. It then calculates" << endl
       << "their average." << endl << endl;

  cout << "Enter values until ready to quit," << endl
       << "then enter 0." << endl << endl;
  //Loop to prompt, input, validate, add and count
  while(true)
  {
    //Prompt for a number, then input it
    cout << "Number ? ";
    cin >> num;

    //Guard against a non-numeric vlaue,
    //Guard against a non-integer value,
    //Guard against an out-of-range value,
    //then either quit or calculate.
    if(num < 0 || num > 99)
    {
      cout << "Invalid: Out of Range" << endl;
    }
    else if(num == 0)
    {
      break;
    }
    else
    {
      count++;    //Accumulate
      sum += num; //Increment
    }
  }

  //Format results
  cout << fixed << showpoint << setprecision(1);

  //Output sum and count
  cout << endl;
  cout << "Sum    : " << setw(6) << (float)sum   << endl;
  cout << "Count  : " << setw(6) << (float)count << endl;

  //Calcuate average, and output
  if(count == 0)
  {
    avg = 0.0;
  }
  else
  {
    avg = (float)sum / count;
  }

  cout << "Average: " << setw(6) << avg << endl;
}
