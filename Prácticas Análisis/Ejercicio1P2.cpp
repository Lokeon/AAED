
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main(void) {
    int a=1 , b=9 ;

    std::srand( unsigned ( std::time(0) ) );
    std::cout << (rand()%(b - a + 1)+ a) << std::endl ;
}