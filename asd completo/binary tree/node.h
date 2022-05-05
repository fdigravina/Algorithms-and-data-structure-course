#ifndef _NODE_H
#define _NODE_H

template <typename T> class Tree;

template <typename T> class Node {
	
	friend class Tree <T>;
	
	public:
		
		Node ();	// costruttore di default
		Node (T);	// costruttore con passaggio di valore
	
	private:
		T value;		// valore presente nel nodo
		Node<T>* sx;	// puntatore al figlio sinistro
		Node<T>* dx;	// puntatore al figlio destro
	
};



// descrizione: costruttore di default

template <typename T> Node<T>::Node () {
	this->sx = nullptr;
	this->dx = nullptr;
}


// input: valore con cui inizializzare il nodo
// descrizione: costruttore con passaggio di valore

template <typename T> Node<T>::Node (T value) {
	
	this->value = value;
	this->sx = nullptr;
	this->dx = nullptr;
	
}

#endif
