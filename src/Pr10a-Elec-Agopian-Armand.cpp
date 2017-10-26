/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 10
 * Program: Pr10a-Elec-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 24, 2017
 *
 * Purpose: Learn about getting data from an input
 *          file instead of from the console.
 *
 *          Review looping, validation. formatting
 *          output, functions, and the switch-case
 *          construct.
 *
 * Problem: Create an input file that contains
 *          electricity bill data.
 *
 *          Write a program that processes data in
 *          that file as described in the putHead
 *          function.
 *
 *          Watch and listen in class, and refer to
 *          a console document for more information.
 *
 * Submit : Two files simultaneously:
 *          -- source program file (.cpp)
 *          -- input data file     (.in)
 */

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Function Prototypes
void putHead();
string getName();
void procData(string);
string setAbbr(int);

//Main Routine
int main()
{
  //Declare Variables
  string ifname;  //Input file name

  //Output Heading
  putHead();

  //Get and validate file name
  ifname = getName();

  //Process data
  procData(ifname);

  return 0;
}

//Level 1 Functions
void putHead()
{
  cout << endl
       << "Electricity Bill Program"           << endl
       << "---------------------------------"  << endl
       << endl;

  cout << "This program gets electricity bill" << endl
       << "data from an input file, converts"  << endl
       << "month numbers to abbreviated month" << endl
       << "names, and outputs the data to the" << endl
       << "console, along with a count of "    << endl
       << "records processed."                 << endl
       << endl;

  cout << "Enter the name of an input file"    << endl
       << "contains electricity bill data."    << endl
       << endl;
}

string getName()
{
  //Declare Variables
  string ifname;  //Input filename

  ifstream fin;   //Input file object

  //Request Filename
  while(true)
  {
    cout << "Input filename? ";
    cin >> ifname;

    fin.open(ifname);
    if(fin.good())
    {
      fin.close();
      break;
    }
    else
    {
      cout << "Error \a\n";
    }
  }

  cout << endl;

  return ifname;
}

void procData(string ifname)
{
  //Declare Variables
  ifstream fin;  //Input file object

  int year;      //Year
  int mint;      //Month number
  int  kwh;      //Kilowatt hours

  float cost;    //Cost

  string mabbr;  //Month name abbreviation

  int count;     //Count of records processed

  //Initialize Variables
  count = 0;

  //Output Column Headings
  cout << endl
       << "Year  Mon.   KWh   $ Cost" << endl
       << "----  ----  ----  -------" << endl
       << endl;

  //Open input file and format fixed-point output
  fin.open(ifname);

  cout << fixed << showpoint << setprecision(2);

  //Get and put data
  while(fin >> year)
  {
    fin >> mint;
    fin >> kwh;
    fin >> cost;

    cout << setw(4) << year          << "  ";
    cout << setw(4) << setAbbr(mint) << "  ";
    cout << setw(4) << kwh           << "  ";
    cout << setw(7) << cost          << endl;

    count++;
  }

  //Close file and output count
  fin.close();

  cout << endl
       << "Count: " << count << endl << endl;
}

string setAbbr(int mint)
{
  string mabbr;

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
      default : mabbr = "Inv.";
    }

    return mabbr;
}