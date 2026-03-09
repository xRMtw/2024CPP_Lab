#include<bits/stdc++.h>

using namespace std;

class Squares {
    private:
        vector<vector<string> > board;
        vector<string> temp;
        vector<pair<int , int> > Qsave;
        int high;
        int wide;

    public:

        Squares () : wide(0) , high(0) {
            board.clear();
            temp.clear();
            Qsave.clear();
        }

        void setHigh ( int a ) {
            high = a;
        }

        void setWide ( int a ) {
            wide = a;
        }

        void scanBoard () {
            
            temp.resize(high);
            
            board.resize(high);
            for ( int i = 0 ; i < high ; i ++ ) board[i].resize(wide);
            
            for ( int i = 0 ; i < high ; i ++ ) {
                cin >> temp[i];
            }

            for ( int i = 0 ; i < high ; i ++ ) {
                for ( int k = 0 ; k < wide ; k++ ) {
                    board[i][k] = temp[i].substr( k , 1 );
                }
            }

        }

        int getLargestsquareLength ( int a , int b ) {
            
            int LengthofSide = 1;
            
            for ( int k = -1 ; a+k >= 0 && b+k >= 0 ; k-- ) {
                int count = 0;
                int area = pow( abs(k)*2+1 , 2);
                
                for ( int dx = a + k ; dx <=  a + abs(k) ; dx++ ) {
                    for ( int dy = b + k ; dy <=  b + abs(k) ; dy ++ ) {
                        if ( (a + abs(k)) >= high || (b + abs(k)) >=wide ) break;
                        if ( board[a][b] == board[dx][dy] ) {
                            count ++;
                        }
                    }
                }
                
                if ( count != area ) {
                    return LengthofSide;
                }
                else {
                    LengthofSide += 2;
                }
                
            }
            return LengthofSide;
        }

        void enterCoor ( int x , int y ) {
            Qsave.push_back(pair<int , int >(x,y));
        }

        void printLengthofSide ( int Q ) {
            cout << high << " " << wide << " " << Q << endl;
            for ( int i = 0 ; i < Q ; i++ ) {
                cout << getLargestsquareLength( Qsave[i].first , Qsave[i].second ) << endl;
            }
        }

};

int main () {
    
    int times;
    cin >> times;

    while (times) {
        Squares s;
        int M ,N ,Q;
        cin >> M >> N >> Q;
        s.setHigh(M);
        s.setWide(N);
        s.scanBoard();
    
        int tempQ = Q;

        while ( tempQ ) {
            tempQ--;
            int x ,y;
            cin >> x >> y;
            s.enterCoor(x,y);
        }

        s.printLengthofSide(Q);
        times --;
    }

    return 0;    
}