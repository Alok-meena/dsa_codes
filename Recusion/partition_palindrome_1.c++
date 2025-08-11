131. Palindrome Partitioning
Solved
Medium
Topics
premium lock icon
Companies
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,174,754/1.6M
Acceptance Rate
72.6%


t.c:-O(n^2 * 2^n) and s.c:-O(N) due to recursion 

here in t.c either we have to make the cur ot not so exponentail and n^2 as scanning the string and checking for palindrome 


class Solution {
public:
    bool ispalindrome(int i,int j,string s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void solve(int idx,vector<string>path,vector<vector<string>>&ans,string s){
        if(idx>=s.length()){
            ans.push_back(path);
            return;
        }

        for(int j=idx;j<s.length();j++){
            if(ispalindrome(idx,j,s)){
                path.push_back(s.substr(idx,j-idx+1));
                solve(j+1,path,ans,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;

        vector<string>path;

        solve(0,path,ans,s);

        return ans;
    }
};
