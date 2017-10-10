/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 08
 * Program: Pr08b-Leap-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 10, 2017
 *
 * Purpose: Learn more about functions, including
 *          prototypes and parameters.
 *
 *          Review data validation, iteration,
 *          and nested conditions.
 *
 Problem: Identify leap years between beginning and
          ending years tht a user specifies.

          Though similar to the earlier Pr06c
          assignment, there are a few differences.

          This program is divided into functions,
          and uses prototypes and parameters.

          This program treats the year Britain
          adopted the Gregorian calendar, not when
          a pope introduced it, as the first valid
          year.

          This program uses a for loop, not a while
          loop, to identify and output leap years.

          Use a batch file to run the program and
          to display the count of leap years.

          Watch and listen in class, and refer to
          a console document for more information.

          When done, simultaneously submit both the
          source (.cpp) and batch (.bat) files.
 */

//Preprocessor Directives
#include <iostream>
#include <limits>

using namespace std;

//Function Prototypes
void putHead(int, int);
int   getBeg(int, int);
int   getEnd(int, int);
int  putYear(int, int);

//Main Routine
int main()
{
  //Declare variables (only these)
  int greg;  //Britain's first Gregorian year
  int now ;  //Current year

  int beg;  //Year to begin processing
  int end;  //Year to end   processing

  int count;  //Count of leap years

  //Initialize Variables
  greg = 1752;
  now - 2017;

  //Output program heading
  putHead(greg, now);

  //Get and validate beginning and ending years
  beg = getBeg(greg, now);

  end = getEnd(beg, now);

  //Output Results
  count = putYear(beg, end);

  return count
}

//Functions
void putHead(int greg, int now)
{
  //Output Heading
  cout << endl
       << "Leap Year Program"               << endl
       << "------------------------------"  << endl
       << endl;

  cout << "This program determines whether"   << endl
       << "years are leap years (Y means"     << endl
       << "yes, N means no)."                 << endl
       << endl;

  cout << "Choose the years for which to"     << endl
       << "begin and end processing, between" << endl
       << greg << " and " << now << "."       << endl
       << endl;
}

int getBeg(int greg, int now)
{
  //Declare Variables
  int beg;  //Beginning year

  //Get and validate beginning year and return
  while(true)
  {
    cout << "Beginning Year? ";
    cin  >> beg;

    if(cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: Not a Number" << endl;
    }
    else if(cin.peek() != '\n')
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: Not an Integer" << endl;
    }
    else if(beg < greg || beg > now)
    {
      cout << "Error: Out of Range" << endl;
    }
    else
    {
      cout << endl;
      return beg;
    }
  }
}