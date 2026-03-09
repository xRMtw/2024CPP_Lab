#include<iostream>
#include<string>

using namespace std;

class PokerCard {
    public:
        PokerCard(std::string s, int f)
        {
            suit = s;
            face = f;
        }

        friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
        {
            out<<"["<<p.face<<" of "<<p.suit<<"]";
            return out;
        }

        //Please finish the comparison operator override
        //compare face first, if the same then compare suit 
        //請完成比較運算子多載
        //先比較 face ， face 一樣再比較 suit
        //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
        //spade > heart > diamond > club
        bool operator>(PokerCard &b) {
            if ( face == 1 && b.face != 1) {
                return true;
            }
            else if ( b.face == 1 && face != 1 ) {
                return false;
            }
            else {
                if ( face > b.face ) {
                    return true;
                }
                else if ( b.face > face ) {
                    return false;
                }
                else {
                    if ( suit == "spade" && b.suit != "spade" ) {
                        return true;
                    }
                    else if ( suit == "heart" &&  b.suit != "spade" && b.suit != "heart" ) {
                        return true;
                    }
                    else if ( suit == "diamond" &&  b.suit == "club" ) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        bool operator<(PokerCard &b) {
            if ( face == 1 && b.face != 1) {
                return false;
            }
            else if ( b.face == 1 && face != 1 ) {
                return true;
            }
            else {
                if ( face < b.face ) {
                    return true;
                }
                else if ( b.face < face ) {
                    return false;
                }
                else {
                    if ( b.suit == "spade" && suit != "spade" ) {
                        return true;
                    }
                    else if ( b.suit == "heart" && suit != "spade" && suit != "heart" ) {
                        return true;
                    }
                    else if ( b.suit == "diamond" && suit == "club" ) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        bool operator==(PokerCard &b) {
            if ( face == b.face && suit == b.suit ) {
                return true;
            }
            else {
                return false;
            }
        }

    private:
        std::string suit;
        int face;
};

int main ( ) {
    int a , b;
    string c,d;
    cin >> c >> a >> d >> b;
    PokerCard A(c,a) ,B(d,b);
    bool k,m,n;
    k = A > B;
    m = A < B;
    n = A == B;
    cout << k << m << n;

}