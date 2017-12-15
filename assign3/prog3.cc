#ifndef PROG3_C
#define PROG3_C
#include "prog3.h"

//*****************************************************************
// FILE:      prog3.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  9/21/2017
//*****************************************************************/

#include <set>
#include <iostream>
#include <iomanip>

using namespace std;

//FUNCTIONS:

/***************************************************************
sieve()
Use:  This is the function of the Eratosthenes algorithm
Parameters: set<int>& s, int n
Returns: Nothing
***************************************************************/
void sieve(set<int>& s, int n) {
	//int CAPACITY=n;
	//fill set with ints
	for (int i=2; i<n; i++)
		s.insert(i);
	//go through each item and test
	for (int m=2; (m*m)<n; m++) {
		//test items as long as they're not deleted
		if (s.end() != s.find(m)) {
			for (unsigned int k=m; k<=s.size(); k++) {
				//find multiples of k and m, delete them
				s.erase(k*m);
			}
		}
	}
};

/***************************************************************
print_primes()
Use:  This prints out the remaining elements in the set
Parameters: const set<int>& s
Returns: Nothing
***************************************************************/
void print_primes(const set<int>& s) {
	set<int>::const_iterator it;
        int counter=0;
        for (it=s.begin(); it!=s.end(); it++) {
                if (counter==NO_ITEMS) {
                        cout<<endl;
                        counter=0;
                }
                cout<<setw(ITEM_W)<<*it;
                counter++;
        }
};

int main() {
	int lim;
	set<int> nums;
	cout<<"Please enter the upper limit: ";
	cin>>lim;
	cout<<endl;
	sieve(nums, lim);
	print_primes(nums);
	return(0);
}

#endif
