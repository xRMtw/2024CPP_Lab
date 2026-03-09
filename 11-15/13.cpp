#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix {
    private:
        
        int n = 0;
        vector<vector<int>> matrix;

    public:
    
        void ScanMatrix() {

            cin >> n;
            matrix.resize(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++)
                {

                    cin >> matrix[i][k];
                }
            }
        }

        void TurnRitht() {
            if (n == 0) {
                cout << "No element in matrix can be rotated.\n";
                return;
            }
            
            vector<vector<int>> temp;
            temp.resize(n, vector<int>(n));

            for (int i = 0; i < n; i++ ) {
                for (int k = 0; k < n; k++){
                    temp[k][n - 1 - i] = matrix[i][k];
                }
            }
            matrix = temp;
        }

        void TurnLeft() {
            
            if (n == 0) {
                cout << "No element in matrix can be rotated.\n";
                return;
            }
            vector<vector<int>> temp;
            temp.resize(n, vector<int>(n));

            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    temp[n - 1 - k][i] = matrix[i][k];
                }
            }
            matrix = temp;
        }

        void PrintMatrix() {
            if (n == 0) {
                cout << "No element in matrix can be printed.\n";
                return;
            }
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    cout << matrix[i][k] << " ";
                }
                cout << endl;
            }
            cout << "\n";
        }
};

int main()
{

    string step;
    Matrix ob1;

    while (true) {

        getline(cin, step);

        if (step == "stop") {
            break;
        }
        else if (step == "scan") {

            ob1.ScanMatrix();
            cin.ignore();
        }
        else if (step == "print") {

            ob1.PrintMatrix();
        }
        else if (step == "rotate right") {
            ob1.TurnRitht();
        }
        else if (step == "rotate left") {

            ob1.TurnLeft();
        }

        else {
            cout << "unknown\n";
        }
    }

    return 0;
}