#ifndef PROG5_CC
#define PROG5_CC
#include "/home/cs340/progs/17f/p5/prog5.h"

//*****************************************************************
// FILE:      prog5.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  10/10/2017
//*****************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

//FUNCTIONS
/***************************************************************
init_vals()
Use:  It reads the input vals of N,M, and K of the struct object
      in when the program prompts for them and prints out those
      values on stdout.
Parameters: vector<string>& v, inargs& in
Returns: Nothing
***************************************************************/
void init_vals(vector<string>& v, inargs& in) {
	//get values of M, N and K
	cin>>in.N;
	cin>>in.M;
	cin>>in.K;
	//resize vector
	v.resize(in.N);
	//fill vector with generate
	generate(v.begin(), v.end(), SEQ(in.N));
	cout<<"Number of people? "<<in.N<<endl;
	cout<<"Index for elimination? "<<in.M<<endl;
	cout<<"Index for printing? " <<in.K<<endl;
	cout<<"\n";
};

/***************************************************************
print_vector()
Use:  It prints out the contents of vector v at the beginning
      after removing K name tags from the vector until only one
      nametag remains, where cnt has an initial value of 0 and 
      indicates the total num of removals so far.
Parameters: const vector<string>& v, const unsigned& cnt
Returns: Nothing
***************************************************************/
void print_vector(const vector<string>& v, const unsigned& cnt) {
	//vars for printing
	int counter=0;
	vector<string>::const_iterator it;
	if (cnt!=0)
		cout<<"After eliminating "<<cnt<<"th person"<<endl;
	//print if not empty
	if (!v.empty()) {
		//print items
		for (it=v.begin(); it!=v.end(); it++) {
			if (counter==NO_ITEMS) {
				cout<<endl;
				counter=0;
			}
			cout<<*it<<" ";
			counter++;
		}
	}
	cout<<"\n\n";
};


//MAIN FUNCTION
int main() {
	vector<string> vec;
	int pos=0;
	unsigned int count=0;
	inargs input;
	unsigned int posEliminated=0;
	//call and print init vals
	init_vals(vec, input);
	cout<<"Initial group of people"<<endl;
	cout<<"-----------------------"<<endl;
	print_vector(vec, count);
	//start josephus loop
	while (!vec.empty()) {
		pos=(count+input.M-1) % vec.size();
		for (unsigned int i=0; i<vec.size(); i+=pos) {
			//find Mth item, erase
			vec.erase(vec.begin()+i);
		}
		posEliminated+=input.K;
		//print vector after eliminating
		print_vector(vec, posEliminated);
	}
return(0);
};

#endif



