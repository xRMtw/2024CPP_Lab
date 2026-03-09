#include<bits/stdc++.h>

using namespace std;

class PirmeTest {
    private:
        int Number;
        int reverseN;

    public:

        PirmeTest () : Number(0) , reverseN(0) {}
        
        void setNumber ( int a ) {
            Number = a;
        }

        int getNumber () {
            return Number;
        }

        bool testPirme () {
            for ( int i = 2 ; i < (int)sqrt(Number) + 1  ; i++ ) {
                if ( Number % i == 0 ) {
                    return false;
                }
            }
            return true;
        }

        void reverseNumber () {
            int temp = Number;
            reverseN = 0;
            while ( temp  ) {
                reverseN *=10;
                reverseN = reverseN + temp % 10;
                temp = temp /10;
            }
        }

        bool testEmrip () {
            if ( Number == reverseN ) return false;
            for ( int i = 2 ; i < (int)sqrt(reverseN) + 1  ; i++ ) {
                if ( reverseN % i == 0 ) {
                    return false;
                }
            }
            return true;
        }

};

int main ( ) {

    int n;
    while ( cin >> n ) {
        
        PirmeTest p;
        if (  n >= 1000000 || n <= 1 ) break;
        p.setNumber(n);

        if ( p.testPirme() ) {
            
            p.reverseNumber();

            if ( p.testEmrip() ) {
                cout << p.getNumber() << " is emirp." << endl;
            }
            else {
                cout << p.getNumber() << " is prime." << endl;
            }

        }
        else {
            cout << p.getNumber() << " is not prime." << endl;
        }
    }
    return 0;
}