
#include <vector>

template <typename T>
void inserccion(std::vector<T>& A) {

    int j = 0;
    
    for(int i = 0 ; i < A.size() ; ++i) {
        j = i ; 
        while( j > 0 && A[j-1] > A[j]) {
            std::swap(A[j],A[j-1]);
            --j;
        }
    }
}