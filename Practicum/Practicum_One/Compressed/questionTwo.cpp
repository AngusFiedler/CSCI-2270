#include <iostream>
using namespace std;

struct Node{
	int key;
	Node * next;
};

void print(Node *head){
	Node *temp = head;
	Node *headEven = new Node;
	Node *headOdd = new Node;
	Node *evenTemp = NULL;
	Node *oddTemp = NULL;

	while(temp != NULL){
		Node *newNode = new Node;
		newNode->key = temp->key;
		newNode->next = NULL;
		if(temp->key %2 == 0){
			if(evenTemp == NULL){
				headEven->key = temp->key;
				evenTemp = headEven;
				evenTemp->next = NULL;
			}
			else{
				evenTemp->next = newNode;
				evenTemp = newNode;
				evenTemp->next = NULL;
			}
		}
		else{
			if(oddTemp == NULL){
				headOdd->key = temp->key;
				oddTemp = headOdd;
				oddTemp->next = NULL;
			}
			else{
				oddTemp->next = newNode;
				oddTemp = newNode;
				oddTemp->next = NULL;
			}

		}
		temp = temp->next;
	}
 	//oddTemp->next = NULL;
	//evenTemp->next = NULL;

	Node* loopTemp;
	if(evenTemp != NULL){
		cout << "Even Numbers" << endl;
		loopTemp = headEven;
		while(loopTemp != NULL){
			cout << loopTemp->key << endl;
			loopTemp = loopTemp->next;
		}
	}

	cout << "odd numbers" << endl;
	loopTemp = headOdd;
	while(loopTemp != NULL){
		cout << loopTemp->key << endl;
		loopTemp = loopTemp->next;
	}
}
int main(){
	Node *head = new Node;
	head->key = 1;

	Node *a = new Node;
	a->key = 2;
	head->next = a;

	Node *b = new Node;
	b->key = 3;
	a->next = b;

	Node *c = new Node;
	c->key = 4;
	b->next = c;

	Node *d = new Node;
	d->key = 5;
	c->next = d;
	d->next = NULL;
	cout << "with numbers 1,2,3,4,5" << endl;
	print(head);
	cout << endl;

	cout << "with just the number 3" << endl;
	Node* headTwo = new Node;
	headTwo->key = 3;
	headTwo->next = NULL;
	print(headTwo);


}