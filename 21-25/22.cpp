#include<iostream>
#include<string>
#include<cmath>

using namespace std;

const int NormalMonth[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

class Date {

    public:
        Date() : year (1900) , month(1) , day (1) , a("1900/01/01"){}
        
        Date( string _a ) : a(_a){
            
            year = stoi ( a.substr (0,4) );
            month = stoi ( a.substr (5,2) );  
            day = stoi ( a.substr (8,2) );
                
        }
        
        string toString() const {
            return a;
        }

        int CountDay () const {
            
            int DAY = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + (month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
            for(int i = month - 1; i > 0; i-- ) 
                DAY += NormalMonth[i - 1];    

            DAY += day;
            return DAY;
        }

        int operator-(const Date &D ) const {
            
            int DAY = abs( CountDay() - D.CountDay() );
            return DAY;

        }

    private:
        string a;
        int year , month , day;

};

int main () {

    string a ,b;
    getline ( cin , a);
    getline ( cin , b);
    Date A(a),B(b);
    cout << (B-A);
}
