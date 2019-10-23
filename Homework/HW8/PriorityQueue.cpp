#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////
bool groupIsGreater(GroupNode A, GroupNode B){
	if(A.groupSize > B.groupSize){
		return true;
	}
	if(A.groupSize == B.groupSize){
		if(A.cookingTime > B.cookingTime){
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
////////////////////////////////////////////////////////
void swap(GroupNode &x, GroupNode &y){
    GroupNode temp = x;
    x = y;
    y = temp;
}
////////////////////////////////////////////////////////
PriorityQueue::PriorityQueue(int queueSize){
	maxQueueSize = queueSize;
	currentQueueSize = 0;
	priorityQueue = new GroupNode[maxQueueSize];
}
////////////////////////////////////////////////////////
PriorityQueue::~PriorityQueue(){
	delete [] priorityQueue;
}
////////////////////////////////////////////////////////
void PriorityQueue::enqueue(std::string _groupName, int _groupSize, int _cookingTime){
	if (isFull()) {
		cout << "Heap full, cannot enqueue" << endl;
    }
    else{
     	currentQueueSize++;
      	int i = currentQueueSize - 1;
      	priorityQueue[i].groupName = _groupName;
		priorityQueue[i].groupSize = _groupSize;
		priorityQueue[i].cookingTime = _cookingTime;
    	if(i != 0 && groupIsGreater(priorityQueue[parent(i)] ,priorityQueue[i])){
         	swap(priorityQueue[i], priorityQueue[parent(i)]);
         	repairUpward(parent(i));
      	}
    }
}
////////////////////////////////////////////////////////
void PriorityQueue::dequeue(){
	if(currentQueueSize == 0){
      cout << "Heap empty, cannot dequeue" << endl;
   	}
   	else{
      	if(currentQueueSize == 1){
      		currentQueueSize--;
         	return;
        }
      	priorityQueue[0] = priorityQueue[currentQueueSize-1];
      	currentQueueSize--;
      	repairDownward(0);
   }
}
////////////////////////////////////////////////////////
GroupNode PriorityQueue::peek(){
	return priorityQueue[0];
}
////////////////////////////////////////////////////////
bool PriorityQueue::isFull(){
	return (currentQueueSize >= maxQueueSize);
}
////////////////////////////////////////////////////////
bool PriorityQueue::isEmpty(){
	return (currentQueueSize <= 0);
}
////////////////////////////////////////////////////////
void PriorityQueue::repairUpward(int nodeIndex){
	while(nodeIndex != 0 && groupIsGreater(priorityQueue[parent(nodeIndex)], priorityQueue[nodeIndex])){
		swap(priorityQueue[nodeIndex], priorityQueue[parent(nodeIndex)]);
      	nodeIndex = parent(nodeIndex);
	}
}
////////////////////////////////////////////////////////
void PriorityQueue::repairDownward(int nodeIndex){
	int left = ((2*nodeIndex) + 1);
	int right = ((2*nodeIndex) + 2);
	int smallest  = nodeIndex;
	if(left < currentQueueSize && groupIsGreater(priorityQueue[nodeIndex], priorityQueue[left])){
      	smallest = left;
   	}
   	if(right < currentQueueSize && groupIsGreater(priorityQueue[smallest],priorityQueue[right])){
      smallest = right;
  	}

   	if(smallest != nodeIndex){
      	swap(priorityQueue[nodeIndex], priorityQueue[smallest]);
      	repairDownward(smallest);
   	}
}
////////////////////////////////////////////////////////