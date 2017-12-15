#ifndef PROG1_CC
#define PROG1_CC
#include "prog1.h"

//*****************************************************************
// FILE:      prog1.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  9/7/2017
//****************************************************************/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

//generate random ints method
void genRndNums(vector<int>&);
//print vector method
void printVec(const vector<int>&);

/***************************************************************
genRndNums()
Use:  This routine generates VEC_SIZE integers and
          puts them in vector v
Parameters: vector<int>& v
Returns: Nothing
***************************************************************/
void genRndNums(vector<int>& v) {
        //initialize srand
	srand(time(&SEED));
        int num;
        //generate random ints and insert into vector
        for (int i=0; i<VEC_SIZE; i++) {
                //generate random number between LOW and HIGH
                num=rand() % (HIGH-LOW+1) + LOW;
                //insert into vector
                v.push_back(num);
        }
};

/***************************************************************
printVec()
Use:  This routine prints the items in the vector
Parameters: const vector<int>& v
Returns: Nothing
***************************************************************/
void printVec(const vector<int>& v) {
	for (int i=0; i<VEC_SIZE; i++) {
		cout<<setw(5)<<v[i];
		if ((i+1)%12 == 0)
			cout<<endl;
	}
};

int main() {
        //create vector
        vector<int> v;
        //generate random ints into vector
        genRndNums(v);
	//sort vector
        sort(v.begin(), v.end());
        //print vector items
        printVec(v);
        return(0);
};

#endif
