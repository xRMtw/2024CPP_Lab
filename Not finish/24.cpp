#include<iostream>
#include<vector>

using namespace std;

struct Request {
    
    int Topic;
    int Times;
    int FirstDeliverTime;
    int WorkTime;
    int GapTime;

};

struct CoWorker {
    
    int ID;
    int WorkNumber;
    vector<int> Priority;
    bool ok = false;
    int endtime;

};

int main() {
    
    int Num;
    int Person;
    int Count = 0;

    while ( 1 ) {
        
        cin >> Num; 
        if ( Num == 0 ) break;

        Count ++;

        vector<vector<int>> test(20, vector<int>(2, 0)); 
        vector<Request> Req (20);
        for ( int i = 0 ; i < Num ; i ++ ) {
            
            cin >> Req[i].Topic >> Req[i].Times >> Req[i].FirstDeliverTime >> Req[i].WorkTime >> Req[i].GapTime;
            test[i][0] = Req[i].Topic;

        }
        
        cin >> Person;
        vector<CoWorker> Co (5);
        for ( int i = 0 ; i < Person ; i++ ) {
            
            cin >> Co[i].ID >> Co[i].WorkNumber;
            for ( int k = 0 ; k < Co[i].WorkNumber ; k++ ) {
                int Temp;
                cin >> Temp;
                Co[i].Priority.push_back(Temp);
            
            }
            
        }

        int MaxTime = 0;
        
        for ( int i = 0 ; i < Num ; i ++ ) {
            for ( int k = 0 ; k < Person ; k++ ) {
                bool FindorNot = false;
                for ( int q = 0 ; q < Co[k].WorkNumber ; q++ ) {
                    if ( !FindorNot && test[i][1] == 0 && Co[k].Priority[q] == test[i][0] ) {
                        int temptime = Req[i].FirstDeliverTime + ( Req[i].Times- 1 )*Req[i].GapTime + Req[i].WorkTime;
                        test[i][1] = 1;
                        MaxTime = ( temptime > MaxTime )? temptime : MaxTime;
                        FindorNot = true;
                        break;
                    }
                }
                if ( FindorNot ) break;
            }
        }

        cout << "Scenario " << Count << ": All requests are serviced within " << MaxTime << " minutes." << endl;
    }

    return 0;
    
}