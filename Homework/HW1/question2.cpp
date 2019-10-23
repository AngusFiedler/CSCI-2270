#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct User {
    string username;
    float gpa;
    int age;
};

void addUser(User users[], string _username, float _gpa, int _age, int length){
    User newUser;
    newUser.username = _username;
    newUser.gpa = _gpa;
    newUser.age = _age;
    users[length] = newUser;
}

void printList(const User users[], int length){
    for(int i = 0; i < length; i++){
        cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << endl;
    }
}

void saveData(User users[],float minGpa, int arrayLength, string filename){
    ofstream outfile;
    outfile.open(filename);
    for(int i = 0; i < arrayLength; i++){
        if(users[i].gpa > minGpa){
            outfile << users[i].username << ',' << users[i].gpa << ',' << users[i].age << endl;
        }
    }
    outfile.close();
}

int main(int argc, char*argv[]){
    string inFileName = argv[1];
    string oFileName = argv[2];
    float minGPA = stof(argv[3]);
    ifstream infile;
    User usersArray[100];
    int arrayLength = 0;
    string tempString;
    string username;
    float gpa;
    int age;


    infile.open(inFileName);
    if(infile.is_open()){
        while(getline(infile,tempString)){
            istringstream tempStream(tempString);
            string innertemp;
            int i = 0;
            while(getline(tempStream,innertemp,',')){
                if(i == 0){
                    username = innertemp;
                }
                if(i == 1){
                    gpa = stof(innertemp);
                }
                if(i == 2){
                    age = stoi(innertemp);
                }
                i++;
            }
            addUser(usersArray,username,gpa,age,arrayLength);
            arrayLength++;
        }
    }
    else{
        cout << "file could not be opened" << endl;
    }
    saveData(usersArray,minGPA,arrayLength,oFileName);
    printList(usersArray, arrayLength);
}