#ifndef _PQUEUE_H
#define _PQUEUE_H

#include <vector>
#include <cassert>

using namespace std;

template <typename T> class priority_queue {
	
	public:
		
		priority_queue ();			// metodo costruttore
		~priority_queue ();			// metodo distruttore
		
		void push (T);				// inserisce un elemento nella coda di priorita'
		void pop ();				// elimina un elemento dalla coda di priorita'
		
		T top ();					// restituisce l'elemento in testa (il piu' piccolo) della coda
		
		bool isEmpty () { return v.size() == 0; }	// true se la coda e' vuota
		int size () { return v.size(); }		// restituisce il numerodi elementi nella coda
		
	private:
		
		vector <T> v;
		
		int left (int parent) {
			int l = 2*parent + 1;
			return (l < v.size() ? l : -1);
		}
		
		int right (int parent) {
			int r = 2*parent + 2;
			return (r < v.size() ? r : -1);
		}
		
		int father (int child) {
			if (child == 0) return -1;
			return (child-1) / 2;
		}
		
		void up (int node) {
			
			if (node >= 0 and father(node) >= 0 and v[father(node)] > v[node]) {
				swap (v[node], v[father(node)]);
				up (father(node));
			}
			
		}
		
		void down (int node) {
			
			int child1 = left (node);
			int child2 = right (node);
			
			if (child1 >= 0 and child2 >= 0 and v[child1] > v[child2]) child1 = child2;
			
			if (child1 > 0 and v[node] > v[child1]) {
				swap (v[node], v[child1]);
				down (child1);
			}
			
		}
	
};




template <typename T> priority_queue<T>::priority_queue () { }



template <typename T> priority_queue<T>::~priority_queue () {
	v.clear ();
}



template <typename T> void priority_queue<T>::push (T value) {
	
	v.push_back (value);
	up (v.size() - 1);
	
}



template <typename T> void priority_queue<T>::pop () {
	
	if (this->isEmpty()) return;
	
	v[0] = v[v.size() - 1];
	v.pop_back ();
	
	down (0);
	
}



template <typename T> T priority_queue<T>::top () {
	
	assert (not this->isEmpty());
	return v.front ();
	
}




#endif
