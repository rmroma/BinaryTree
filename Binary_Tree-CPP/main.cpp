#include <iostream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;

int main(){

	Tree<int> * tree = new Tree<int>();

	tree->insert(20);
	tree->insert(10);
	tree->insert(30);
	tree->insert(25);
	tree->insert(12);
	tree->insert(17);
	tree->insert(7);
	tree->insert(15);
	tree->insert(28);
	cout << "There are: " << tree->getNumOfNodes() << " nodes in the tree" << endl << endl;
	tree->printInOrder();
	tree->removeNode(10);
	cout << "There are: " << tree->getNumOfNodes() << " nodes in the tree" << endl << endl;
	tree->printInOrder();

	int * dataArray = tree->getAscOrDdecDataArray('d');

	for (int i = 0; i < tree->getNumOfNodes(); i++)
		cout << dataArray[i]<<" ";
	cout << endl<<endl;

	delete dataArray;

	dataArray = tree->getAscOrDdecDataArray('a');

	for (int i = 0; i < tree->getNumOfNodes(); i++)
		cout << dataArray[i] << " ";
	cout << endl << endl;

	delete dataArray;

	tree->clear();
	

	
	//t1.returnAscOrDesc('a');

	//cout << "\nNum of leaves: " << t1.getNumOfLeaves() << endl;

  return 0;
}
