#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void readFile(HashTable &myTable, HashTable &stopWords,string fileName){
	string line,word;
	ifstream file;
	file.open(fileName);
	if(file.is_open()){
		while(getline(file,line)){
			stringstream tempstream(line);
			while(getline(tempstream,word,' ')){
				if(word != ""){
					if(!isStopWord(word,stopWords)){
						if(myTable.isInTable(word)){
							myTable.incrementCount(word);
						}
						else{
							myTable.addWord(word);
						}
					}
				}
			}
		}
	}
	else{
		cout << "File could not be opened" << endl;
	}
}
void print(HashTable& table, int num){
	table.printTopN(num);
    cout << "#" << endl;
  	cout << "Number of collisions: " << table.getNumCollisions() << endl;
  	cout << "#"<<endl;
  	cout << "Unique non-stop words: " << table.getNumItems() << endl;
  	cout << "#" << endl;
  	cout << "Total non-stop words: " << table.getTotalNumWords() << endl;
}
int main(int argc, char*argv[]){
	string fileName = argv[2];
	HashTable stopWords(STOPWORD_TABLE_SIZE);
	HashTable myTable(stoi(argv[4]));

	getStopWords(argv[3] ,stopWords);
	readFile(myTable,stopWords, fileName);

	print(myTable, stoi(argv[1]));
}