/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 9, 11, 13
 * Program: Pr13b-Pres-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 21, 2017
 *
 * Purpose: Similar to Pr3a-Pres, but also:
 *
 *          -- learn to search an array, to identify
 *             maximum and minimum array values, and
 *             to set and use a boolean indicator
 *
 *          -- review the concatenation of string values
 *
 * Problem: Process data regarding American presidents
 *          as shown in class and in a sample console
 *          document on our course website
 *
 * Data: Two data files called Pr13b-Pres-Real.in and
 *       Pr13b-Pres-Fake.in will be downloadable from
 *       our course website.
 *
 * Submit: Source Program (.cpp) file
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
    string init;
    string gen;
    int birYr;
    int birMo;
    int trmYr;
    int trmMo;
    int age;
};

//Function Prototypes
void putHead();
string getName();
int countRec(string);
void getData(string, int, Pres[]);
void calcAge(int, Pres[]);
void putData(int, Pres[]);
void putFoot(int, Pres[]);

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
  calcAge(count, p);
  putData(count, p);
  putFoot(count, p);

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
       << endl
       << "This program also identifies the"     << endl
       << "maximum and minimum age of all"       << endl
       << "presidents, determines whether any"   << endl
       << "president has been female, and"       << endl
       << "outputs these results too."           << endl
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
    fin >> p[i].init;
    fin >> p[i].gen;
    fin >> p[i].birYr;
    fin >> p[i].birMo;
    fin >> p[i].trmYr;
    fin >> p[i].trmMo;
  }

  fin.close();
}

void calcAge(int count, Pres p[])
{
  for(int i = 0; i < count; i++)
  {
    p[i].age = p[i].trmYr - p[i].birYr;

    if(p[i].trmMo < p[i].birMo)
    {
      p[i].age--;
    }
  }
}

void putData(int count, Pres p[])
{
  //Output Heading
  cout << "                           Birth     Term"      << endl
       << "                         -------  -------"      << endl
       << "Ord  Name             G  Year Mo  Year Mo  Age" << endl
       << "---  ---------------  -  ---- --  ---- --  ---" << endl
       << endl;

  for(int i = 0; i < count; i++)
  {
    cout << setw(3)  << right << p[i].ord         << "  ";
    cout << setw(15) << left  << p[i].last + ", "
                              +  p[i].init        << "  ";
    cout << setw(1)  << left  << p[i].gen         << "  ";
    cout << setw(4)  << right << p[i].birYr       << " ";
    cout << setw(2)  << right << p[i].birMo       << "  ";
    cout << setw(4)  << right << p[i].trmYr       << " ";
    cout << setw(2)  << right << p[i].trmMo       << "  ";
    cout << setw(3)  << right << p[i].age         << endl;
  }

  cout << endl;
}

void putFoot(int count, Pres p[])
{
  int max = p[0].age;
  int min = p[0].age;

  bool female = false;
  //string female = "No";

  //Calculate min, max, and average
  for(int i = 0; i < count; i++)
  {
    if(p[i].age > max)
    {
      max = p[i].age;
    }

    if(p[i].age < min)
    {
      min = p[i].age;
    }

    if(p[i].gen == "F")
    {
      //female = "Yes";
      female = true;
    }
  }

  //Output footer
  cout << setw(41) << right << "Max. age:" << "  ";
  cout << setw(3)  << right << max << endl;
  cout << setw(41) << right << "Min. age:" << "  ";
  cout << setw(3)  << right << min << endl;
  cout << endl;

  cout << setw(41) << right << "Females?"  << "  ";
  //cout << setw(3) << right << female << endl;

  //Redundant if statement but oh well.
  //Can directly call yes or no.
  if(female)
  {
    cout << setw(3) << right << "Yes" << endl;
  }
  else
  {
    cout << setw(3) << right << "No" << endl;
  }

  cout << endl;
}