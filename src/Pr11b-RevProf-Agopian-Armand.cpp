/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 
 * Program: Pr11b-RevProf-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 07, 2017
 *
 * Purpose: Learn to divide a large function into
 *          several lower-level functions.
 *
 *          This will involve passing arrays by
 *          reference among functions.
 *
 * Initial
 * Problem: Similar to assignment Pr11a, but
 *          from the procData function. call
 *          separate functions to sort data,
 *          to output resulting data, and to
 *          output footings with statistics.
 *
 * Submit: Simultaneously submit:
 *         -- source program file (.cpp)
 *         -- input data file (.in)
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
void sortData(int, string[], int[], int[]);
void putData(int, string[], int[], int[]);
void putFoot(int, int, int);

//Constant Values
const int SIZE = 20;  //Array size

//Main Routine
int main()
{
  string ifname;

  putHead();

  ifname = getName();

  procData(ifname);

  return 0;
}

//Level 1 Functions
void putHead()
{
  cout << endl
       << "Revenue and Profit Program"         << endl
       << "---------------------------------"  << endl
       << endl;

  cout << "Regarding 15 top technology"        << endl
       << "companies, this program sorts"      << endl
       << "their names, revenues, and profits" << endl
       << "in descending order by profits,"    << endl
       << "then outputs results to the"        << endl
       << "console."                           << endl
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

void procData(string ifname)
{
  //Declare Variables
  ifstream fin;       //Input file object

  string comp[SIZE];  //Company name

  int rev[SIZE];      //Revenue ($ millions)
  int prof[SIZE];     //Profit  ($ millions)

  int i;              //Array index
  int count;          //Record count

  int totrev;         //Total revenue
  int totprof;        //Total profit

  //Initialize Variables
  i = 0;

  totrev = 0;
  totprof = 0;

  //Input values from file, and store in array
  fin.open(ifname.c_str());

  while(fin >>comp[i])
  {
    fin >> rev[i];
    fin >> prof[i];

    totrev += rev[i];
    totprof += prof[i];

    i++;
  }

  fin.close();

  count = i;

  //Sort Arrays
  sortData(count, comp, rev, prof);

  //Output Data
  putData(count, comp, rev, prof);

  //Output Total and Average
  putFoot(count, totrev, totprof);
}

//Level 2 Functions
void sortData(int count, string comp[], int rev[], int prof[])
{
  //Declare Variables
  string stemp;

  int itemp;

  //Sort arrays
  for(int i = 0; i < count; i++)
  {
    for(int j = i + 1; j < count; j++)
    {
      if(prof[i] < prof[j])
      {
        stemp = comp[i];
        comp[i] = comp[j];
        comp[j] = stemp;

        itemp = rev[i];
        rev[i] = rev[j];
        rev[j] = itemp;

        itemp = prof[i];
        prof[i] = prof[j];
        prof[j] = itemp;
      }
    }
  }
}

void putData(int count, string comp[], int rev[], int prof[])
{
  //Output headings
  cout << endl
       << "Company          Revenue       Profit" << endl
       << "-----------      -------       ------" << endl
       << endl;

  //Output array values
  for(int i = 0; i < count; i++)
  {
    cout << setw(11) << left  << comp[i] << "      ";
    cout << setw(7)  << right << rev[i]  << "       ";
    cout << setw(6)  << right << prof[i] << endl;
  }
}

void putFoot(int count, int totrev, int totprof)
{
  //Calculate and output total

  cout << fixed << showpoint << setprecision(3);

  cout << endl;
  cout << setw(11) << left  << "Total" << "    ";
  cout << setw(9)  << right << totrev  << "  ";
  cout << setw(11)  << right << totprof << endl;
  cout << setw(11) << left  << "Average" << "    ";
  cout << setw(9)  << right << (double)totrev / count  << "  ";
  cout << setw(11)  << right << (double)totprof / count << endl;
  cout << endl;
}