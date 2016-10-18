
#include<iostream>

class char_vector{

  private:

    char* base_;
    int sz_;

  public:

    char_vector(int sz);
    ~char_vector(void);
    char get_item(int i);
    void set_item(int i, char dato);
    int get_sz(void);
};
