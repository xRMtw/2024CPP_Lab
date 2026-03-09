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

        Point &getPoin1() {
            return point1;
        }

        Point &getPoin2() {
            return point2;
        }
        
    private:
        Point point1;
  		  Point point2;
    
};

class Shape {
    
    public:
        
        Shape() : edgeCount(0) {};
        
        Shape ( Segment *_seg, int _edgeCount ) : edgeCount(_edgeCount) {
            

            if ( edgeCount < 3 ) {
                throw invalid_argument ( "invalid segment" );
            }

            if ( _seg[0].getPoin1().getX() != _seg[edgeCount - 1].getPoin2().getX() && _seg[0].getPoin1().getY() != _seg[edgeCount - 1].getPoin2().getY()) {
                throw invalid_argument ( "invalid segment" );
            }

            for (int i = 0; i < edgeCount - 1; ++i) {
                if ( _seg[i].getPoin2().getX() != _seg[i + 1].getPoin1().getX() && _seg[i].getPoin2().getY() != _seg[i + 1].getPoin1().getY() ) {
                    throw invalid_argument ( "invalid segment" );
                }
            }

            for ( int i = 0 ; i < edgeCount ; i ++ ) {
                    
                seg[i] = _seg[i];

            }
        
        }; // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
        
        virtual float getArea() = 0;
        
        float getPerimeter() {
            int Perimeter = 0;
            for ( int i = 0 ; i < edgeCount ; i ++ ) {
                Perimeter += seg[i].getLength();
            }
            return Perimeter;
        };
        
        Segment &getSeg(int index) {
            
            return seg[index];
        
        }

    private:

        Segment seg[10];
        int edgeCount;

};

class Rectangle : public Shape {
    public:
        Rectangle( Segment *_seg ) {
            for( int i = 0 ; i < 4 ; i++ ) {
                seg[i]=_seg[i];
            }
        };
        float getArea() {
            if ( seg[0].getLength() == seg[1].getLength() && seg[1].getLength() == seg[2].getLength() && seg[2].getLength() == seg[3].getLength() )
                return seg[0].getLength()*seg[0].getLength();
            
            for ( int i = 0 ; i < 4 ; i++ ) {
                
                if ( seg[0].getLength() != seg[i].getLength() ) {
                    double area = seg[0].getLength()*seg[i].getLength();
                    return area;
                }
            } 
        }
    private:
        Segment seg[4];
};
