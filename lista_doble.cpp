#include <iostream>
#include<cstlib>

using namespace std;


class nodo_t
{
    private:

        int dato_;
        nodo_t siguiente_;

    public:

        nodo_t(void):
        dato_(0);
        siguiente_(NULL);

        ~nodo_t(void){}

        void set_dato(int dato)
        {
            dato_=dato;
        }

        int get_dato(void)
        {
            return dato_;
        }

        nodo_t get_siguiente(void)
        {
            return siguiente_;
        }
        void set_siguiente(nodo_t* reset)
        {
            reset = siguiente_;
        }

};

class lista_t
{
    private:

        nodo_t inicio_;
        nodo_t fin_;
    public:

        lista_t(void):
        inicio_(NULL),
        fin_(NULL){}


        ~lista_t(void){}

        void introducir_inicio(nodo_t* nodo)
        {
            nodo->set_siguiente(inicio_);
            inicio_=nodo;


        }
        void introducir_final(nodo_t* nodo, nodo_t* previo)
        {
            nodo->set_siguiente(previo->get_siguiente());
            previo->set_siguiente(nodo);
        }
};

int main (void)
{

}
