#ifndef _DEQUE_H
#define _DEQUE_H

#include <iostream>
#include <cassert>
#include "node.h"

using std::cout;

template <typename T> class dequeue {
	
	public:
		
		dequeue ();		// costruttore di default
		~dequeue ();	// metodo distruttore
		
		
		void push_back (T);		// inserisce un valore in coda
		void pop_back ();		// rimuove l'elemento in coda se la dequeue non e' vuota
		
		void push_front (T);	// inserisce un valore in testa
		void pop_front ();		// rimuove l'elemento in testa se la dequeue non e' vuota
		
		void print ();			// stampa gli elementi presenti nella dequeue
		
		void inverti ();		// inverte l'ordine degli elementi nella dequeue
		bool palindroma ();		// restituisce true se la dequeue e' palindroma, false altrimenti
		
		int length () { return size; }			// restituisce il numero di elementi presenti nella dequeue
		bool isEmpty () { return size == 0; }	// restituisce true se la dequeue non contiene elementi, false altrimenti
	
	private:
		Node<T>* _head;		// nodo di testa della dequeue
		Node<T>* _tail;		// nodo di coda della dequeue
		int size;			// numero di elementi presenti nella dequeue
};



// costruttore di default

template <typename T> dequeue<T>::dequeue () {
	
	_head = new Node<T>;
	_tail = new Node<T>;
	
	_head->_next = _tail;
	_tail->_prev = _head;
	
	size = 0;
	
}



// metodo distruttore

template <typename T> dequeue<T>::~dequeue () {
	
	while (size) pop_back();
	delete _head;
	
}



// input: valore da inserire nella dequeue
// operazione: inserisce il valore richiesto in coda

template <typename T> void dequeue<T>::push_back (T value) {
	
	Node<T>* elem = new Node<T> (value);
	
	elem->_prev = _tail->_prev;
	elem->_next = _tail;
	
	_tail->_prev->_next = elem;
	_tail->_prev = elem;
	
	++size;
}



/*
 * se la dequeue e' vuota non esegue alcuna rimozione
 * altrimenti elimina l'elemento in coda
*/

template <typename T> void dequeue<T>::pop_back () {
	
	if (isEmpty()) return;
	
	Node<T>* elem = _tail->_prev;
	
	_tail->_prev->_prev->_next = _tail;
	_tail->_prev = _tail->_prev->_prev;
	
	delete elem;
	--size;
	
}



// input: valore da inserire nella dequeue
// operazione: inserisce il valore richiesto in testa

template <typename T> void dequeue<T>::push_front (T value) {
	
	Node<T>* elem = new Node<T> (value);
	
	elem->_prev = _head;
	elem->_next = _head->_next;
	
	_head->_next->_prev = elem;
	_head->_next = elem;
	
	++size;
	
}



/*
 * se la dequeue e' vuota non esegue alcuna rimozione
 * altrimenti elimina l'elemento in testa
*/

template <typename T> void dequeue<T>::pop_front () {
	
	if (isEmpty()) return;
	
	Node<T>* elem = _head->_next;
	
	_head->_next->_next->_prev = _head;
	_head->_next = _head->_next->_next;
	
	delete elem;
	--size;
	
}



// stampa gli elementi presenti nella dequeue

template <typename T> void dequeue<T>::print () {
	
	Node<T>* elem = _head->_next;
	
	while (elem != _tail) {
		cout << elem->value << ' ';
		elem = elem->_next;
	};
	
	cout << '\n';
}




// inverte l'ordine degli elementi nella dequeue

template <typename T> void dequeue<T>::inverti () {
	
	Node<T>* start = _head->_next;
	Node<T>* end = _tail->_prev;
	
	for (int i=0; i<size/2; ++i) {
		
		T aux = start->value;
		start->value = end->value;
		end->value = aux;
		
		start = start->_next;
		end = end->_prev;
	}
	
}



// restituisce true se la dequeue e' palindroma, false altrimenti

template <typename T> bool dequeue<T>::palindroma () {
	
	Node<T>* start = _head->_next;
	Node<T>* end = _tail->_prev;
	
	for (int i=0; i<size/2; ++i) {
		
		if (start->value != end->value) return false;
		
		start = start->_next;
		end = end->_prev;
	}
	
	return true;
	
}


#endif
