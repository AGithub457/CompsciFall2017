/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 07
 * Program: Pr07b-Timer-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: September 28, 2017
 *
 * Purpose: Learn about timer simulation. This will
 *          involve iterating with nested for loops,
 *          and delaying output with some form of
 *          a sleep function.
 *
 *          It will also involve outputting leading
 *          zeros with the cout.fill() method,
 *          and returning the cursor to column 1 on
 *          the same line with an '\r' escape code.
 *
 *          Review sounding an audible alert with the
 *          '\a' escape code, and advancing the cursor
 *          to a new line with the '\n' escape code.
 *
 *          Also review validating input with the
 *          cin.peek() method, and setting the width
 *          of an output field with the setw()
 *          function.
 *
 * Problem: Output a digital timer that counts
 *          down seconds since the program
 *          started.
 *
 *          Use a stationary format in which
 *          the time is constantly overwritten.
 *
 *          Sound an audible alert every 5
 *          seconds, on seconds evenly
 *          divisible by 5.
 *
 *          Also process minutes (in addition
 *          to seconds).
 */

//Preprocessor Directives
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  //Declare Variables
  int min;  //Minutes
  int sec;  //Seconds

  int i;  //Minute loop index
  int j;  //Second loop index

  //Output title and description
  cout << endl;
  cout << "Timer Program"              << endl;
  cout << "--------------------------" << endl;
  cout << endl;

  cout << "This proogram counts down to zero " << endl
       << "from the starting time you enter."  << endl;
  cout << endl;
  cout << "Enter a number of minutes between"  << endl
       << "0 and 2."                           << endl;
  cout << endl;
  cout << "Enter a number of seconds between"  << endl
       << "0 and 59."                          << endl;
  cout << endl;

  // At console, get and validate minutes
  while(true)
  {
    cout << "Minutes (0-2)? ";
    cin >> min;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not an integer \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(min < 0 || min > 2)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      break;
    }
  }
  cout << endl;

  // At console, get and validate seconds
  while(true)
  {
    cout << "Seconds (0-59)? ";
    cin >> sec;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not an integer \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(sec < 0 || sec > 59)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      break;
    }
  }
  cout << endl;

  //Format output to show a leading zero
  cout.fill('0');

  //At console, begin countdown
  cout << "Starting the countdown" << endl;
  cout << endl;

  //Begin the countdown
  for(i = min; i >= 0; i--)
  {
    for(j = sec; j >= 0; j--)
    {
      cout << setw(2) << i << ":";
      cout << setw(2) << j << " ";

      if(j % 5 == 0)
      {
        cout << '\a';
      }
    }
  }
}