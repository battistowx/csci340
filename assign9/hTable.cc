#ifndef PROG9_CC
#define PROG9_CC
#include "/home/cs340/progs/17f/p9/hTable.h"

//*****************************************************************
// FILE:      hTable.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  11/28/2017
//*****************************************************************/

#include <iostream>
using namespace std;

/***************************************************************
consructor HT()
Use:  This constructs a the hash table and sets default values.
Parameters: const unsigned& hs
Returns: Nothing
***************************************************************/
HT::HT(const unsigned& hs) {
  //set values
  hTable.resize(hs);
  pTable.resize(hs);
  hsize=hs;
};

/***************************************************************
destructor HT()
Use:  This is the destructor function of the HT object
Parameters: None
Returns: Nothing
***************************************************************/
HT::~HT() {
  //pop back items in htable
  for (unsigned int i=0; i<hsize; i++)
    hTable.pop_back();
  //delete ptable
  for (unsigned int i=0; i<pTable.size(); i++)
    delete pTable[i];
};

/***************************************************************
struct cmp()
Use:  This class uses a bool function to check if there is a 
      duplicate key for the insert function
Parameters: None
Returns: Bool if there is a duplicate key
***************************************************************/
struct cmp {
  string item;
  //constructor
  cmp(const string& x):item(x) {}
  //bool operator for testing duplicate
  bool operator()(const Entry& e) {return item==e.key;}
};

/***************************************************************
insert()
Use:  This inserts the record of item e into the hash table
Parameters: const Entry& e
Returns: Nothing
***************************************************************/
void HT::insert(const Entry& e) {
  //get key
  int i=hash(e.key);
  //check if in size
  i %= hsize;
  //make list object for comparing
  list <Entry>& l=hTable[i];
  //check for duplicate keys
  if (find_if(l.begin(), l.end(), cmp(e.key)) != l.cend())
    cout<<"Duplicate key, not inserted"<<endl;
  //else, insert item to front of table and print entry
  else {
    //push front e key
    l.push_front(e);
    //get new item
    Entry* item=new Entry(e.key, e.desc, e.num);
    //push back in pointer table
    pTable.push_back(item);
    //print out item
    cout<<" Item: "<<i<<endl;
  }
};

/***************************************************************
search()
Use:  This searches the table for a record given a key
Parameters: const string& key
Returns: Nothing
***************************************************************/
void HT::search(const string& key) {
  //get key
  int i=hash(key);
  //check if within size
  i %= hsize;
  list <Entry>& l=hTable[i];
  //search for key, declare iterator
  list<Entry>::iterator it;
  //use lambda for comparing at end of function
  it=find_if(l.begin(), l.end(), [key](Entry e) {return key==e.key;});
  if (it != l.cend())
    cout<<" Number: "<< it->key <<" Desc: "<< it->desc <<endl;
  else
    cout<<"Item not found"<<endl;
};
    
/***************************************************************
hTable_print()
Use:  This prints the subscript and content of the records
Parameters: None
Returns: Nothing
***************************************************************/
void HT::hTable_print() {
  //make object for item
  Entry item;
  //loop through table and find item
  for (unsigned int i=0; i<hsize; i++) {
    list <Entry>& l=hTable[i];
    //declare iterator
    list<Entry>::iterator it;
    for (it=l.begin(); it != l.end(); it++) 
      cout<<i<<": "<< it->key<<" Desc: "<< it->desc <<" Num: "<< it->num <<endl;
  }
};

/***************************************************************
pTable_print()
Use:  This prints the active records in the hash table
Parameters: None
Returns: Nothing
***************************************************************/
void HT::pTable_print() {
  //sort alphabetically using lambda predicate
  sort(pTable.begin(), pTable.end(), [](Entry* p, Entry* q) {return p->key < q-> key;});
  //print ptable
  vector<Entry*>::iterator it;
  for (it=pTable.begin(); it != pTable.end(); it++)
    //dereference pointers when printing
    cout<< (*it)->key <<" Num: "<< (*it)->num <<" Desc: "<< (*it)->desc <<endl;
};

#endif