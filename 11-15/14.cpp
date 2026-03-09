#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Palindrome {
    
    private:
    
        int n;
        vector<int> Arr;
        vector<vector<int>> Number;

    public:

        void Scannumber () {
            
            cin >> n;
            Arr.resize( n );
            for ( int i = 0 ; i < n ; i ++ ) {
                cin >> Arr[i];
            }       
        
        }
            
        bool TestPali ( int k ) {

            string P1 = to_string(k);
            string P2 = P1;
            reverse(P1.begin(), P1.end());

            if ( P1 == P2 ) {
                return true;
            }
            else {
                return false;
            }

        }

        void CountPali () {
            
            Number.resize( n , vector<int>(2) );
            
            for ( int i = 0 ; i < n ; i ++ ) {
                
                int count = 0;
                int temp = Arr[i];
                while (1) {
                    
                    
                    temp = Pali( temp );
                    count ++;
                    if ( TestPali( temp ) == true ) break; 
                    
                }
                Number[i][0] = count;
                Number[i][1] = temp;
            }
        
        }
        

        int Pali ( int A ) {
            
            string Pa = to_string (A);
            reverse( Pa.begin(), Pa.end());

            int Ans = stoi(Pa) + A;

            return Ans;

        }

        void Print () {

            for ( int i = 0 ; i < n ; i ++ ) {
                cout << Number[i][0] << " " << Number[i][1] << endl;
            }

        }    
};

int main ( ) {

    Palindrome ob1;
    
    ob1.Scannumber();
    ob1.CountPali();
    ob1.Print();

}