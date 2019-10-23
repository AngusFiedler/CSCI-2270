#include "MovieTree.hpp"
#include <iostream>
using namespace std;

MovieTree :: MovieTree(){
	root = NULL;
}
/////////////////////////////////////////////////////////////////////
void deleteTree(MovieNode *node){
	if (node == NULL) return;
	deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
}
MovieTree :: ~MovieTree(){
	deleteTree(root);
	root = NULL;
}
/////////////////////////////////////////////////////////////////////
MovieNode* recursiveSearch(string title, MovieNode *temp){
	if(temp == NULL || temp->title == title){
		return temp;
	}
	if(temp->title < title){
		return recursiveSearch(title,temp->rightChild);
	}
	return recursiveSearch(title, temp->leftChild);
}
MovieNode* MovieTree :: search(string title){
	return recursiveSearch(title, root);
}
/////////////////////////////////////////////////////////////////////
void printOrderRecursive(MovieNode* currentMovie){
	if(currentMovie == NULL){
		return;
	}
	printOrderRecursive(currentMovie->leftChild);
	cout << "Movie: " << currentMovie->title << " " << currentMovie->rating << endl;
	printOrderRecursive(currentMovie->rightChild);
}

void MovieTree :: printMovieInventory(){
	printOrderRecursive(root);
}
/////////////////////////////////////////////////////////////////////
void addNodeRecursive(MovieNode *addNode, MovieNode *temp){
	if(addNode->title < temp->title){
		if(temp->leftChild == NULL){
			temp->leftChild = addNode;
			addNode->parent = temp;
		}
		else{
			addNodeRecursive(addNode, temp->leftChild);
		}
	}
	else{
		if(temp->rightChild == NULL){
			temp->rightChild = addNode;
			addNode->parent = temp;
		}
		else{
			addNodeRecursive(addNode, temp->rightChild);
		}

	}
}
void MovieTree :: addMovieNode(int ranking, string title, int year, float rating){
	MovieNode *newNode = new MovieNode;
	newNode->ranking = ranking;
	newNode->title = title;
	newNode->year = year;
	newNode->rating = rating;
	if(root == NULL){
		root = newNode;
	}
	else{
		addNodeRecursive(newNode,root);
	}
}
/////////////////////////////////////////////////////////////////////
void printMovieInfo(MovieNode *movie){
	cout << "Movie Info:" << endl;
	cout << "==================" << endl;
	cout << "Ranking:" << movie->ranking << endl;
	cout << "Title  :" << movie->title << endl;
	cout << "Year   :" << movie->year << endl;
	cout << "rating :" << movie->rating << endl;
}
void MovieTree :: findMovie(string title){
	MovieNode *temp = search(title);
	if(temp != NULL){
		printMovieInfo(temp);
	}
	else{
		cout << "Movie not found." << endl;
	}
}
/////////////////////////////////////////////////////////////////////
void printMoviesGivenRating(float rating, int year, MovieNode *temp){
	if(temp == NULL){
		return;
	}
	if(temp->year > year && temp->rating >= rating){
		cout << temp->title << "(" << temp->year << ") " << temp->rating << endl;
	}
	printMoviesGivenRating(rating, year, temp->leftChild);
	printMoviesGivenRating(rating, year, temp->rightChild);
}
void MovieTree :: queryMovies(float rating, int year){
	cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
	printMoviesGivenRating(rating, year, root);
}
/////////////////////////////////////////////////////////////////////
int numNodes(MovieNode *temp){
	if(temp == NULL){
		return 0;
	}
	return (numNodes(temp->leftChild) + numNodes(temp->rightChild) + 1);
}
double recurAdd(MovieNode *temp){
	if(temp == NULL){
		return 0;
	}
	return(temp->rating + recurAdd(temp->leftChild) + recurAdd(temp->rightChild));
}
void MovieTree :: averageRating(){
	double sum = recurAdd(root);
	int num = numNodes(root);
	double avg = (double)sum/num;
	if(root == NULL){
		avg = 0;
	}
	cout << "Average rating:" << avg << endl;
}