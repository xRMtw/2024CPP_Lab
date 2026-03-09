#include<iostream>
#include<cmath>
using namespace std;

class Point {
    public:
        
        Point( double _x, double _y ) {
            x = _x , y = _y;
        }
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
    private:
        double x, y;
};
class Segment {
    public:
        Point A;
  		Point B;
        Segment ( Point _A ,Point _B ) :A(_A),B(_B) {
            
        }
        
        double length () {
            
            return sqrt ( pow ( A.getX() - B.getX() , 2 ) + pow ( A.getY() - B.getY() , 2) );
        }
        Point getEnd (int v) {
            if ( v == 0 ) {
                return A; 
            }
            else {
                return B;
            }
        }
};