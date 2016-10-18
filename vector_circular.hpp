#pragma once
#include<iostream>


class vector_circular
{
    private:

        char base_;
        int sz_;

    public:

        vector_circular(int sz);
        ~vector_circular(void);
        char get_item(int i);
        void set_item(int i, char c);
        int get_sz(void);

    private:

        int pos(int i);
};

