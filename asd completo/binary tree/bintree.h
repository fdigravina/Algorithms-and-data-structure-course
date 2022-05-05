#ifndef _BINTREE_H
#define _BINTREE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "node.h"

using namespace std;

template <typename T> class Tree {
	
	public:
		
		Tree ();		// costruttore di default
		~Tree ();		// metodo distruttore
		
		void insert (T);	// inserisce il valore nell'albero binario
		void cancel (T);	// elimina, se presente, il valore dall'albero binario
		
		bool find (T);		// restituisce true se il valore cercato e' presente nell'albero binario
		void print ();		// stampa i valori degli elementi nell'albero binario
		
		int depth ();		// restituisce la profondita' dell'albero
		int width ();		// restituisce l'ampiezza dell'albero
		
	private:
		
		Node<T>* root;		// radice dell'albero
		
		void insert (Node<T>* &, T);	// funzione ricorsiva ausiliaria per l'inserimento di un nodo
		void cancel (Node<T>*, T);		// funzione ricorsiva ausiliaria per l'eliminazione di un nodo
		void deleteSubTree (Node<T>*);	// funzione ricorsiva ausiliaria per l'eliminazione di un sottoalbero
		bool find (Node<T>*, T);		// restitiuisce true se il sottoalbero attuale contiene il valore richiesto
		void print (Node<T>*);			// funzione ricorsiva ausiliaria per la stampa di un sottoalbero
		int depth (Node<T>*, int);		// funzione ricorsiva ausiliaria che restituisce la profondita' di un sottoalbero
		void width (Node<T>*, int, vector<int>&);	// funzione ricorsiva ausiliaria che restituisce l'ampiezza di un sottoalbero
		
};




// costruttore di default

template <typename T> Tree<T>::Tree () {
	root = nullptr;
}



// metodo distruttore

template <typename T> Tree<T>::~Tree () {
	deleteSubTree (this->root);
}



// inserisce il valore nell'albero binario

template <typename T> void Tree<T>::insert (T value) {
	insert (root, value);
}



// elimina, se presente, il valore dall'albero binario

template <typename T> void Tree<T>::cancel (T value) {
	return cancel (root, value);
}




// restituisce true se il valore cercato e' presente nell'albero binario

template <typename T> bool Tree<T>::find (T value) {
	return find (root, value);
}




// stampa i valori degli elementi nell'albero binario

template <typename T> void Tree<T>::print () {
	print (this->root);
	cout << endl;
}




// restituisce la profondita' dell'albero

template <typename T> int Tree<T>::depth () {
	return depth (this->root, 0);
}




// restituisce l'ampiezza dell'albero

template <typename T> int Tree<T>::width () {
	
	vector <int> levelsCount (100, 0);
	width (this->root, 0, levelsCount);
	return *max_element (levelsCount.begin(), levelsCount.end());
	
}




// funzione ricorsiva ausiliaria per l'inserimento di un nodo

template <typename T> void Tree<T>::insert (Node<T>* &root, T value) {
	
	if (root == nullptr) {
		root = new Node<T> (value);
		return;
	}
	
	if (root->value > value) insert (root->sx, value);
	else insert (root->dx, value);
	
}




// restitiuisce true se il sottoalbero attuale contiene il valore richiesto

template <typename T> bool Tree<T>::find (Node<T>* root, T value) {
	if (root == nullptr) return false;
	return root->value == value | find (root->sx, value) | find (root->dx, value);
}




// funzione ricorsiva ausiliaria per l'eliminazione di un sottoalbero

template <typename T> void Tree<T>::deleteSubTree (Node<T>* root) {
	
	if (root == nullptr) return;
	
	deleteSubTree (root->sx);
	deleteSubTree (root->dx);
	delete root;
	
}



// funzione ricorsiva ausiliaria per l'eliminazione di un nodo

template <typename T> void Tree<T>::cancel (Node<T>* root, T value) {
	
	if (root == nullptr) return;
	if (root->value == value) deleteSubTree (root);
	cancel (root->sx, value), cancel (root->dx, value);
	
}



// funzione ricorsiva ausiliaria per la stampa di un sottoalbero

template <typename T> void Tree<T>::print (Node<T>* root) {
	
	if (root == nullptr) return;
	
	print (root->sx);
	cout << root->value << ' ';
	print (root->dx);
	
}



// funzione ricorsiva ausiliaria che restituisce la profondita' di un sottoalbero

template <typename T> int Tree<T>::depth (Node<T>* root, int level) {
	
	if (root == nullptr) return level;
	return max (depth (root->sx, level+1), depth (root->dx, level+1));
	
}



// funzione ricorsiva ausiliaria che restituisce l'ampiezza di un sottoalbero

template <typename T> void Tree<T>::width (Node<T>* root, int level, vector<int>& levelsCount) {
	
	if (root == nullptr) return;
	
	++levelsCount[level];
	width (root->sx, level+1, levelsCount), width (root->dx, level+1, levelsCount);
}




#endif
