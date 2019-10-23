/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
	head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
	bool result = false;
	if (head == NULL)
	{
		result = true;
	}
	return result;
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country *previous, string countryName)
{
	Country *newCountry = new Country();
	newCountry->name = countryName;
	if (head == NULL)
	{
		cout << "adding: " << countryName << " (HEAD)" << endl;
		newCountry->next = NULL;
		head = newCountry;
		return;
	}
	else if (previous == NULL)
	{
		cout << "adding: " << countryName << " (HEAD)" << endl;
		newCountry->next = head;
		head = newCountry;
	}
	else
	{
		cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
		newCountry->next = previous->next;
		previous->next = newCountry;
	}
}

/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
	//NEED TO FINISH THIS
	Country *temp = head;
	bool found = false;
	if (head->name == countryName)
	{
		Country *toFollow = head->next;
		delete head;
		head = toFollow;
		return;
	}
	while (temp != NULL && !found)
	{
		if (temp->next == NULL)
		{
			break;
		}
		if (temp->next->name == countryName)
		{
			found = true;
			Country *toDelete = temp->next;
			Country *toFollow = temp->next->next;
			delete toDelete;
			temp->next = toFollow;
		}
		temp = temp->next;
	}
	if (!found)
	{
		cout << "Country does not exist." << endl;
	}
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
	if(head != NULL){
		deleteEntireNetwork();
	}
	int arraylength = 5;
	insertCountry(NULL, "United States");
	string names[5] = {"Canada", "Brazil", "India", "China", "Australia"};
	for (int i = 0; i < arraylength; ++i)
	{
		Country *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		insertCountry(temp, names[i]);
	}
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country *CountryNetwork::searchNetwork(string countryName)
{
	Country *temp = head;
	bool found = false;
	while (!found && temp != NULL)
	{
		if (temp->name == countryName)
		{
			found = true;
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
	Country *current = head;
	while (current != NULL)
	{
		Country *next = current->next;
		cout << "deleting: " << current->name << endl;
		delete current;
		current = next;
	}
	head = NULL;
	cout << "Deleted network" << endl;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
	if (head == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	Country *temp = head;
	temp->message = message;
	temp->numberMessages += 1;
	cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
	while (temp->name != receiver)
	{
		temp = temp->next;
		temp->message = message;
		temp->numberMessages += 1;

		cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
	}
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
	cout << "== CURRENT PATH ==" <<  endl;
	if(head == NULL){
		cout << "nothing in path" << endl;
		cout << "==="  << endl;
		return;
	}
	Country *temp = head;
	while(temp != NULL){
		cout << temp->name << " -> ";
		temp = temp->next;
	}
	cout << "NULL";
	cout << endl << "===" << endl << endl;

}

/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
	Country *current = head;
	Country *prev = NULL, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}