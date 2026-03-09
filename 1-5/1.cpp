#include<iostream>

using namespace std;

class Point {

    public:
        
        int N;
        float X ,Y;
        
        void GetCoordinates () {
            for ( int i = 0 ; i < N ; i ++ ) {
                cin >> X >> Y;
                DisplayCoor();
            }
        }
        void DisplayCoor ( ) {
            cout << "(" << X << ", "<< Y << ")" << endl;
        }


};

int main () {
    
    Point Coordinate;
    cin >> Coordinate.N;
    Coordinate.GetCoordinates();


    return 0;
}