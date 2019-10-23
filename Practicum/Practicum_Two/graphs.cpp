#include "graphs.hpp"
#include <queue>
using namespace std;


Graph::Graph(){
}
////////////////////////////////////////////////////////////////////////
Graph::~Graph(){
}
////////////////////////////////////////////////////////////////////////
void Graph::addEdge(int v1, int v2){
	vertex *newEdge = new vertex;
	newEdge->id = v2;

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].id == v1){
			vertices[i].Edges.push_back(newEdge);
		}
	}
}
////////////////////////////////////////////////////////////////////////
void Graph::addVertex(int id){
	vertex newVertex;
	newVertex.id = id;
	vertices.push_back(newVertex);
}
////////////////////////////////////////////////////////////////////////
void Graph::displayEdges(){
	for(vertex v : vertices){
		cout << v.id << "-->";
		int count = 0;
		for(int i = 0; i < v.Edges.size(); i++){
			if(count != 0){
				cout << "***";
			}
			cout << v.Edges[i]->id << endl;
			count++;
		}
		cout << endl;
	}
}
////////////////////////////////////////////////////////////////////////
void Graph::printDFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited){
			DFTraversal(&vertices[i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////
void Graph::printBFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited)
			BFTraversal(&vertices[i]);
	}
}
////////////////////////////////////////////////////////////////////////
void Graph::setAllVerticesUnvisited(){
	for(int i = 0; i < vertices.size(); i++){
		vertices[i].visited = false;
	}
}
////////////////////////////////////////////////////////////////////////
vertex* Graph::findVertex(int id){
	for(vertex v : vertices){
		if(v.id == id){
			vertex *vertexFound = &v;
			return vertexFound;
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////
void Graph::BFTraversal(vertex *v){
	cout << v->id << endl;
	v->visited = true;

	queue<vertex*> q;
	q.push(v);

	vertex *n;

	while(!q.empty()){
		n = q.front();
		q.pop();


		for(int i = 0; i < n->Edges.size(); i++){
			if(!n->Edges[i]->visited){
				n->Edges[i]->visited = true;
				cout << n->Edges[i]->id << endl;
				q.push(n->Edges[i]);
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dftRecursive(vertex *v){
	v->visited = true;
	for(int i = 0; i < v->Edges.size(); i++){
		if(!v->Edges[i]->visited){
			cout << v->Edges[i]->id << endl;
			dftRecursive(v->Edges[i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////
void Graph::DFTraversal(vertex *v){
	cout << v->id << endl;
	dftRecursive(v);
}
////////////////////////////////////////////////////////////////////////