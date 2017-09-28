/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 07
 * Program: Pr07a-Vac-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: September 26, 2017
 *
 * Purpose: Learn about conditional logic with
 *          types of statements known as else if
 *          and nested if.
 *
 *          Learn to sound an audible alert with the
 *          escape character '\a' when a user enters
 *          invalid data.
 *
 *          Review continuous looping, and the
 *          toupper() function.
 *
 * Initial
 * Problem: Inform a user of vacation costs for 1
 *          or 2 passengers, depending on the month
 *          of year, and prepare a tentative
 *          reservation.
 *
 * Next
 * Problem: Refine the process to confirm a
 *          reservation.
 */

//Preprocessor Directives
#include<iostream>
#include <string>

using namespace std;

#include <cctype>
//#include <windows.h>

//Main Routine
int main()
{
  //Declare Variables
  string fname;  //First name
  string lname;  //Last name
  string mabbr;  //Month abbreviation (Xxx.)

  int mint;      //Month number (integer)
  int pax;       //Passenger count
  int cost;      //Vacation cost

  char conf;     //Confirmation (Y or N)

  //To the console, output a title and description
  cout << endl;
  cout << "Vacation Program"                   << endl;
  cout << "----------------------------------" << endl;
  cout << endl;
  cout << "Welcome to Dream Vacation Cruises"  << endl
       << "(DVC)! Please look at our prices,"  << endl
       << "then choose a month, and number of" << endl
       << "passengers, for which to possibly"  << endl
       << "reserve a vacation."                << endl;
  cout << endl;

  cout << "Mon.   1 Pax   2 Pax" << endl;
  cout << "----  ------  ------" << endl;
  cout << endl;
  cout << "01    $ 1400  $2100 " << endl
       << "02    $ 1400  $2100 " << endl
       << "03    $ 1400  $2100 " << endl
       << "04    $ 2000  $3000 " << endl
       << "05    $ 2000  $3000 " << endl
       << "06    $ 2000  $3000 " << endl
       << "07    $ 2000  $3000 " << endl
       << "08    $ 2000  $3000 " << endl
       << "09    $ 2000  $3000 " << endl
       << "10    $ 1400  $2100 " << endl
       << "11    $ 1400  $2100 " << endl
       << "12    $ 1400  $2100 " << endl;
  cout << endl;

  //Prompt for a passenger's last and first names
  cout << "Last  name  ? ";
  getline(cin, lname);

  cout << "First name  ? ";
  getline(cin, fname);
  cout << endl;

  //Prompt for a month number, input and validate it
  while(true)
  {
    cout << "Month (1-12)? ";
    cin >> mint;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not an integer \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(mint < 1 || mint > 12)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      break;
    }
  }
  cout << endl;

  //Prompt for a passenger count number,
  //input and validate it
  while(true)
  {
    cout << "Pax   (1- 2)? ";
    cin >> pax;


    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not an integer \a" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    else if(mint < 1 || mint > 12)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      break;
    }
  }
  cout << endl;

  //Assign month abbreviation
  switch(mint)
  {
    case 1  : mabbr = "Jan."; break;
    case 2  : mabbr = "Feb."; break;
    case 3  : mabbr = "Mar."; break;
    case 4  : mabbr = "Apr."; break;
    case 5  : mabbr = "May" ; break;
    case 6  : mabbr = "Jun."; break;
    case 7  : mabbr = "Jul."; break;
    case 8  : mabbr = "Aug."; break;
    case 9  : mabbr = "Sep."; break;
    case 10 : mabbr = "Oct."; break;
    case 11 : mabbr = "Nov."; break;
    case 12 : mabbr = "Dec."; break;
    default : mabbr = "??? "; break;
  }

  //Determine cost
  if((mint >=  1 && mint <=  3)
  || (mint >= 10 && mint <= 12))
  {
    if(pax == 1)
    {
      cost = 1400;
    }
    else if(pax == 2)
    {
      cost = 2100;
    }
    /*
     * switch(pax)
     * {
     *   case 1 : cost = 1400;
     *   case 2 : cost = 2100;
     * }
     */
  }
  else if(mint >= 4 && mint <= 9)
  {
    if(pax == 1)
    {
      cost = 2100;
    }
    else if(pax == 2)
    {
      cost = 3000;
    }
    /*
     * switch(pax)
     * {
     *   case 1 : cost = 2100;
     *   case 2 : cost = 3000;
     * }
     */
  }
  else
  {
    cost = 0;
  }

  //Output greeting
  cout << "Hello, " << fname << " "
                    << lname << "." << endl;
  cout << endl;

  //Output reservation results
  cout << "Your vacation for " << pax;
  if(pax == 1)
  {
    cout << " passenger ";
  }
  else if(pax == 2)
  {
    cout << " passengers ";
  }
  /*
   * switch(pax)
   * {
   *   case 1 : cout << " passenger ";
   *   case 2 : cout << " passengers ";
   * }
   */
  cout << "in " << mabbr
       << " would cost $ " << cost
       << endl;
  cout << endl;

  //Output and check confirmation,
  //then output response
  while(true)
  {
    cout << "Confirm (Y or N)? ";
    cin >> conf;
    cout << endl;

    if(toupper(conf) != 'Y' && toupper(conf) != 'N')
    {
      cout << "Error: Please enter either Y or N"
           << endl;
      //cin.clear();
      //cin.ignore(1000, '\n');
    }
    else
    {
      if(toupper(conf) == 'Y')
      {
        cout << "Thanks for your reservation.";
      }
      else if(toupper(conf) == 'N')
      {
        cout << "Maybe another time.";
      }
      /*
       * switch(toupper(conf))
       * {
       *   case 'Y' : cout << "Thanks for your reservation."; break;
       *   case 'N' : cout << "Maybe another time."; break;
       * }
       */
      break;
    }
  }
}