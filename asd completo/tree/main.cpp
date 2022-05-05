#include <iostream>
#include "tree.h"

using std::cout;

int main () {
	
	Tree <int> t;
	
	// l'albero contiene 4 nodi: 1, 2, 3, 4
	// insert ha come parametri il padre ed il figlio
	
	t.insert (0, 1);	// nel primo inserimento passiamo un finto nodo padre, in questo caso 0
	t.insert (1, 2);
	t.insert (2, 3);
	t.insert (1, 4);
	
	t.print ();
	
	t.remove (2);		// rimuovo il sottoalbero composto dai nodi 2, 3
	
	t.print ();
	
}
