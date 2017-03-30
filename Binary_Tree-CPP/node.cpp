#include "node.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node(){
	setData(0);
	setLeft(NULL);
	setRight(NULL);
	
	
}

template <class T>
Node<T>::Node(T data){
	setData(data);
	setLeft(NULL);
	setRight(NULL);
}

template <class T>
void Node<T>::setData(const T data){
  this->data = data;
}

template <class T>
T Node<T>::getData()const {
  return data;
}

template <class T>
void Node<T>::setLeft(Node<T>* left){
	this->left = left;
}

template <class T>
Node<T>* Node<T>::getLeft(){
	return left;
}

template <class T>
void Node<T>::setRight(Node<T>* right){
	this->right = right;
}

template <class T>
Node<T>* Node<T>::getRight() {
	return right;
}

template<class T>
Node<T>* Node<T>::getParent()
{
	return parent;
}

template<class T>
void Node<T>::setParent(Node<T>* parent)
{
	this->parent = parent;
}


template<class T>
Node<T>::~Node(){
	cout << endl;
	if (left != NULL)
		delete left;
	if (right != NULL)
		delete right;
}
