#include "MovieTree.hpp"
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;

void printMenu(){
	cout << "======Main Menu======"<< endl;
	cout << "1. Print the inventory" << endl;
	cout << "2. Delete a movie" << endl;
	cout << "3. Quit" << endl;
}

int main(int argc,char* argv[]){
	MovieTree myTree;
	string input,temp;
	string filename = argv[1];
	ifstream file;
	file.open(filename);
	if(file.is_open()){
		while(getline(file,temp)){
			string array[4];
			int i = 0;
			istringstream innerTemp(temp);
			string innerString;
			while(getline(innerTemp, innerString, ',')){
				array[i] = innerString;
				i++;
			}
			myTree.addMovie(stoi(array[0]), array[1], stoi(array[2]), stof(array[3]));
		}
	}
	while(true){
		printMenu();
		getline(cin,input);
		switch(stoi(input)){
			case 1:
			{
				myTree.printMovieInventory();
				break;
			}
			case 2:
			{
				cout << "Enter a movie title:" << endl;
				getline(cin,input);
				myTree.deleteMovie(input);
				break;
			}
			case 3:
			{
				cout << "Goodbye!" << endl;
				return 0;
			}
		}
	}
	return 0;
}