#include "stack_t.h"
#include <iostream>

using namespace std;

stack_t::stack_t()
{
    dato_ = NULL;
    sz_=10;
}

stack_t::~stack_t()
{
    
}

bool stack_t::empty(void)
{
    if(dato_==NULL)
    return true;
    else
    return false;

}

bool stack_t::full(void)
{
    return false;
}

void stack_t::push(int dato)
{
    dato_ = dato;
}

int stack_t::pop(void)
{
    return dato_;
}

void stack_t::write(void)
{
    
    
    pop();
    cout << pop() << endl; 
    
  
    
}

void stack_t::imprimir (void)
{

}



