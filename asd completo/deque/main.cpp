#include <iostream>
#include "deque.h"

using std::cout;

int main () {
	
	dequeue<int> d;
	d.push_back(2), d.push_front(1), d.push_back(3);
	
	cout << "lista: ";
	d.print ();
	
	d.pop_back();
	d.push_back(1);
	
	cout << "lista: ";
	d.print ();
	
	cout << "lista palindroma? " << (d.palindroma () ? "true" : "false") << '\n';
	
	cout << "lista invertita: ";
	d.inverti ();
	d.print ();
	
	cout << "lista invertita palindroma? " << (d.palindroma () ? "true" : "false") << '\n';
};
