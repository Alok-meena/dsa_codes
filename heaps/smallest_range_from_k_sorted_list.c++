You are given ‘K’ lists containing non-negative integers.
Each list has a size ‘N’ and is sorted in non-decreasing order.
You need to find the minimum length of a range such that at least one element of each list must be included in that range.

For example :

If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 
from the second list, and 5 from the third list i.e, this range contains at least one element from each list.



#include<bits/stdc++.h>
#include <limits.h>
#include <queue>


class node{
    public:
      int data;
      int row;
      int col;

      node(int d,int r,int c){
          this->data=d;
          this->row=r;
          this->col=c;
      }
};

class compare{
    public:
      bool operator()(node* a,node*b){
          return a->data>b->data;
      }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini=INT_MAX;
    int maxi=INT_MIN;

    priority_queue<node*,vector<node*>,compare>minheap;

   // put first element of eahc list into the minheap
   for(int i=0;i<k;i++){
      int element=a[i][0];
      mini=min(mini,element);
      maxi=max(maxi,element);
      minheap.push(new node(element,i,0));
   }


   int start=mini,end=maxi;

   while(!minheap.empty()){
       node *temp=minheap.top();
       minheap.pop();

       mini=temp->data;

       if(maxi-mini<end-start){
           start=mini;
           end=maxi;
       }

       if(temp->col+1<n){
           maxi=max(maxi,a[temp->row][temp->col+1]);
           minheap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
       }
       else{
           break;
       }
   }
   return end-start+1;


}

