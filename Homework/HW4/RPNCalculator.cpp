#include "RPNCalculator.hpp"
#include <iostream>

using namespace std;

RPNCalculator :: RPNCalculator(){
	stackHead = NULL;
}

RPNCalculator :: ~RPNCalculator(){
	Operand* temp = stackHead;
	while(stackHead != NULL){
		pop();
	}
}

bool RPNCalculator :: isEmpty(){
	if(stackHead == NULL){
		return true;
	}
	return false;
}

void RPNCalculator :: push(float number){
	Operand* push = new Operand;
	push->number = number;
	push->next = stackHead;
	stackHead = push;
}

void RPNCalculator:: pop(){
	if(!isEmpty()){
		Operand* temp = stackHead->next;
		delete stackHead;
		stackHead = temp;
	}
	else{
		cout << "Stack empty, cannot pop an item." << endl;
	}
}

Operand* RPNCalculator :: peek(){
	if(isEmpty()){
		cout << "Stack empty, cannot peek." << endl;
		return NULL;
	}
	else{
		return stackHead;
	}
}

bool RPNCalculator :: compute(string symbol){
	if(symbol == "+" || symbol == "*"){
		if(isEmpty() || stackHead->next == NULL){
			cout << "err: not enough operands" << endl;
			return false;
		}
		float tempA = stackHead->number;
		pop();
		if(symbol == "*"){
			stackHead->number = stackHead->number*tempA;
		}
		else{
			stackHead->number += tempA;
		}
		return true;
	}
	else{
		cout << "err: invalid operation" << endl;
		return false;
	}
}




