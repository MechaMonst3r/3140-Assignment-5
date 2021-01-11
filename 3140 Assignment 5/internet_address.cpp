//Name: Lukas Bowden
//Student Number: T00040951
//Date: 2020-11-03
//Description: Implementation file for the Internet Address class.
#include <iostream>
#include <string>
#include <math.h>
#include "internet_address.h"
using namespace std;

//Default, Parameter, and Copy Constructors
internet_address :: internet_address()
{
 decimal_address = " ";
 binary_address = " ";
 dotted_address = " ";
}

internet_address :: internet_address(string address)
{
 setAddresses(address);
}

internet_address :: internet_address(internet_address& internet_address1)
{
 decimal_address = internet_address1.getDecimalAddress();
 binary_address = internet_address1.getBinaryAddress();
 dotted_address = internet_address1.getDottedAddress();
}

//Destructor
internet_address :: ~internet_address()
{   
}

//All mutators (getters and setters)
string internet_address :: getDecimalAddress()
{
 return decimal_address;
}

string internet_address :: getBinaryAddress()
{
 return binary_address;
}

string internet_address :: getDottedAddress()
{
 return dotted_address;   
}

void internet_address :: setDecimalAddress(string decimal)
{
 decimal_address = decimal;
}

void internet_address :: setBinaryAddress(string binary)
{
 binary_address = binary;    
}

void internet_address :: setDottedAddress(string dotted)
{
 dotted_address = dotted;   
}

//Helper functions to conver strings

//Converts a decimal address to a binary address.
string internet_address :: convertDecimaltoBinary(string decimal)
{
 //Variable to convert the decimal address string to an int.  
 long long dec = stoll(decimal);

 //Instantiated variables
 int remain = 0;
 int count = 0;
 string bin1;
 string bin2;
 string bin3;
 string bin4;
 string completeBin;

 //While the decimal number doesn't equal 0
 while(dec)
 {
  //Collects what the remainder would be of the current decimal divided by 2.   
  remain = dec % 2;
  //Divides the current decimal by 2, stores the result back into the same variable.   
  dec /= 2;
  //Increases the count variable.
  count++;
  if(count < 8)
  {
   //Appends the remainder variable to the binary string.
   bin1 += to_string(remain);
  }
  //If the count variable is equal to 8, it resets the variable to 0 and appends a space to the binary string.
  else if(count > 8 && count < 16)
  {
   bin2 += to_string(remain);   
  }

  else if(count > 16 && count < 24)
  {
   bin3 += to_string(remain); 
  }

  else if(count > 24 && count < 32)
  {
   bin4 += to_string(remain); 
  }
 }

 //While loop to fill in each string with remaining bits
 count = 0;
 while(count != 8)
 {
   if(bin1.length() != 8)
   {
     bin1 = "0" + bin1;
   }

   if(bin2.length() != 8)
   {
     bin2 = "0" + bin2;;
   }

   if(bin3.length() != 8)
   {
     bin3 = "0" + bin3;;
   }

   if(bin4.length() != 8)
   {
     bin4 = "0" + bin4;;
   }

  count++;
 }

 //Puts all string sections into a single string with spaces.
 completeBin = bin1 + " " + bin2 + " " + bin3 + " " + bin4;

 //Returns the completeBin string that contains the binary address.
 return completeBin;
}

//Function that converts a binary address into a decimal address.
string internet_address :: convertBinarytoDecimal(string binary)
{
 //Instantiating variables   
 string noSpaceBin;    
 string decimal;
 int binArr[32];
 int remain = 0;
 int base = 1;
 int result = 0;

 //Loops through the binary address and appends every char except spaces to a new string
 for(int i = 0; i < binary.length(); i++)
 {
  if(binary[i] != ' ')
  {
   noSpaceBin += binary[i];
  }
 }   

 for(int i = 0; i < noSpaceBin.length(); i++)
 { 
   string tempChar = to_string(noSpaceBin[i]);
   binArr[i] = stoi(tempChar);
 }

 for(int i = 0; i < 32; i++)
 {
   result = result*2 + binArr[i];
 }
  
 //Returns the newly created decimal string.
 return decimal = to_string(result); 
}

//Converts a decimal address to a dotted address.
string internet_address :: convertDecimaltoDotted(string decimal)
{
 //cout << "It's happening here on Line 160" << "\n"; 
 //First it converts the Decimal into Binary   
 string bin = convertDecimaltoBinary(decimal);
 //Then converts the binary into a dotted address
 string binToDot = convertBinarytoDotted(bin);
 //Returns the dotted address
 return binToDot;
}

//Converts a Binary address to a Dotted address
string internet_address :: convertBinarytoDotted(string binary)
{
 //cout << "It's happening here on Line 172" << "\n"; 
 //Initializing variables
 string tempSect;
 string dot;
 long long binSect = 0;
 int remain = 0;
 int iterator = 0;
 int index = 0;
 int result;
 int base;
 
 //Runs until it completes every 8 digit section of the binary address.
 while(iterator != 4)
 {
  remain = 0;
  binSect = 0;
  result = 0;   
  base = 1;  
  binSect = 0;
  tempSect = "";

  //Scans through and gets every indiviudal section in the binary address.   
  for(index; index < binary.length(); index++)
  {
    if(binary[index] == ' ')
    {
     index += 1;
     break;   
    } 

   tempSect += binary[index];
  }
  
  //Converts the current binary section into a long variable type
  binSect = stoll(tempSect);
  //While the current section doesn't equal 0, it will conver the section into a number then append it
  //To the dotted address string.
  while(binSect)
  {
   remain = binSect % 10;
   binSect /= 10;

   result += remain*base;
   base *= 2;
  }

  if(iterator != 3)
  {
   dot += to_string(result) + ".";
  }

  else
  {
   dot += to_string(result);   
  } 
  //Increases the iterator variable, indicating the first section of the string is complete.
  iterator++;
 }
 
 //Returns the completed dotted address.
 return dot;
}

//Converts a dotted address into a decimal addresss
string internet_address :: convertDottedtoDecimal(string dotted)
{
  //First converts the dotted address into a binary address.
  string tempBin = convertDottedtoBinary(dotted);
  //Takes the newly created binary address and converts it to a decimal addres.
  string tempDec = convertBinarytoDecimal(tempBin);
  //Returns the new decimal address.
  return tempDec;
}

//Converts a dotted address into a binary addres.
string internet_address :: convertDottedtoBinary(string dotted)
{
 //Variables to use in the function   
 string tempSect;
 long long tempDec = 0;
 string bin1;
 string bin2;
 string bin3;
 string bin4;
 string binComplete;
 int index = 0;
 int remain = 0;
 int iterator = 0;
 int count = 0;

 //Runs until every section of the dotted address has been scanned through.
 while(iterator != 4)
 { 
  tempSect = "";
  tempDec = 0;
  remain = 0;

  //Goes through and grabs each section of the dotted address.   
  for(index; index < dotted.length(); index++)
  {
   if(dotted[index] == '.')
   {
     index += 1;
     break;
   }  
   tempSect += dotted[index];  
  }

  //Converts the current section into a number.
  tempDec = stoll(tempSect);

  //Converts the current section into binary and appends it to a bin address section string.
  while(tempDec)
  {
   remain = tempDec % 2;
   tempDec /= 2;
   
   if(iterator == 0)
   {
    bin1 += to_string(remain);  
   }

   if(iterator == 1)
   {
    bin2 += to_string(remain); 
   }

   if(iterator == 2)
   {
    bin3 += to_string(remain); 
   }

   if(iterator == 3)
   {
    bin4 += to_string(remain);  
   }
  }
  
  iterator++;
 }

 count = 0;
 //Fills in each section with missing diggits.
 while(count != 8)
 {
   if(bin1.length() != 8)
   {
     bin1 = "0" + bin1;
   }

   if(bin2.length() != 8)
   {
     bin2 = "0" + bin2;
   }

   if(bin3.length() != 8)
   {
     bin3 = "0" + bin3;
   }

   if(bin4.length() != 8)
   {
     bin4 = "0" + bin4;
   }

  count++;
 }
 
 //Strings the new binary address together.
 binComplete = bin1 + " " + bin2 + " " + bin3 + " " + bin4;
 //Returns the newly converted binary string.
 return binComplete;
}

void internet_address :: setAddresses(string address)
{
 int decCount = 0;
 int spaceCount = 0;

 //Scans through the string and checks to see what type of address it is, changes bool variables accordingly.
 for(int i = 0; i < address.length(); i++)
 {
   if(address[i] == ' ')
   {
    spaceCount++;
   }

   if(address[i] == '.')
   {
    decCount++;
   } 
 }

 //Converts the address and assigns it to the correct variables accordingly based on given address.
 if(decCount == 0 && spaceCount == 0)
 {
  decimal_address = address;
  binary_address = convertDecimaltoBinary(address);
  dotted_address = convertDecimaltoDotted(address);   
 }

 else if(spaceCount > 0)
 {
  decimal_address = convertBinarytoDecimal(address);
  binary_address = address;
  dotted_address = convertBinarytoDotted(address);   
 }

 else if(decCount > 0 && spaceCount == 0)
 {
  decimal_address = convertDottedtoDecimal(address);
  binary_address = convertDottedtoBinary(address);
  dotted_address = address;
 }
}

//Prints out the addresses stored in the object of the class.
void internet_address :: printAddresses()
{
  cout << "Your address in three different formats: " << "\n";
  cout << "Decimal Format: " << decimal_address << "\n";
  cout << "Binary Format: " << binary_address << "\n";
  cout << "Dotted Decimal Format: " << dotted_address << "\n";
}