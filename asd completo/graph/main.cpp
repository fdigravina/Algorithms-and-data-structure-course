#include <iostream>
#include "graph.h"

using namespace std;

int main () {
	
	Graph <int, int> g;		// tipo dell'etichetta e del peso
	
	g.insertNode (0);
	g.insertNode (1);
	g.insertNode (2);
	g.insertNode (3);
	
	g.insertEdge (0, 1, 10);
	g.insertEdge (0, 2, 20);
	g.insertEdge (1, 2, 40);
	g.insertEdge (0, 3, 30);
	
	g.print ();
	
}
