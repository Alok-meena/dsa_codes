40. Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30





same code just to avoid duplicate values we skip the duplicates after sorting 

it gives tle


class Solution {
public:
    void solve(vector<int>&v,vector<int>&ans,int i,int n,int sum,vector<vector<int>>&d){
    if(sum==0){
      d.push_back(ans);
      return;
    }
    if(i>=n){
       return;
    }
    
    //include
    ans.push_back(v[i]);
    solve(v,ans,i+1,n,sum-v[i],d);
    ans.pop_back();

     //this is required because duplicate combinations are not accepted that's why this is used

     //The duplicates are avoided only within a single combination, not across all combinations. Let me clarify this further

     //means ye only single combination me duplicates avoid kr rha hai baki hm duplicates ko alag alag combinations me use kr skte hai okkkk
    while(i+1<n && v[i]==v[i+1]){
        i++;
    }
    
    //exclude
    solve(v,ans,i+1,n,sum,d);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>d;
        vector<int>ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,0,n,target,d);
        return d;
    }
};

Input
candidates =
[10,1,2,7,6,1,5]
target =
8
Output
[[1,1,6],[1,2,5],[1,7],[1,2,5],[1,7],[2,6]]  //so to remove the duplicate ans we used that while loop and sorting
Expected
[[1,1,6],[1,2,5],[1,7],[2,6]]




optimized 


class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& current, int index, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Prune unnecessary branches
            if (candidates[i] > target) break;

            // Include the current element
            current.push_back(candidates[i]);
            solve(candidates, current, i + 1, target - candidates[i], result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort to handle duplicates and enable pruning
        sort(candidates.begin(), candidates.end());

        solve(candidates, current, 0, target, result);
        return result;
    }
};

t.c:-O(2^n)



or this is also correct


#include <bits/stdc++.h>
using namespace std;

void solve(int idx,vector<vector<int>>&ans,vector<int>&output,vector<int>&v,int target){
    if(idx>=v.size()){
        int sum=accumulate(output.begin(),output.end(),0);
        if(sum==target){
            ans.push_back(output);
        }
        return;
    }

    //exclude
    solve(idx+1,ans,output,v,target);

    //include
    output.push_back(v[idx]);
    solve(idx+1,ans,output,v,target);
    output.pop_back();
}

int main(){
    vector<int>v={1,2,4,7};

    int target=7;

    vector<vector<int>>ans;
    vector<int>output;

    solve(0,ans,output,v,target);

    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

but instead of this use method in which till sum becomes zero
