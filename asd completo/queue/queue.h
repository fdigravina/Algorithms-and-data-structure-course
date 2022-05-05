#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <cassert>
#include "node.h"

using namespace std;

template <typename T> class queue {
	
	public:
		
		queue ();					// metodo costruttore
		queue (const queue<T>& q);	// costruttore di copia
		~queue ();					// metodo distruttore
		
		bool operator == (const queue<T>&);		// restituisce true se questa lista e' uguale alla lista passata come parametro
		bool operator != (const queue<T>&);		// restituisce true se questa lista e' diversa dalla lista passata come parametro
		
		void push (T);			// inserisce un elemento in coda
		
		void pop ();			// rimuove un elemento dalla fine della coda se la coda non e' vuota
		void clear ();			// svuota la coda rimuovendo tutti gli elementi
		
		T top ();				// restituisce l'elemento in testa alla coda
		void print ();			// stampa gli elementi della coda
		
		int length () { return size; }		// restituisce il numero di elementi della coda
		bool isEmpty () { return size == 0; }	// restituisce true se la coda non contiene elementi
	
	private:
		Node<T>* head;
		int size;
};



template <typename T> queue<T>::queue () {
	head = new Node<T> ();
	size = 0;
}



template <typename T> queue<T>::~queue () {
	while (not isEmpty()) pop ();
	delete head;
}



// costruttore di copia
template <typename T> queue<T>::queue (const queue<T>& q) {
	
	this->size = 0;
	this->head = new Node<T> ();
	
	Node<T>* temp = q.head->next;
	
	while (temp != NULL) {
		push (temp->value);
		temp = temp->next;
	}
}



template <typename T> bool queue<T>::operator == (const queue<T>& other) {
	
	if (this->size != other.size) return false;
	
	Node<T>* temp = this->head->next;
	Node<T>* elem = other.head->next;
	
	while (temp != nullptr) {
		
		if (temp->value != elem->value) return false;
		
		temp = temp->next;
		elem = elem->next;
	}
	
	return true;
}



template <typename T> bool queue<T>::operator != (const queue<T>& other) {
	
	if (this->size != other.size) return true;
	
	Node<T>* temp = this->head->next;
	Node<T>* elem = other.head->next;
	
	bool equal = true;
	
	while (temp != nullptr) {
		
		equal &= temp->value == elem->value;
		
		temp = temp->next;
		elem = elem->next;
	}
	
	return not equal;
	
}



template <typename T> void queue<T>::push (T value) {
	
	Node<T>* nuovo = new Node<T> (value);
	Node<T>* temp = head;
	
	while (temp->next != NULL) temp = temp->next;
	
	temp->next = nuovo;
	++size;

}



template <typename T> T queue<T>::top () {
	assert (head->next != NULL);
	return head->next->value;
}



template <typename T> void queue<T>::pop () {
	
	assert (head->next != NULL);
	
	Node<T>* temp = head;
	while (temp->next->next != NULL) temp = temp->next;
	
	delete temp->next;
	temp->next = NULL;
	
	--size;
}



template <typename T> void queue<T>::print () {
	
	Node<T>* temp = head->next;
	
	while (temp != NULL) {
		cout << temp->value << ' ';
		temp = temp->next;
	}
	
	cout << std::endl;
}



template <typename T> void queue<T>::clear () {
	while (not isEmpty()) pop();
}


#endif
