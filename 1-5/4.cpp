#include<iostream>

using namespace std;

class Velocity{
    public:
        double X , Y , V;
        
        void GetXY ( ) {
            cin >> X >> Y;
        }
        void CountVelocity () {
            V = X/Y;
        }
        void DisplayVelocity () {
            cout << V << endl;
        }

};

int main () {
    
    Velocity man;
    man.GetXY ();
    man.CountVelocity ();
    man.DisplayVelocity ();

    return 0;
}