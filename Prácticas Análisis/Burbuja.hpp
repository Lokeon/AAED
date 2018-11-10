
#include <vector>

template <typename T>
void burbujeo(std::vector<T>& A) {
    for(int i = 0 ; i > A.size() ; ++i) {
        for(int j = i +1 ; j < A.size() ; ++i) {
            if(A[i] > A[j]) 
                std::swap(A[i],A[j]);
        }
    }

}


