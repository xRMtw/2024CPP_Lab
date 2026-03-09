#include<iostream>
#include<cmath>

using namespace std;

struct SavePoint {
    double x;
    double y;
};

class Path {
    public:
        Path ( Segment *aarr , int length ) {
            
            double sum = 0;
            int test = 0;
            SavePoint A[1000];
            for ( int k = 0 ; k < length ; k++ ) {
                
                sum = aarr[k].length() + sum;
                
                for ( int i = 0 ; i < length ; i ++ ) {
                    
                    if ( ( aarr[k].getEnd(1).getX() == A[i].x && aarr[k].getEnd(1).getY() == A[i].y ) || ( aarr[k].getEnd(0).getX() != aarr[k - 1].getEnd(1).getX() && aarr[k].getEnd(0).getY() != aarr[k - 1].getEnd(1).getY() && k > 0 ) ) {
        
                        cout << "-1" << endl;
                        test = 1;
                        break;
                    }
                }
                A[k].x = aarr[k].getEnd(0).getX();
                A[k].y = aarr[k].getEnd(0).getY();
            }

            if ( test == 0 ) cout << sum << endl;
        }
};

class Point {
    public:
        Point(double _x, double _y) {
            x = _x , y = _y;
        };
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
    private:
        double x , y;
};

class Segment {
    public:
        Point P1;
        Point P2;
        Segment(Point p1, Point p2):P1(p1),P2(p2) {
            P1 = p1 , P2 = p2;
        }
        Point getEnd (int n) {
            if ( n == 0 ) {
                return P1;
            }
            else {
                return P2;
                
            }
        }
        double length() {
            
            double dx = ( P1.getX() - P2.getX() );
            double dy = ( P1.getY() - P2.getY() );
            
            return sqrt( pow( dx ,2 ) + pow( dy , 2 ) );
        }
};