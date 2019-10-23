#include <ostream>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char str[10];
    ifstream iFile("filename.txt");
    //reads one string from the file
    iFile >> str;
    //outputs the file contents
    cout << str << "/n";
    //waits for a keypress
    cin .get();
    //iFile is closed
}