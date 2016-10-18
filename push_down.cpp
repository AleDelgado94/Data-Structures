

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>


typedef short int state_t;
typedef short int input_symbol_t;
typedef short int stack_symbol_t;

using namespace std;

enum stack_move_t {PUSH, POP, ERROR};

class transition_t{
private:
	state_t        state_;
	stack_move_t   stack_move_;
	stack_symbol_t stack_symbol_;

public:
	transition_t(void):
	state_(-1),
	stack_move_(ERROR),
	stack_symbol_(-1){}

	transition_t(state_t state, stack_move_t stack_move, stack_symbol_t stack_symbol):
	state_(state),
	stack_move_(stack_move),
	stack_symbol_(stack_symbol){}


	transition_t(state_t state, stack_move_t stack_move):
	state_(state),
	stack_move_(stack_move){}

	~transition_t(void){}

	void           set(state_t state, stack_move_t stack_move, stack_symbol_t stack_symbol)
	{
	    state_=state;
	    stack_move_=stack_move;
	    stack_symbol_=stack_symbol;
	}

	void           set(state_t state, stack_move_t stack_move)
	{
	    state_=state;
	    stack_move_=stack_move;
	}

	state_t        get_state(void)
	{
	    return state_;
	}
	stack_move_t   get_stack_move(void)
	{
	    return stack_move_;
	}
	stack_symbol_t get_stack_symbol(void)
	{
	    return stack_symbol_;
	}

};

class stack_vector_t{
private:
	stack_symbol_t* base_;
	short int sz_;

public:
	stack_vector_t(short int sz)
	{
    base_=0;
	base_ = new stack_symbol_t [sz];
	sz_=sz;
	}
	~stack_vector_t(void)
	{
        if(base_!=0)
        delete [] base_;
        base_=0;

	}

	stack_symbol_t get_item(short int pos)
	{
	    return base_[pos];
	}
	void set_item(short int pos, stack_symbol_t dato)
	{
	    base_[pos]=dato;
	}

	short int get_sz(void)
	{
	    return sz_;
	}

};


class char_vector_t{
private:
	char* base_;
	short int sz_;

public:
	char_vector_t(short int sz):
	base_(0),
	sz_(sz)
	{
        base_ = new char [sz];

	}

	char_vector_t(void):
	base_(0),
	sz_(0){}

	~char_vector_t(void)
	{
	    delete [] base_;
	}

	void resize(short int sz)
	{
        base_ = new char [sz];
	}

	char get_item(short int pos)
	{
	    return base_[pos];
	}
	void set_item(short int pos, char dato)
	{
	    base_[pos]=dato;
	}

	short int get_sz(void)
	{
	    return sz_;
	}

};


#define EMPTY_STACK 0

class stack_t {
private:
	stack_vector_t vector_;
	short int top_;

public:
	stack_t(int max_sz):
    vector_(max_sz),
    top_(-1){}

	~stack_t(void){}

	bool empty(void)
	{
	    return (top_<= -1);
	}
	bool full(void)
	{
	    return (top_>= vector_.get_sz()-1);
	}

	void push(stack_symbol_t symbol)
	{
	    if(!full())
	    {
	        top_++;
	        vector_.set_item(top_, symbol);
	    }
	    else
	    {
	        cout << "STACK OVERFLOW!!"<<endl;
	        exit(1);
	    }
	}
	stack_symbol_t pop(void)
	{
    stack_symbol_t aux = 0;
	    if(!empty())
	    {
	        aux = vector_.get_item(top_);
	        top_--;
	    }
	    else
	    {
	        cout << "EMPTY STACK" << endl;
	        exit(1);
	    }
	    return aux;
	}

	stack_symbol_t top(void)
	{
	     stack_symbol_t aux = 0;
	    if(!empty())
	    {
	        aux=vector_.get_item(top_);
	    }
	    return aux;
	}
};



class delta_matrix_t{
private:

	transition_t* base_;

	short int n_state_;           // Estados
	short int n_input_symbol_;    // Símbolos
	short int n_stack_symbol_;

public:
	delta_matrix_t(void):
	base_(0),
	n_state_(0),
	n_input_symbol_(0),
	n_stack_symbol_(0){}


	delta_matrix_t(short int n_state, short int n_input_symbol, short int n_stack_symbol):
	base_(0),
	n_state_(n_state),
	n_input_symbol_(n_input_symbol),
	n_stack_symbol_(n_stack_symbol){}



	~delta_matrix_t(void){}

	void resize(short int n_state, short int n_input_symbol, short int n_stack_symbol)
	{
	    n_state_=n_state;
	    n_input_symbol_=n_input_symbol;
	    n_stack_symbol_=n_stack_symbol;
	}

	short int get_n_state(void)
	{
	    return n_state_;
	}
	short int get_n_input_symbol(void)
	{
	    return n_input_symbol_;
	}
	short int get_n_stack_symbol(void)
	{
	    return n_stack_symbol_;
	}

    transition_t get_transition(state_t current_state, input_symbol_t current_input_symbol, stack_symbol_t top)
	{
        return (base_[pos(current_state,current_input_symbol,top)]);
	}



	void  set_transition(state_t state, input_symbol_t input_symbol, stack_symbol_t stack_symbol, const transition_t& transition)
	{
	    base_[pos(state, input_symbol, stack_symbol)]=transition;
	}

private:
	void resize(void)
	{
	    clear();
	    base_ = new transition_t [n_state_ * n_input_symbol_ * n_stack_symbol_];
	}

	void clear(void)
	{
	    if(base_!=NULL)
	    {
	        delete [] base_;
	        base_=0;
	    }
	}

	unsigned int pos(state_t state, input_symbol_t input_symbol, stack_symbol_t stack_symbol)
	{
	    return (state*(n_input_symbol_*n_stack_symbol_)+n_stack_symbol_* input_symbol+stack_symbol);
	}

};



#define MAX_STACK_SZ 20


class pushdown_automata_t{
private:

	char_vector_t& Q_;                 // Conjunto de estados Q
	char_vector_t& Sigma_;			   // Conjunto de símbolos de entrada
	char_vector_t& Gamma_;			   // Conjunto de símbolos de la pila

	delta_matrix_t& delta_;			   // Función de transición

	stack_t		   stack_;			   // Pila

public:

	pushdown_automata_t(char_vector_t& Q, char_vector_t& Sigma, char_vector_t& Gamma, delta_matrix_t& delta);
	~pushdown_automata_t(void);

	bool accept(const char* cadena);

};

	pushdown_automata_t::pushdown_automata_t(char_vector_t& Q, char_vector_t& Sigma, char_vector_t& Gamma, delta_matrix_t& delta):
	Q_(Q),
	Sigma_(Sigma),
	Gamma_(Gamma),
	delta_(delta),
	stack_(MAX_STACK_SZ)
	{}

	pushdown_automata_t::~pushdown_automata_t(void)
	{}

	bool pushdown_automata_t::accept(const char* cadena)
	{}



int main(void)
{

	char_vector_t Q(3);

	Q.set_item(0, 'Q');
	Q.set_item(1, 'R');
	Q.set_item(2, 'S');


	char_vector_t Sigma(3);

	Sigma.set_item(0, 'x');
	Sigma.set_item(1, 'y');
	Sigma.set_item(2, 'z');

	char_vector_t Gamma(2);

	Sigma.set_item(0, '#');          // Símbolo para la pila vacía
	Sigma.set_item(1, 'x');
	Sigma.set_item(2, 'y');

    delta_matrix_t delta(Q.get_sz(), Sigma.get_sz(), Gamma.get_sz());

/////////////////////////////////////////////////////////////////////

	delta.set_transition(0, 0, 0, transition_t( 1, PUSH, 1));
	delta.set_transition(0, 1, 0, transition_t( 2, PUSH, 2));

/////////////////////////////////////////////////////////////////////

	delta.set_transition(1, 0, 0, transition_t( 1, PUSH, 1));
	delta.set_transition(1, 0, 1, transition_t( 1, PUSH, 1));
	delta.set_transition(1, 1, 1, transition_t( 1, POP));

	delta.set_transition(1, 1, 0, transition_t( 2, PUSH, 2));

/////////////////////////////////////////////////////////////////////

	delta.set_transition(2, 1, 0, transition_t( 2, PUSH, 2));
	delta.set_transition(2, 1, 2, transition_t( 2, PUSH, 2));
	delta.set_transition(2, 1, 1, transition_t( 2, POP));

	delta.set_transition(1, 1, 0, transition_t( 2, PUSH, 2));

/////////////////////////////////////////////////////////////////////

	return 0;
}
