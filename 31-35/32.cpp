#include<iostream>
using namespace std;

template<class T>
class Set {
  public:
    
    Set () : count (0) {
      for ( int i = 0 ; i < 100 ; i++ ) {
        element[i] = 0;
      }
    }
    Set ( const  Set<T> &copySet ) : count(copySet.getCount()) {
      for ( int i = 0 ; i < count ; i++ ) {
        element[i] = copySet.getelement()[i];
      }
    }

    int getCount () const {
      return count;
    }

    T *getelement() {
      return element;
    }

    int add(const T &value ) {
      if ( count == 100 ) return 0;
      for ( int i = 0 ; i < count ; i++ ) {
        if ( element[i] == value ) return 0;
      }
      element[count] = value;
      count ++;
      return 1;
      
    }

    int add(const Set<T> &_Set ) {
      
      int addcount = 0;
      for ( int i = 0 ; i < _Set.getCount() ; i ++ ) {
        if ( add ( _Set.element[i] ) == 1 ) {
          addcount ++;
        }
      }

      return addcount;
    
    }
  	
    void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        std::cout<<element[j]<<" ";
    }

  private:
  	T element[100];
  	int count;
    
};

int main() {

    int a ,b ,c ,d ,e ,f;
    cin >> a >> b >> c >> d >> e >> f;
    Set<int> set1;
    set1.add(a);
    set1.add(b);
    set1.add(c);
    set1.display(); // Output: 1 2 3
    
    cout << endl;
    Set<int> set2;
    set2.add(d);
    set2.add(e);
    set2.add(f);
    set2.display(); // Output: 4 5 6

    cout << endl;
    std::cout << "Elements added: " << set1.add(set2) << std::endl; // Output: 3
    set1.display(); // Output: 1 2 3 4 5 6

    return 0;
}