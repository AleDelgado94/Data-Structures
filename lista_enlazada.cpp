#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;



class nodo1_t
{
    private:


        nodo1_t* next_;
    public:
         int dato_;
        nodo1_t(int dato):
        dato_(dato),
        next_(NULL){}


        ~nodo1_t(void)
        {
            dato_=0;
            next_=NULL;
        }

        int get_dato(void)
        {
            return dato_;
        }
        nodo1_t* get_next(void)
        {
            return next_;
        }
        void set_next(nodo1_t* next)
        {
            next_=next;
        }
        void write(void)
        {
            cout<< dato_ << " ";
            cout.flush();
        }
};

class lista_1
{
    private:
        nodo1_t* inicio_;

    public:

        lista_1(void):                                                                //     -----------
        inicio_(0){}                                                                  //    | dato |next|
                                                                                      //     -----------
        ~lista_1(void)
        {
            clear();
        }
        void insertar_inicio(nodo1_t* nodo)
        {
            nodo->set_next(inicio_);
            inicio_=nodo;
        }
        void insertar_despues(nodo1_t* nodo, nodo1_t* previo)
        {
            nodo->set_next(previo->get_next());
            previo->set_next(nodo);
        }
        nodo1_t* eliminar_inicio(void)
        {
            nodo1_t* aux=inicio_;

            inicio_=inicio_->get_next();
            aux->set_next(NULL);
            return aux;
        }
        nodo1_t* eliminar_despues(nodo1_t* previo)
        {
            nodo1_t* aux=previo->get_next();

            if(aux!=NULL)
            {
                previo->set_next(aux->get_next());
                aux->set_next(NULL);
            }
            return aux;
        }
        void write(void)
        {
            nodo1_t* aux=inicio_;
            while(aux!=0)
            {
                aux->write();
                aux= aux->get_next();
            }
        }
        bool empty(void)
        {
            if((inicio_->get_next())==0)
            return true;
            else
            return false;
        }

    private:
        void clear(void)
        {
            nodo1_t* aux=NULL;
            while(inicio_!=NULL)
            {
                aux=inicio_;
                inicio_=inicio_->get_next();
                delete aux;
            }
        }

};

int main (void)
{

    nodo1_t* a;
    lista_1* b;


    a->dato_=10;

    a->write();

}













