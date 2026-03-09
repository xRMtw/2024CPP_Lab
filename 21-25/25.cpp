#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class MeetWhere {
    
    private:
        vector<int> st, av;
        int f;

    public:
        
        MeetWhere(vector<int> _st, vector<int> _av, int _f): f(_f) {
            
            st.assign(_st.begin(), _st.end());
            av.assign(_av.begin(), _av.end());
            
            sort(st.begin(), st.end());
            sort(av.begin(), av.end());
        }

        void ans() const {
            int test = ( f % 2 == 0 )?1:0;
            int a = f / 2 - test;
            cout << "(Street: " << st[a] << ", Avenue: " << av[a] << ")" << endl; 
        }
};

int main() {
	
    int cases;
	cin >> cases;
	
    for(int z = 0; z < cases; z++) {
		
        int stre, ave, fri;
        cin >> stre >> ave >> fri;
        
        vector<int> st(fri), av(fri);
        for(  int i = 0; i < fri; i++ ) {
            cin >> st[i] >> av[i];
        }
        MeetWhere place (st, av, fri );
        place.ans();
	
    }
}
