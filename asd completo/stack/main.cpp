#include "stack.h"

int main () {
	
	stack <int> s;
	
	s.push (1);
	s.pop ();
	
	s.push(2), s.push(3), s.push(4);
	s.print();
	
}
