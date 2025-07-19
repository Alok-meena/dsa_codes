39. Combination Sum
Solved
Medium
Topics
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40












solution 1

class Solution {
public:
    void solve(vector<int>&v,vector<vector<int>>&d,vector<int>&ans,int i,int n,int sum){
    if(sum==0){
      d.push_back(ans);
      return;
    }
    if(i>=n || sum<0){
       return;
    }

    for(int k=0;;k++){
        int new_sum=sum-v[i]*k;

        if(new_sum<0) break;

        for(int j=0;j<k;j++){
            ans.push_back(v[i]);
        }
        solve(v,d,ans,i+1,n,new_sum);

        for(int j=0;j<k;j++){
            ans.pop_back();
        }
    }
    
   
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>d;
        vector<int>ans;
        int sum=7;
        solve(candidates,d,ans,0,candidates.size(),target);
        return d;
    }
};

t.c:-O(2^k) where k>>>n


 or can also do 


 #include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&a,vector<vector<int>>&ans,vector<int>&output,int target,int i){
        if(target==0){
            ans.push_back(output);
            return;
        }

        if(i>=a.size() or target<0){
            return;
        }
        
        //include
        output.push_back(a[i]);
        //we are not increasing the index then it will take the current value again and again
        solve(a,ans,output,target-a[i],i);
        output.pop_back();

        // while(i+1<a.size() and a[i]==a[i+1]) i++; not require alright
       //to handle duplicates;

        //exclude
        solve(a,ans,output,target,i+1);
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>ans;
        
        vector<int>output;
        solve(A,ans,output,B,0);
        
        return ans;
    }

int main() {
    vector<int>v={1,1,2};
    sort(v.begin(),v.end());
    vector<vector<int>>ans=combinationSum(v,10);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


same 
