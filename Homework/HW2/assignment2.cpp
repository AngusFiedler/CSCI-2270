#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct wordItem {
	string word;
	int count;
};

void swap(wordItem *xp, wordItem *yp) { 
    wordItem temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void resize(wordItem **arrayPtr, int *capacity)
{
	//TODO increase the capacity by two times
	int newCapacity = (*capacity)*2;

	//TODO dynamically allocate an array of size newCapacity
	wordItem *newArray = new wordItem[newCapacity];

	//TODO copy all data from oldArray to newArray
	for (int i = 0; i < *capacity; i++)
	{
		newArray[i] = (*arrayPtr)[i];
	}
	//TODO free the memory associated with oldArray
	delete[] *arrayPtr;

	*arrayPtr = newArray;
	*capacity = newCapacity;

}

void addWord(wordItem **wordArray, string word, int &numItems,int &arraySize,int &timesDoubled){
	bool wordFound = false;
	for (int i = 0; i < numItems; ++i)
	{
		if((*wordArray)[i].word == word){
			wordFound = true;
			(*wordArray)[i].count += 1;
		}
	}
	if(!wordFound){
		(*wordArray)[numItems].word = word;
		(*wordArray)[numItems].count = 1;
		numItems++;
		if(numItems >= arraySize){
			resize(wordArray,&arraySize);
			timesDoubled++;
		}
	}
}

bool isStopWord(string word, string ignoreWords[]){
	bool wordFound = false;
	int arraySize = 50;
	for (int i = 0; i < arraySize; ++i){
		if(word == ignoreWords[i]){
			wordFound = true;
		}
	}
	return wordFound;
}

void readFile(string inFileName, int &arraySize, int &numItems,string ignoreWords[], wordItem **wordArray,int &timesDoubled){
	string tempWord;
	ifstream file;
	file.open(inFileName);
	if(file.is_open()){
		while(getline(file,tempWord,' ')){
			if(!isStopWord(tempWord,ignoreWords)){
				addWord(wordArray, tempWord,numItems,arraySize,timesDoubled);
			}
		}
	}
	else{
		cout << "File could not be opened" << endl;
	}
}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
	string tempstring;
	ifstream file;
	file.open(ignoreWordFileName);
	if(file.is_open()){
		int count = 0;
		while(getline(file,tempstring) && count < 50){
			ignoreWords[count] = tempstring;
			count++;
		}
	}
	else{
		cout << "Failed to open " << ignoreWordFileName << endl;
	}
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
	int totalWords = 0;
	for (int i = 0; i < length; ++i)
	{
		int temp = uniqueWords[i].count;
		totalWords += temp;
	}
	return totalWords;
}

void arraySort(wordItem uniqueWords[], int length){
	bool swapped; 
   	for (int i = 0; i < length-1; i++){ 
   		swapped = false; 
   		for (int j = 0; j < length-i-1; j++){ 
   			if (uniqueWords[j].count < uniqueWords[j+1].count){
   				swap(&uniqueWords[j], &uniqueWords[j+1]);
   				swapped = true; 
        	} 
     	}
     	if (swapped == false){
     		break;
     	}
   } 
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords){
	for (int i = 0; i < topN; ++i)
	{
		float probability = (float) uniqueWords[i].count / totalNumWords;
		cout << fixed;
		cout << setprecision(4);
		cout << probability << " - " << uniqueWords[i].word << endl;
	}
}

void print(int timesDoubled, int uniqueWords, int totalWords,int topN){
	cout << "Array doubled: " << timesDoubled << endl << "#" << endl;
	cout << "Unique non-common words: " << uniqueWords << endl << "#" << endl;
	cout << "Total non-common words: " << totalWords << endl << "#" << endl;
	cout << "Probabilities of top " << topN << " most frequent words" << endl;
	cout << "---------------------------------------" << endl;
}

int main(int argc, char*argv[]){
	if(argc <= 3){
		cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
		return 0;
	}
	else{
		int numFreq = stoi(argv[1]);
    	string inFileName = argv[2];
    	string ignoreFileName = argv[3];

    	string ignoreWords[50];
    	getStopWords(argv[3], ignoreWords);		//reads words to ignore and places in array
    	int arraySize = 100;
    	wordItem *uniqueWords = new wordItem[arraySize];
   		int numItems = 0;
   		int timesDoubled = 0;

    	readFile(inFileName,arraySize,numItems,ignoreWords,&uniqueWords,timesDoubled);
    	arraySort(uniqueWords,numItems);
    	int totalWords = getTotalNumberNonStopWords(uniqueWords,numItems);
    	print(timesDoubled,numItems,totalWords,numFreq);
    	printTopN(uniqueWords,numFreq,totalWords);
    	return 0;
	}
}