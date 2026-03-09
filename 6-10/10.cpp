#include<iostream>

using namespace std;

class Detect {
    
    private:
        int N;

    public:
        void Get4DigitsInt ( int n ) {
            N = n;
        }

        int Detecting () {
            
            while ( N != 0 ) {
               
                if ( N % 10 == 4 ) {
                    
                    cout << "Yes" << endl;
                    return 0;
                
                }
                 N = N / 10;    
            }
            
            cout << "No" << endl;
            return 0;
        }
    
};

int main () {
    
    int n;
    Detect Four;
    cin >> n;
    Four.Get4DigitsInt ( n );
    Four.Detecting ();
    
    return 0;
}