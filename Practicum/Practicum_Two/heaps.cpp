#include "heaps.hpp"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////
bool groupIsGreater(int A, int B){
	if(A > B){
		return true;
	}
	if(A == B){
		if(A > B){
			return true;
		}
		return false;
	}
	return false;
}
////////////////////////////////////////////////////////
int parent(int index){
	return (index-1)/2;
}
////////////////////////////////////////////////////////////////////////
Heap::Heap(int _heapSize){
	heapSize = _heapSize;
	currentSize = 0;
	heap = new int[heapSize];
}
////////////////////////////////////////////////////////////////////////
Heap::~Heap(){
	delete [] heap;
}
////////////////////////////////////////////////////////////////////////
void Heap::printHeap(){
	for(int i = 0; i < currentSize; i++){
		cout << heap[i] << endl;
	}
}
////////////////////////////////////////////////////////////////////////
void Heap::addToHeap (int value){
	if (isFull()) {
		cout << "Heap full, cannot enqueue" << endl;
    }
    else{
     	currentSize++;
      	int i = currentSize - 1;
      	heap[i] = value;
    	if(i != 0 && groupIsGreater(heap[parent(i)] ,heap[i])){
         	swap(heap[i], heap[parent(i)]);
         	repairUpward(parent(i));
      	}
    }
}
////////////////////////////////////////////////////////////////////////
int Heap::removeFromHeap(){
	if(currentSize == 0){
      cout << "Heap empty, cannot dequeue" << endl;
   	}
   	else{
      	if(currentSize == 1){
      		currentSize--;
         	return heap[0];
        }
      	heap[0] = heap[currentSize-1];
      	currentSize--;
      	repairDownward(0);
   }
   return heap[0];
}
////////////////////////////////////////////////////////////////////////
int Heap::peekValue(){
	return heap[0];
}
////////////////////////////////////////////////////////////////////////
bool Heap::isFull(){
	return (currentSize >= heapSize);
}
////////////////////////////////////////////////////////////////////////
bool Heap::isEmpty(){
	return (currentSize <= 0);
}
////////////////////////////////////////////////////////////////////////
void Heap::repairUpward(int nodeIndex){
	while(nodeIndex != 0 && groupIsGreater(heap[parent(nodeIndex)], heap[nodeIndex])){
		swap(heap[nodeIndex], heap[parent(nodeIndex)]);
      	nodeIndex = parent(nodeIndex);
	}
}
////////////////////////////////////////////////////////////////////////
void Heap::repairDownward(int nodeIndex){
	int left = ((2*nodeIndex) + 1);
	int right = ((2*nodeIndex) + 2);
	int smallest  = nodeIndex;
	if(left < currentSize && groupIsGreater(heap[nodeIndex], heap[left])){
      	smallest = left;
   	}
   	if(right < currentSize && groupIsGreater(heap[smallest],heap[right])){
      smallest = right;
  	}

   	if(smallest != nodeIndex){
      	swap(heap[nodeIndex], heap[smallest]);
      	repairDownward(smallest);
   	}
}
////////////////////////////////////////////////////////////////////////