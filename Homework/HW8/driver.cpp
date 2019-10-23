#include "PriorityQueue.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

void printMenu(){
	cout << "============Main Menu============" << endl;
	cout << "1. Get group information from file" << endl;
	cout << "2. Add a group to Priority Queue" << endl;
	cout << "3. Show next group in the queue" << endl;
	cout << "4. Serve Next group" << endl;
	cout << "5. Serve Entire Queue" << endl;
	cout << "6. Quit" << endl;
}

void readFile(string filename, PriorityQueue* myQueue){
	ifstream file;
	file.open(filename);
	string temp[3];
	string templine,tempChar;
	if(file.is_open()){
		while(getline(file,templine)){
			stringstream tempStream(templine);
			int i = 0;
			while(getline(tempStream,tempChar,' ')){
				temp[i] = tempChar;
				i++;
			}
			if(myQueue->isFull()){
				cout << "Heap full, cannot enqueue" << endl;
				return;
			}
			myQueue->enqueue(temp[0], stoi(temp[1]), stoi(temp[2]));
		}
	}
	else{
		cout << "Error opening file" << endl;
	}
}

string getInput(string question){
	string input;
	cout << question << endl;
	getline(cin,input);
	return input;
}

int main(int argc, char*argv[]){
	int maxQueueSize = stoi(argv[1]);
	bool contin = true;
	string temp;
	int input;
	int totalCookTime = 0;
	PriorityQueue* myQueue = new PriorityQueue(maxQueueSize);
	while(contin){
		printMenu();
		getline(cin, temp);
		input = stoi(temp);
		switch(input){
			case 1:
			{
				string fileName = getInput("Enter filename:");
				readFile(fileName, myQueue);
				break;
			}
			case 2:
			{
				string groupName = getInput("Enter Group Name:");
				int groupSize = stoi(getInput("Enter Group Size:"));
				int cookTime = stoi(getInput("Enter Estimated Cooking Time:"));
				if(myQueue->isFull()){
					cout << "Heap full, cannot enqueue" << endl;
				}
				else{
					myQueue->enqueue(groupName, groupSize, cookTime);
				}
				string name = myQueue->peek().groupName;
				break;
			}
			case 3:
			{
				if(myQueue->isEmpty()){
					cout << "Heap empty, nothing to peek" << endl;
				}
				else{
					cout << "Group Name: " << myQueue->peek().groupName << endl;
					cout << "Group Size: " << myQueue->peek().groupSize << endl;
					cout << "Group Time: " << myQueue->peek().cookingTime << endl;
				}
				break;
			}
			case 4:
			{
				totalCookTime += myQueue->peek().cookingTime;
				cout << "Group Name: " << myQueue->peek().groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
				myQueue->dequeue();
				break;
			}
			case 5:
			{
				while(!myQueue->isEmpty()){
					totalCookTime += myQueue->peek().cookingTime;
					cout << "Group Name: " << myQueue->peek().groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
					myQueue->dequeue();
				}
				break;
			}
			case 6:
			{
				cout << "Goodbye!" << endl;
				contin = false;
				break;
			}
		}
	}
	return 0;
}