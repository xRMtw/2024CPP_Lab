#include<iostream>
#include<string>

using namespace std;

class Anagram : public string {
    
    public:

        Anagram ( string _ang ) {

            for ( int i = 0 ; i < _ang.length() ; i ++ ) {
                if ( isalpha( _ang[i] ) ) {

                    ang += tolower( _ang[i] );

                }
            }
        }

        bool operator==(const Anagram &str) const {
            int Count[26] = {0};
            if ( str.ang.length() != ang.length() ) 
                return false;
            
            for ( int i = 0 ; i < ang.length() ; i++ ) {
                Count[ ang[i] - 'a' ] ++;
            } 
            for ( int i = 0 ; i < ang.length() ; i++ ) {
                Count[ str.ang[i] - 'a' ] --;
            } 

            bool test = 1;

            for ( int i = 0 ; i < 26 ; i++ ) {
                if ( Count[i] != 0 ) {
                    test = 0;
                    break;
                }
            }
            return test;
            
        };

    private:

        string ang = "";
};


int main() {
    
    string buf;
    getline(cin, buf);
    
    Anagram a1(buf);
    getline(cin, buf);
    
    Anagram a2(buf);
    
    cout << (a1 == a2) << endl;
    cout << (a2 == a1) << endl;

}

//判斷是否為字母 isalpha
//判斷是否為大寫字母isupper
//把大寫字母換成小寫tolower
//把小寫字母換成大寫toupper