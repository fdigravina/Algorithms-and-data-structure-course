#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "edge.h"

using namespace std;

template <typename T, typename W> class Graph {
	
	public:
		
		Graph ();	// metodo costruttore
		~Graph ();	// metodo distruttore
		
		void insertEdge (T, T, W);	// inserisce un arco dal primo nodo al secondo e viceversa (grafo non direzionato)
		void removeEdge(T, T);		// cancella, se esiste, l'arco che collega i due nodi
		
		void insertNode (T);		// inserisce un nodo con tale valore, se non esiste gia' nel grafo
		void removeNode (T);		// rimuove, se presente, un nodo con tale valore dal grafo
		
		int findNode (T);		// restituisce l'indice in cui e' presente nel vettore, e -1 se non e' presente
		bool findEdge (T, T);	// restituisce true se l'arco che collega i due nodi esiste
		
		void print ();			// stampa il grafo
		bool empty ();			// true se il grafo non contiene alcun nodo
		
	private:
		
		vector<T> nodes;
		vector <vector<Edge<T,W>>> edges;
		
};


// costruttore di default

template <typename T, typename W> Graph<T,W>::Graph () {
	
}


// metodo distruttore

template <typename T, typename W> Graph<T,W>::~Graph () {
	
	nodes.clear ();
	edges.clear ();
	
}


// true se il grafo non contiene nodi

template <typename T, typename W> bool Graph<T,W>::empty () {
	return nodes.size() == 0;
}



// restituisce l'indice in cui e' presente nel vettore, e -1 se non e' presente

template <typename T, typename W> int Graph<T,W>::findNode (T value) {
	
	for (int i=0; i<nodes.size(); ++i) if (nodes[i] == value) return i;
	return -1;
	
}



// restituisce true se l'arco che collega i due nodi esiste

template <typename T, typename W> bool Graph<T,W>::findEdge (T from, T to) {
	
	int idx = findNode (from);
	
	if (idx == -1) return false;
		
	for (int i=0; i<edges[idx].size(); ++i) if (edges[idx][i].to == to) return true;
	return false;
	
}



// inserisce il nodo nel grafo se non e' gia' presente

template <typename T, typename W> void Graph<T,W>::insertNode (T value) {
	
	vector <Edge<T,W>> e;
	if (findNode(value) == -1) nodes.push_back (value), edges.push_back(e);
	
}



// inserisce l'arco nel grafo se non e' gia' presente

template <typename T, typename W> void Graph<T,W>::insertEdge (T from, T to, W weight) {
	
	if (from == to) return;		// non permetto archi da un nodo allo stesso nodo
	if (findNode(from) == -1 or findNode(to) == -1) return;
	
	if (findEdge(from,to) == false) {
		
		Edge<T,W> e1 (to, weight);
		Edge<T,W> e2 (from, weight);
		
		edges[from].push_back (e1);
		edges[to].push_back (e2);
		
	}
	
}



// stampa il grafo

template <typename T, typename W> void Graph<T,W>::print () {
	
	for (int i=0; i<nodes.size(); ++i) {
		
		cout << "adiacenze di " << nodes[i] << ":\n";
		for (int j=0; j<edges[i].size(); ++j) cout << edges[i][j].to << " con peso " << edges[i][j].weight << '\n';
		cout << endl;
		
	}
	
	cout << endl;
	
}







#endif
