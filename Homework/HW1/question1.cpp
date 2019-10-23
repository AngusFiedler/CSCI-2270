#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    int i = numEntries-1;
    while(newValue < myArray[i] && i >= 0){
        myArray[i+1] = myArray[i];
        i--;
    }
    myArray[i+1] = newValue;
    return numEntries+1;
}

int main(int argc, char*argv[]){
    string tempString;
    int myArray[100];
    int numStored = 0;
    
    
    ifstream file;
    file.open(argv[1]);
    if(file.is_open()){
        while(getline(file,tempString)){
            int tempInt = stoi(tempString);
            numStored = insertIntoSortedArray(myArray,numStored,tempInt);
            cout << myArray[0];
            for(int i = 1; i < numStored; i++){
                cout << "," << myArray[i];
            }
            cout << endl;
        }
    }
    else{
        cout << "Failed to open the file." << endl;
    }
}