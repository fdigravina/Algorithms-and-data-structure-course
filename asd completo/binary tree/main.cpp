#include <iostream>

#include "node.h"
#include "bintree.h"

using namespace std;

int main () {
	
	Tree <int> t;
	
	t.insert (4);
	t.insert (2);
	t.insert (1);
	t.insert (3);
	t.insert (5);
	t.insert (6);
	
	t.print ();
	
	cout << t.depth () << endl;
	cout << t.width () << endl;
}
