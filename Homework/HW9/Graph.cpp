#include "Graph.hpp"
#include <queue>
using namespace std;

Graph::Graph(){
}
Graph::~Graph(){
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::addVertex(std::string cityName){
	vertex newVertex;
	newVertex.name = cityName;
	vertices.push_back(newVertex);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::addEdge(std::string city1, std::string city2, int distance){
	Edge e0;
	e0.distance = distance;

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].name == city1){
			for(int j = 0; j < vertices.size(); j++){
				if(vertices[j].name == city2 && j!=i){
					e0.v = &vertices[j];
					vertices[i].Edges.push_back(e0);
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::displayEdges(){
	for(vertex v : vertices){
		cout << v.name << "-->";
		int count = 0;
		for(Edge e : v.Edges){
			if(count != 0){
				cout << "***";
			}
			cout << e.v->name << " (" << e.distance << " miles)";
			count++;
		}
		cout << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::printDFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited){
			DFT_traversal(&vertices[i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::printBFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited)
			BFT_traversal(&vertices[i]);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::setAllVerticesUnvisited(){
	for(int i = 0; i < vertices.size(); i++){
		vertices[i].visited = false;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vertex* Graph::findVertex(string name){
	for(vertex v : vertices){
		if(v.name == name){
			vertex *vertexFound = &v;
			return vertexFound;
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::BFT_traversal(vertex *v){
	cout << v->name << endl;
	v->visited = true;

	queue<vertex*> q;
	q.push(v);

	vertex *n;

	while(!q.empty()){
		n = q.front();
		q.pop();

		for(Edge e : n->Edges){
			if(!e.v->visited){
				e.v->visited = true;
				cout << e.v->name << endl;
				q.push(e.v);
			}
        }
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dftRecursive(vertex *v){
	v->visited = true;
	for(Edge e : v->Edges){
		if(!e.v->visited){
			cout << e.v->name << endl;
			dftRecursive(e.v);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::DFT_traversal(vertex *v){
	cout << v->name << endl;
	dftRecursive(v);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
