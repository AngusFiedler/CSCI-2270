/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer myConsumer = ProducerConsumer();
	string input;
	int numItems;
	while(true){
		menu();
		getline(cin,input);
		if(input == "1"){
			cout << "Enter the number of items to be produced:" << endl;
			getline(cin,input);
			numItems = stoi(input);
			for (int i = 1; i < numItems+1; ++i)
			{
				cout << "Item" << i << ":" << endl;
				getline(cin,input);
				myConsumer.enqueue(input);
			}

		}
		else if(input == "2"){
			int itemsToRemove;
			cout << "Enter the number of items to be consumed:" << endl;
			getline(cin,input);
			itemsToRemove = stoi(input);
			for (int i = 1; i < (numItems+1) && itemsToRemove > 0; ++i)
			{
				cout << "Consumed: " << myConsumer.peek() << endl;
				myConsumer.dequeue();
				itemsToRemove--;
			}
			if(itemsToRemove != 0){
				cout << "No more items to consume from queue" << endl;
			}
		}
		else if(input == "3"){
			cout << "Number of items in the queue:" << myConsumer.queueSize()<< endl;
			break;
		}
		else{
			cout << "Invalid input" << endl;
		}
	}
}
