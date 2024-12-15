

class Solution {
public:
    void solve(vector<int>&a,int n,set<vector<int>>&ans,int i,vector<int>&output){
   if(i==n){
      ans.insert(output);
      return;
   }


   //exclude
   solve(a,n,ans,i+1,output);

   //include
   output.push_back(a[i]);
   solve(a,n,ans,i+1,output);
   output.pop_back();
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            set<vector<int>>ans;
            int n=nums.size();
    vector<int>output;
    sort(nums.begin(),nums.end());

    solve(nums,n,ans,0,output);
    vector<vector<int>>v(ans.begin(),ans.end());
    return v;
        }
    
};


t.c:-O(2^nlog(2^n)) log is introduced due to set okk
