/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 08
 * Program: Pr08a-Pop-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: October 05, 2017
 *
 * Purpose: Learn about functions, including return
 *          values (also known as error levels).
 *
 *          Review console input, validation, counting,
 *          accumulating, averaging, formatting and
 *          console output.
 *
 * Problem: Use a function to output a program
 *          heading.
 *
 *          Use another function to get and validate
 *          population figures. For a program
 *          description, see the main routine.
 *
 *          In that function, if a population figure
 *          is not zero, consider it invalid if it is
 *          less than or equal to 1 million
 *          or greater than 4 million.
 *
 *          In the main routine, format and output
 *          the sum and count of population figures.
 *
 *          Use a function to calculate, format, and
 *          output an average.
 *
 *          To the operating system, send back either
 *          zero to indicate a positive count, or else
 *          a non-zero value.
 *
 *          Use a batch file to run the program and
 *          to display the error level.
 *
 *          Watch and listen in class, and refer to a
 *          console document for more information.
 *
 *          When done, submit both source (.cpp) and
 *          batch (.bat) files.
 */

//Preprocessor Directives
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

//Functions
void putHead()
{
  //Output title and description
  cout << endl
       << "Population Program"                  << endl
       << "------------------------------------"<< endl
       << endl;

  cout << "Research and enter the populations"  << endl
       << "of California's three most populous" << endl
       << "cities, each rounded to the nearest" << endl
       << "thousand. When done, enter 0."       << endl
       << endl;

  cout << "This program then calculates and"    << endl
       << "output a sum, count and average."    << endl
       << endl;
}

int getPop()
{
  int pop;  //Population

  //Get and validate population
  while(true)
  {
    cout << "Pop ? ";
    cin >> pop;

    if(cin.fail())
    {
      cout << "Error: Not a number   \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Max character size
    }
    else if(cin.peek() != '\n')
    {
      cout << "Error: Not an integer \a" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(pop == 0)
    {
      return pop;
    }
    else if(pop <= 1000 || pop > 4000)
    {
      cout << "Error: Out of range   \a" << endl;
    }
    else
    {
      return pop;
    }
  }
}

void calcAvg(int sum, int count)
{
  //Calculate and output average population
  double avg;  //Average population

  //Format Output
  cout << fixed << showpoint << setprecision(1);

  //Output Average
  if(count == 0)
  {
    avg = 0;
  }
  else
  {
    avg = (double) sum / count;
  }

  cout << "Avg  : " << setw(5) << avg << endl;
}

int main()
{
  //Declare and Initialize Variables
  int pop;        //Population
  int sum   = 0;  //Sum
  int count = 0;  //Count

  //Header
  putHead();

  //Get population, accumulate sum, and increment count
  while(true)
  {
    pop = getPop();

    if(pop == 0)
    {
      break;
    }

    sum += pop;  //Accumulate sum
    count++;     //Iterate counter
  }

  /*//Other Method
  do
  {
    pop = getPop();

    if(pop != 0)
    {
      sum += pop;
      count++;
    }
  } while(pop != 0);*/

  //Format Output
  cout << fixed;

  //Output Sum and Count
  cout                                  << endl;
  cout << "Sum  : " << setw(5) << sum   << endl;
  cout << "Count: " << setw(5) << count << endl;

  //Calculate and Output Average
  calcAvg(sum, count);

  //To OS, return error level
  if(count > 0)
  {
    return 0;
  }
  else
  {
    return 4;
  }
}