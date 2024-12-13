
class Solution {
public:
void solve(vector<int>&a,int n,vector<vector<int>>&ans,int i,vector<int>&output){
   if(i==n){
      ans.push_back(output);
      return;
   }


   //exclude
   solve(a,n,ans,i+1,output);

   //include
   output.push_back(a[i]);
   solve(a,n,ans,i+1,output);
   output.pop_back();
}


    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         int n=nums.size();
   vector<int>output;

   solve(nums,n,ans,0,output);
return ans;
    }
};


t.c:-O(2^n) and s.c:-O(n*2^n)

here we use backtracking because output is passed by reference so no new copy will be created if did pass by value so backtracking is not required as for each call new copy of output will be created
