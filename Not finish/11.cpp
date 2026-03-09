#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Digit { // class Digit represent a digit in base 10
  int digit;
public:
  Digit(int d = 0) : digit(d % 10) {}
  void setDigit(int d) { digit = d % 10; }
  int getDigit() const {return digit;}
};

class Integer { //class Integer represent a poistive integer
  Digit value[1000];
public:

  //construct an integer in base 10 using a string.
  //This constructor will convert the given string to integer if possible.
  //Otherwise it will convert the digit part in prefix of the given string.
  Integer( string n );

  //default constructor will construct an Integer object with value 0.
  Integer() {
    Integer value[0];
  };

  //Display the value in given base from 2 to 16.
  //Order of symbol as 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.
  void displayInBase(int base) const {
    int TEMP = 0;
    long long digit = 0, ans = 0;
        while ( TEMP != 0 ) {
                
            ans += ( TEMP % base ) * ( pow ( 10, digit ) );
            TEMP /= base;
            digit++;
        }
        
  }; 
  
};

int main() {

  string in;
  int j;
  cin >> in;
  Integer i(in);
  for(j = 2;j <= 16;j ++) {
    i.displayInBase(j);
    cout << endl;
  }

}
