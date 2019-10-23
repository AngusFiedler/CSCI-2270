#include <iostream>
using namespace std;

const int MAXSIZE = 5;

class QueArrCir{
	private:
		int head,tail,queSize;
		string a[MAXSIZE];
	public:
		QueArrCir();

		bool isEmpty();
		bool isFull();

		void enque(string newItem);
		string deque();
};

QueArrCir::QueArrCir(){
	head = 0;
	tail = 0;
	queSize = 0;
}

bool QueArrCir::isEmpty(){
	if(queSize == 0){
		return true;
	}
	return false;
}

bool QueArrCir::isFull(){
	if(queSize == MAXSIZE){
		return true;
	}
	return false;
}

void QueArrCir::enque(string newItem){
	if(!isFull()){
		a[tail] = newItem;
		queSize++;
		if(tail == MAXSIZE-1){
			tail = 0;
		}
		else{
			tail++;
		}
	}
	else{
		cout << "queue is full" << endl;
	}
}

string QueArrCir::deque(){
	string output;
	if(!isEmpty()){
		output = a[head];
		queSize--;
		if(head == MAXSIZE-1){
			head = 0;
		}
		else{
			head++;
		}
	}
	else{
		cout << "queue is empty, returning empty string" << endl;
		output = "";
	}

	return output;
}