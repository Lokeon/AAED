
#include <vector>

template <typename T>
void burbujeo(std::vector<T>& A) {
    for(int i = 1 ; i < A.size() ; ++i) 
        for(int j = 0 ; j < A.size() -i - 1 ; ++i) 
            if(A[j] > A[j+1]) 
                std::swap(A[j],A[j+1]);
}