#ifndef PROG4_CC
#define PROG4_CC
#include "prog4.h"

//*****************************************************************
// FILE:      prog4.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  10/2/2017
//*****************************************************************/

#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//FUNCTIONS

/***************************************************************
clean_entry()
Use:  It cleans a word from its punctuation marks. The first 
      argument is the original word in the input stream and the
      second argument contains the same word after cleaning.
Parameters: const string&, string&
Returns: Nothing
***************************************************************/
void clean_entry(const string& word, string& str) {
	//index vars
	unsigned int i=0;
	unsigned int j;
	//test for punctuation until word is done and there is no punctuation
	while(!isalnum(word[i]) && i<word.length()) {
		//go to next char in word
		i++;
	}
	//set positions
	j=i;
	//increment j if string j is punctuation
	while(isalnum(word[j]) && j<word.length()) {
		j++;
		if(j==i)
			str="";
		else {
			//copy function
			str=word.substr(i, j-i);
			//convert all capitals to lower case
			//str=for_each(str.begin(), str.end(), str.begin(), tolower);
		}
	}
};

/***************************************************************
get_words()
Use:  It gets a word from the input stream and removes its 
      punctuation marks.
Parameters: map<string, int>&
Returns: Nothing
***************************************************************/
void get_words(map<string, int>& w) {
	//index var
	string wrd;
	string str;
		while(cin>>wrd) {
			//counter for amount of words before cleaning
			before++;
			clean_entry(wrd, str);
			//insert into map
			w[str]++;
		}
};

/***************************************************************
print_words()
Use:  It prints the final list of words and their frequencies. 
      It also prints the number of nonempty words and the number
      of distinct words in the input stream.
Parameters: map<string, int>&
Returns: Nothing
***************************************************************/
void print_words(map<string, int>& w) {
	map<string, int>::iterator it;
	int counter=0;
	//print all elements
	for (it=w.begin(); it!=w.end(); it++) {
		counter++;
		cout<<setw(ITEM_W)<< it->first<<" : "<< it->second;
		if (counter==NO_ITEMS) {
			counter=0;
			cout<<endl;
		}
        }
	cout<<"Amount of words in input stream: "<<before<<endl;
	cout<<"Amount of words in output stream: "<<w.size()<<endl;
};

//MAIN

int main() {
	map<string, int> words;
	get_words(words);
	print_words(words);
	return(0);
}

#endif


