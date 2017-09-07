/*
 * School: Diablo Valley College
 * Term: 2017 Fall
 * Course: ComSc-110-3120,
 *         Introduction to Programming with C++
 *
 * Chapter: 05
 * Program: Pr05a-Client-Agopian-Armand.cpp
 * Author: Agopian, Armand
 * Date: September 7, 2017
 *
 * Purpose: Create a program that interactively inputs
 *          data from the console, edits that data,
 *          and confirms the results to the console.
 *
 *          Learn about these commands and functions:
 *          cin, getline(), at(), and toupper().
 *
 * Initial
 * Problem: At the console, prompt a user to input the
 *          name and address of a client, and to actually
 *          input the data.
 *
 *          Edit the data by concatenating the
 *          client's last and first names into a
 *          combined field called name, with a comma
 *          and space between the two parts of the name.
 *
 *          At the console, output a confirmation of data
 *          that was input and edited.
 *
 *          For more information, listen in class,
 *          watch the big screen, and refer to our
 *          course web site for a console sample.
 *
 * Next
 * Problem: Declare a field called loc (for location)
 *          of a type that can hold letters, digits,
 *          and punctuation marks.
 *
 *          Further edit the data. Force the state
 *          code to uppercase.
 *
 *          Also, concatenate city name,
 *          a comma and space, state code, two spaces,
 *          and zip code into the new field called loc.
 *
 *          When confirming data, output the loc field
 *          for the client's address. Do NOT output
 *          city state, and zip as separate fields.
 */

//Preprocessor Directives
#include<iostream>
#include<string>

using namespace std;

#include<cctype>

//Main Routine
int main()
{
  //Declare Variables
  string lname;   //Client last  name
  string fname;   //Client first name
  string name;    //Cleint       name

  string street;  //Client street address
  string city;    //Client city name
  string state;   //Client state code
  string zip;     //Client zip code

  string loc;     //Client combined location

  //To the console, output program title
  cout << endl;
  cout << "Client Program         " << endl;
  cout << "-----------------------" << endl;

  //Next, ask for each parameter, and save them
  //to their respective variables

  cout << endl;
  cout << "Input:" << endl;

  cout << "  Last name     ? ";
  //cin.ignore(50,'\n');
  getline(cin, lname);

  cout << "  First name    ? ";
  //cin.ignore(50,'\n');
  getline(cin, fname);

  cout << "  Street Address? ";
  getline(cin, street);

  cout << "  City          ? ";
  getline(cin, city);

  cout << "  State (XX)    ? ";
  getline(cin, state);

  cout << "  Zip Code      ? ";
  getline(cin, zip);

  //Format output
  name = lname + ", " + fname;

  state.at(0) = toupper(state.at(0));
  state.at(1) = toupper(state.at(1));
  loc = city + ", " + state + "  " + zip;

  //Confirm the input by outputting
  //formatted results
  cout << "Output:" << endl;
  cout << "  Name          : " << name << endl;
  cout << "  Street        : " << street << endl;
  cout << "  Location      : " << loc;
}
