#include<bits/stdc++.h>

using namespace std;

int main() {
    
    string key = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char in;
    int temp;

    while (cin.get(in)) {
        
        if (in == ' ' || in == '\n' || in == '\t') {
            cout << in;

        } 
        else {

            in = tolower(in);
            temp = key.find(in);

            if ( temp > 1) {
                cout << key[temp - 2];
            } 
            
            else {
                cout << in;
            }
        }
    }
    
    return 0;

}
