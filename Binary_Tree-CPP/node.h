#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;
template <class T>
class Node {
  
  private:
    T         data;
    Node<T>*  left;
    Node<T>*  right;
	Node<T>*  parent;

  public:

    Node();	    //Default Constructor, sets all private properties to NULL
    Node(T);	//Overloaded constructor, allows a node to be created with a specified data
    
    T getData() const;
    void setData(const T);

    Node<T> *getLeft();
    void setLeft(Node<T>*);	

    Node<T> * getRight();
    void setRight(Node<T>*);

	Node<T> *getParent();
	void setParent(Node<T>*);

	//operator overloading  <<
	friend ostream &operator<<(ostream & out, Node<T> & node) {
		out << " Data: " << node.getData() << endl;
		out << " Parent: " << node.getParent() << endl;
		out << " Left: " << node.getLeft() << endl;
		out << " Right: " << node.getRight() << endl << endl;

		return out;
	}
    
	//Destructor
	Node<T>::~Node();
};

#endif 
