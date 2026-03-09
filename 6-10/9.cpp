#include<iostream>

using namespace std;

class KM {
    
    public:
        
        void GetKM ( int km ) {
            K = km;
        }
        
        int Count ( ) {
            
            int money = 0;
            
            if ( K < 200 || K == 200 ) {
                float temp = 0;
                temp = K * 1.2;
                
                if ( (int)( temp * 10 ) % 10 >= 5 ) {
                    money = (int)( K * 1.2 ) + 1;
                }
                else {
                    money = (int)( K * 1.2 );
                }
                
            }
            
            else {
                
                float temp = 0;
                temp = ( K - 200 ) * 0.9;
                if ( (int)( temp * 10 ) % 10 >=5 ) {
                    
                    money = (int)( K-200 )*0.9 + 240 + 1;
                }
                else {
                    money = (int)( K-200 )*0.9 + 240;
                }
                
            }
            
            return money;
        
        }
    private:
        int K;
};

int main () {

    int km;
    KM obj;

    cin >> km;
    obj.GetKM ( km );
    
    cout << obj.Count () << endl;

    return 0;
}