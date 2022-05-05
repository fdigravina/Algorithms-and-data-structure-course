#ifndef _NODE_H
#define _NODE_H

template <typename T> class orderedList;

template <typename T> class Node {
	
	friend class orderedList<T>;
	
	public:
		
		// costruttore di default
		
		Node () {
			this->next = nullptr;
		}
		
		
		// costruttore con passaggio del valore
		
		Node (T value) {
			this->value = value;
			this->next = nullptr;
		}
	
	private:
		T value;
		Node<T>* next;
};


#endif
