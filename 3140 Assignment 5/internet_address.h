//Name:Lukas Bowden
//Student Number: T00040951
//Date: 2020-11-03
//Description: Header file for the Internet Address class.
#include <string>
using namespace std;
#ifndef ADDRESS_DEF
#define ADDRESS_DEF

class internet_address
{
 private:
      string decimal_address;
      string binary_address;
      string dotted_address;

 public:
      internet_address();
      internet_address(string address);
      internet_address(internet_address& internet_address1);
      ~internet_address();
      string getDecimalAddress();
      string getBinaryAddress();
      string getDottedAddress();
      void setDecimalAddress(string decimal);
      void setBinaryAddress(string binary);
      void setDottedAddress(string dotted);
      string convertDecimaltoBinary(string decimal);
      string convertBinarytoDecimal(string binary);
      string convertDecimaltoDotted(string decimal);
      string convertBinarytoDotted(string binary);
      string convertDottedtoDecimal(string dotted);
      string convertDottedtoBinary(string dotted);
      void printAddresses();
      void setAddresses(string address);
};

#endif
