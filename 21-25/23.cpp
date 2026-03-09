#include <bits/stdc++.h>

using namespace std;

class DateTime {

    private:
        string a;
        int year , month , day , hour , mint , sec;
    public:

    DateTime ( ) : year(1900) , month(1) , day(1) , hour(0) , mint(0) , sec(0) , a("1900/01/01 00:00:00") {}

    DateTime ( string _a ) : a(_a) {
        /*
        year = stoi ( a.substr (0,4) );
        month = stoi ( a.substr (5,2) );
        day = stoi ( a.substr (8,2) );
        hour = stoi ( a.substr (11,2) );
        mint = stoi ( a.substr (14,2) );
        sec = stoi ( a.substr (17,2) );
        */
    }
    
    string toString() const {
        return a;
    }

};
