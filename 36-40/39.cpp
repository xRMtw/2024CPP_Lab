#include<iostream>
#include<vector>
using namespace std;

class Train {
    private:
        int n;
        vector<int>train;

    public:
        Train ( int _n ) : n(_n) {
            train.reserve(n+1);
        }

        void Scantrain ( int a , int i) {
            train[i] = a;
        }

        int Maxlongtrain () {
            int dp[2][n + 1] = {0}, ans = 0; 
            for(int i = n; i > 0; i--){ 
                dp[0][i] = 1;
                dp[1][i] = 1; 
                for(int j = n; j > i; j--){
                if(train[i] > train[j]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
                else dp[1][i] = max(dp[1][i], dp[1][j] + 1);
            }
            ans = max(ans, dp[0][i] + dp[1][i] - 1);
            }
            return ans;
        }
 
};

int main() {

    int cases;
    cin >> cases;

    for(int z = 1; z <= cases; z++){
        
        if(z != 1) cout << endl;
        int n;
        cin >> n;

        Train mytrain(n);

        int trainheavy;
        for(int i = 1; i <= n; i++) {
            cin >> trainheavy;
            mytrain.Scantrain(trainheavy , i);
        }
        
        cout << mytrain.Maxlongtrain();
    }
}