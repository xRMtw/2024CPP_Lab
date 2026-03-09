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
        
        friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
            
            if (f.denominator != 1)
                out << "[" << f.numerator << "/" << f.denominator << "]";
            else
                out << f.numerator;
            return out;
        }
    
    private:
    
    int numerator, denominator;

};

Fraction operator+ ( const Fraction &f , const Fraction &f2 ) {
    
    int N = f.getNumerator()*f2.getDenominator() + f2.getNumerator()*f.getDenominator();
    int M = f.getDenominator() * f2.getDenominator();
          
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

Fraction operator- ( const Fraction &f , const Fraction &f2 ) {

    int N = f.getNumerator()*f2.getDenominator() - f2.getNumerator()*f.getDenominator();
    int M = f.getDenominator() * f2.getDenominator();
    
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

bool operator== ( const Fraction &f , const Fraction &f2 ) {
    
    int N1 , N2;
    int M1 , M2;
    N1 = f.getNumerator();
    N2 = f2.getNumerator();
    M1 = f.getDenominator();
    M2 = f2.getDenominator();

    for ( int i = 1 ; i <= sqrt(M1)+1 ; i++ ) {
        if ( M1%i == 0 && N1%i == 0 ) {
            N1 /=i;
            M1 /=i;
            i = 1;
        }
    }
    for ( int i = 1 ; i <= sqrt(M2)+1 ; i++ ) {
        if ( M2%i == 0 && N2%i == 0 ) {
            N2 /=i;
            M2 /=i;
            i = 1;
        }
    }

    if ( N1 == N2 && M1 == M2 ) {
        return true;
    }
    else 
        return false;

}

int main() {
    
    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;

}