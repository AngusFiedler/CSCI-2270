#include "BST.hpp"
#include <iostream>
#define COUNT 10

using namespace std;

////////////////////////////////////////////////////////////////////////
//THIS IS THE EXAM QUESTION SOLUTION                                  //
////////////////////////////////////////////////////////////////////////
int sumRangeRecurs(Node* currentNode,int min, int max){
	if (currentNode->key <= max && currentNode->key >= min){
		return currentNode->key + sumRangeRecurs(currentNode->left, min, max) + sumRangeRecurs(currentNode->right, min, max); 
	}
    else if (currentNode->key < min){
    	return sumRangeRecurs(currentNode->right, min, max);
    }
    else return sumRangeRecurs(currentNode->left, min, max); 
}
int BST::sumRange(int min, int max){
	//makes sure there is a bst
	if(root == nullptr){
		return 0;
	}
	return sumRangeRecurs(root,min, max);
}
////////////////////////////////////////////////////////////////////////
Node* BST::createNode(int data){
	Node* newNode = new Node;
    newNode->key = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
 /////////////////////////////////////////
/*
void destroyNode(Node *currNode){
     if(currNode!=nullptr)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = nullptr;
     }
 }
 */
////////////////////////////////////////////////////////////////////////
Node* BST::addNodeHelper(Node* currNode, int data){
	if(currNode == nullptr){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;
}
////////////////////////////////////////////////////////////////////////
/*
Node* BST::deleteNodeHelper(Node *currNode, int value){
  if(currNode == nullptr)
  {
    return nullptr;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteNode(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteNode(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == nullptr && currNode->right == nullptr)
    {
      delete currNode;
      currNode = nullptr;
    }
    //TODO Case : Only right child
    else if(currNode->left == nullptr)
    {
      Node *temp = currNode;
      currNode = temp->right;
      delete temp;
    }
    //TODO Case : Only left child
    else if(currNode->right == nullptr)
    {
      Node* temp = currNode;
      currNode = currNode->left;
      delete temp;
    }
    //TODO Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      Node* temp = getMinValueNode(currNode->right);
      currNode->key = temp->key;
      currNode->right = deleteNode(currNode->right, temp->key);
    }

  }
return currNode;
}
*/
////////////////////////////////////////////////////////////////////////
/*
Node* BST::searchKeyHelper(Node* currNode, int data){
	if(currNode == nullptr)
        return nullptr;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}
*/
////////////////////////////////////////////////////////////////////////
void BST::printTreeHelper(Node* currNode){
	if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
}
////////////////////////////////////////////////////////////////////////
void BST::addNode(int t){
	addNodeHelper(root, t);
    cout<<t<<" has been added"<<endl;
}
////////////////////////////////////////////////////////////////////////
/*
void BST::deleteNode(int t){
	deleteNodeHelper(root, t);
}
*/
////////////////////////////////////////////////////////////////////////
/*
bool BST::searchKey(int t){
	Node* tree = searchKeyHelper(root, t);
    if(tree != nullptr) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}
*/
////////////////////////////////////////////////////////////////////////
void BST::printTree(){
	printTreeHelper(root);
    cout<<endl;
}
////////////////////////////////////////////////////////////////////////
BST::BST(){

}
////////////////////////////////////////////////////////////////////////
BST::BST(int data){
	root = createNode(data);
    cout << "New tree created with "<< data << endl;
}
////////////////////////////////////////////////////////////////////////
/*
BST::~BST(){
	destroyNode(root);
}
////////////////////////////////////////////////////////////////////////
void BST::print2DUtil(int space, Node*currNode){
	// Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}
////////////////////////////////////////////////////////////////////////
*/