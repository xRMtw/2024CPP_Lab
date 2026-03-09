#include<iostream>

using namespace std;

template<class T>
class LinkedList
{
    public :
        class Node
        {
            public :
                Node() : next(nullptr), data(0) {}
                Node(int d) : next(nullptr), data(d) {}
                Node(Node *n) : next(n), data(0) {}
                Node(Node *n, int d) : next(n), data(d) {}
                T data;
                Node *next;
        };

        LinkedList() : head(NULL) {}
        ~LinkedList() {
            while(head != NULL){
                Node *nextDel = head;
                head = head -> next;
                delete nextDel;
            }
        }
        bool addFromHead(int d) {
            
            Node *newnode = new Node(d);
            if ( newnode == NULL ) return false;
            newnode -> next = head;
            head = newnode;
            return true;
        
        }

        bool addFromTail(int d) {
            Node *newnode = new Node(d);
            if ( newnode == NULL ) return false;
            if ( head == NULL ) {
                head = newnode;
                return true;
            }
            Node *temp;
            for ( temp = head ; temp -> next != NULL ; temp = temp -> next ) continue;
            temp -> next = newnode;
            return true;

        }

        bool removeFromHead() {
            if ( head == NULL ) return false;
            Node *temp = head->next;
            delete head;
            head = temp;
            return true;
        }

        bool removeFromTail() {
            if ( head == NULL ) return false;
            if ( head -> next == NULL ) {
                delete head;
                head = NULL;
                return true;
            }
            Node *temp;
            for ( temp = head ; temp -> next != NULL && temp -> next -> next != NULL ; temp = temp -> next ) continue;
            delete temp -> next;
            temp -> next = NULL;
            return true;
        }

        friend ostream &operator<<(ostream &o, LinkedList *l) {
            
            o << "{";
            Node *temp;
            for ( temp = l -> head ; temp != NULL ; temp = temp -> next ) {
                o << temp -> data;
                if ( temp -> next != NULL ) o << ", ";
            }
            o << "}\n";
            return o; 
        
        }

        size_t getSize() const {
            size_t count = 0;
            Node *temp;
            for ( temp = head ; temp != NULL ; temp = temp ->next ) {
                count++;
            }
            return count;
        }

        int searchData(int d) {

            Node *temp = head;
            int count = 0;

            while (temp) {
                if (temp->data == d) {
                    return count; 
                }
                temp = temp->next;
                count ++;
            }
            return -1;
    
        }

        int operator[](int i) {
            
            Node *temp = head;
            
            while (i--) {
                temp = temp -> next;
            }
            return temp -> data;
            
        }
    
    protected :
        Node *head;
} ;

template<class T>
class Set : private LinkedList<T>
{
    public :
    
        Set<T>() : LinkedList<T>() {}
        ~Set<T>(){}

        bool addElement(T d) {
            if ( LinkedList<T>::searchData(d) != -1 ) {
                return false;
            }
            LinkedList<T>::addFromTail(d);
            return true;
        }

        friend ostream &operator<<(ostream &o, Set<T> *s) {
            o << (LinkedList<T>*)s;
        	return o;

        }

        Set<T>* operator+(Set<T> *s) {
             
            Set<T> *result = new Set<T>();
            for ( int i = 0 ; i < s -> LinkedList<T>::getSize() ; i  ++ ) {
                result -> addElement ( (*s)[i] );
            }
            for ( int i = 0 ; i < LinkedList<T>::getSize() ; i  ++ ) {
                result -> addElement ( (*this)[i] );
            }

            return result;

        }


        Set<T>* operator-(Set<T> *s) {
            Set<T> *result = new Set<T>();
            
            for ( int i = 0 ; i < LinkedList<T>::getSize() ; i++ ) {
                if ( s -> LinkedList<T>::searchData( (*this)[i] ) == -1 ) {
                    result -> addElement( (*this)[i] );
                }
            }

            return result;
        }

        Set<T>* operator*(Set<T> *s) {
            
            Set<T> *result = new Set<T>();

            for ( int i = 0 ; i < LinkedList<T>::getSize() ; i++ ) {
                if ( s -> LinkedList<T>::searchData( (*this)[i] ) != -1 ) {
                    result -> addElement( (*this)[i] );
                }
            }
            return result;
        }
        
        bool operator==(Set<T> *s) {
            Set<T> *temp1 = ( (*this) - s );
            Set<T> *temp2 = ( *s - this );
            bool ans = ( temp1 -> LinkedList<T>::getSize() == 0 ) && ( temp2 -> LinkedList<T>::getSize() == 0 );
            return ans;
        }

        bool operator>(Set<T> *s) {
            Set<T> *temp1 = ( (*this) - s );
            Set<T> *temp2 = ( *s - this );
            bool ans = ( temp1 -> LinkedList<T>::getSize() != 0 ) && ( temp2 -> LinkedList<T>::getSize() == 0 );
            return ans;
        }

        bool operator<(Set<T> *s) {
            Set<T> *temp1 = ( (*this) - s );
            Set<T> *temp2 = ( *s - this );
            bool ans = ( temp1 -> LinkedList<T>::getSize() == 0 ) && ( temp2 -> LinkedList<T>::getSize() != 0 );
            return ans;
        }

        bool operator>=(Set<T> *s) {
            Set<T> *temp1 = ( (*this) - s );
            Set<T> *temp2 = ( *s - this );
            bool ans = ( temp2 -> LinkedList<T>::getSize() == 0 );
            return ans;
        }

        bool operator<=(Set<T> *s) {
            Set<T> *temp1 = ( (*this) - s );
            Set<T> *temp2 = ( *s - this );
            bool ans = ( temp1 -> LinkedList<T>::getSize() == 0 );
            return ans;
        }

};
