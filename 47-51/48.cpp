#include<bits/stdc++.h>

using namespace std;

class Longest {
    private:
        
        int head;
        int tail;
        int max_length;

    public:

        Longest() : max_length(0){}

        int getMaxlength () {
            return max_length;
        }

        void setHead ( int a ) {
            head = a;
        }

        void setTail ( int a ) {
            tail = a;
        }

        void findMaxlength () {
            for ( int i = head ; i <= tail ; i++ ) {
                int nowTest = i;
                int tempLength = 0;
                while ( 1 ) {
                    tempLength ++;
                    if ( nowTest == 1 ) break;
                    if ( nowTest % 2 ) {
                        nowTest = nowTest*3 + 1;
                    }
                    else {

                        nowTest = nowTest / 2;

                    }
                }

                max_length = ( tempLength > max_length )? tempLength : max_length;
                
            }
        }
};

int main () {
    int a , b;
    while ( cin >> a >> b ) {
        
        Longest test;
        
        if ( (a >= 10,000 || a <= 0) || (b >= 10,000 || b <= 0) ) break;
        
        int tail , head;
        tail = ( b > a )? b:a;
        head = ( a < b )? a:b;   
        
        test.setHead(head);
        test.setTail(tail);
        test.findMaxlength();

        cout << a << " " << b << " " << test.getMaxlength() << endl;
    
    }
    return 0;
}