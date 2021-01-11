//Name:Lukas Bowden
//Student Number: T00040951
//Date: 2020-11-04
//Description: Driver file for the Internet Address class.
#include <iostream>
#include <string>
#include "internet_address.h"
#include "internet_address.cpp"
using namespace std;

int main()
{
 //Creates an array because cin doesn't use spaces in input.   
 char userInput[36] = {" "};
 string input;

 //Gets input and stores each char into the array.
 cout << "Enter your Internet Address (to quit : -1)";
 cin.getline(userInput, 36); 

 //Loops through the array and converts every char into a single string.
 for(int i = 0; i < 36; i++)
 {
  if(userInput != "")
  {   
   input += userInput[i];
  }    
 }

 //Passes the newly created string to an internet address object.
 internet_address userAddress(input);

 //While loop that continues until the user enters -1.
 while(input != "-1")
 {

  //Clears the input and array to get more user input.
  input = "";
  for(int i = 0; i < 36; i++)
  {
   userInput[i] = ' ';
  }

  //Prints the addresses stored in the object.
  userAddress.printAddresses();
  
  //Asks for user input once again.
  cout << "\n";
  cout << "Enter your Internet Address (to quit : -1)";
  cin.getline(userInput, 36); 

  for(int i = 0; i < 36; i++)
  {
   if(userInput != " ")
   {    
    input += userInput[i];
   }       
  }
  cout << "\n";
  
  //Sets all addresses in the current object to a new address.
  userAddress.setAddresses(input);
 }

 cout << "Thanks for using my program!";
 return 0;   
}