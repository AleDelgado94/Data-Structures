#include<iostream>
#include "stack_vector.hpp"

using namespace std;

stack_vector_t::stack_vector_t(short int sz):
sz_(sz),
base_(NULL)
{
    base_ = new stack_symbol_t [sz];
}

stack_vector_t::~stack_vector_t(void)
{
    if(base_!= NULL){

        delete[] base_;
        base_ = NULL;

    }
}

stack_symbol_t stack_vector_t::get_item(short int i)
{
    return base_[i];
}

void stack_vector_t::set_item(short int i, stack_symbol_t dato)
{
    base_[i]=dato;
}

short int stack_vector_t::get_sz(void)
{
    return sz_;
}
