/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 14
 * Program: Pr14a-State-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: November 28, 2017
 *
 * Purpose: Learn about an Excel formatted text (.prn)
 *          print data file, a C++ list of nodes, and
 *          a program debugging technique.
 *
 *          Review declaring and using a Boolean variable.
 *
 * Problem: Process data regarding American states
 *          as described and shown in a sample console
 *          document on our course website.
 *
 # Submit: -- C++ source program:

              Pr14a-State-Agopian-Armand.cpp

           -- Excel formatted text print data file
              (version 2 that is edited to work)

              Pr14a-State-Agopian-Armand-Ver2.prn
 */

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Structure
struct State
{
  int ord;

  string ID;
  string name;

  int admYr;
  int admMo;

  State* next;
};

//Function Prototypes
void putHead();
string getName();
State* getData(string);
void putData(State*);

//Global Variable
bool debug = false;

//Main Routine
int main()
{
  if (debug)
  {
    cout << "**main" << endl;
  }

  //Declare Variables
  string ifname;
  State* start;

  putHead();

  ifname = getName();

  start = getData(ifname);

  putData(start);

  return 0;
}

void putHead()
{
  if(debug)
  {
    cout << "**putHead" << endl;
  }

  cout << "State Program"                        << endl
       << "------------------------------------" << endl
       << endl;

  cout << "This pogram asks for the name of a"   << endl
       << "formatted text (.prn) print file"     << endl
       << "about American sttes, validates the"  << endl
       << "file's existence, inputs records"     << endl
       << "from the file, inserts them as nodes" << endl
       << "at the head of a linked list, then"   << endl
       << "outputs the list to the console"      << endl
       << endl;
}

string getName()
{
  if(debug)
  {
    cout << "**getName" << endl;
  }

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

State* getData(string ifname)
{
  if(debug)
  {
    cout << "**getData" << endl;
  }

  ifstream fin;

  State* start;   //Pointer to starting node

  State* s;       //Pointer to new State node

  start = 0;      //Start node is initially null

  s = new State;  //New State node

  //Input and insert
  fin.open(ifname);

  while(fin >> s->ord)
  {
    fin >> s->ID;
    fin >> s->name;
    fin >> s->admYr;
    fin >> s->admMo;

    if(debug)
    {
      cout << "**s->ord  : " << s->ord
           << ", s->ID   : " << s->ID
           << ", s->name : " << s->name
           << ", s->admYr: " << s->admYr
           << ", s->admMo: " << s->admMo << endl;
    }

    s->next = start;  //Save start pointer

    start = s;        //Place current node at start

    s = new State;    //Make new State node
  }

  fin.close();

  return start;
}

void putData(State* start)
{
  //Output heading and nodes from the linked list

  if(debug)
  {
    cout << "**putData" << endl;
  }

  //Declare variables
  State* s;  //State node pointer

  //Output headings
  cout << "                         Admission" << endl
       << "                         ---------" << endl
       << "Ord  ID  Name            Year   Mo" << endl
       << "---  --  --------------  ----   --" << endl
       << endl;

  //Output nodes
  for(s = start; s; s = s->next)
  {
    cout << setw(3)  << right << s->ord   << "  "
         << setw(2)  << right << s->ID    << "  "
         << setw(14) << left  << s->name  << "  "
         << setw(4)  << right << s->admYr << "   "
         << setw(2)  << right << s->admMo << endl;
  }

  cout << endl;
}