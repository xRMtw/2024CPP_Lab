#include<iostream>
#include<vector>
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

    const T *getelement() const {
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

    Set operator+( const Set<T> &_Set ) {
        
        Set temp(*this);
        temp.add(_Set);

        return temp;
    }

    Set operator-( const Set<T> &_Set ) {
        Set temp;
        for ( int i = 0 ; i < count ; i ++ ) {
            for ( int k = 0 ; k < _Set.getCount() ; k++ ) {
                if ( element[i] == _Set.element[k] ) {
                    temp.add(_Set.element[k]);
                }
            }
        }
        return temp;
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