template < typename T >

T *sort(T *array, int n) {
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int k = 0 ; k < n - 1 - i ; k++ ) {
            if ( array[k] > array[k+1] ) {
                T temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
    }
    return array;
}