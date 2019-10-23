#include <iostream>
using namespace std;

struct Node {
int key;
Node* left;
Node* right;

Node(int k) {
this->key = k;
this->right = this->left = NULL;
}
};

void traverse(Node* n, int *k) {
if (n == NULL) {
(*k)++;
return;
}

traverse(n->left, k);
traverse(n->right, k);
}

int main() {
Node* root = new Node(12);
root->left = new Node(6);
root->right = new Node(15);
root->left->left = new Node(2);
root->right->right = new Node(8);

int m = 0;
traverse(root, &m);

cout << m << endl;
}