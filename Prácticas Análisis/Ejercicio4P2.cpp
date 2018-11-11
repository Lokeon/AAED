
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>

int main(void) {
    double a=0.0 ; 
    int b=1 ;
    double res = 0 ;

    std::srand( unsigned ( std::time(0) ) );
    for(int i = 0 ; i < 10E6 ; ++i ) {
        double ra = (rand()*((b - a )/RAND_MAX) + a) ;
               res += 4 * sqrt(1 - pow(ra,2));
    }

    std::cout << "Media: " << res / 10E6  << std::endl ;

}