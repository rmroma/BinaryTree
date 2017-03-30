#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <cstddef>
#include <vector>

template <class T>
class Tree {

  private:
    int		  numOfNodes;
    Node<T> * root;
    

	//Compares data in 2 nodes   return:  
	//Input: 2 Nodes
	//Output: positive number if a>b , negetive if a<b , 0 if a=b
    int nodeCompare(Node<T>* a, Node<T>* b); 

	//Incerment the size of nodes
	void incNumberOfNods(); 

	//Incerment the size of nodes
	void decNumberOfNods();

	//Set parent's node to null
	//Input:  Node Pointer
	//Output: None
	void setParentToNull(Node<T>* node);

	//Creates a node
	//Input: Data , Node parent Node left,Node right
	//Output:: New Node
	Node<T>* createNode(const T, Node<T>* const parent = NULL, Node<T>* const left = NULL, Node<T>* const right = NULL); 
	
	//Check how many nodes attached to a node
	//Input: Pointer node
	//Output: Number of nodes
	int howManyNodesAttached(Node<T>*);

	
	void printInOrder(Node<T> * root)const;

	void printPostOrder(Node<T> * root)const;

	void printPreOrder(Node<T> * root)const;
	
	//Delete node that have one child
	//Input: Node Pointer
	//Output: None
	void deleteNodeWithSinglePtr(Node<T>* node);

	//Delete node that have two child
	//Input: Node Pointer
	//Output: None
	void deleteNodeWithBothPtrs(Node<T>* node);

	//Delete node that have two child
	//Input: Node Pointer
	//Output: None
	void deleteTree(Node<T> * root);

	void getAscendingDataArray(T dataArray[], Node<T>* node, int & index)const;

	void Tree<T>::swap(T dataArray[], int i, int j)const;

  public:

  //Constructors
    Tree();			  //Default constructor
    Tree(const Tree&);		  //Copy Constructor
    Tree& operator=(const Tree&); //Assignment operator

  //Destructor
    ~Tree();

  //Methods
	

	Node<T> * getRoot() const;

	int getNumOfNodes() const;


	//Insert new node to the tree
	//Input: Address of a node 
	//Output: None
	void insert(Node<T>*);

	//Insert new node to the tree
	//Input: value 
	//Output: None
	void insert(T data);

	//Get a pointer to a node by its data
	//Input: Data
	//Output: pointer to a node
	Node<T> * getNode(const T data);

	//Adds a node to the Tree.
	// Input: Value of templated type T
    void addNode(const T);		
    

	//Check if a data contains in the tree
	//Input: Data of templated type T
	//Output: true if found,false if not
	bool contains(const T data);

	
	//Remove a node from the tree
	//Input: Data of templated type T
	//Output: None
	void removeNode(T data);

	//Remove a node from the tree
	//Input: Pointer to a node
	//Output: None
	void removeNode(Node<T> *  node);

	//Clear all the nodes in the tree
	//Input: None
	//Output: None
	void clear();

	//Print the tree by your order
	//Input: None
	//Output: None
	void visualTraverse();

	//Print the tree by in order
	//Input: None
	//Output: None
	void printInOrder()const;

	//Print the tree post order
	//Input: None
	//Output: None
	void printPostOrder()const;

	//Print the tree by pre order
	//Input: None
	//Output: None
	void printPreOrder()const;

	//Prints data and if there is a node or not attached to the node's pointers
	//Input: 1 Node Pointer
	//Output: Printed data
	void printContents(Node<T>*);


	T *  getAscOrDdecDataArray(char aORd) const;

	int height(Node<T> * node) const;

	void printAllPaths(Node<T>* node, T path[], int size)  const;

	void printLevelOrder(Node<T> * node)const;
	void printGivenLevel(Node<T> * node, int level)const;
};

#endif
