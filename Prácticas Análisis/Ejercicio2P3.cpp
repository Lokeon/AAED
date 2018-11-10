
#include <vector>
#include <algorithm>
#include <iostream>
#include "Burbuja.hpp"
#include "Inserccion.hpp"
#include "Seleccion.hpp"
#include "cronometro.hpp"


int main() {

    std::vector<int> A = {1,2,3,4,5,6,7,8,9} ,B,C,D ;
    cronometro burb , selec , inser ; 

    burb.activar() ;
    do {
        B = A ;     
        burbujeo(B);
    }while(std::next_permutation(A.begin(),A.end()));
    burb.parar();

    std::cout << "Burbuja tiempo: " << burb.tiempo() << std::endl;

    selec.activar() ;
    do {
        C = A ;     
        seleccion(C);
    }while(std::next_permutation(A.begin(),A.end()));
    selec.parar();

    std::cout << "Seleccion tiempo: " << selec.tiempo() << std::endl;

    inser.activar() ;
    do {
        D = A ;     
        burbujeo(D);
    }while(std::next_permutation(A.begin(),A.end()));
    inser.parar();

    std::cout << "Burbuja tiempo: " << inser.tiempo() << std::endl;


}