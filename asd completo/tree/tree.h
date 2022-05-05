#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include <algorithm>
#include "node.h"

using namespace std;

template <typename T> class Tree {
	
	public:
		
		Tree ();	// metodo costruttore
		~Tree ();	// metodo distruttore
		
		void insert (T, T);		// primo parametro: valore nodo padre, secondo parametro: valore nuovo nodo
		void remove (T);		// cancella, se esiste, il sottoalbero radicato nel nodo con tale valore
		void print ();			// stampa l'albero
		bool find (T);			// controlla se il valore sia presente nell'albero
		bool empty ();			// true se l'albero non contiene alcun nodo
		
	private:
		
		Node<T>* root;
		
		void insert (Node<T>* &, T, T);		// funzione ricorsiva ausiliaria per l'inserimento di un nodo
		void remove (Node<T>* &, T);		// funzione ricorsiva ausiliaria per l'eliminazione di un nodo
		void deleteSubTree (Node<T>* &);	// funzione ricorsiva ausiliaria per l'eliminazione di un sottoalbero
		bool find (Node<T>*, T);			// restitiuisce true se il sottoalbero attuale contiene il valore richiesto
		void print (Node<T>*);				// funzione ricorsiva ausiliaria per la stampa di un sottoalbero
		
};


// costruttore di default

template <typename T> Tree<T>::Tree () {
	root = nullptr;
}


// metodo distruttore

template <typename T> Tree<T>::~Tree () {
	deleteSubTree (this->root);
}


template <typename T> bool Tree<T>::empty () {
	return root == nullptr;
}



// inserisce il valore nell'albero binario

template <typename T> void Tree<T>::insert (T father, T son) {
	
	if (this->empty()) insert (root, father, son);
	else if (find(father) and not find(son)) insert (root, father, son);
	else cout << "Valori non validi.\n";
	
}



// elimina, se presente, il valore dall'albero binario

template <typename T> void Tree<T>::remove (T value) {
	return remove (root, value);
}




// restituisce true se il valore cercato e' presente nell'albero binario

template <typename T> bool Tree<T>::find (T value) {
	return find (root, value);
}




// stampa i valori degli elementi nell'albero binario

template <typename T> void Tree<T>::print () {
	print (this->root);
	cout << '\n';
}




// funzione ricorsiva ausiliaria per l'inserimento di un nodo

template <typename T> void Tree<T>::insert (Node<T>* &root, T father, T son) {
	
	if (root == nullptr) {
		root = new Node<T> (son);
		return;
	}
	
	if (root->value == father) {
		(root->childs).push_back (new Node<T> (son));
		return;
	}
	
	for (Node<T>* &x: root->childs) insert (x, father, son);
	
}




// restitiuisce true se il sottoalbero attuale contiene il valore richiesto

template <typename T> bool Tree<T>::find (Node<T>* root, T value) {
	
	if (root == nullptr) return false;
	
	bool check = (root->value == value);		// check = true se root->value e' uguale a value, false altrimenti
	for (Node<T>* &x: root->childs) check |= find (x, value);
	
	return check;
	
}




// funzione ricorsiva ausiliaria per l'eliminazione di un sottoalbero

template <typename T> void Tree<T>::deleteSubTree (Node<T>* &root) {
	
	if (root == nullptr) return;
	
	for (Node<T>* &x: root->childs) deleteSubTree (x);
	
	(root->childs).clear ();
	
	delete root;
	root = nullptr;	
	
}


template <typename T> bool cmp (Node<T>* node) {
	return node == nullptr;
}


// funzione ricorsiva ausiliaria per l'eliminazione di un nodo

template <typename T> void Tree<T>::remove (Node<T>* &root, T value) {
	
	if (root == nullptr) return;
	
	if (root->value == value) {
		deleteSubTree (root);
		return;
	}
	
	for (Node<T>*& x: root->childs) remove (x, value);
	(root->childs).erase(remove_if ((root->childs).begin(), (root->childs).end(), cmp<T>), root->childs.end());
	
}



// funzione ricorsiva ausiliaria per la stampa di un sottoalbero

template <typename T> void Tree<T>::print (Node<T>* root) {
	
	if (root == nullptr) return;
	
	for (Node<T>* x: root->childs) print (x);
	cout << root->value << ' ';
	
}




#endif
