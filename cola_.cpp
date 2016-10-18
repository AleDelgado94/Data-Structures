#include<iostream>
#include "cola_.hpp"


cola::cola(int sz_):
queue_(sz_),
front_(-1),
end_(0)
{
}

cola::~cola()
{

}

bool cola::empty()
{
    return (front_ < end_);
}

bool cola::full()
{
    return (end_- front_ > queue.get_sz()-1);
}

void cola::push(char c)
{
    if(!full())
    {
        front_++;
        queue_.set_item(front, c)
    }
    else
    {
        cerr << "Queue Overflow!!" << endl;
    }
}

char cola::pop()  //Metodo para extraer el elemento
{
    char aux = '\0';

    if(!empty())
    {
        aux = queue_.get_item(end_);
        end_--;
    }
    else
    {
        cerr << "Empty Queue!!" << endl;
    }
    return aux;
}
