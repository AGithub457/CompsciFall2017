/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 10
 * Program: Pr10b-Water-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 26, 2017
 *
 * Purpose: Learn about writing data to an output file
 *          instead of to the console.
 *
 *          Review creating and validating an input
 *          file, formatting output, functions,
 *          arithmetic, and the switch-case construct.
 *
 * Problem: Create an input file that contains
 *          water bill data.
 *
 *          Write a program that processes data in
 *          that file as described in the
 *          putHead function.
 *
 * Submit: Two files simultaneously:
 *         -- source program file (.cpp)
 *         -- input data file (.in)
 */

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

//Function Prototypes
void putHead();
string getNameIn();
string getNameOut();
void procData(string, string);
void putFoot(string);
string setAbbr(int);

int main()
{
  //Declare Variables
  string ifname;  //Input filename
  string ofname;  //Output filename

  //Output Heading
  putHead();

  //Read I/O filenames
  ifname = getNameIn();
  ofname = getNameOut();

  //Process Data, reading input file,
  //calculating results, and writing to output file
  procData(ifname, ofname);

  //Write footing, and return 0 to OS
  putFoot(ofname);
  return 0;
}

//Level 1 Functions
void putHead()
{
  cout << endl
       << "Water Bill Program"               << endl
       << "--------------------------------" << endl
       << endl;

  cout << "This program prompts you to enter"   << endl
       << "the name of an existing input file," << endl
       << "and the name of a new output file."  << endl
       << endl
       << "From the input file, this program"   << endl
       << "reads a service charge, two usage"   << endl
       << "rates, a prior meter reading, and "  << endl
       << "subsequent bi-monthly readings."     << endl
       << endl
       << "Based on such ata, this program"     << endl
       << "calculates water usage and costs,"   << endl
       << "converts month numbers to names,"    << endl
       <<  "and writes results to a file."      << endl
       << endl;
}

string getNameIn()
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

string getNameOut()
{
  //Declare Variables
  string ofname;  //Output filename

  //Read name of output file

  cout << "Output filename? ";
  cin >> ofname;

  cout << endl;

  return ofname;
}

void procData(string ifname, string ofname)
{
  //Declare Variables
  ifstream fin;   //Input file object
  ofstream fout;  //Output file object

  float chrg;   //Service charge
  float rate1;  //Rate for units used <= 22
  float rate2;  //Rate for units used > 22

  int prev;  //Previous meter reading
  int year;  //Year
  int mint;  //Month number (integer)
  int curr;  //Current meter reading
  int unit;  //1 unit used = 100 cubic feet
             //            = 748 gallons

  float cost;  //Cost

  string mabbr; //Month name (abbreviation)

  //Open I/O files
  fin.open(ifname);
  fout.open(ofname);

  //Input file => read first record and store contents
  //to appropriate variables
  fin >> chrg;
  fin >> rate1;
  fin >> rate2;
  fin >> prev;

  //Read beyond blank line if appropriate
  fin.ignore(numeric_limits<streamsize>::max(), '\n');

  //Format file output
  cout << fixed << showpoint << setprecision(2);

  //Read calculate and write
  while(fin >> year)
  {
    //Read first two fields
    fin >> mint;
    fin >> curr;

    //Calculate units used
    unit = curr - prev;

    //Calculate cost
    if(unit <= 22)
    {
      cost = chrg + (unit * rate1);
    }
    else
    {
      cost = chrg + (22 * rate1) + ((unit - 22) * rate2);
    }

    //Set month abbreviation
    mabbr = setAbbr(mint);

    //Write results to output file
    fout << setw(4) << year  << "  ";
    fout << setw(4) << mabbr << "  ";
    fout << setw(3) << curr  << "  ";
    fout << setw(2) << unit  << "  ";
    fout << setw(6) << cost  << endl;

    //Set previous meter to current
    prev = curr;
  }

  //Close both files
  fin.close();
  fout.close();
}

void putFoot(string ofname)
{
  cout << "Done. To see results:" << endl
       << endl
       << "TYPE " << ofname       << endl
       << endl;
}

//Level 2 Functions
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
