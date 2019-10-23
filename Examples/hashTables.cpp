#include <iostream>
using namespace std;

struct Student{
	string name;
	int sid;
};

int hashSum(string key, int keylength, int tableSize){
	int sum = 0;
	for (int i = 0; i < keylength; ++i)
	{
		sum += key[i];
	}
	return (sum % tableSize);
}



int main(){
	//create hashTable
	int hashSize = 4;
	Student hashTable[hashSize];

	//Store records

	//create record
	Student sIn;
	sIn.name = "anna";
	sIn.sid = 823;
	int index = hashSum(sIn.name, 4, hashSize);

	cout << "index for " << sIn.name << " = " << index << endl;
	hashTable[index] = sIn;

	//retrive record from table
	Student sOut = hashTable[hashSum("anna",4,hashSize)];

	return 0;
}