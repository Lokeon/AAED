
#include <vector>

template <typename T>
void seleccion(std::vector<T>& A) {

    int min ; 

    for(int i = 0 ; i < A.size() ; ++i) {
        min = i ; 
        for(int j = i+1 ; j < A.size() ; ++j) {
            if(A[j] < A[i]) {
                min = j ;
            }
            std::swap(A[min],A[j]);
        }
    }
}
