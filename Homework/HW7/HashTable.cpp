#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//////////////////////////////////////////////////////////
//                  BST                                 //
//////////////////////////////////////////////////////////
/*
struct node{
	string title;
	int key;
	node* left;
	node* right;
};
node *newNode(int key, string title) { 
    struct node *temp =  new node; 
    temp->key = key; 
    temp->title = title;
    temp->left = temp->right = NULL; 
    return temp; 
} 
node* insert(node* tempNode, int key, string title) 
{ 
    if (tempNode == NULL){
    	return newNode(key,title); 
    }
    if (key < tempNode->key){
    	tempNode->left = insert(node->left, key); 
    } 
    else if (key > tempNode->key){
        tempNode->right = insert(node->right, key);    
    }
    return node; 
}
*/
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
HashTable::HashTable(int HashTableSize){
	hashTable = new wordItem*[HashTableSize];
	hashTableSize = HashTableSize;
	numItems = 0;
	numCollisions = 0;
}
//////////////////////////////////////////////////////////
void deleteHash(wordItem* currentWord){
	wordItem* next;
	while(currentWord != NULL){
		next = currentWord->next;
		delete currentWord;
		currentWord = next;
	}
}
HashTable::~HashTable(){
	for (int i = 0; i < hashTableSize; ++i)
	{
		if(hashTable[i] != NULL){
			deleteHash(hashTable[i]);
			hashTable[i] = NULL;
		}
	}
	delete hashTable;
}
//////////////////////////////////////////////////////////
void HashTable::addWord(string word){
	wordItem *toAdd = new wordItem;
	toAdd->word = word;
	toAdd->count = 1;
	toAdd->next = NULL;
	int hash = getHash(word);
	if(hashTable[hash] == NULL){
		hashTable[hash] = toAdd;
		numItems += 1;
		return;
	}
	wordItem *temp = hashTable[hash];
	if(isInTable(word)){
		while(temp->word != word){
			temp = temp->next;
		}
		temp->count += 1;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = toAdd;
		numItems += 1;
	}
	numCollisions+=1;
}
//////////////////////////////////////////////////////////
bool HashTable::isInTable(string word){
	if(searchTable(word) == NULL){
		return false;
	}
	return true;
}
//////////////////////////////////////////////////////////
void HashTable::incrementCount(string word){
	wordItem *temp = searchTable(word);
	temp->count++;
}
//////////////////////////////////////////////////////////
struct word{
	int count;
	string title;
};
void bubbleSort(word arr[], int n){ 
	int i, j; 
   	for (i = 0; i < n-1; i++){
   		for (j = 0; j < n-i-1; j++){
   			if (arr[j].count > arr[j+1].count){
   				word temp = arr[j];
   				arr[j] = arr[j+1];
   				arr[j+1] = temp;
   			} 
   		}
   }
} 
int addToArray(wordItem* temp, word myWordArray[], int size){
	while(temp != NULL){
		word tempWord;
		tempWord.count = temp->count;
		tempWord.title = temp->word;
		myWordArray[size] = tempWord;
		temp = temp->next;
		size++;
	}
	return size;
}
void HashTable::printTopN(int n){
	int arraySize = 0;
	word myWordArray[100000];
	int wordCount = getTotalNumWords();
	for (int i = 0; i < hashTableSize; ++i)
	{
		if(hashTable[i] != NULL){
			arraySize = addToArray(hashTable[i], myWordArray, arraySize);
		}
	}
	bubbleSort(myWordArray, arraySize);
	for (int i = arraySize-1; i >= arraySize-n; --i)
	{
		cout << fixed << setprecision(4) << (float)myWordArray[i].count/wordCount << " - " << myWordArray[i].title << endl;
	}
}
//////////////////////////////////////////////////////////
int HashTable::getNumCollisions(){
	return numCollisions;
}
//////////////////////////////////////////////////////////
int HashTable::getNumItems(){
	return numItems;
}
//////////////////////////////////////////////////////////
int sumLL(wordItem* temp,int &sum){
	sum += temp->count;
	while(temp->next != NULL){
		sum += temp->next->count;
		temp = temp->next;
	}
	return sum;
}
int HashTable::getTotalNumWords(){
	int sum = 0;
	for (int i = 0; i < hashTableSize; ++i)
	{
		if(hashTable[i] != NULL){
			sumLL(hashTable[i],sum);
		}
	}
	return sum;
}
//////////////////////////////////////////////////////////
unsigned int HashTable::getHash(string word){
	unsigned int hashValue = 5381;
	int lenght = word.length();
	for (int i = 0; i < lenght; ++i){
		hashValue = ((hashValue<<5) + hashValue) + word[i];
	}
	hashValue %= hashTableSize;
	return hashValue;
}
//////////////////////////////////////////////////////////
wordItem* searchLL(string word, wordItem* temp){
	while(temp != NULL && temp->word != word){
		temp = temp->next;
	}
	if(temp == NULL){
	    return NULL;
	}
		return temp;
}
wordItem* HashTable::searchTable(string word){
	int index = getHash(word);
	return searchLL(word,hashTable[index]);
}

//////////////////////////////////////////////////////////
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable){
	string temp;
	ifstream file;
	file.open(ignoreWordFileName);
	if(file.is_open()){
		while(getline(file,temp)){
			stopWordsTable.addWord(temp);
		}
	}
}
//////////////////////////////////////////////////////////
bool isStopWord(string word, HashTable &stopWordsTable){
	return stopWordsTable.isInTable(word);
}