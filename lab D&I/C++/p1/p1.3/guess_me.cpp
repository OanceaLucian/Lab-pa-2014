#include <iostream>
#include "guess_me.h"


int guess(const GuessMe& g)
{
    //TODO Folosind metoda is_in_bounds a clasei GuessMe
    //Cautati binar cea mai mare valoare pentru care
    //is_in_bounds intoarce true.
    //
    //Vom denumi acea valoare unknown.
    //
    //Se stie ca is_in_bounds intoarce true de la 0
    //la unknown și false pentru numere mai mari
    //decat unknown
    //
    //Exemplu, unknown = 4
    //   _________
    //f:          |_______
    //x: 0 1 2 3 4 5 6 7 8
    //
    //Remember! (lower + upper) / 2 is bad!

    int lower = 0;
    int upper = GuessMe::max_value;
    int res = lower+(upper-lower)/2;

 while (! (g.is_in_bounds(res) && !g.is_in_bounds(res + 1))) {
                    if (g.is_in_bounds(res)) {
                        lower = res;
                    } else {
                        upper = res;
                    }
                    res = lower + (upper - lower) / 2;
                }

    return res;
}


int main(void)
{
    GuessMe g1(1), g2(10), g3(15), g4(42);

    std::cout << (guess(g1) == 1  ? "Corect!" : "Gresit!") << std::endl;
    std::cout << (guess(g2) == 10 ? "Corect!" : "Gresit!") << std::endl;
    std::cout << (guess(g3) == 15 ? "Corect!" : "Gresit!") << std::endl;
    std::cout << (guess(g4) == 42 ? "Corect!" : "Gresit!") << std::endl;
    return 0;
}
