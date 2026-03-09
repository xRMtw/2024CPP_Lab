#include<iostream>
#include<cmath>
using namespace std;

class Point {
    public:
        Point ()  : x(0) , y(0) {}
        Point( double _x, double _y ) :x(_x) , y(_y) {}
        
        double getX() {
            return x;
        }
        void setX(double a) {
            x = a;
        }
        double getY() {
            return y;
        }
        void setY(double b) {
            y = b;
        }
        double getDistance ( Point &D ) const {
            
            double Distance = sqrt( pow ( D.getX() - x , 2 ) + pow ( D.getY() - y , 2 ) );

            return Distance;
        } 

        void printPoint() {
            cout << "(" << x << ", " << y << ")";
        }
    private:
        double x, y;
};

class Segment {
    
    public:
        
        Segment ( ) :point1(0,0) , point2(0,0) {}
        Segment ( Point _A ,Point _B ) :point1(_A),point2(_B) {}
        
        double getLength () {
            
            return sqrt ( pow ( point1.getX() - point2.getX() , 2 ) + pow ( point1.getY() - point2.getY() , 2) );
        }

    private:
        Point point1;
  		Point point2;
    
};

int main () {

    Point a(1,2),b(3,4);
    cout << a.getDistance(b) << endl;
    cout << b.getDistance(a) << endl;
    Segment A(a,b);
    cout << A.getLength();

}