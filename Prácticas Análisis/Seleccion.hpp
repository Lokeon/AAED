
#include <vector>

template <typename T>
void seleccion(std::vector<T>& A) {

    int min = 0 ; 

    for(int i = 0 ; i < A.size() - 1  ; ++i) {
        min = i ; 
        for(int j = i+1 ; j < A.size() ; ++j) {
            if(A[j] < A[min]) {
                min = j ;
            }
        }
        std::swap(A[min],A[i]);
    }
}
