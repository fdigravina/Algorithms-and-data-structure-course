#include <iostream>
#include <cassert>

using std::cout;
using std::string;

template <typename T> class Node;
template <typename T> class uniquestack;

template <typename T> class Node {
	
	friend class uniquestack<T>;
	
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

template <typename T> class uniquestack {
	
	public:
		
		uniquestack () {
			head = new Node<T> ();
			size = 0;
		}
		
		~uniquestack () {
			while (not isEmpty()) pop ();
			delete head;
		}
		
		bool isEmpty () {
			return size == 0;
		}
		
		int length () {
			return size;
		}
		
		bool exists (T value) {
			
			Node<T>* temp = head->next;
			
			while (temp != NULL) {
				if (temp->value == value) return true;
				temp = temp->next;
			}
			
			return false;
			
		}
		
		void push (T value) {
			
			if (exists(value)) return;
			
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

int main ()
{
	uniquestack <int> s;
	
	s.push (1), s.push(2), s.push(3), s.push(1);
	s.print();
}
