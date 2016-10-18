
#include <iostream>

using namespace std;


typedef unsigned long block_t;
typedef unsigned char item_t;
typedef unsigned char block_size_t;

#define EMPTY_SET_MASK 0x00 // Máscara hexadecimal que representa el 0
#define ONE_MASK 0x01 // Máscara hexadecimal que representa el bit menos significativo a 1
class bit_set {

public:
    block_t block_; /**< Bloque de bits */
    block_size_t block_size_; /**< Tamaño del bloque en bits */

public:
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Constructor. Construye un conjunto vacío a partir de un bloque de bits.
También inicializa el atributo block_size con el número de bits que
contiene un bloque de tipo block_t ¿Cómo se consigue esto? */
bit_set(void):
block_(0),
block_size_(15){}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Destructor. No efectúa ninguna tarea en particular */
~bit_set(void)
{

}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Efectúa la unión de conjuntos. Se presentan tres métodos:
- El primero inserta un único elemento dentro del conjunto. Para ello
Se debe crear un bloque auxiliar conteniendo la máscara ONE_MASK y
hacer un desplazamiento de bits a la izquierda tantas veces como
indique el elemento a insertar. Después se efectuará el or lógico con
el conjunto llamante.
- El segundo efectúa la unión entre el conjunto llamante y el conjunto bs.
Para ello el conjunto llamante será el resultado de la unión (or) con el
conjunto bs.
- El tercer método incluye en el conjunto o_bs el resultado del operador
or lógico entre el conjunto llamante y el conjunto i_bs.*/
void set_union(item_t i)
{
    block_t aux = ONE_MASK;

    aux = aux << (i-1);
    block_ = aux | block_;
}
void set_union(const bit_set& bs)
{
    block_ = (block_ | bs.block_);
}
void set_union(const bit_set& i_bs, bit_set& o_bs)
{
    block_ = (i_bs.block_ | o_bs.block_);
}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Efectúa la intersección de conjuntos. Se presentan dos métodos:
- El primero efectúa la intersección entre el conjunto llamante
y el conjunto bs. Para ello el conjunto llamante será el resultado
de la intersección (and) con el conjunto bs.
- El segundo método incluye en el conjunto o_bs el resultado del operador
and lógico entre el conjunto llamante y el conjunto i_bs. */
void set_intersection(const bit_set& bs)
{
    block_ = (block_&bs.block_);
}
void set_intersection(const bit_set& i_bs, bit_set& o_bs)
{
    block_=(i_bs.block_ & o_bs.block_);
}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Efectúa la diferencia de conjuntos. Se presentan tres métodos:
- El primero elimina un único elemento dentro del conjunto. Para ello
Se debe crear un bloque auxiliar conteniendo la máscara ONE_MASK y
hacer un desplazamiento de bits a la izquierda tantas veces como
indique el elemento a insertar. Después se efectuará la negación
del bloque auxiliar y el and lógico con el conjunto llamante.
- El segundo efectúa la diferencia entre el conjunto llamante y el
conjunto bs. Para ello el conjunto llamante será el resultado de
la intersección (and) con el negado del conjunto bs.
- El tercer método incluye en el conjunto o_bs el resultado del operador
and lógico entre el conjunto llamante y el conjunto i_bs negado. */
void set_diff(item_t i)
{
    block_t aux = ONE_MASK;

        aux = aux << (i-1);
        aux = ~aux;

        block_=(aux & block_);

}
void set_diff(const bit_set& bs)
{

        block_=(~bs.block_ & block_);

}
void set_diff(const bit_set& i_bs, bit_set& o_bs)
{
    block_= (~i_bs.block_ & o_bs.block_);
}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Determina si un elemento pertenece al conjunto.
Se debe crear un bloque auxiliar conteniendo la máscara ONE_MASK y
hacer un desplazamiento de bits a la izquierda tantas veces como
indique el elemento a comprobar. Después se efectuará el and lógico con
el conjunto llamante. Si el resultado de la operación es distinto de 0x00
significa que el elemento ha sido insertado.*/
bool belongs(item_t i)
{
    block_t aux = ONE_MASK;

    aux = aux << (i-1);
    if((block_&aux)==0x01)
        return true;
    else
        return false;

}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Determina la contención de conjuntos. Si la intersección entre el
bloque llamante y el conjunto a es exactamente a entonces el resultado
es verdadero. */
bool contains(const bit_set& a)
{
    if((block_ & a.block_)==0x01)
        return true;
    else
        return false;
}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Vierte al flujo de salida que pasamos por parÁmetro
el contenido del conjunto. Este método se proporciona al alumno.*/
void write(ostream& os)
{
    char aux[80];

	itoa(aux);
	os << aux << std::endl;
}
//========================================================================================
// Métodos privados
//========================================================================================
private:
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Transforma el conjunto de bits en una cadena de caracteres.
Este método se proporciona al alumno.*/
void itoa(char s[])
{
     block_t n = block_;
	  char i;

	  i = 0;
	  do {       /* generate digits in reverse order */
	      s[i++] = n % 2 + '0';   /* get next digit */
	  } while ((n /= 2) > 0);     /* delete it */

	  for(;i<block_size_;i++)
	    s[i]='0';

	  s[i] = '\0';
	  reverse(s);
}
/**
\author Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
\date 12 de marzo de 2012
\details Invierte la cadaena de caracteres.
Este método se proporciona al alumno.*/
void reverse(char s[])
{
    int i, j;
	  char c;

	  for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
	      c = s[i];
	      s[i] = s[j];
	      s[j] = c;
	  }
}
};

int factorial(int n)
{
    int aux;
    if(n==0)
    {
        aux=1;
    }
    else
    {
        aux = n*factorial(n-1);
    }
    return aux;
}

int main(void)
{
  // Conjunto A
  bit_set rojo;

  rojo.set_union(1);
  rojo.set_union(5);            //ROJO: 1.2.3
  rojo.set_union(8);           //VERDE: 3.4.5

  // Conjunto B
  bit_set verde;

  verde.set_union(8);
  verde.set_union(10);
  verde.set_union(11);

  cout << "CONJUNTO A"<< endl;
  rojo.write(cout);

  cout << "CONJUNTO B"<< endl;
  verde.write(cout);


    rojo.set_intersection(rojo,verde);


 cout << "El elemento comun en los dos conjuntos es: " << endl;
 rojo.write(cout);


int i;
cin >> i;
cout << endl;
factorial(i);
cout << "Factorial de "<<i<<" es: "<<factorial(i)<<endl;



 /* // Conjunto C
  bit_set C;

  B.set_intersection(A,C);

  // Conjunto D
  bit_set D;

  D.set_union(B);
  D.set_diff(A);
*/


 /* cout << "CONJUNTO C"<< endl;
  C.write(cout);

  cout << "CONJUNTO D"<< endl;
  D.write(cout);*/
}
/*int main(void)
{
  // Conjunto A
  bit_set A;

  A.set_union(0);
  A.set_union(5);
  A.set_union(30);

  // Conjunto B
  bit_set B;

  B.set_union(A);
  B.set_union(9);
  B.set_union(15);
  B.set_union(20);

  // Conjunto C
  bit_set C;

  B.set_intersection(A,C);

  // Conjunto D
  bit_set D;

  D.set_union(B);
  D.set_diff(A);


  cout << "CONJUNTO A"<< endl;
  A.write(cout);

  cout << "CONJUNTO B"<< endl;
  B.write(cout);

  cout << "CONJUNTO C"<< endl;
  C.write(cout);

  cout << "CONJUNTO D"<< endl;
  D.write(cout);
}*/

/*main(void)
{
  // Conjunto A
  bit_set A;

  A.set_union(0);
  A.set_union(5);
  A.set_union(30);

  // Test: set_union(item_t)
  cout << "CONJUNTO A"<< endl;
  A.write(cout);

  // Conjunto B
  bit_set B;

  B.set_union(A);
  B.set_union(9);
  B.set_union(15);
  B.set_union(20);

  // Test: belongs(item_t)
  if (B.belongs(9))
    cout << "TRUE" << endl;
  else
   cout << "FALSE" << endl;

  // Test: belongs(item_t)
  if (B.belongs(4))
    cout << "TRUE" << endl;
  else
   cout << "FALSE" << endl;

  // Test: set_union(const bit_set&)
  cout << "CONJUNTO B"<< endl;
  B.write(cout);

  // Test: contains(const bit_set&)
  if (B.contains(A))
    cout << "TRUE" << endl;
  else
   cout << "FALSE" << endl;

  // Test: contains(const bit_set&)
  if (A.contains(B))
    cout << "TRUE" << endl;
  else
   cout << "FALSE" << endl;

  // Conjunto C
  bit_set C;

  B.set_intersection(A,C);

 // Test: set_intersection(const bit_set&, bit_set&)
  cout << "CONJUNTO C"<< endl;
  C.write(cout);

  // Conjunto D
  bit_set D;

  D.set_union(B);
  D.set_diff(A);

  // Test: set_diff(const bit_set&)
  cout << "CONJUNTO D"<< endl;
  D.write(cout);

  // Conjunto E
  bit_set E;

  C.set_union(D, E);

  // Test: set_union(const bit_set&, bit_set&)
  cout << "CONJUNTO E"<< endl;
  E.write(cout);

  // Conjunto F
  bit_set F;

  C.set_diff(E, F);

  // Test: set_diff(const bit_set&, bit_set&)
  cout << "CONJUNTO F"<< endl;
  F.write(cout);

}
*/
