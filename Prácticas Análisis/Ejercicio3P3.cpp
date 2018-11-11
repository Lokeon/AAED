
#include <algorithm>
#include <iostream>
#include "cronometro.hpp"
#include <vector>
#include "Burbuja.hpp"
#include "Inserccion.hpp"
#include "Seleccion.hpp"


template <typename T>
void generate_random_vector(std::vector<T>& A,int i) {
    int k = A.size();
    for( int j = 0 ; j < i ; ++j ) {
        A.push_back( k + j );
    }
}

int main(void) {

    cronometro burb,sel,inser;
    std::vector<int> B,S,I;
    std::srand( unsigned ( std::time(0) ) );

    for(int b = 1000 ; b < 20001 ; b += 1000){
        generate_random_vector(B,1000);
        std::random_shuffle ( B.begin(), B.end() );
        burb.activar();
        burbujeo(B);
        burb.parar();
    }
    std::cout << "Burbuja: " << burb.tiempo() << std::endl;
    
    for(int i = 1000 ; i < 20001 ; i += 1000){
        generate_random_vector(I,1000);
        std::random_shuffle ( I.begin(), I.end() );
        inser.activar();
        inserccion(I);
        inser.parar();
    }
    std::cout <<"Inserccion: " << inser.tiempo() << std::endl;
   
    for(int s = 1000 ; s < 20001 ; s += 1000){
        generate_random_vector(S,1000);
        std::random_shuffle ( S.begin(), S.end() );
        sel.activar();
        seleccion(S);
        sel.parar();
    }
    std::cout <<"Seleccion: " << sel.tiempo() << std::endl;
   
}