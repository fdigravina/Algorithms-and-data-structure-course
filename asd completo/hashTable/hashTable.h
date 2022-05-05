#ifndef _HASH_TABLE
#define _HASH_TABLE

#include "hashNode.h"

const unsigned TABLE_SIZE = 100;


// funzione personalizzata per convertire qualunque tipo di dato ad intero per essere indicizzato

template <typename K> struct KeyHash {
	
	unsigned operator () (const K& key) const {
		return reinterpret_cast<unsigned> (key) % TABLE_SIZE;
	}
	
};



template <typename K, typename V, typename F = KeyHash<K>> class HashTable {
	
	public:
		
		HashTable ();			// metodo costruttore
		~HashTable ();			// metodo distruttore
		
		void insert (K, V);		// inserisce la coppia <chiave, valore> nel rispettivo bucket
		void remove (K);		// rimuove, se esiste, la coppia <chiave, valore> dal rispettivo bucket
		bool find (K, V);		// cerca se tale coppia <chiave, valore> sia presente nella hash table
		
	private:
		
		HashNode<K,V>** table;	// vettore di puntatori di coppie <chiave, valore>
		F HashFunc;				// funzione di hash per un tipo generico K della chiave
		
};


template <typename K, typename V, typename F> HashTable<K,V,F>::HashTable () {
	table = new HashNode<K,V>* [TABLE_SIZE];
}



template <typename K, typename V, typename F> HashTable<K,V,F>::~HashTable () {
	
	for (int i=0; i<TABLE_SIZE; ++i) {
		
		HashNode<K,V>* elem = table[i];
		
		while (elem != nullptr) {
			
			HashNode<K,V>* prev = elem;
			elem = elem->getNext ();
			delete prev;
			
		}
		
		table[i] = nullptr;
		
	}
	
	delete [] table;
	
}



template <typename K, typename V, typename F> void HashTable<K,V,F>::insert (K key, V value) {
	
	unsigned HashValue = HashFunc (key);
	HashNode<K,V>* prev = nullptr;
	HashNode<K,V>* elem = table[HashValue];
	
	while (elem != nullptr and elem->getKey() != key) prev = elem, elem = elem->getNext();
	
	if (elem == nullptr) {
		
		elem = new HashNode<K,V> (key, value);
		
		if (prev == nullptr) table[HashValue] = elem;	// inserisco nel primo bucket
		else prev->setNext (elem);
		
	} else elem->setValue (value);	// altrimenti aggiorno il valore
	
}



template <typename K, typename V, typename F> void HashTable<K,V,F>::remove (K key) {
	
	unsigned HashValue = HashFunc (key);
	HashNode<K,V>* prev = nullptr;
	HashNode<K,V>* elem = table[HashValue];
	
	while (elem != nullptr and elem->getKey() != key) prev = elem, elem = elem->getNext();
	
	if (elem == nullptr) return;	// chiave non trovata
	
	if (prev == nullptr) table[HashValue] = elem->getNext ();	// sto rimuovendo il primo bucket
	else prev->setNext(elem->getNext());					// il bucket prima di me punta al bucket dopo di me
	
	delete elem;
}



template <typename K, typename V, typename F> bool HashTable<K,V,F>::find (K key, V value) {
	
	unsigned HashValue = HashFunc (key);
	HashNode<K,V>* elem = table[HashValue];
	
	while (elem != nullptr) {
		
		if (elem->getKey() == key) return true;
		elem = elem->getNext ();
		
	}
	
	return false;
	
}

#endif
