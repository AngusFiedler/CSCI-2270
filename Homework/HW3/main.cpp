/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    CountryNetwork myNetwork = CountryNetwork();
    while(true){
        displayMenu();
        string input;
        getline(cin,input);
        int intInput = stoi(input);
        switch(intInput){
            case 1:{
                myNetwork.loadDefaultSetup();
                myNetwork.printPath();
                break;
            }
            case 2:{
                myNetwork.printPath();
                break;
            }
            case 3:{
                string message;
                string reciever;
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin,reciever);
                cout << "Enter the message to send:" << endl;
                getline(cin,message);
                myNetwork.transmitMsg(reciever,message);
                break; 
            }
            case 4:{
                string newCountry,previous;
                Country *countryCheck;
                cout << "Enter a new country name:" << endl;
                getline(cin,newCountry);
                cout << "Enter the previous country name (or First):" << endl;
                getline(cin,previous);
                countryCheck = myNetwork.searchNetwork(previous);
                while(countryCheck == NULL){
                    if(previous == "First"){
                        countryCheck = NULL;
                        break;
                    }
                    cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                    getline(cin,previous);
                    countryCheck = myNetwork.searchNetwork(previous);
                }
                cout << endl;
                myNetwork.insertCountry(countryCheck,newCountry);
                myNetwork.printPath();
                break;
            }
            case 5:{
                string input;
                cout << "Enter a country name:" << endl;
                getline(cin,input);
                myNetwork.deleteCountry(input);
                myNetwork.printPath();
                break;
            }
            case 6:{
                myNetwork.reverseEntireNetwork();
                myNetwork.printPath();
                break;
            }
            case 7:{
                myNetwork.deleteEntireNetwork();
                break;
            }
            case 8:{
                cout << "Quitting... cleaning up path: " << endl;
                myNetwork.printPath();
                if(!myNetwork.isEmpty()){
                    myNetwork.deleteEntireNetwork();
                }
                if(myNetwork.isEmpty()){
                    cout << "Path cleaned" << endl;
                }
                else{
                    cout << "Error: Path NOT cleaned" << endl;
                }
                cout << "Goodbye!" << endl;
                return 0;
            }
            cout << endl;
        }
    }
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    //cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}