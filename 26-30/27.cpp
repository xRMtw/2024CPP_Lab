#include<iostream>

using namespace std;

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
                int data;
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
    
    protected :
        Node *head;
} ;