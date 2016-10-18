#pragma once
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include "stack_vector.hpp"

using namespace std;

typedef short int state_t;
typedef short int input_symbol_t;
typedef short int stack_symbol_t;
enum stack_move_t {PUSH, POP, ERROR} //Define un tipo enumerativo


class stack_t
{
    private:

        stack_vector_t vector_;
        short int       top_;

    public:

        stack_t(short int sz);
        ~stack_t(void);
        bool empty (void);
        bool full (void);
        void push (stack_symbol_t dato);
        stack_symbol_t pop (void);
        stack_symbol_t top (void);
};
