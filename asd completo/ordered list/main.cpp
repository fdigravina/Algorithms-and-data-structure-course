#include <iostream>
#include "orderedList.h"

using namespace std;

int main () {
	
	orderedList<int> q;
	
	q.push (2), q.push(5), q.push(3), q.push(1);
	q.print();
	
	cout << "2 presente? " << boolalpha << q.search(2) << '\n';
	
	q.pop_back();
	q.pop(2);
	
	cout << '\n';
	q.print();
	
	cout << "2 presente? " << boolalpha << q.search(2) << '\n';
	
	orderedList<int> l;
	l.push(4), l.push(0);
	
	cout << "\nseconda lista: ";
	l.print();
	
	cout << "\nliste unite: ";
	q.merge (l);
	q.print();
	
}
