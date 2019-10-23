// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node *temp = table[index];
    while(temp != NULL && temp->key != key){
        temp = temp->next;
    }
    return temp;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    if(!searchItem(key))
    {
        node * newNode = new node();
        newNode->key = key;
        newNode->next = NULL;
        if(temp == NULL){
            table[index] = newNode;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if(table[i] != NULL){
            node* temp = table[i];
            while(temp != NULL){
                cout << temp->key << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

 }
