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
	tree->printLevelOrder(tree->getRoot());
	int depth = tree->height(tree->getRoot());
	cout << "The depth is: " << depth << endl;
	cout << "There are: " << tree->getNumOfNodes() << " nodes in the tree" << endl << endl;
	tree->printInOrder();
	cout << "There are: " << tree->getNumOfNodes() << " nodes in the tree" << endl << endl;
	tree->printInOrder();

	/*int * dataArray = tree->getAscOrDdecDataArray('d');

	for (int i = 0; i < tree->getNumOfNodes(); i++)
		cout << dataArray[i]<<" ";
	cout << endl<<endl;

	delete dataArray;

	dataArray = tree->getAscOrDdecDataArray('a');

	for (int i = 0; i < tree->getNumOfNodes(); i++)
		cout << dataArray[i] << " ";
	cout << endl << endl;*/


	//tree->printPreOrder();

	//delete dataArray;
	cout << "Level Order" << endl;
	tree->printLevelOrder(tree->getRoot());


	tree->clear();
	cout << endl << endl;

	
	

	
	//t1.returnAscOrDesc('a');

	//cout << "\nNum of leaves: " << t1.getNumOfLeaves() << endl;

  return 0;
}
