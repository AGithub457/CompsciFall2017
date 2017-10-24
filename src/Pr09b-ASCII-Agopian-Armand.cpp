/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 09
 * Program: Pr09b-ASCII-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 19, 2017
 *
 * Purpose: Learn about how a microcomputer typically
 *          stores and represents character data.
 *
 *          Become familiar with the American Standard
 *          Code for Information Interchange (ASCII),
 *          and with related decimal, binary,
 *          and hexadecimal values.
 *
 * Problem: To the console, output a table of ASCII
 *          characters, along with their equivalent
 *          binary, decimal, and hexadecimal values.
 *
 *          Watch and listen in class, and refer to
 *          a console document for more information.
 *
 *          Submit just a source (.cpp) file.
 *
 * Source : http://www.asciitable.com/
 */

//Preprocessor Directives
#include <bitset>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

//Function Prototypes
void putHead();
char getBeg();
char getEnd(char);
void putRes(char, char);

//Main Routine
int main()
{
  //Declare Variables
  char beg;  //Beginning value
  char end;  //Ending    value

  //Call functions
  putHead();          //Output headings

  beg = getBeg();     //Input beginning value
  end = getEnd(beg);  //Input ending    value

  putRes(beg, end);   //Output results

  return 0;
}

//Level 1 Functions
void putHead()
{
  cout                                         << endl
       << "ASCII Program"                      << endl
       << "---------------------------------"  << endl
                                               << endl
       << "This program output part of an"     << endl
       << "American Standard Code for"         << endl
       << "Information Interchange table."     << endl
                                               << endl
       << "Enter a beginning value between"    << endl
       << "! and ~, and an ending value"       << endl
       << "between the beginning value and ~." << endl
                                               << endl;
}

char getBeg()
{
  //Declare Variable
  char beg;

  //Get and Validate
  while(true)
  {
    cout << "Beg? ";
    cin  >> beg;

    /*if(cin.peek() != '\n')
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: Not a Character \a" << endl;
    }*/
    if(beg < '!' || beg > '~')
    {
      cout << "Error: Out of Range    \a" << endl;
    }
    else
    {
      cout << endl;
      return beg;
    }
  }
}

char getEnd(char beg)
{
  //Declare Variable
  char end;

  //Get and Validate
  while(true)
  {
    cout << "End? ";
    cin  >> end;

    /*if(cin.peek() != '\n')
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: Not a Character \a" << endl;
    }*/
    if(end < beg || end > '~')
    {
      cout << "Error: Out of Range   \a" << endl;
    }
    else
    {
      cout << endl;
      return end;
    }
  }
}

void putRes(char beg, char end)
{
  //Declare Variables
  char c;     //Character loop index

  int count;  //Count of characters

  //Initialize Variables
  count = 0;

  //Output column headings
  cout << "Char  Dec       Bin  Hex" << endl
       << "----  ---  --------  ---" << endl
                                     << endl;

  //Output ASCII Table
  for(c = beg; c <= end; c++)
  {
    cout << setw(4)            <<      c  << "  ";
    cout << setw(3) << dec     << (int)c  << "  ";
    cout << setw(8) << bitset<8> ((int)c) << "  ";
    cout << setw(3) << hex     << (int)c  << endl;

    count++;
  }

  //Output Count
  cout << endl
       << "Count: " << count << endl;
}