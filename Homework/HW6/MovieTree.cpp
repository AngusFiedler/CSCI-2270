#include "MovieTree.hpp"
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
MovieTree::MovieTree(){
	root = NULL;
}
/////////////////////////////////////////////////////////////////////
void deleteLinkedList(LLMovieNode* currentNode){
	LLMovieNode* next;
	while(currentNode != NULL){
		next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}
}
void deleteTree(TreeNode *node){
	if (node == NULL) return;
	deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    deleteLinkedList(node->head);
    delete node;
}
MovieTree :: ~MovieTree(){
	deleteTree(root);
	root = NULL;
}
/////////////////////////////////////////////////////////////////////
void printFromLL(LLMovieNode* currentNode){
	while(currentNode != NULL){
		cout << " >> " << currentNode->title << " " << currentNode->rating << endl;
		currentNode = currentNode->next;
	}
}
void printBSTRecursive(TreeNode* currentNode){
	if(currentNode == NULL){
		return;
	}
	printBSTRecursive(currentNode->leftChild);
	cout << "Movies starting with letter: " << currentNode->titleChar << endl;
	printFromLL(currentNode->head);
	printBSTRecursive(currentNode->rightChild);
}
void MovieTree::printMovieInventory(){
	printBSTRecursive(root);
}
/////////////////////////////////////////////////////////////////////
void addToLinkedList(LLMovieNode* currentNode, LLMovieNode* addNode){
	string newNodeTitle = addNode->title;
	string currentTitle;
	bool contin = true;
	while(currentNode->next != NULL && contin){
		currentTitle = currentNode->next->title;
		for (int i = 0; i < currentTitle.length() && newNodeTitle.length(); ++i){
			if(tolower(currentTitle[i]) > tolower(newNodeTitle[i])){
				contin = false;
				break;
			}
		}
		if(contin){
			currentNode = currentNode->next;
		}
	}
	addNode->next = currentNode->next;
	currentNode->next = addNode;
}
void addToBST(TreeNode* currentNode, LLMovieNode* addNode){
	if(addNode->title[0] < currentNode->titleChar){
		if(currentNode->leftChild == NULL){
			TreeNode* newTree = new TreeNode;
			newTree->head = addNode;
			currentNode->leftChild = newTree;
			newTree->parent = currentNode;
			newTree->titleChar = addNode->title[0];
			//if there is no node to the leftChild
		}
		else{
			addToBST(currentNode->leftChild, addNode);
		}
	}
	else if(addNode->title[0] > currentNode->titleChar){
		if(currentNode->rightChild == NULL){
			//if there is no Node to the rightChild
			TreeNode* newTree = new TreeNode;
			newTree->head = addNode;
			currentNode->rightChild = newTree;
			newTree->parent = currentNode;
			newTree->titleChar = addNode->title[0];
		}
		else{
			addToBST(currentNode->rightChild,addNode);
		}
	}
	else{
		bool contin = true;
		for (int i = 0; i < currentNode->head->title.length() && addNode->title.length(); ++i){
			if(tolower(currentNode->head->title[i]) > tolower(addNode->title[i])){
				addNode->next = currentNode->head;
				currentNode->head = addNode;
				contin = false;
			}
			if(tolower(currentNode->head->title[i]) < tolower(addNode->title[i])){
				break;
			}
		}
		if(contin){
			addToLinkedList(currentNode->head, addNode);
		}
	}
}
void MovieTree::addMovie(int ranking,string title, int year, float rating){
	LLMovieNode* newNode = new LLMovieNode(ranking,title,year,rating);
	if(root == NULL){
		TreeNode* newTree = new TreeNode;
		newTree->titleChar = newNode->title[0];
		newTree->head = newNode;
		root = newTree;
	}
	else{
		addToBST(root,newNode);
	}
}
/////////////////////////////////////////////////////////////////////
TreeNode* recursiveSearchTree(char titleChar, TreeNode *temp){
	if(temp == NULL || temp->titleChar == titleChar){
		return temp;
	}
	if(temp->titleChar < titleChar){
		return recursiveSearchTree(titleChar,temp->rightChild);
	}
	return recursiveSearchTree(titleChar, temp->leftChild);
}

bool doesMovieExist(LLMovieNode* currentNode, string title){
	while(currentNode != NULL){
		if(currentNode->title == title){
			return true;
		}
		currentNode = currentNode->next;
	}
		return false;
}

bool deletefromLL(LLMovieNode *currentNode, string title){
	LLMovieNode *temp = currentNode;
	bool found = false;
	if(currentNode->title == title && currentNode->next == NULL){
		delete currentNode;
		return true;
	}
	while (temp != NULL && !found){
		if (temp->next == NULL){
			break;
		}
		if (temp->next->title == title){
			found = true;
			LLMovieNode *toDelete = temp->next;
			LLMovieNode *toFollow = temp->next->next;
			delete toDelete;
			temp->next = toFollow;
		}
		temp = temp->next;
	}
	return false;
}
TreeNode* getMinValueNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

TreeNode* deleteNode(TreeNode *currNode, char titleChar){
	if(currNode == NULL){
		return NULL;
	}

	else if(titleChar < currNode->titleChar){
    	currNode->leftChild = deleteNode(currNode->leftChild, titleChar);
  	}

  	else if(titleChar > currNode->titleChar){
    	currNode->rightChild = deleteNode(currNode->rightChild, titleChar);
  	}

  	else{
    	//No child
    	if(currNode->leftChild == NULL && currNode->rightChild == NULL){
      		delete currNode;
      		currNode = NULL;
      	}
    	//Only right child
      	else if(currNode->leftChild == NULL){
      		TreeNode* temp = currNode;
      		currNode = temp->rightChild;
      		delete temp;
      	}
    	//Only left child
    	else if(currNode->rightChild == NULL){
      		TreeNode* temp = currNode;
      		currNode = currNode->leftChild;
      		delete temp;
    	}
    	//Both left and right child
    	else{
      		///Replace with Minimum from right subtree
      		TreeNode* temp = getMinValueNode(currNode->rightChild);
      		currNode->head = temp->head;
      		currNode->titleChar = temp->titleChar;
      		currNode->rightChild = deleteNode(currNode->rightChild, temp->titleChar);
   		}
  	}
	return currNode;
}
void MovieTree::deleteMovie(string title){
	TreeNode* myTreeNode = recursiveSearchTree(title[0], root);
	if(myTreeNode == NULL){
		cout << "Movie: " << title << " not found, cannot delete." << endl;
		return;
	}
	LLMovieNode* myLLNode = myTreeNode->head;
	if(!doesMovieExist(myLLNode,title)){
		cout << "Movie: " << title << " not found, cannot delete." << endl;
		return;
	}
	if(myLLNode->title == title && myLLNode->next != NULL){
		LLMovieNode *next = myLLNode->next;
		delete myLLNode;
		myLLNode = next;
		myTreeNode->head = myLLNode;
	}
	if(deletefromLL(myLLNode, title)){
		root = deleteNode(root, title[0]);
	}
}
/////////////////////////////////////////////////////////////////////