/* Bivol Mihai - Laborator PA 01 2014 */
#ifndef __GUESS_ME_H__
#define __GUESS_ME_H__

class GuessMe {
private:
    unsigned int unknown;
public:
    // Magic constant is magic
    static const int max_value = 424242;

    GuessMe(int unknown_) : unknown(unknown_) { }

    bool is_in_bounds(unsigned int x) const
    {
        return x <= unknown;
    }
};

#endif
