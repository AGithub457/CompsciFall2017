/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 11.3 & 13
 * Program: Pr13a-Pres-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 16, 2017
 *
 * Purpose: Learn about declaring an array that has a
 *          dynamic size, counting records in an
 *          input file, and passing by reference a
 *          dynamic array among functions.
 *
 *          Review creating a C++ structure, basing an
 *          array on a structure, inputting data from
 *          a file into an array, using an if
 *          statement to adjust a value, and neatly
 *          outputting data to the console.
 *
 * Problem: Process data regarding American presidents
 *          as described in class and in a sample
 *          console document on our course website.
 *
 * Data: A data file called Pr13a-Pres.in will be
 *       downloadable from our course website.
 *
 # Submit: Source Program (.cpp) file
 */

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Structure
struct Pres
{
    int ord;
    string last;
    string first;
    string mid;
    string st;
    int birYr;
    int birMo;

};
//Function Prototypes
void putHead();
string getName();
int countRec(string);
void getData(string, int, Pres[]);
void putData(int, Pres[]);
string setAbbr(int);

//Main Routine
int main()
{
  //Variables
  string ifname;

  int count;  //Record count

  Pres* p;  //President pointer to array

  putHead();

  ifname = getName();

  count = countRec(ifname);

  p = new Pres[count];

  getData(ifname, count, p);
  putData(count, p);

  return 0;
}

void putHead()
{
  cout << endl
       << "President Program"                 << endl
       << "---------------------------------" << endl
       << endl;

  cout << "This program asks for the name of a"  << endl
       << "file of data about American"          << endl
       << "presidents, validates the file name," << endl
       << "counts the file's records, inputs"    << endl
       << "records into a dynamically-sized"     << endl
       << "array, and output results to the"     << endl
       << "console."                             << endl
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

int countRec(string ifname)
{
  ifstream fin;

  string rec;

  int count = 0;  //Record count

  //Count records
  fin.open(ifname);

  while(getline(fin, rec))
  {
    count++;
  }

  fin.close();

  return count;
}

void getData(string ifname, int count, Pres p[])
{
  ifstream fin;

  fin.open(ifname);

  //Store data into each President object in the array
  for(int i = 0; i < count; i++)
  {
    fin >> p[i].ord;
    fin >> p[i].last;
    fin >> p[i].first;
    fin >> p[i].mid;
    fin >> p[i].st;
    fin >> p[i].birYr;
    fin >> p[i].birMo;
  }

  fin.close();
}

void putData(int count, Pres p[])
{
  //Output Heading
  cout << endl
       << "Ord  Last Name   First Name  Mid   St  Year  Mo  Mabbr" << endl
       << "---  ----------  ----------  ----  --  ----  --  -----" << endl
       << endl;

  for(int i = 0; i < count; i++)
  {
    if(p[i].mid == ".")
    {
      p[i].mid = "";
    }

    cout << setw(3)  << right << p[i].ord            << "  ";
    cout << setw(10) << left  << p[i].last           << "  ";
    cout << setw(10) << left  << p[i].first          << "  ";
    cout << setw(4)  << left  << p[i].mid            << "  ";
    cout << setw(2)  << left  << p[i].st             << "  ";
    cout << setw(4)  << right << p[i].birYr          << "  ";
    cout << setw(2)  << right << p[i].birMo          << "  ";
    cout << setw(4)  << left  << setAbbr(p[i].birMo) << "  ";
    cout << endl;
  }

  cout << endl;
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