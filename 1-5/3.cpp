#include<iostream>
#include<cmath>

using namespace std;

class Triangle {
    
    public:

        int N;
        double X1 , Y1 , X2 , Y2 , X3 , Y3;

    
        void Perimeter () {
            double d;
            for ( int i = 0 ; i < N ; i ++ ) {
                cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
                d = sqrt ( pow( ( X1-X2 ) , 2 ) + pow( ( Y1-Y2 ) , 2 ) ) + sqrt ( pow( ( X1-X3 ) , 2 ) + pow( ( Y1-Y3 ) , 2 ) ) + sqrt ( pow( ( X3-X2 ) , 2 ) + pow( ( Y3-Y2 ) , 2 ) );
                DisplayPerimeter ( d );
            }
        }

        void DisplayPerimeter ( double d ) {
            cout << d << endl;
        }
};


int main () {
    
    Triangle t;
    
    cin >> t.N;
    t.Perimeter ( );

    return 0;
}
