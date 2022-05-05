#ifndef _NODE_H
#define _NODE_H

template <typename T> class dequeue;

template <typename T> class Node {
	
	friend class dequeue <T>;
	
	public:
		
		Node ();	// costruttore di default
		Node (T);	// costruttore con passaggio di valore
	
	private:
		T value;			// valore presente nel nodo
		Node<T>* _prev;		// puntatore al nodo precedente
		Node<T>* _next;		// puntatore al nodo successivo
	
};



// descrizione: costruttore di default

template <typename T> Node<T>::Node () {
	this->_prev = nullptr;
	this->_next = nullptr;
}


// input: valore con cui inizializzare il nodo
// descrizione: costruttore con passaggio di valore

template <typename T> Node<T>::Node (T value) {
	
	this->value = value;
	this->_prev = nullptr;
	this->_next = nullptr;
	
}

#endif
