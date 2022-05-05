#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <cassert>
#include "node.h"

using namespace std;

template <typename T> class stack {
	
	public:
		
		stack ();		// metodo costruttore
		~stack ();		// metodo distruttore
		
		bool isEmpty () { return size == 0; }	// restituisce true se la pila e' vuota
		int length () { return size; }			// restituisce il numero di elementi presenti nella pila
		
		void push (T);		// inserisce un elemento in testa alla pila
		void pop ();		// elimina, se presente, un elemento dalla testa della pila
		
		T top ();			// restituisce l'elemento in testa alla pila
		void print ();		// stampa gli elementi presenti nella pila
	
	private:
		Node<T>* head;
		int size;
};




template <typename T> stack<T>::stack () {
	head = new Node<T> ();
	size = 0;
}


		
template <typename T> stack<T>::~stack () {
	while (not isEmpty()) pop ();
	delete head;
}



template <typename T> void stack<T>::push (T value) {
	
	Node<T>* elem = new Node<T> (value);
	
	elem->next = head->next;
	head->next = elem;
	
	++size;
	
}



template <typename T> void stack<T>::pop () {
	
	assert (not isEmpty());
	
	Node<T>* elem = head->next;
	
	head->next = head->next->next;
	
	delete elem;
	--size;
	
}



template <typename T> T stack<T>::top () {
	assert (head->next != NULL);
	return head->next->value;
}



template <typename T> void stack<T>::print () {
	
	Node<T>* temp = head->next;
	
	while (temp != NULL) {
		cout << temp->value << ' ';
		temp = temp->next;
	}
	
	cout << std::endl;
}

#endif
