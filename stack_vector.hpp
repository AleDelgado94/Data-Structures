#pragma once
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>


using namespace std;

typedef short int state_t;
typedef short int input_symbol_t;
typedef short int stack_symbol_t;
enum stack_move_t {PUSH, POP, ERROR} //Define un tipo enumerativo

class stack_vector_t
{
    private:

        stack_symbol_t* base_;
        short int       sz_;

    public:

        stack_vector_t(short int sz);
        ~stack_vector_t(void);
        stack_symbol_t get_item (short int i);
        void set_item (short i, stack_symbol_t dato);
        short get_sz (void);

};


