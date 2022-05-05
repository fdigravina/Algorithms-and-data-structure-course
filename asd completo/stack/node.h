#ifndef _NODE_H
#define _NODE_H

template <typename T> class stack;

template <typename T> class Node {
	
	friend class stack<T>;
	
	public:
		
		// costruttore di default
		
		Node () {
			this->next = NULL;
		}
		
		
		// costruttore con passaggio per valore
		
		Node (T value) {
			this->value = value;
			this->next = NULL;
		}
	
	private:
		T value;
		Node<T>* next;
};

#endif
