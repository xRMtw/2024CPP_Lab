#include<iostream>
#include<cmath>

using namespace std;

class Fraction {
    public:
        
        Fraction() : numerator(0), denominator(1) {}

        Fraction(int n, int m) : numerator(n) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        
        int getNumerator() const {
            return numerator;
        }
        
        int getDenominator() const {
            return denominator;
        }
        
        void setNumerator(int n) {
            numerator = n;
        }
        
        void setDenominator(int m) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        
        friend std::ostream& operator << (std::ostream& out, Fraction &f) {
            
            if (f.denominator < 0) {
                f.denominator *= -1;
                f.numerator *= -1;
            }

            if (f.denominator != 1)
                out << "(" << f.numerator << "/" << f.denominator << ")";
            else
                out << "(" << f.numerator << ")";
            return out;
        }

        void display () {

            cout << *this;
        
        }

        Fraction operator+ ( const Fraction &f ) const {
        
            int N = numerator*f.getDenominator() + f.getNumerator()*denominator ;
            int M = denominator * f.getDenominator();
            int MAX = ( abs(N) > abs(M) )? N : M;
            for ( int i = 1 ; i <= (int)sqrt(abs(MAX))+1 ; i++ ) {
                if ( N%i == 0 && M%i == 0 ) {
                    N /=i;
                    M /=i;
                    i = 1;
                }
            }
        
            if ( N == 0 && M != 1 ) {
                M = 1;
                return Fraction( N,M );
            }
            else {
                return Fraction( N,M );
            }
        }

        Fraction operator- ( const Fraction &f ) const {

            int N = numerator*f.getDenominator() - f.getNumerator()*denominator ;
            int M = denominator * f.getDenominator();
            if ( N < 0 && M < 0 ) {
                N *= -1;
                M *= -1;
            }
            int MAX = ( abs(N) > abs(M) )? N : M;
            for ( int i = 1 ; i <= (int)sqrt(abs(MAX))+1 ; i++ ) {
                if ( N%i == 0 && M%i == 0 ) {
                    N /=i;
                    M /=i;
                    i = 1;
                }
            }

            if ( N == 0 && M != 1) {
                M = 1;
                return Fraction( N,M );
            }
            else {
                return Fraction( N,M );
            }
        }
        
        Fraction operator* ( const Fraction &f ) const {

            int N = numerator * f.getNumerator();
            int M = denominator * f.getDenominator();
            int MAX = ( abs(N) > abs(M) )? N : M;
            for ( int i = 1 ; i <= (int)sqrt(abs(MAX))+1 ; i++ ) {
                if ( N%i == 0 && M%i == 0 ) {
                    N /=i;
                    M /=i;
                    i = 1;
                }
            }
            
            return Fraction( N,M );

        }
        
        Fraction operator/ ( const Fraction &f ) const {

            int N = numerator * f.getDenominator();
            int M = denominator * f.getNumerator();
            int MAX = ( abs(N) > abs(M) )? N : M;

            for ( int i = 1 ; i <= (int)sqrt(abs(MAX))+1 ; i++ ) {
                if ( N%i == 0 && M%i == 0 ) {
                    N /=i;
                    M /=i;
                    i = 1;
                }
            }
            
            return Fraction( N,M );

        }

        Fraction operator! ()  {
            
            int N = numerator;
            int M = denominator;
            int MAX = ( abs(N) > abs(M) )? N : M;

            for ( int i = 1 ; i <= (int)sqrt(abs(MAX))+1 ; i++ ) {
                if ( N%i == 0 && M%i == 0 ) {
                    N /=i;
                    M /=i;
                    i = 1;
                }
            }

            int temp = N;
            N = M;
            M = temp;

            return Fraction ( N , M );
        }

        void operator =(const Fraction &f){
            numerator = f.getNumerator();
            denominator = f.getDenominator();
        }
    
    private:
    
    int numerator, denominator;

};


int main(){
    int a, b;
    cin >> a >> b;
    Fraction aa(a, b), k;
    k = !aa;
    k.display();
}