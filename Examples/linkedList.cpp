#include <ostream>
#include <iostream>
using namespace std;

struct Node{
	string key;
	Node *next;	//self referential pointer, points to its own type
};

int main(){
	Node *p1 = new Node;	//create a dynamic pointer for a new node(A)
	Node *p2 = new Node;	//create another dynamic pointer for a node(B)
	p1 -> key = "llama";
	p2 -> key = "donkey";
	p1 -> next = p2;		//links p1 to p2
	p2 = new Node;		//moves the pointer to a new Node(C)
	cout << p1 -> next -> key << endl;	//prints donkey, the orginal key of p2

	//link b and c
	p1 -> next -> next = p2;
}