#include<iostream>
#include<cmath>
#include<string>


using namespace std;

class MIPS {

    private:
        string order , Enter1 , Enter2 , Enter3;
    public:

        MIPS ( string _order , string _Enter1 , string _Enter2 , string _Enter3 ) : order(_order) , Enter1(_Enter1) , Enter2(_Enter2) , Enter3(_Enter3) {
        
            if ( order == "addi" ) {
                
                opcode ( order );
                regis ( Enter1 );
                regis ( Enter2 );
                BinaryFormat ( Enter3 );

            }
            else {

                opcode ( order );
                regis ( Enter2 );
                regis ( Enter3 );
                regis ( Enter1 );
                shamt ();
                funct ( order );
            
            }
        }
        
        void opcode ( string order ) {

            if ( order == "add" ) cout << "000000";
            else if ( order == "sub" ) cout << "000000";
            else if ( order == "or" ) cout << "000000";
            else if ( order == "and" ) cout << "000000";
            else if ( order == "addi" ) cout << "001000";
        
        }

        void regis ( string Enter ) {

            string temp = Enter.substr(0, 3);
            if ( temp == "$t0" ) cout << "01000";
            else if ( temp == "$t1" ) cout << "01001";
            else if ( temp == "$t2" ) cout << "01010";
            else if ( temp == "$t3" ) cout << "01011";
            else if ( temp == "$t4" ) cout << "01100";
            else if ( temp == "$t5" ) cout << "01101";
            else if ( temp == "$t6" ) cout << "01110";
            else if ( temp == "$t7" ) cout << "01111";

        }

        void shamt ( ) {
            cout << "00000";
        }

        void funct ( string order ) {
            
            if ( order == "add" ) cout << "100000";
            else if ( order == "sub" ) cout << "100010";
            else if ( order == "or" ) cout << "100101";
            else if ( order == "and" ) cout << "100100";
        
        }

        void BinaryFormat ( string Enter ) {
            
            int N = stoi ( Enter );
            long long digit = 0, ans = 0;
            
            while ( N != 0 ) {
                
                ans += ( N % 2 ) * ( pow ( 10, digit ) );
                N /= 2;
                digit++;
            
            }
        
            if ( digit == 0 ) digit = 1;
            
            for(int i = 0; i < (16 - digit); i++) cout << "0";
            
            cout << ans;
        }   

};

int main () {

    
    string order , Enter1 , Enter2 , Enter3;

    while ( cin >> order >> Enter1 >> Enter2 >> Enter3 ) {
        MIPS ob1( order , Enter1 , Enter2 , Enter3 );
        cout << endl;
    }
    
    
}