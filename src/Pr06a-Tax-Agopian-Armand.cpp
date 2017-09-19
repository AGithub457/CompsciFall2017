/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 06
 * Program: Pr06a-Tax-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: September 14, 2017
 *
 * Purpose: Learn about branching statements
 *          that evaluate either simple or
 *          compound conditions.
 *
 *          Review calculations, and the neat
 *          formatting of console output.
 *
 * Initial
 * Problem: Based on an annual income amount that
 *          a user enters, calculate and output a
 *          tax amount that the user may owe the
 *          Internal Revenue Service (IRS).
 *
 *          See the course website and/or the internet
 *          for documents that show sample console
 *          interaction, year 2017 federal tax
 *          brackets, and coding conventions.
 *
 *          For other details, watch the classroom
 *          screen, and listen to instructions.
 *
 * Next
 * Problem: Validate the income that a user enters.
 *          If it is too low or too high, output an
 *          error message, and end the program.
 */

//Preprocessor directives
#include <iomanip>
#include <iostream>

using namespace std;

//Main Routine
int main()
{
  //Declare variables
  int   year;   //Tax year
  float inc;    //User's annual income (dollars)

  float high1;  //High end income for bracket 1
  float high2;  //...                 bracket 2
  float high3;  //...                 bracket 3

  float btax1;  //Base tax amount for bracket 1
  float btax2;  //...                 bracket 2
  float btax3;  //...                 bracket 3

  float rate1;  //Tax rate for bracket 1 (percent)
  float rate2;  //...          bracket 2
  float rate3;  //...          bracket 3

  float low;    //Low end income for user's bracket
  float high;   //High...

  float exc;    //Excess income (above low end
                //of user's bracket)

  float rate;   //Tax rate (percent) for user's
                //excess income

  float btax;   //User's base tax amount
  float etax;   //User's excess...
  float ttax;   //User's total...

  //Assign values

  year = 2017;

  high1 =  9325.00;
  high2 = 37950.00;
  high3 = 91900.00;

  btax1 =     0.00;
  btax2 =   932.50;
  btax3 =  5226.25;

  rate1 = 10.0;
  rate2 = 15.0;
  rate3 = 25.0;

  //Output title, description, and instructions
  cout << endl;
  cout << "            Tax Program            " << endl;
  cout << "-----------------------------------" << endl;
  cout << endl;

  cout << "This program calculates a US \n"
       << "federal income tax amount for \n"
       << "a single person of modest means." << endl;

  cout << endl
       << "For year "
       << year
       << ", enter an annual \n"
       << "income as a positive dollar amount \n"
       << "less than or equal to "
       << high3
       << "." << endl;

  //Prompt the user for annual income, and inpput it
  cout << endl;
  cout << "Income? ";
  cin  >> inc;

  //Validat the user's income
  if(inc <= 0 || inc > high3)
  {
    cout << "Invalid: Out of Range";
    return 69;
  }

  //Identify the user's tax bracket
  if(inc > 0 && inc <= high1)
  {
    low = 0;
    high = high1;
    rate = rate1;
    btax = btax1;
  } else if(inc > high1 && inc <= high2)
  {
    low = high1;
    high = high2;
    rate = rate2;
    btax = btax2;
  } else if(inc > high2 && inc <= high3)
  {
    low = high2;
    high = high3;
    rate = rate3;
    btax = btax3;
  }

  //Calculate the user's tax amounts
  exc = inc - low;
  etax = rate / 100.0 * exc;
  ttax = btax + etax;

  //Set console formatting, then output results
  cout << fixed << showpoint << setprecision(2);

  cout << endl;
  cout << "Bracket" << endl;
  cout << "  Low    : " << "$ " << setw(8)  << low
                                            << endl;
  cout << "  High   : " << "$ " << setw(8)  << high
                                            << endl;
  cout << "Base Tax : " << "$ " << setw(18) << btax
                                            << endl;
  cout << "Exc. Inc.: " << "$ " << setw(8)  << exc
                                            << endl;
  cout << "Tax Rate : " << setw(10)  << rate << "%"
                                            << endl;
  cout << "Exc. Tax : " << "$ " << setw(18) << etax
                                            << endl;
  cout << setw(31) << "---------"           << endl;
  cout << "Tot. Tax : " << "$ " << setw(18) << ttax
                                            << endl;
}
