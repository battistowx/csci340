#ifndef PROG7_H
#define PROG7_H
#include "/home/cs340/progs/17f/p7/Node.h"
#include "binTree.h"

//*****************************************************************
// FILE:      binSTree.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  10/31/2017
//*****************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//template class definition
template<class T> class binSTree:public binTree<T> {
	public:
		void insert(const T& x);
		void remove(const T& x);
	private:
		void insert(Node<T>*&, const T&);
		void remove(Node<T>*&, const T&);
		Node<T>* pred(Node<T>*);
};

/***************************************************************
public insert()
Use:  This inserts a node with value x
Parameters: const T& x
Returns: Nothing
***************************************************************/
template<class T> void binSTree<T>::insert(const T& x) {
	//recursively call
	insert(this->root, x);
};

/***************************************************************
public remove()
Use:  This removes a node with value x
Parameters: const T& x
Returns: Nothing
***************************************************************/
template<class T> void binSTree<T>::remove(const T& x) {
	//recursively call
	remove(this->root, x);
};

/***************************************************************
pred()
Use:  This gets the predecessor of the node
Parameters: Node<T>* x
Returns: Node<T>*
***************************************************************/
template<class T> Node<T>* binSTree<T>::pred(Node<T>* x) {
  //check if null, return predecessor (left child)
  if(x!=NULL)
    return x->left;
  else
    return NULL;
  x=x->left;
  while (x->right != NULL)
    x=x->right;
  return x;
};

/***************************************************************
private insert()
Use:  This inserts a node with value x
Parameters: const T& x
Returns: Nothing
***************************************************************/
template<class T> void binSTree<T>::insert(Node<T>*& n, const T& x) {
	//check if empty, make new node
  if(n==NULL) {
    Node<T>* item=new Node<T>(x);
    n=item;
  }
  //add node based on position in tree
  else if(x == n->data)
    insert(n->right, x);
  else if(x == n->data)
    insert(n->left, x);
  //break
  else
    return;
};

/***************************************************************
private remove()
Use:  This removes a node with value x
Parameters: Node<T>* n, const T& x
Returns: Nothing
***************************************************************/
template<class T> void binSTree<T>::remove(Node<T>*& n, const T& x) {
  if(n == NULL)
    return;
  else if(n->data < x)
    remove(n->right, x);
  else if(n->data > x)
    remove(n->left, x);

  else {
    Node<T>* temp;
    if(n->left == NULL && n->right == NULL) { //No children
      delete n;
      n = NULL;
    }
    else if(n->left != NULL && n->right == NULL) { //Has only left child
      temp = n;
      n = n->left;
      delete temp;
    }
    else if(n->left == NULL && n->right != NULL) { //Has only right child
      temp = n;
      n = n->right;
      delete temp;
    }
    else if(n->left != NULL && n->right != NULL) { //Has both children
      n->data = pred(n)->data;
      remove(n->left, n->data);
    }
  }

};

#endif