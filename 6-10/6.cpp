#include<iostream>

using namespace std;

class Point {

    public:
        
        int N;
        
        float getX () {
            return X;
        };
        float getY () {
            return Y;
        };
        
        void SetCoordinates ( float x , float y ) {
            X = x; 
            Y = y;
        }
        
    private:
        float X;
        float Y;

};

int main () {
    
    float x , y;
    Point Coordinate;
    
    cin >> Coordinate.N;
    
    for ( int i = 0 ; i < Coordinate.N ; i ++ ) {
        
        cin >> x >> y;
        Coordinate.SetCoordinates ( x , y );
        
        cout << "(" << Coordinate.getX () << ", " << Coordinate.getY () << ")" << endl;
    
    }

    return 0;
}