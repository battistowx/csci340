#ifndef PROG6_H
#define PROG6_H
#include "/home/cs340/progs/17f/p7/Node.h"

//*****************************************************************
// FILE:      binTree.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  10/24/2017
//*****************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

//default binary tree template
template<class T> class binTree {

  public:
    //default constructor
    binTree();
    //returns height of tree
    unsigned height() const;
    //returns size of tree
    unsigned size() const;
    //inserts a node in the tree
    virtual void insert(const T&);
    //in order transversal of tree
    void inorder(void(*)(const T&));
  protected:
    //root of tree
    Node<T>* root;
    
  private:
    //private versions of functions:
    unsigned height(Node<T>*) const;
    unsigned size(Node<T>*) const;
    void insert(Node<T>*&, const T&);
    void inorder(Node<T>*, void(*)(const T&));
};

/***************************************************************
public binTree()
Use:  This is the default constructor of the binary tree class
Parameters: None
Returns: Nothing
***************************************************************/
template<class T> binTree<T>::binTree() {
  root=0;
};

/***************************************************************
public height()
Use:  This is the public height function
Parameters: None
Returns: Nothing
***************************************************************/
template<class T> unsigned binTree<T>::height() const {
  return height(root);
};

/***************************************************************
public size()
Use:  This is the public size function
Parameters: None
Returns: Nothing
***************************************************************/
template<class T> unsigned binTree<T>::size(Node<T>* item) const {
  if (item != 0)
    return size(item->left) + size(item->right) + 1;
  else
    return 0;
};

/***************************************************************
public insert()
Use:  This is the public insert function
Parameters: None
Returns: Nothing
***************************************************************/
template<class T> void binTree<T>::insert(const T& x) {
  insert(this->root, x);
};

/***************************************************************
public inorder()
Use:  This is the public inorder function
Parameters: None
Returns: Nothing
***************************************************************/
template<class T> void binTree<T>::inorder(void(*x)(const T&)) {
  inorder(root, x);
};

/***************************************************************
private height()
Use:  This is the default constructor of the binary tree class
      using a recursive call to add each left/right item
Parameters: Node<T>*
Returns: unsigned int size
***************************************************************/
template <class T> unsigned binTree<T>::height(Node<T>* item) const {
  unsigned int right, left;
  //test if empty
  if (item==NULL)
    return 0;
  else {
    //recursively call height function
    right=height(item->right);
    left=height(item->left);
    if (left > right)
      return left + 1;
    else
      return right + 1;
  }
};  

/***************************************************************
private size()
Use:  This returns the size of the binary tree
Parameters: Node<T>*
Returns: unsigned int
***************************************************************/
template <class T> unsigned binTree<T>::size() const {
  if (root==NULL)
    return 0;
  return size(root);
};

//Typedef for SIDE:
typedef enum{left_side, right_side} SIDE;
SIDE rnd() { return rand() % 2 ? right_side : left_side; }

/***************************************************************
private insert()
Use:  This inserts a node into the tree
Parameters: const T& x
Returns: Nothing
***************************************************************/
template <class T> void binTree<T>::insert(Node<T>*& nodePtr, const T& x) {
  //test if tree is empty, insert node at root of tree with val x
  if (nodePtr==NULL) {
      Node<T>* item=new Node<T>(x);
      nodePtr=item;
  }
  else {
    SIDE s=rnd();
    //randomly select left or right side, call recursively
    if (s==right_side)
      insert(nodePtr->right, x);
    else
      insert(nodePtr->left, x);
  }
};

/***************************************************************
private inorder()
Use:  This recursively performs an in order transversal of 
      the tree
Parameters: Node<T>*, void(*)(const T&)
Returns: Nothing
***************************************************************/
template<class T> void binTree<T>::inorder(Node<T>* nodePtr, void(*x)(const T&)) {
  //test if tree is empty
  if (nodePtr!=NULL) {
    //recursively call left side
    inorder(nodePtr->left, x);
    //print value
    x(nodePtr->data);
    //go to right subtree
    inorder(nodePtr->right, x);
  }
};

#endif