#ifndef WDIGRAPH2_CC
#define WDIGRAPH2_CC
#include "/home/cs340/progs/17f/p10/wdigraph.h"

//*****************************************************************
// FILE:      wdigraph2.cc
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  12/6/2017
//*****************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************
depth_first()
Use:  This transeverses a digraph in the depth-first-order and
      prints the resulting path
Parameters: int u
Returns: Nothing
***************************************************************/
void wdigraph::depth_first(int u) const {
   //declare vars for first vertex and visited node
   static int first=-1;
   static bool* visitedArray=NULL;
   //test if first item is not visited
   if (first==-1) {
      //set first vertex equal to passed u
      first=u;
      //make new visited array
      visitedArray=new bool(size);
      //reset visiting status to false
      for (int i=0; i<size; i++)
         visitedArray[i]=false;
   }
   //print item, set visited to true
   cout<<label[u];
   visitedArray[u]=true;
   //transverse through graph and print each item
   for (int i=0; i!=size; i++) {
      if (adj_matrix[u][i] != 0 && visitedArray[i] != true) {
         //print arrow if not visited
         cout<<"=>";
         //recursively call, passing j for printing item
         depth_first(i);
      }
   }
      //test if u is same as first to print new lines
      if (u==first) {
         first=-1;
         //clear array
         delete[] visitedArray;
         visitedArray=NULL;
         cout<<endl<<endl;
      }
};

/***************************************************************
print_graph()
Use:  This prints the values in the digraph
Parameters: None
Returns: Nothing
***************************************************************/
void wdigraph::print_graph() const {
   //print number of nodes and the matrix
   cout<<"Num of Nodes: "<<size<<endl<<endl;
   //print matrix
   cout<<"Matrix:"<<endl;
   //loops for | and --
   cout<<" |";
   for (int i=0; i<(int)label.size(); i++)
      cout<<" "<<label[i];
   cout<<endl<<"--|";
   for (int j=0; j<(int)label.size(); j++)
      cout<<"--";
   cout<<endl;
   for (int k=0; k<(int)label.size(); k++) {
      cout<<label[k]<<" |";
         for (int l=0; l<(int)label.size(); l++) {
            //test if the matrix is not empty, print dash if else
            if(adj_matrix[k][l]!=0)
               cout<<setw(3)<<adj_matrix[k][l];
            else
               cout<<setw(3)<<"-";
         }
      //test if k is less than the size-1, print |
      if(k<(int)label.size() -1)
         cout<<endl<<"  |"<<endl;
   }
};

#endif
