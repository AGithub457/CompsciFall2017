/*
 * School : Diablo Valley College
 * Term   : 2017 Fall
 * Course : ComSc-110-3120,
            Introduction to Programming (with C++)
 *
 * Chapter: 06
 * Program: Pr06c-Leap-Agopian-Armand.cpp
 * Author : Agopian, Armand
 * Date   : September 21, 2017
 *
 * Purpose: Continue learning about looping, data
 *          validation and conditional logic.
 *
 * Initial
 * Problem: Since the advent of the Gregorian
 *          calendar, determine white years are leap
 *          years, except for a possible inaccuracy
 *          related to century years.
 *
 * Next
 * Problem: Refine the program's logic to better
 *          validate input, and to more accurately
 *          identify century years that are leap
 *          years.
 *
 *          For more information, listen and watch in
 *          class, refer to a console document on
 *          our course website, and search the internet.
 *
 * Data
 * Source:  https://en.wikipedia.org/wiki/Gregorian_calendar
 */
//Preprocessor Directives
#include<iostream>

using namespace std;

//Main Routine
int main()
{
  //Declare variables
  int greg; //Year Gregorian calendar was introduced
  int now;  //Current year

  int beg;  //Year to begin processing
  int end;  //Year to end   processing

  int year; //Year to process

  char leap;  //Leap    year?
  char cent;  //Century year?

  //Initialize variables
  greg = 1582;
  now = 2017;

  //To the console, output a program title, a
  //program description, and some user instructions
  cout << endl;
  cout << "Leap Year Program"               << endl;
  cout << "------------------------------"  << endl;
  cout << endl;

  cout << "This program determines whether"   << endl
       << "years are leap years (Y means"     << endl
       << "yes, N means no)."                 << endl
       << endl;

  cout << "Choose the years for which to"     << endl
       << "begin and end processing, between" << endl
       << "and including " << greg << " and "
                           << now << "."      << endl
       << endl;

  //Loop to prompt the user for a beginning year,
  //to input that year, and to validate it
  while(true)
  {
    cout << "Beginning Year? ";
    cin  >> beg;

    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error: NaN" << endl;
    }
    /*else if(!cin.good())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error: Not an Integer" << endl;
    }*/
    else if(beg < greg || beg > now)
    {
      cout << "Error: Out of Range" << endl;
    }
    else
    {
      cout << endl;
      break;
    }
  }

  //Loop to prompt the user for a ending year,
  //to input that year, and to validate it
  while(true)
  {
    cout << "Ending Year? ";
    cin  >> end;
    cout << end;

    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error: Not a Number" << endl;
    }
    /*else if(cin.peek() == )
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error: Not an Integer" << endl;
    }*/
    else if(end < beg || end < greg || end > now)
    {
      cout << "Error: Out of Range" << endl;
    }
    else
    {
      cout << endl;
      break;
    }
  }

  //Calculate which years are leap years and
  //print them to the console
  cout << "Year" << "  Leap?" << "  Cent?"<< endl;
  cout << "----" << "  -----" << "  -----"<< endl;
  cout << endl;

  for(int i = beg; i <= end; i++)
  {
    cent = 'N';
    leap = 'N';

    cout << i << "  ";

    if(i % 100 == 0)
    {
      cent = 'Y';
    }
    if(cent == 'Y' && i % 400 == 0)
    {
      leap = 'Y';
    }
    if(cent == 'N' && i % 4 == 0)
    {
      leap = 'Y';
    }

    cout << leap << "      " << cent << endl;
  }
}
