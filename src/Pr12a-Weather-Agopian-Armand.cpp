/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 12
 * Program: Pr12a-Weather-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 09, 2017
 *
 * Purpose: Introduce a C++ data structure.
 *
 *          Pass by reference among functions
 *          an array based on a C++ structure.
 *
 * Problem: From a file on our website, inout five
 *          columns of weather data for six years,
 *          and store the data in a single array
 *          based on a C++ structure.
 *
 *          From the weather array, output the
 *          data to the console.
 *
 * Submit: Just  source program file (.cpp)
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
void putData(int, Weather[]);
void putFoot(int, Weather[]);


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

  return 0;
}

//Level 1 Functions
void putHead()
{
  cout << endl
       << "Weather Program"                  << endl
       << "--------------------------------" << endl
       << endl;

  cout << "For one weather reporting location"   << endl
       << "and for each year and month on file," << endl
       << "this program displays a rainfall"     << endl
       << "amount and a mean temperature"        << endl
       << "followed by totals."                  << endl
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
  }
}

void putData(int count, Weather w[])
{

}

void putFoot(int count, Weather w[])
{

}