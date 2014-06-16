#include <iostream>
#include <cmath>

bool compare(double x, double y, double precision)
{
    return std::abs(x - y) < precision;
}

double my_sqrt(double x, double lower, double upper, double precision)
{
    // TODO Cautati intre lower si upper o valoare care ridicata
    // la patrat sa dea x.
    //
    // Good to know!
    // La calcularea pozitiei de mijloc folositi
    // double m = lower + (upper - lower) / 2;
    // nu
    // double m = (lower + upper) / 2;
    // Pentru a evita overflow la adunarea pe double
    //
    // Folositi functia compare pentru a verifica cu aproximare
    // egalitatea.

    double m = lower + ( upper - lower ) / 2;
    if( compare ( m * m , x , precision ) ) return m;
     if( m * m > x ) return my_sqrt( x , lower , m , precision );
     if( m * m  < x) return my_sqrt( x , m , upper , precision);




    ///return 0;
}

int main(void) {
    //TODO Testati codul cu 3 valori alese de voi.
    // Cel putin o valoare sa fie subunitara.
    //Precizia va fi 0.001.
    //Decideti care va fi valoarea upper folosita.
    //
    //Hint ce se intampla cand x < 1?
    //
    //Afisati numarul si patratul rezultatului.
    double x=24;
    std::cout << x << " " << my_sqrt ( x , 0 , x , 0.001 ) << " " << sqrt ( x ) << std::endl;
    x=45.6;
    std::cout << x << " " << my_sqrt ( x , 0 , x , 0.001 ) << " " << sqrt ( x ) << std::endl;
    x=0.034;
    std::cout << x << " " << my_sqrt ( x , 0 , 1 ,0.001 )<< " " << sqrt(x) << std::endl;
}
