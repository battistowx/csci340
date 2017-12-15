#ifndef PROG2_H
#define PROG2_H

//*****************************************************************
// FILE:      prog2.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  9/14/2017
//*****************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//CONSTANTS
const int ARR_SIZE=200;
const int TEST_ARR_SIZE=100;
const int LOW=1;
const int HIGH=1000;
const int NO_ITEMS=16;
const int ITEM_W=4;
const int SEED1=1;
const int SEED2=3;

//FUNCTION PROTOTYPES:

//create vectors
void Vectors(vector <int>& v1, vector<int>& v2, int s1, int s2);
//linear search algorithm
bool linearSearch(const vector<int>& v, int x);
//binary search algorithm
bool binarySearch(const vector<int>& v, int x);
//generic search algorithm
int search(const vector<int>& v1, const vector<int>& v2, bool(*p)(const vector<int>&, int));
//sort vector algorithm
void sortVector(vector<int>& v);
//print vector items
void printVector(const vector<int>& v);
//print percentage of successful searches
void printStat(int totalSucCnt, int vectorSz);

#endif 
