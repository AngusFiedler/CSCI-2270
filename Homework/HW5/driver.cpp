#include "MovieTree.hpp"
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;

void printMenu(){
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Query movies" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Average Rating of movies" << endl;
	cout << "5. Quit" << endl;
}


int main(int argc,char* argv[]){
	MovieTree myTree = MovieTree();
	string temp;
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
			myTree.addMovieNode(stoi(array[0]), array[1], stoi(array[2]), stof(array[3]));
		}
	}
	bool contin = true;
	while(contin){
		string input;
		printMenu();
		getline(cin,input);
		switch(stoi(input)){
			case 1: 
			{
				cout << "Enter title:" << endl;
				getline(cin,input);
				myTree.findMovie(input);
				break;
			}
			case 2:
			{
				string minRating,year;
				cout << "Enter minimum rating:" << endl;
				getline(cin,minRating);
				cout << "Enter minimum year:" << endl;
				getline(cin,year);
				myTree.queryMovies(stof(minRating), stoi(year));
				break;
			}
			case 3:
			{
				myTree.printMovieInventory();
				break;
			}
			case 4:
			{
				myTree.averageRating();
				break;
			}
			case 5:
			{
				cout << "Goodbye!" << endl;
				contin = false;
				break;

			}
		}
	}
}