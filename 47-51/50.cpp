#include<bits/stdc++.h>

using namespace std;

class Minesweeper {
    private:
        vector<vector<string> > board;
        vector<string> temp;

        int high;
        int wide;

    public:

        Minesweeper () : wide(0) , high(0) {
            board.clear();
            temp.clear();
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

        int findBOMBNumber ( int x , int y ) {
            int Bombnumber = 0;
            for ( int dx = -1 ; dx < 2 ; dx++ ) {
                for ( int dy = -1 ; dy < 2 ; dy ++ ) {
                    if ( x+dx < 0 || y+dy < 0 || x+dx >=high || y+dy >= wide ) continue;
                    else if ( board[x+dx][y+dy] == "*" ) {
                        Bombnumber ++;
                    }
                }
            }
            return Bombnumber;
 
        }

        void setBOMBnumber () {
            for ( int i = 0 ; i < high ; i++ ) {
                for ( int k = 0 ; k < wide ; k++ ) {
                    if ( board[i][k] == ".") {
                        board[i][k] = to_string( findBOMBNumber(i,k) );
                    }

                }
            }
        }

        void display () {
            for ( int i = 0 ; i < high ; i++ ) {
                for ( int k = 0 ; k < wide ; k++ ) {
                    cout << board[i][k];
                }
                cout << endl;
            }
        }

};

int main () {
    
    int tag = 1;
    int M ,N;

    while ( cin >> M >> N ) {

        if ( M == 0 || N == 0 ) break;
        Minesweeper m;
        
        m.setHigh(M);
        m.setWide(N);
        m.scanBoard();

        cout << "Field #" << tag << ":" << endl;
        m.setBOMBnumber();
        m.display();
        
        tag++;
        cout << endl; // must have
       
    }

    return 0;    
}