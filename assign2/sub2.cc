#ifndef SUB2_CC
#define SUB2_CC
#include "prog2.h"

//*****************************************************************
// FILE:      sub2.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  9/14/2017
//****************************************************************/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;

/***************************************************************
Vectors()
Use:  This routine creates the vectors
Parameters: <int>&, vector<int>&, int, int
Returns: Nothing
***************************************************************/
void Vectors(vector<int>& v1, vector<int>& v2, int s1, int s2) {
	//initialize random numbers
	srand(s1);
	int num;
	//generate random ints and insert into vector
	for (int i=0; i<ARR_SIZE; i++) {
		//generate random number between LOW and HIGH
		num=rand() % (HIGH-LOW+1) + LOW;
		//insert into vector
		v1[i]=num;
	}
	//fill v2
	srand(s2);
	for (int i=0; i<TEST_ARR_SIZE; i++) {
                //generate random number between LOW and HIGH
                num=rand() % (HIGH-LOW+1) + LOW;
                //insert into vector
                v2[i]=num;
        }
};

/***************************************************************
linearSearch()
Use:  This routine executes a linear search algorithm
Parameters:  const vector <int>& v, int x
Returns: bool
***************************************************************/
bool linearSearch(const vector <int>& v, int x) {
	vector<int>::const_iterator key;
	key=find(v.begin(), v.end(), x);
	if (key!=v.end())
		return true;
	else
		return false;
};

/***************************************************************
binarySearch()
Use:  This routine executes a binary search algorithm
Parameters:  const vector <int>& v, int x
Returns: bool
***************************************************************/
bool binarySearch(const vector <int>& v, int x) {
	bool key=binary_search(v.begin(), v.end(), x);
        return key;
};

/***************************************************************
search()
Use:  This routine executes a generic search algorithm
Parameters:  const vector<int>& v1, const vector<int>& v2,
	      bool(*p)(const vector<int>&, int)
Returns: int
***************************************************************/
int search(const vector<int>& v1, const vector<int>& v2, bool(*p)(const vector<int>&, int)) {
	int counter=0;
	vector<int>::const_iterator it;
	for (it=v2.begin(); it != v2.end(); it++) {
		if (p(v1, *it))
			counter++;
	}
	return counter;
};

/***************************************************************
sortVector()
Use:  This routine sorts the passed vector
Parameters:  vector<int>& v
Returns: nothing
***************************************************************/
void sortVector(vector<int>& v) {
	sort(v.begin(), v.end());
};

/***************************************************************
printVector()
Use:  This routine prints the passed vector
Parameters:  const vector<int>& v
Returns: nothing
***************************************************************/
void printVector(const vector<int>& v) {
	vector<int>::const_iterator it;
	int counter=0;
	for (it=v.begin(); it!=v.end(); it++) {
		if (counter==NO_ITEMS) {
			cout<<endl;
			counter=0;
		}
		cout<<setw(ITEM_W)<<*it;
		counter++;
	}
};

/***************************************************************
printStat()
Use:  This routine prints the percent of successful searches
Parameters:  int totalSucCnt, int vectorSz
Returns: nothing
***************************************************************/
void printStat(int totalSucCnt, int vectorSz) {
	float p1=totalSucCnt;
	float p2=vectorSz;
	float percent=p1/p2;
	percent*=100.00;
	cout<<"Percent of Successful Searches = ";
	cout<<fixed<<showpoint;
	cout<<setprecision(2);
	cout<<right<<percent<<"%"<<endl;
};

#endif

