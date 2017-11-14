/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 12
 * Program: Pr12b-Weather-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 14, 2017
 *
 * Purpose: Similar to program 12a.
 *
 *          Also, learn to sort based on two data
 *          fields, not just one.
 *
 *          Review averaging, and the switch-case construct.
 *
 * Problem: As a basis for this program, you may
 *          copy much of your own assignment Pr12a.
 *
 *          For details about the current assignment,
 *          see below, watch and listen in class, and
 *          refer to our course website's sample
 *          console file, which also includes a
 *          hierarchy char of program functions.
 *
 # Submit: Just a source program (.cpp) file.
 */

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Structure and Constant
struct Weather
{
    string loc;   //Location
    int year;     //Year
    int mint;     //Month Integer
    double rain;  //Rainfall
    double temp;  //Temperature
};

const int SIZE = 120;

//Function Prototypes
void putHead();
string getName();
int getData(string, Weather[]);
void sortData(int, Weather[]);
void putData(int, Weather[]);
void putFoot(int, Weather[]);
string setAbbr(int);

//Main Routine
int main()
{
  //Declare Variables
  string ifname;

  int count;

  Weather w[SIZE];

  //Call functions
  putHead();

  ifname = getName();

  count = getData(ifname, w);

  sortData(count, w);
  putData(count, w);
  putFoot(count, w);

  return 0;
}

//Level 1 Functions
void putHead()
{
  cout << endl
       << "Weather Program"                  << endl
       << "--------------------------------" << endl
       << endl;

  cout << "For one weather reporting location,"  << endl
       << "this program sorts records in"        << endl
       << "descending order by year and month,"  << endl
       << "then displays a rainfall amount and"  << endl
       << "mean temperature for each record,"    << endl
       << "followed by totals and averages."     << endl
       << endl;
}

string getName()
{
  ifstream fin;
  string ifname;

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
      cout << "Invalid \a\n";
    }
  }

  cout << endl;

  return ifname;
}

int getData(string ifname, Weather w[])
{
  //Get records of monthly weather data and store
  //them in a single array with multiple fields

  //Declare Variables
  ifstream fin;

  int i;
  int count;

  i = 0;

  //Get and store data
  fin.open(ifname);

  while(fin >> w[i].loc)
  {
    fin >> w[i].year;
    fin >> w[i].mint;
    fin >> w[i].rain;
    fin >> w[i].temp;

    i++;
  }

  fin.close();

  count = i;

  return count;
}

void sortData(int count, Weather w[])
{
  Weather t;  //Temp weather object

  //Sort logic
  for(int i = 0; i < count; i++)
  {
    for(int j = i + 1; j < count; j++)
    {
      if(w[i].mint < w[j].mint)
      {
        t = w[i];
        w[i] = w[j];
        w[j] = t;
      }

      if(w[i].year < w[j].year)
      {
        t = w[i];
        w[i] = w[j];
        w[j] = t;
      }
    }
  }
}

void putData(int count, Weather w[])
{
  //Header
  cout << endl
       << "Loc  Year  Mon    Rain    Temp" << endl
       << "---  ----  ----  -----  ------" << endl
       << endl;

  cout << fixed << showpoint;

  for(int i = 0; i < count; i++)
  {
    cout << setw(3) << w[i].loc << "  ";
    cout << setw(4) << right << w[i].year << "  ";
    cout << setw(3) << right << setAbbr(w[i].mint) << "  ";
    cout << setw(5) << right << setprecision(2)
         << w[i].rain << "  ";
    cout << setw(6) << right << setprecision(1)
         << w[i].temp << endl;
  }
}

void putFoot(int count, Weather w[])
{
  //Declare Variables
  double totrain = 0;
  double tottemp = 0;

  //Calculate totals
  for(int i = 0; i < count; i++)
  {
    totrain += w[i].rain;
    tottemp += w[i].temp;
  }

  //Output totals
  cout << endl;
  cout << setw(17) << left << "Total";
  cout << setw(5)  << right << setprecision(2)
       << totrain << "  ";
  cout << setw(6)  << right << setprecision(1)
       << tottemp << endl;

  //Output averages
  cout << setw(17) << left << "Avergae";
  cout << setw(5)  << right << setprecision(2)
       << (totrain / count) << "  ";
  cout << setw(6)  << right << setprecision(1)
       << (tottemp / count) << endl;
  cout << endl;
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