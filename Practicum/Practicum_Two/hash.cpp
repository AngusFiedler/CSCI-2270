#include "hash.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////
node* HashTable::createNode(int key,node* next){
	node* nw = new node;
    nw->data = key;
    nw->next = next;
    return nw;
}
////////////////////////////////////////////////////////////////////////
HashTable::HashTable(int bsize){
	this->tableSize= bsize;
    hashTable = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        hashTable[i] = nullptr;
}
////////////////////////////////////////////////////////////////////////
bool HashTable::insertItem(int key){
	int index = hashFunction(key);
    node* temp = hashTable[index];
    if(!searchItem(key))
    {
        node * newNode = new node();
        newNode->data = key;
        newNode->next = NULL;
        if(temp == NULL){
            hashTable[index] = newNode;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return newNode;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return NULL;
    }
}
////////////////////////////////////////////////////////////////////////
unsigned int HashTable::hashFunction(int key){
	if(key < 0){
		key = key*(-1);
	}
	return (key % tableSize);
}
////////////////////////////////////////////////////////////////////////
void HashTable::printTable(){
	for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if(hashTable[i] != NULL){
            node* temp = hashTable[i];
            while(temp != NULL){
                cout << temp->key << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////////////
node* HashTable::searchItem(int key){
    int index = hashFunction(key);

    node *temp = hashTable[index];
    while(temp != NULL && temp->data != key){
        temp = temp->next;
    }
    return temp;
}
////////////////////////////////////////////////////////////////////////