#include <iostream>
using namespace std;

struct Node{
	int key;
	Node * next;
};

void createList(Node *head,int aa, int bb, int cc){
	Node *a = new Node;
	a->key = aa;
	head->next = a;
	Node *b = new Node;
	b->key = bb;
	a->next = b;
	Node *c = new Node;
	c->key = cc;
	b->next = c;
	c->next = NULL;

}

int sumEvens(Node* head){
	Node* temp = head;
	int sum = 0;;
	while(temp != NULL){
		if((temp->key) %2 == 0){
			sum += temp->key;
		}
		temp = temp->next;
	}
	return sum;
}
int main(){
	Node* head = new Node;
	head->key = 7;
	Node *test = NULL;

	cout << "with list of 7,4,6,2" << endl;
	createList(head, 4,6,2);
	cout << "sum = " << sumEvens(head) << endl;
	cout << "-------------" << endl;

	cout << "with empty list" << endl;
	Node* fake = NULL;
	cout << "sum = " << sumEvens(fake) << endl;
	cout << "-------------" << endl;

	cout << "with two elements, 400, 3" << endl;
	Node *finalHead = new Node;
	finalHead->key = 400;
	Node *nodeTwo = new Node;
	nodeTwo ->key = 3;
	nodeTwo->next = NULL;
	finalHead->next = nodeTwo;
	cout << "sum = " << sumEvens(finalHead) << endl; 
}