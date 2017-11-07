/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 11
 * Program: Pr11a-RevProf-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 02, 2017
 *
 * Purpose: Introduce arrays and sorting.
 *
 *          Review constant value, function,
 *          and file input.
 *
 * Problem: Create a data file called
 *
 *          Pr11a-RevProf-Agopian-Armand.in
 *
 *          where you use your last and first names.
 *
 *          Into that file, type the names of 15 top
 *          technology companies, along with their
 *          revenues and profits for one somewhat
 *          recent year. The data should appear in
 *          descending order by revenues.
 *
 *          For a source of this data, refer to a
 *          NetworkWorld magazine article at
 *
 *          https://www.networkworld.com/article/2940537/
 *
 *          Write a program that processes data from
 *          the file you create, as described in a
 *          related console document.
 *
 *          Watch and listen in class, and refer
 *          to a console document for more information.
 *
 *          Simultaneously submit:
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
  int j;              //Array index
  int count;          //Record count

  string stemp;       //Temporary string

  int itemp;          //Temporary integer

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

  //Sort arrays
  for(i = 0; i < count; i++)
  {
    for(j = i + 1; j < count; j++)
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

  //Output headings
  cout << endl
       << "Company      Revenue  Profit" << endl
       << "-----------  -------  ------" << endl
       << endl;

  //Output array values
  for(i = 0; i < count; i++)
  {
    cout << setw(11) << left  << comp[i] << "  ";
    cout << setw(7)  << right << rev[i]  << "  ";
    cout << setw(6)  << right << prof[i] << endl;
  }

  //Calculate and output total
  cout << endl;
  cout << setw(11) << left  << "Total" << "  ";
  cout << setw(7)  << right << totrev  << "  ";
  cout << setw(6)  << right << totprof << endl;
  cout << endl;
}