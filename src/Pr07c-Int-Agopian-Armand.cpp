/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 07
 * Program: Pr07c-Int-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 03, 2017
 *
 * Purpose: Learn about the switch and case
 *          commands, and about an interest
 *          formula.
 *
 *          Review event-controlled iteration
 *          and conditional statements to get
 *          and validate input data.
 *
 *          Review count-controlled iteration
 *          to repeatedly calculate and output
 *          results.
 *
 * Problem: In the main routine, see the
 *          program description.
 *
 *          Watch and listen in class, and
 *          refer to a console document on our
 *          course website.
 */

//Preprocessor Directives
#include <iomanip>
#include <iostream>
#include <limits>  //Explained later
#include <string>

using namespace std;

#include <cmath>

//Main Routine
int main()
{
  //Declare Variables
  double prin;  //Principal (starting balance)
  double bal;   //Balance   (end of month)

  double r1;    //Rate of annual interest (pct.)
  double rx;    //Rate at 1x, 2x, or 3x   (dec.)

  int mint;     //Month integer (number)

  string mabbr; //Month abbreviation (name)

  //Output title
  cout << endl;
  cout << "Interest Program               "      << endl
       << "-------------------------------"      << endl
                                                 << endl;

  cout << "This program compounds interest"      << endl
       << "monthly to output ending balances"    << endl
       << "for each month of a year."            << endl
                                                 << endl;
  cout << "It does so for 1, 2, and 3 times"     << endl
       << "the original rate of interest"        << endl
                                                 << endl;
  cout << "Enter a positive principal less than" << endl
       << "or equal to 250000.00, and a positive"<< endl
       << "annual interest percentage less than" << endl
       << "or equal to 100.00"                   << endl
                                                 << endl;

  //Request principal value, input, and validate
  while(true)
  {
    cout << "Principal? ";
    cin >> prin;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Max character size
    }
    else if(prin < 0 || prin > 250000.00)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      cout << endl;
      break;
    }
  }

  //Request interest rate, input, and validate
  while(true)
  {
    cout << "Interest ? ";
    cin >> r1;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Max character size
    }
    else if(r1 < 0 || r1 > 100.00)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      cout << endl;
      break;
    }
  }

  //Output Title and Heading
  cout << "        E n d i n g   B a l a n c e  " << endl;
  cout << "      -------------------------------" << endl
                                                  << endl;
  cout << "Mon.  ";
  cout << setw(8) << r1     << "%  ";
  cout << setw(8) << r1 * 2 << "%  ";
  cout << setw(8) << r1 * 3 << "%";
  cout << endl;
  cout << "----  ---------  ---------  ---------" << endl
                                                  << endl;

  //Format fixed-point output
  cout << fixed << showpoint << setprecision(2);

  //Convert starting interest to decimal
  r1  /= 100.0;

  //Output Results
  for(mint = 1; mint <= 12; mint++)
  {
    switch(mint)
    {
      case 1  : mabbr = "Jan."; break;
      case 2  : mabbr = "Feb."; break;
      case 3  : mabbr = "Mar."; break;
      case 4  : mabbr = "Apr."; break;
      case 5  : mabbr = "May "; break;
      case 6  : mabbr = "Jun."; break;
      case 7  : mabbr = "Jul."; break;
      case 8  : mabbr = "Aug."; break;
      case 9  : mabbr = "Sep."; break;
      case 10 : mabbr = "Oct."; break;
      case 11 : mabbr = "Nov."; break;
      case 12 : mabbr = "Dec."; break;
      default : mabbr = "Inv."; break;
    }

    cout << mabbr << "  ";

    //1x
    bal = prin * pow(1.0 + (r1 / 12), mint);
    cout << setw(9) << bal << "  ";

    //2x
    rx  = r1 * 2.0;
    bal = prin * pow(1.0 + (rx / 12), mint);
    cout << setw(9) << bal << "  ";

    //3x
    rx  = r1 * 3.0;
    bal = prin * pow(1.0 + (rx / 12), mint);
    cout << setw(9) << bal;

    cout << endl;
  }
}