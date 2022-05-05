#ifndef _ORDLIST_H
#define _ORDLIST_H

#include <iostream>
#include <cassert>

#include "node.h"

using namespace std;

template <typename T> class orderedList {
	
	public:
		
		orderedList ();			// metodo costruttore
		~orderedList ();		// metodo distruttore
		
		void push (T);			// inserisce un valore nella lista in modo ordinato
		
		void pop (T);			// elimina, se presente, il valore richiesto dalla lista
		void pop_back ();		// elimina l'elemento in coda
		
		T top ();				// restituisce l'elemento in testa alla lista
		void print ();			// stampa la lista ordinata
		
		bool search (T);		// restituisce true se l'elemento e' presente nella lista, false altrimenti
		
		void merge (const orderedList<T>&);		// unisce questa lista ordinata con un'altra preservando l'ordine tra gli elementi
		int length () { return size; }			// restituisce quanti elementi ci sono nella lista
		bool isEmpty () { return size == 0; }	// restituisce true se la lista e' vuota, false altrimenti
		
	
	private:
		Node<T>* head;
		int size;
};




template <typename T> orderedList<T>::orderedList () {
	head = new Node<T> ();
	size = 0;
}



template <typename T> orderedList<T>::~orderedList () {
	while (not isEmpty()) pop_back ();
	delete head;
}



template <typename T> void orderedList<T>::pop_back () {
	
	assert (head->next != NULL);
	
	Node<T>* temp = head;
	while (temp->next->next != NULL) temp = temp->next;
	
	delete temp->next;
	temp->next = NULL;
	
	--size;
}



template <typename T> void orderedList<T>::push (T value) {
			
	Node<T>* nuovo = new Node<T> (value);
	Node<T>* temp = head;
	
	while (temp->next != NULL and temp->next->value < value) temp = temp->next;
	
	nuovo->next = temp->next;
	temp->next = nuovo;
	++size;
	
}



template <typename T> T orderedList<T>::top () {
	assert (head->next != NULL);
	return head->next->value;
}



template <typename T> void orderedList<T>::pop (T value) {
	
	if (isEmpty() or not search (value)) return;
	
	Node<T>* temp = head;
	while (temp->next->next != NULL and temp->next->value < value) temp = temp->next;
	
	delete temp->next;
	temp->next = temp->next->next;
	
	--size;
	
}



template <typename T> void orderedList<T>::print () {
			
	Node<T>* temp = head->next;
	
	while (temp != NULL) {
		cout << temp->value << ' ';
		temp = temp->next;
	}
	
	cout << std::endl;
	
}
		
		
template <typename T> bool orderedList<T>::search (T value) {
	
	Node<T>* temp = head->next;
	
	while (temp != NULL) {
		if (temp->value == value) return true;
		temp = temp->next;
	}
	
	return false;
}


template <typename T> void orderedList<T>::merge (const orderedList<T>& other) {
	
	Node<T>* temp = other.head->next;
	
	while (temp != NULL) {
		push (temp->value);
		temp = temp->next;
	}
	
}


#endif
