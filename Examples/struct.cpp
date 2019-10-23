#include <iostream> 
using namespace std;

struct AnimalPatient{
    string name;
    string species;
    int age;
    double weight;
    bool sex;
};

int main(){
    AnimalPatient p0;
    p0.name = "Steve";
    p0.species = "cat";
    p0.age = 4;
    
    AnimalPatient animalArr[3]; //create an arrray of AnimalPatient
    animalArr[0].name = "Steve";
    animalArr[1].name = "Bean";
    return 0;
}