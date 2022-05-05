#ifndef _HASH_NODE
#define _HASH_NODE

template <typename K, typename V> class HashNode {
	
	public:
			
		HashNode (K, V);					// metodo costruttore
		~HashNode ();						// metodo distruttore
		
		K getKey ();						// restituisce la chiave del nodo
		
		V getValue ();						// restituisce il valore del nodo
		void setValue (V);					// aggiorna il valore del nodo
		
		HashNode<K,V>* getNext ();			// restituisce il puntatore al nodo successivo
		void setNext (HashNode<K,V>*);		// aggiorna il puntatore al nodo successivo
		
	private:
		
		K key;
		V value;
		HashNode<K,V>* next;
		
};


template <typename K, typename V> HashNode<K,V>::HashNode (K key, V value) {
	
	this->key = key;
	this->value = value;
	
}




template <typename K, typename V> HashNode<K,V>::~HashNode () {
	delete next;
}



template <typename K, typename V> K HashNode<K,V>::getKey () {
	return this->key;
}



template <typename K, typename V> V HashNode<K,V>::getValue () {
	return this->value;
}



template <typename K, typename V> void HashNode<K,V>::setValue (V value) {
	this->value = value;
}



template <typename K, typename V> HashNode<K,V>* HashNode<K,V>::getNext () {
	return this->next;
}



template <typename K, typename V> void HashNode<K,V>::setNext (HashNode<K,V>* other) {
	this->next = other;
}



#endif
