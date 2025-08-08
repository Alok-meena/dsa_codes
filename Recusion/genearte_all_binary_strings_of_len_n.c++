
// User function Template for C++

class Solution {
  public:
    void solve(int lastdigit,int n,string s,vector<string>&ans){
        if(n==0){
            ans.push_back(s);
            return;
        }
        
        solve(0,n-1,s+"0",ans);
        
        solve(0,n-1,s+"1",ans);
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string>ans;
        
        string s;
        
        solve(0,num,s,ans);
        
        return ans;
    }
};
