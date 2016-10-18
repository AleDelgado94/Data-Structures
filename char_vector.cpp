#include<iostream>
#include "char_vector.hpp"


using namespace std;


char_vector::char_vector():

  base_(NULL),
  sz_(sz)
{
    base_= new char[sz_];
}

  char_vector::~char_vector(void)
  {
    delete [] base_;
    sz_(NULL)
  }

char char_vector::get_item(int i)
{

  return(base_[i])

}

void char_vector::set_item(int i, char dato)
{



}

int char_vector::get_sz(void)
{



}

