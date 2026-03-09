#include<iostream>

using namespace std;

class OverlayORNOT{
    public:
        int X11 , X12 , X21 , X22;
        
        void SetX() {
            cin >> X11 >> X12 >> X21 >> X22;
            if ( X11 > X12 ) {
                int temp = X12;
                X12 = X11;
                X11 = temp;
            }
             if ( X21 > X22 ) {
                int temp = X22;
                X22 = X21;
                X21 = temp;
            }
        }

        int Test () {
            if ( ( X11 < X21 && X21 < X12 && X12 != X21 ) || ( X21 < X11 && X11 < X22 && X12 != X21 ) || ( X21 < X12 && X12 < X22 && X12 != X21) || ( X11 < X22 && X22 < X12 && X12 != X22 ) ) {
                return 1;
            }
            else 
                return 2;
        }

        void DisplayResult () {
            if ( Test() == 1 ) {
                cout << "overlay" << endl;
            }
            else {
                cout << "no overlay" << endl;
            }
        }

};

int main () {

    OverlayORNOT A;

    A.SetX ();
    A.Test ();
    A.DisplayResult ();

    return 0;
}