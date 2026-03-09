#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Container {
    public:
        virtual void push(int) = 0;
        virtual void pop() = 0;
        virtual int top() const = 0;
        virtual bool empty() const = 0;
};

class Stack: public Container {
    private:
        vector<int>n;        
    
    public:    
        void push ( int a ) {
            n.push_back(a);
        }

        void pop () {
            if ( n.empty() ) {
                throw out_of_range ( "bad" );
            }
            n.pop_back();
        }

        int top () const {
            if ( n.empty() ) {
                throw out_of_range ( "bad" );
            }
            
            return n.back(); 
        }

        bool empty () const {
            return n.empty();
        }

};

class PriorityQueue: public Container {
    private:
        vector<int>n;

    public:
        void push ( int a ) {
            n.push_back(a);
        }

        void pop () {
            if ( n.empty() ) {
                throw out_of_range ( "bad" );
            }
            auto max = max_element(n.begin() , n.end());
            n.erase(max);
        
        }

        int top () const {
            if ( n.empty() ) {
                throw out_of_range ( "bad" );
            }
            auto max = *max_element(n.begin() , n.end());
            return max; 
        }

        bool empty () const {
            return n.empty();
        }

};
