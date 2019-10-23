#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout<<"Creating tree"<<endl;
  BST tree(5);


  tree.addNode(2); //left child to 5
  tree.addNode(1); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(7); //right child to 5
  tree.addNode(10); //right child of 7
  tree.addNode(8); // left child of 10
  tree.addNode(6); // left child of 7

  //THIS SHOULD RETURN 3
  cout << "with range of 1 to 2: "<<tree.sumRange(1, 2) << endl;

  cout << "--------------------------" << endl;
  cout << "TEST 2" << endl;
  cout << "--------------------------" << endl;
  //this should return 40
  cout << "with range of 4 to 10: "<<tree.sumRange(4, 10) << endl;

  cout << "--------------------------" << endl;
  cout << "TEST 3" << endl;
  cout << "--------------------------" << endl;
  BST tree2(20);
  tree2.addNode(3);
  tree2.addNode(100);
  //should print 120
  cout << "with range 4 to 100: " << tree2.sumRange(4,100) << endl;
    
}
