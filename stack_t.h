#ifndef STACK_T_H
#define STACK_T_H
#include <iostream>

using namespace std;

class stack_t
{
   private:

        int dato_;
        int sz_;

    protected:
    public:
        stack_t();
        ~stack_t();
        bool empty (void);
        bool full (void);
        void push (int dato);
        int pop (void);
        void write (void);
        void imprimir (void);
};


#endif // STACK_T_H
