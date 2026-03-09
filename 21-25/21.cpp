#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Time {
    public:
        Time() : a("00:00:00") {}
        Time( string _a ) : a(_a) {}
        
        string toString() const {
            return a;
        }

        int operator-(const Time &T) const {
            
            int Hour = stoi ( a.substr (0,2) ) -  stoi( T.toString().substr (0,2) );
            int Min = stoi ( a.substr (3,2) ) -  stoi( T.toString().substr (3,2) );
            int Sec = stoi ( a.substr (6,2) ) -  stoi( T.toString().substr (6,2) );
            
            Hour *= 3600;
            Min *=60;

            int TotalSec = Hour + Min + Sec;

            return abs(TotalSec);

        }

    private:
        string a;
};

int main () {
    
    string a ,b;
    getline ( cin , a);
    getline ( cin , b);
    Time A(a) , B(b);
    cout << (A-B);

}