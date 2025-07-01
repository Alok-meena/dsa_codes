
Minimum swap required to convert binary tree to binary search tree
Difficulty: HardAccuracy: 62.15%Submissions: 7K+Points: 8
Given an array arr[] which represents a Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
The task is to find the minimum number of swaps required to convert it into a Binary Search Tree. 

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 11]
Output: 3
Explanation: 
Binary tree of the given array:
 
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
 
So, minimum 3 swaps are required.
Input: arr[] = [1, 2, 3]
Explanation: 
Binary tree of the given array:
 
After swapping node 1 with node 2, obtain the below binary search tree:

Output: 1
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 109






t.c:-O(nlogn) due to sorting and s.c:-O(n) alright


are bhai khuch nhi hai ager tree ka root diya hota na to baye hath ka kehl tha inorder store kr lo and then apply on the array

but given is that if ith node is parent then left is 2*i+1 and right is 2*i+2 th index alright bs we used that in inorder function that's it



// User function Template for C++
class Solution {
  public:
    int solve(vector<int>& nums) {
        // Code here
        vector<pair<int,int>>v;
	    for(int i=0;i<nums.size();i++){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    int count=0;

      //ham ulta kam kr rhe hai means sorted array se given order me convert krne me bhi same no. of swaps lgenge
	    
	    for(int i=0;i<nums.size();i++){
	        if(v[i].second==i){
	            continue;
	        }
	        else{
	            count++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return count;
    }
    
    void inorder(vector<int>&arr,vector<int>&in,int idx){
        if(idx>=arr.size()) return;
        
        inorder(arr,in,2*idx+1);
        in.push_back(arr[idx]);
        inorder(arr,in,2*idx+2);
    }
    int minSwaps(vector<int>& arr) {
        // Write your code here
        vector<int>in;
        inorder(arr,in,0);
        return solve(in);
    }
};
