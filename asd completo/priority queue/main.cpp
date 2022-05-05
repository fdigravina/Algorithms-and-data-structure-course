#include <iostream>
#include "priority_queue.h"

using std::cout;

int main () {
	
	priority_queue <int> pq;
	
	pq.push (7);
	pq.push (5);
	pq.push (8);
	pq.push (2);
	pq.push (9);
	
	cout << "minimo da cancellare: " << pq.top () << "\n\n";
	
	pq.pop ();
	
	cout << "coda: ";
	
	while (not pq.isEmpty()) {
		cout << pq.top () << ' ';
		pq.pop ();
	}
	
}
