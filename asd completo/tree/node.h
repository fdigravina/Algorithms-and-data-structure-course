#ifndef _NODE_H
#define _NODE_H

#include <vector>
using std::vector;

template <typename T> class Tree;

template <typename T> class Node {
	
	friend class Tree <T>;
	
	public:
		Node (T);	// costruttore con passaggio di valore
	
	private:
		T value;					// valore presente nel nodo
		vector <Node<T>*> childs;	// vettore di nodi figli
	
};

// input: valore con cui inizializzare il nodo
// descrizione: costruttore con passaggio di valore

template <typename T> Node<T>::Node (T value) {
	this->value = value;
}

#endif
