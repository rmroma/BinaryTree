#include <iostream>
#include "tree.h"

using namespace std;

// Constructors/Destructor ---------------------------
template <class T>
Tree<T>::Tree() : numOfNodes(0), root(NULL){}

template <class T>
Tree<T>::Tree(const Tree<T>& other){
  numOfNodes = other.getNumOfNodes();
  root = other.getRoot();
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other){
  numOfNodes = other.getNumOfNodes();
  root = other.getRoot();
}

template <class T>
Tree<T>::~Tree(){
	if (root != NULL)
		deleteTree(root);
}
// ----------------------------------------------------

// Private Functions ----------------------------------
 
template <class T>
int Tree<T>::nodeCompare(Node<T> *a, Node<T> *b){
	return a->getData() - b->getData();
}

template<class T>
void Tree<T>::incNumberOfNods(){
	numOfNodes++;
}

template<class T>
void Tree<T>::decNumberOfNods(){
	if (numOfNodes > 0)
		numOfNodes--;
}

template <class T>
void Tree<T>::printContents(Node<T>* node) {

	Node<T>* left = node->getLeft();
	Node<T>* right = node->getRight();
	Node<T>* parent = node->getParent();

	cout << "Data: " << node->getData() << endl;

	if (left != NULL)
		cout << "Left Node holds: " << left->getData() << endl;
	else
		cout << "No left node.\n";

	if (right != NULL)
		cout << "Right node holds: " << right->getData() << endl;
	else
		cout << "No right node.\n";

	if (parent != NULL)
		cout << "Previous node holds: " << parent->getData() << endl;
	else
		cout << "This is the root node.\n";

	cout << endl << endl;

}


template<class T>
Node<T>* Tree<T>::createNode(const T data, Node<T>* const parent, Node<T>* const left, Node<T>* const right)
{
	Node<T>* newNode = new Node<T>;
	newNode->setData(data);
	newNode->setParent(parent);
	newNode->setLeft(left);
	newNode->setRight(right);
	return newNode;
}

template<class T>
void Tree<T>::insert(Node<T>* newNode)
{
	if (root == NULL) {
		root = newNode;
		incNumberOfNods();
	}
	else {
		Node<T> *temp = root;							// Copy the root pointer

		while (true) {			
			int compare = nodeCompare(newNode, temp);
			if ( compare> 0) {		                   // If newNode->getData() > temp->getData()

				if (temp->getRight() == NULL) {	       // if right node empty
					temp->setRight(newNode);           // Attached to right , which holds greater-than data
					newNode->setParent(temp);          // Set the newNode's parent 
					incNumberOfNods();			       //Update number of nodes
					break;							   // Break from loop 

				}
				else									
					temp = temp->getRight();		   // Continue to the right node

			}

			else if (compare < 0) {                    // If newNode->getData() < temp->getData()

				if (temp->getLeft() == NULL) {		   // If left node empty

					temp->setLeft(newNode);			   // Attached to right , which holds less-than data
					newNode->setParent(temp);          // Set the newNode's parent
					incNumberOfNods();				   //Update number of nodes
					break;							   // Break from the  loop

				}
				else									
					temp = temp->getLeft();             // Continue to the left node
			}
			else {												//If the nodes equales
				cout << newNode->getData() << " is already in the tree.\n";    // Notify that the node is already in the tree
				break;
			}

		}
	}
}

template<class T>
void Tree<T>::insert(T data){
	Node<T> * node = new Node<int>(data);
	insert(node);
}

template<class T>
bool Tree<T>::contains(const T data)
{

	Node<T>* temp = root;

	while (temp) {
		if (temp->getData() == data) {
			return true;
		}
		else if (temp->getData() > data)
				temp = temp->getRight();
		else  (temp->getData() < data)
				temp = temp->getLeft();
	}
	return false;
}

template <class T>
int Tree<T>::howManyNodesAttached(Node<T>* node){

  int numOfNodes = 0;

  if(node->getLeft() != NULL)
    numOfNodes++;
  
  if(node->getRight() != NULL)
    numOfNodes++;

  return numOfNodes; 

}

template<class T>
Node<T>* Tree<T>::getNode(const T data){
	Node<T>* temp = root;

	while (temp) {
		if (temp->getData() == data) {
			return temp;
		}
		else if (data> temp->getData())
			temp = temp->getRight();
		else  
			temp = temp->getLeft();
	}
	return NULL;
}

template <class T>
void Tree<T>::clear() {
	if (root != NULL)
		deleteTree(root);
}

template <class T>
void Tree<T>::deleteNodeWithSinglePtr(Node<T>* node) {

	//Check if the node is left node
	bool isLeft = (node->getParent()->getLeft() == node);
	bool isLeftChild = (node->getLeft() != NULL);
	if (isLeft)
	{
		if (isLeftChild)
		{
			//Update the pointers
			node->getParent()->setLeft(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			node->setLeft(NULL);
		}
		else
		{
			//Update the pointers
			node->getParent()->setLeft(node->getRight());
			node->getRight()->setParent(node->getParent());node->setLeft(NULL);
			node->setRight(NULL);
		}
	}
	else
	{
		if (isLeftChild)
		{
			node->getParent()->setRight(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			node->setLeft(NULL);
		}
		else {
			node->getParent()->setRight(node->getRight());
			node->getRight()->setParent(node->getParent());
			node->setRight(NULL);
		}
	}
	node = NULL;
	
	
}

template <class T>
void Tree<T>::deleteNodeWithBothPtrs(Node<T>* node){

  //Will go down to the minimum data in the sub right tree

  Node<T>* temp = node->getRight();

  while (temp->getLeft() != NULL) {

    temp = temp->getLeft();

  } 
  node->setData(temp->getData());
  setParentToNull(temp); 
  if (temp->getRight() != NULL)
	  deleteNodeWithSinglePtr(temp);
  else {
	  setParentToNull(temp);
	  delete temp;
  }
	 
}

template <class T>
void Tree<T>::setParentToNull(Node<T>* node){

  Node<T>* parent = node->getParent();
  bool nodeIsLeftChild = (parent->getLeft() == node);

  if (nodeIsLeftChild)
    parent->setLeft(NULL);
  else
    parent->setRight(NULL);

}

template<class T>
/* Tree<T>::getAscendingData(T data[], Node<T>* node, int &index)
{
	if (node->getLeftPtr() != NULL) {
		getAscendingData(data, node->getLeftPtr(), index);	// Use recursion to go through each node
	}

	data[index] = node->getData();							// If the left node ptr is null, we are at the smallest node in the branch and can copy data to the array
	index++;	

	if (node->getRightPtr() != NULL) {						// If there's a right node, we want to print that next
		getAscendingData(data, node->getRightPtr(), index);
	}
}*/





// Accessors/Mutators -------------------------------------------



int Tree<T>::getNumOfNodes() const {
	return numOfNodes;
}



template <class T>
Node<T>* Tree<T>::getRoot() const {
  return root;
}


// ------------------------------------------------------

// Tree Methods -----------------------------------------

template <class T>
void Tree<T>::addNode(const T dat) {
  
	Node<T>* newNode = makeNode(dat);					// Make a new node and insert the data
  
														// 2 scenarios:
	if (startPtr == NULL)								// 1) The Tree instance has no nodes
		startPtr = newNode;												
    else 											    // 2) The Tree instance has nodes already
		parseTree(newNode);
  
	incNumberOfNods();
	setLeavesToZeroAndUpdate(startPtr);

}


template <class T>
void Tree<T>::removeNode(const T data) {
  Node<T>* nodeToRemove = getNode(data);
  if (nodeToRemove != NULL)
	  removeNode(nodeToRemove);
  else
	  cout << "The node: " << data << " not found!!!" << endl << endl;;
}

template <class T>
void Tree<T>::removeNode(Node<T> *  node) {

	if (node != NULL) {
		int numOfNodesAttached = howManyNodesAttached(node);

		switch (numOfNodesAttached) {

		case 0:
			setParentToNull(node);
			delete node;
			break;
		case 1:
			deleteNodeWithSinglePtr(node);
			break;
		case 2:
			deleteNodeWithBothPtrs(node);
			break;
		default:
			cout << "Some weird ass error\n";
		}

		decNumberOfNods();
	}

}

template <class T>
void Tree<T>::getAscendingDataArray(T dataArray[], Node<T>* node, int & index)const {

	if (node->getLeft() != NULL)
		getAscendingDataArray(dataArray, node->getLeft(), index);

	dataArray[index] = node->getData();
	index++;

	if (node->getRight() != NULL)
		getAscendingDataArray(dataArray, node->getRight(), index);
	


}

template <class T>
T *  Tree<T>::getAscOrDdecDataArray(char aORd) const {
	if (root == NULL) {
		cout << "The tree is empty" << endl << endl;
		return NULL;
	}

	Node<T> * temp = root;

	T * dataArray = new T[getNumOfNodes()];

	int index = 0;

	getAscendingDataArray(dataArray, temp, index);
	aORd = tolower(aORd);
	if (aORd == 'a') 
		return dataArray;

	int i = 0;
	int j=getNumOfNodes();

	while (i != j) {
		swap(dataArray, i, j - 1);
		i++;
		j--;
	}

	return dataArray;
}

template <class T>
void Tree<T>::swap(T dataArray[], int i, int j) const {
	int temp = dataArray[i];
	dataArray[i] = dataArray[j];
	dataArray[j] = temp;
}

/*template <class T>
void Tree<T>::returnAscOrDesc(const char aOrD) {
	
	T *dataArray = new T[numOfNodes];	// Allocate an array to hold all the data.
										// Putting the data in an array will make it easy to return in ascending or descending order
	int index = 0;
	
	getAscendingData(dataArray, startPtr, index);	// Fill the array in ascending order... 1, 2, 4, etc

	if (aOrD == 'a') {					// If ascending

		for (int i = 0; i < numOfNodes; i++) {

			cout << dataArray[i] << " ";

		}

	}
	else {								// If descending					

		for (int i = numOfNodes-1; i >= 0; i--) {

			cout << dataArray[i] << " ";

		}

	}

	cout << endl;

}*/

template <class T>
void Tree<T>::visualTraverse() {

	char choice;
	bool quit = false;
	Node<T>* movingPtr = root;

	while (true) {

		cout << *movingPtr << endl;	// 1) Output root node's contents

		do {

			cout << "How would you like to traverse the tree? (l - left, r - right, p - parent, q - quit): ";   // 2) Ask if the user would like to move left or right down the tree
			cin >> choice;

			choice = tolower(choice);

			if (choice == 'l') {	// 3) Move down tree

				if (movingPtr->getLeft() != NULL) {

					movingPtr = movingPtr->getLeft();
					break;

				}
				else {
					cout << "There is no node there. Enter another command.\n";
					continue;
				}

			}
			else if (choice == 'r') {

				if (movingPtr->getRight() != NULL) {

					movingPtr = movingPtr->getRight();
					break;

				}
				else {
					cout << "There is no node there. Enter another command.\n";
					continue;
				}

			}
			else if (choice == 'p') {

				if (movingPtr->getParent() != NULL) {

					movingPtr = movingPtr->getParent();
					break;

				}
				else {
					cout << "You are at the root node, there's no parent node!\nEnter another command.\n";
					continue;
				}

			}
			else if (choice == 'q') {

				quit = true;
				break;

			}
			else if (choice != 'l' && choice != 'r') {

				cout << "Please enter a valid selection (l, r, or q).\n";
				continue;

			}


		} while (true);

		if (quit)
			break;

	}
		// 4) Output next node's contents

		// 5) repeat steps 2, 3, and 4 until either the user quits or the user reaches a leaf node  

}

// ------------------------------------------------------
template <class T>
void Tree<T>::deleteTree(Node<T> * root) {
	delete root;
}

template <class T>
void Tree<T>::printInOrder(Node<T> * root) const {

	if (root) {
		printInOrder(root->getLeft());
		cout << root->getData() << " ";
		printInOrder(root->getRight());
	}
}

template <class T>
void Tree<T>::printPostOrder(Node<T> * root) const {

	if (root) {
		
		printPostOrder(root->getLeft());
		printPostOrder(root->getRight());
		cout << root->getData() << " ";
	}
}

template <class T>
void Tree<T>::printPreOrder(Node<T> * root) const {

	if (root) {
		cout << root->getData() << " ";
		printPreOrder(root->getLeft());
		printPreOrder(root->getRight());
	}
}

template <class T>
void Tree<T>::printInOrder() const {
	Node<T> * temp = root;
	if (root) {
		cout << "Print Tree: IneOrder" << endl;
		printInOrder(temp);
		cout << endl << endl;
	}else
		cout << "The tree is empty" << endl;


}

template <class T>
void Tree<T>::printPostOrder() const {

	Node<T> * temp = root;
	if (root) {
		cout << "Print Tree: PostOrder" << endl;
		printPostOrder(temp);
		cout << endl << endl;
	}
	else
		cout << "The tree is empty" << endl;
}

template <class T>
void Tree<T>::printPreOrder() const {
	Node<T> * temp = root;
	if (root) {
		cout << "Print Tree: PreOrder" << endl;
		printPreOrder(temp);
		cout << endl << endl;
	}
	else
		cout << "The tree is empty" << endl;
}
