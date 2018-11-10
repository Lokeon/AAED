
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

int main(void) {
    
    int a=1 , b=6, res ;
    std::vector<int> A = {0,0,0,0,0,0,0} ;

    std::srand( unsigned ( std::time(0) ) );
    
    for(int i = 1 ; i <=(10E6) ; ++i) {
        res =  (rand()%(b - a + 1)+ a);
        A[res] += 1 ; 
    }

    for(int i = 1 ; i <= 6 ; ++i) {
        std::cout << "Cara "<< i << " Frecuencia Relativa: " << A[i] /((10E6) * 100) << " %"<< std::endl;
        std::cout << "Tiradas: " << " "<<  A[i] << std::endl;
     }
   
}