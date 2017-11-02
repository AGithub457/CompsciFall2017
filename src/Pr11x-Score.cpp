//Experiment with an array

//Preprocessor Directives
#include <fstream>
#include <iostream>

using namespace std;

//Constant
const int SIZE = 8;

//Main Routine
int main()
{
  //Declare Variables
  ifstream fin;

  int score[SIZE];

  int i;
  int sum   = 0;
  int count = 0;

  float avg;

  cout << endl
       << "Score Program" << endl
       << "-------------" << endl
       << endl;

  fin.open("Pr11x-Score.in");

  for(i = 0; i < SIZE; i++)
  {
    fin >> score[i];

    cout << score[i] << endl;

    sum += score [i];
  }

  fin.close();

  avg = (float)sum / SIZE;

  for(i = 0; i < SIZE; i++)
  {
    if(score[i] > avg)
    {
      count++;
    }
  }

  cout << endl
       << "Average score: " << avg   << endl
       << "Above average: " << count << endl;

  return 0;
}