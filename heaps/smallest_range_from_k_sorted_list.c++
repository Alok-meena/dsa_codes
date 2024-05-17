You are given ‘K’ lists containing non-negative integers.
Each list has a size ‘N’ and is sorted in non-decreasing order.
You need to find the minimum length of a range such that at least one element of each list must be included in that range.

For example :

If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 
from the second list, and 5 from the third list i.e, this range contains at least one element from each list.

1st approach :
brute force by combining all the elements in a single list and then finding the range
Time Complexity
O(N^3 * K^3), where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists. 

For each of the ‘K’ lists, we have ‘N’ elements so the total number of elements is N*K.
Now for generating each possible pair of elements will take O((N * K) ^ 2) time and
for each pair we need to traverse on each list in the worst case we will traverse all
the elements which will take O(N * K) time. So overall time complexity in the worst case will be O((N * K)  ^3)

Space Complexity
O(N * K), where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

We are using a list for storing all pairs. So space complexity will be O(N * K).


2nd approach :
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

       if(maxi-mini<end-start){//yha bs vhi kr rhe jo niche vale code me hai bs minheap min element dega aor isse complexity improve ho rhi hai bs ab ans ko 
           // update kr liya aor next loop me ham min element ko next greater element assign kr rhe hai
           start=mini;
           end=maxi;
       }

       if(temp->col+1<n){// temp me minimum element ka pointer store hai to bs vhi check kiya ki ager element exist krta hai to push kr do minheap me
           // yha bhi +1 isliye kiya hai because next element ka index n se kam hona chahihe
           maxi=max(maxi,a[temp->row][temp->col+1]);//max ko update kr diya aor iska minheap me push bhi kr diya aor at last max element from heap mil hi jayega
           //temp->col+1 +1 kiya to access the next element jo current hai uska next
           minheap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
       }
       else{
           break;
       }
   }
   return end-start+1;


}
O(N * K * log(K)), where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists. 

In worst case we may consider each and every element present in input which will take O(N * K)  time.
And for each time we are finding the minimum and maximum element present in consideration which will take O(log(K))
time as we will have K elements in Min heap( one from each list ) in our consideration. So total complexity will be O(N * K * log(K)).

Space Complexity
O(K), where ‘K’ is the number of lists. 

We are using a Min heap of size ‘K’. So space complexity will be O(K).

so here the time complexity is optimized

approach 2: using the point that the individual lists are already sorted

#include<bits/stdc++.h>
#include <limits.h>
#include <queue>



int kSorted(vector<vector<int>> &a, int k, int n) {
   vector<int>index(k,0);//index vector bnaya aor sare indices pe 0 dal diya aor pahle sbka first element store kiya and then
   //min element ko increase krte gye because max ko to decrease nhi kr skte because vo list already sorted hai

   int min_index=0;
   int ans=INT_MAX;

   while(index[min_index]<n){
       int mini=INT_MAX;
       int maxi=INT_MIN;
       for(int i=0;i<k;i++){
           if(mini>a[i][index[i]]){//use index[i] not min_index because hame yha to array ke elements ko access karna hai
               mini=a[i][index[i]];
               min_index=i;
           }
           if(maxi<a[i][index[i]]){
               maxi=a[i][index[i]];
           }
       }

       int len=maxi-mini+1;

       ans=min(ans,len);
       index[min_index]++;//then jo bhi min_index hoga use update kr do and at last ager ye >=n hua then it will terminate
   }

   return ans;

}


Time Complexity
O(N * K^2), where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists. 

In the worst case, we may consider each and every element present in input which will take O(N * K)  time.
And for each time we are finding the minimum and maximum element present in consideration which will take O(K)
time as we will have K elements ( one from each list ) in our consideration. So total complexity will be O(N * K^2)

Space Complexity
O(K), where ‘K’ is the number of lists. 

We are using an 'index' array of size ‘K’. So space complexity will be O(K).

but it will also cause tle so the above approach is perfectly correct




leetocdoe solution


    #include<bits/stdc++.h>
#include <limits.h>
#include <queue>

class Solution {

public:
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        
         int mini=INT_MAX;
    int maxi=INT_MIN;

    priority_queue<node*,vector<node*>,compare>minheap;

        //maintain max while processing first element of each array
   for(int i=0;i<k;i++){
      int element=nums[i][0];
      mini=min(mini,element);
      maxi=max(maxi,element);
      minheap.push(new node(element,i,0));
   }


   int start=mini,end=maxi;
    //process all the remaining element by increasing mini

   while(!minheap.empty()){
       node *temp=minheap.top();
       minheap.pop();
         //assign mini


       mini=temp->data;
       //update range

       if(maxi-mini<end-start){
           start=mini;
           end=maxi;
       }
        int row = temp->row, col = temp->col;
            //add next element infront of mini if within array
            if (col+1 < nums[row].size()){
                minHeap.push(new node(nums[row][col+1],row, col+1));
                maxi = max(maxi, nums[row][col+1]);
            }
       else{//one of the array is fully traveresed!!
           break;
       }
   }

   
   return {start,end};
    }
};
