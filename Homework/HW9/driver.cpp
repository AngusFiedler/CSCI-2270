#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void printInfo(string text){
	cout << "------------------------------" << endl;
	cout << text << endl;
	cout << "------------------------------" << endl;
}
void printGraphs(Graph *g){
	printInfo("Breadth First Traversal");
	g->printBFT();
	printInfo("Depth First Traversal");
	g->printDFT();
	printInfo("Display Edges");
	g->displayEdges();
}

int main(int argc, char*argv[]){
	string filename = argv[1];
	Graph g;
	vector<string> cityNames;

	ifstream file;
	string line,inner, tempName;
	file.open(filename);
	int count, innercount;
	if(file.is_open()){
		count = 0;
		while(getline(file,line)){
			innercount = 0;
			stringstream tempstream(line);
			while(getline(tempstream,inner,',')){
				if(count == 0){
					if(innercount != 0){
						g.addVertex(inner);
						cityNames.push_back(inner);
					}
				}
				else{
					if(innercount == 0){
						tempName = inner;
					}
					else{
						if(stoi(inner) > 0){
							cout << " ... Reading in " << tempName << " -- " << cityNames[innercount-1] << " -- " << inner << endl;
							g.addEdge(tempName, cityNames[innercount-1], stoi(inner));
						}
					}
				}
				innercount++;
			}
			count++;
		}
	}

	printGraphs(&g);
}