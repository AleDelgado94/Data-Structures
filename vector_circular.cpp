#include<iostream>
#include "vector_circular.hpp"


using namespace std;


vector_circular::vector_circular(int sz):
base_(NULL),
sz_(sz)
{
    base_= new char[sz_];
}

vector_circular::~vector_circular()
{
    if(base_!=NULL)
    {
        delete [] base_;
        base_=NULL;
    }
}

int vector_circular::get_sz()
{
    return sz_;
}

char vector_circular::get_item(int i)
{
    return base_[pos(i)];
}

void vector_circular::set_item(int i, char c)
{
    base_[pos(i)]=c;
}

int vector_circular::pos(int i)
{
    return i%sz_;  // <--- Clave
}
