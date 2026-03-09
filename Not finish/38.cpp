#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int month[12] = { 31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };

class Date {
    private:
        
        int y , m , d;
        
    public:

        Date (): y(1900) , m (1) , d(1) {}

        Date (int _y , int _m , int _d ): y(_y) , m(_m) , d(_d) {}

        Date ( string year ) {

            y = stoi( year.substr( 0 , 4 ));
            m = stoi( year.substr( 4 , 2 ) );
            d = stoi( year.substr( 6 , 2) );
        }

        int getYear () {
            return y;
        }

        int getMonth () {
            return m;
        }

        int getDay () {
            return d;
        }

        bool leapyear ( int year ) const {
            return ( !(year % 4) && year % 100 ) || !( year % 400 );
        }

        int getDays( ) const {
            int day = ( y - 1 )*365 + leapyear(y) - ( m < 3 );
            for ( int i = m - 1 ; i >= 0 ; i -- ) {
                day += month[i-1];
            }

            day += d;
            return day;
        }

        Date Nextday () const {
            int y2 = y, m2 = m , d2 = d;
            
            if ( (d2+1) > month[m2-1] + ( m2 == 2 && leapyear(y2) ) ) {
                
                d2 = 0;
                m2 ++;
            
            }

            else if ( m2 > 12 ) {

                y2 ++;
                m2 = 1;

            }
            d2 ++;

            return Date(y2,m2,d2);
            
        }

        void Print () {
            cout << m << "/" << d << "/" << y << endl;
        }

        bool operator ==(Date date) const {
        return getDays() == date.getDays();
        }

        bool operator >(Date date) const {
            return getDays() > date.getDays();
        }

        bool operator <(Date date) const {
            return getDays() < date.getDays();
        }

        bool operator <=(Date date) const {
            return getDays() <= date.getDays();
        }

        bool operator >=(Date date) const {
            return getDays() >= date.getDays();
        }
    
};


bool JudgeInORNot ( vector<pair<Date , Date>> &a , vector<pair<Date , Date>> &b , int i , int k ) {
    if ( ( a[i].second.getDays() - a[i].first.getDays() > b[k].second.getDays() - b[k].first.getDays() ) && ( a[i].first.getYear() <= b[k].first.getYear() && a[i].second.getYear() >= b[k].second.getYear() ) && ( a[i].first.getMonth() <= b[k].first.getMonth() && a[i].second.getMonth() >= b[k].second.getMonth() ) && ( a[i].first.getDay() <= b[k].first.getDay() && a[i].second.getDay() >= b[k].second.getDay() ) ) {
        return true;
    }
    else {
        return false;
    }
}

void inCludeORnot ( vector<pair<Date , Date>> &a , vector<pair<Date , Date>> &b , int size1 , int size2 ) {
    for ( int i = 0 ; i < size1 ; i ++ ) {
            for ( int k = 0 ; k < size2 ; k ++ ) {
                if ( JudgeInORNot ( a , b , i , k ) ) {
                    b.erase( b.begin() + k );
                    k--;
                }
            } 
    }
}

bool TestcontinuousORnot ( pair<Date , Date> &a , pair<Date , Date> &b ) {
    if ( ( a.second.Nextday() == b.first ) ) {
        return true;
    }
    else {
        return false;
    }
}

void Continuous ( vector<pair<Date , Date>> &a , vector<pair<Date , Date>> &b , int size1 , int size2 , vector<pair<Date , Date>> &Output  ) {
    for ( int i = 0 ; i < size1 ; i ++ ) {
            for ( int k = 0 ; k < size2 ; k ++ ) {
                if ( TestcontinuousORnot ( a[i] , b[k] ) ) {
                    Output.push_back( pair<Date , Date>( Date( a[i].first.getYear() ,a[i].first.getMonth() , a[i].first.getDay() ) , Date(b[k].second.getYear() ,b[k].second.getMonth() , b[k].second.getDay()) ) );
                    a.erase( a.begin() + i );
                    b.erase( b.begin() + k );
                    k--;
                }
            } 
    }
}

bool Same ( pair<Date , Date> &a ) {
    if ( a.first == a.second ) {
        return true;
    }
    else {
        return false;
    }
}

int main () {
    

    int CaseNumber = 0;
    while ( true ) {
        
        vector<pair<Date ,Date>> Output;

        int NX , NR;
        cin >> NX >> NR;
        if ( NX == 0 && NR == 0 ) return 0;
        CaseNumber ++;

        string a ,b;
        vector<pair<Date , Date>> NXtype , NRtype;

        for ( int i = 0 ; i < NX ; i++ ) {
            cin >> a >> b;
            NXtype.push_back( make_pair( Date(a) , Date(b) ) );
        }
        sort( NXtype.begin() , NXtype.end());
        for ( int i = 0 ; i < NR ; i++ ) {
            cin >> a >> b;
            NRtype.push_back( make_pair( Date(a) , Date(b) ) );
        }
        sort( NRtype.begin() , NRtype.end());

        int size1 = NXtype.size() , size2 = NRtype.size();

        inCludeORnot ( NXtype , NRtype , size1 , size2 );
        inCludeORnot ( NRtype , NXtype , size2 , size1 );
        inCludeORnot ( NXtype , NXtype , size1 , size1 );
        inCludeORnot ( NRtype , NRtype , size2 , size2 );

        Continuous ( NXtype , NRtype , size1 , size2 , Output );
        Continuous ( NRtype , NXtype , size2 , size1 , Output );
        Continuous ( NXtype , NXtype , size1 , size1 , Output );
        Continuous ( NRtype , NRtype , size2 , size2 , Output );
        
        int size3 = Output.size();
        inCludeORnot ( NXtype , Output , size1 , size3 );
        inCludeORnot ( NRtype , Output , size2 , size3 );
        inCludeORnot ( Output , Output , size3 , size3 );

        if ( Output.empty() ) {
            cout << "Case "<< CaseNumber << ":" << endl;
            cout << "No additional quotes are required.";
            
        }
        else {

            cout << "Case "<< CaseNumber << ":" << endl;
            for ( int i = 0 ; i < NXtype.size() ; i ++ ) {
                if ( Same(Output[i]) ) {
                    NXtype[i].first.Print();
                }
                else {
                    NXtype[i].first.Print();
                    cout << " to ";
                    NXtype[i].second.Print();
                    cout << endl;
                }
            }

            for ( int i = 0 ; i < NRtype.size() ; i ++ ) {
                if ( Same(Output[i] )) {
                    NRtype[i].first.Print();
                }
                else {
                    NRtype[i].first.Print();
                    cout << " to ";
                    NRtype[i].second.Print();
                    cout << endl;
                }
            }

            for ( int i = 0 ; i < Output.size() ; i ++ ) {
                if ( Same(Output[i]) ) {
                    Output[i].first.Print();
                }
                else {
                    Output[i].first.Print();
                    cout << " to ";
                    Output[i].second.Print();
                    cout << endl;
                }
            }
        }
        
    } 

}