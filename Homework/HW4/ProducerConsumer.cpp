#include <iostream>
#include "ProducerConsumer.hpp"
using namespace std;

ProducerConsumer :: ProducerConsumer(){
	queueFront = -1;
	queueEnd = -1;
}

bool ProducerConsumer :: isEmpty(){
	if(queueFront == -1){
		return true;
	}
	return false;
	/*if(queueFront == -1 && queueEnd == -1){
		return true;
	}
	return false;*/
}

bool ProducerConsumer :: isFull(){
	if(queueSize() >= 20){
		return true;
	}
	return false;
}

void ProducerConsumer :: enqueue(string player){
	if(isFull()){
		cout << "Queue full, cannot add new item" << endl;
		return;
	}
	if(queueEnd+1 == SIZE){
		queueEnd = 0;
		queue[queueEnd] = player;
	}
	else{
		queueEnd++;
		queue[queueEnd] = player;
	}
	if(queueFront == -1){
		queueFront++;
	}
}

void ProducerConsumer :: dequeue(){
	if(isEmpty()){
		cout << "Queue empty, cannot dequeue an item" << endl;
	}
	else{
		if(queueFront == queueEnd){
			queueFront = -1;
			queueEnd = -1;
		}
		else if(queueFront+1 == SIZE){
			queueFront=0;
		}
		else{
			queueFront++;
		}
	}
}

int ProducerConsumer :: queueSize(){
	int total = queueFront > queueEnd ? (SIZE - queueFront + queueEnd + 1) : (queueEnd - queueFront + 1);
	//int total = abs(abs(SIZE - queueFront) - abs(SIZE - queueEnd))+1;
	if(isEmpty()){
		total = 0;
	}
	return total;
}

string ProducerConsumer :: peek(){
	string output = "";
	if(isEmpty()){
		cout << "Queue empty, cannot peek" << endl;
		return output;
	}
	output = queue[queueFront];
	return output;
}