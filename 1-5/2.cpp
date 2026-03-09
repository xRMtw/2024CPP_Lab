#include<iostream>
#include<cmath>

using namespace std;

class Segment {
    
    public:

        int N;
        double X1 , Y1 , X2 , Y2;

    
        void distance () {
            double d;
            for ( int i = 0 ; i < N ; i ++ ) {
                cin >> X1 >> Y1 >> X2 >> Y2;
                d = sqrt ( pow( ( X1-X2 ) , 2 ) + pow( ( Y1-Y2 ) , 2 ) );
                DisplayDistance ( d );
            }
        }

        void DisplayDistance ( double d ) {
            cout << d << endl;
        }
};


int main () {

    Segment PointDistance;
    
    cin >> PointDistance.N;
    PointDistance.distance ( );

    return 0;
}
