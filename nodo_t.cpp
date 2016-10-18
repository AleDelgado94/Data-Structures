#include <iostream>
#include <cstdlib>
#define SZ 10

using namespace std;




class nodo_t{

private:

nodo_t* siguiente_;
public:
char dato_;
nodo_t(void):
dato_('0'){}

~nodo_t(void){}

void inicializa(char dato)
{
    dato_=dato;
}

void imprimir(void)
{
    cout << "El dato del nodo es " << dato_<<endl;
}

nodo_t* get_siguiente(void)
{
    return siguiente_;
}

void set_siguiente(nodo_t* inx)
{
    inx = siguiente_;
}

};

/*class lista_t{

private:
nodo_t* inicio_;
nodo_t* fin_;

public:

lista_t(void);

~lista_t(void);

void imprimir(void)
{
   // cout << "El dato es: " << inicio_.dato_ << endl;
}

void imprimir_inverso(void);

void imprimir_inverso(nodo_t* nodo);

void insertar_inicio(nodo_t* inx);

void insertar_after(nodo_t* after,nodo_t* inx);

nodo_t* extraer_after(nodo_t* after);

};*/



int main (void)
{

//lista_t lista_;
nodo_t a;
char caracteres;
cin >> caracteres;

a.dato_=caracteres;

a.imprimir();




}
