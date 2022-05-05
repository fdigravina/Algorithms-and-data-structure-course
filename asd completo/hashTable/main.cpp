#include <iostream>
#include <cmath>
#include "hashTable.h"

using namespace std;

struct myHash {
	unsigned operator () (const double& k) const {
		return floor (k);
	}
};

int main () {
	
	HashTable <double, int, myHash> h;
	
	h.insert (3.51, 3);
	h.insert (4.12, 4);
	h.insert (2.71, 2);
	
	cout << "coppia <4.12, 4> presente? " << boolalpha << h.find (4.12, 4) << '\n';
	
	h.remove (4.12);
	
	cout << "coppia <4.12, 4> presente? " << boolalpha << h.find (4.12, 4) << '\n';
	
}
