
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

int main(void) {
    double a=0.0 ; 
    int b=4 ;

    std::srand( unsigned ( std::time(0) ) );
    std::cout << (a + rand()*(b - a )/RAND_MAX) << std::endl ;
}