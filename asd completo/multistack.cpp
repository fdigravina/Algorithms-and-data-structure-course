#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

template <typename T> class Node;
template <typename T> class stack;

template <typename T> class Node {
	
	friend class stack<T>;
	
	public:
	
		Node () {
			this->next = NULL;
		}
		
		Node (T value) {
			this->value = value;
			this->next = NULL;
		}
	
	private:
		T value;
		Node<T>* next;
};

template <typename T> class stack {
	
	public:
		
		stack () {
			head = new Node<T> ();
			size = 0;
		}
		
		~stack () {
			while (not isEmpty()) pop ();
			delete head;
		}
		
		bool isEmpty () {
			return size == 0;
		}
		
		int length () {
			return size;
		}
		
		void push (T value) {
			
			Node<T>* elem = new Node<T> (value);
			
			elem->next = head->next;
			head->next = elem;
			
			++size;
			
		}
		
		void pop () {
			
			assert (not isEmpty());
			
			Node<T>* elem = head->next;
			
			head->next = head->next->next;
			
			delete elem;
			--size;
			
		}
		
		T top () {
			assert (head->next != NULL);
			return head->next->value;
		}
		
		void print () {
			
			Node<T>* temp = head->next;
			
			while (temp != NULL) {
				cout << temp->value << ' ';
				temp = temp->next;
			}
			
			cout << std::endl;
		}
	
	private:
		Node<T>* head;
		int size;
};


template <typename T> class multistack {
	
	public:
	
		multistack () {
			this->size = 1;
			s = new stack<T> [size];
		}
	
		multistack (unsigned int size) {
			this->size = size;
			s = new stack<T> [size];
		}
		
		~multistack () {
			delete [] s;
		}
		
		void push (T value, unsigned int idx) {
			
			assert (idx < size);
			s[idx].push (value);
			
		}
		
		void pop (unsigned int idx) {
			
			assert (idx < size);
			s[idx].pop();
			
		}
		
		void print () {
			
			for (unsigned int i=0; i<size; ++i) {
				cout << "stack " << i << ": ";
				s[i].print();
			}
			
			cout << endl;
		}
	
	private:
		stack<T>* s;
		unsigned int size;
};

int main ()
{
	multistack <int> m (3);
	
	m.push (1, 0), m.push (2, 0), m.push (3, 0);
	m.push (4, 1), m.push (5, 1), m.push (6, 1);
	m.push (7, 2), m.push (8, 2), m.push (9, 2);
	
	m.print ();
	m.pop (1);
	m.print ();
}
