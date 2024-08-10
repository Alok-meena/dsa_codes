Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.




1:recursion

class Solution {
public:
    bool solve(int i,set<string>&dict,string s){
        if(i==s.length()){
            return 1;
        }
  //Both string temp = ""; and string temp; will give you an empty string to start with. The difference is mainly in clarity and style, not in behavior.
        string temp;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
               //aor dekho ex dic=["ab","cd"] s="abcd" to start me ab milega dic me and j=1 then correect so
               //j+1=1+1=2 pass hoga i me means i=2 se start hoga to ab ka dekh liya ab cd ko search kiya jab vo bhi mila to i=4 that's all
              // this is the base condition so return 1 aor ese answer aa jayega
               if(solve(j+1,dict,s)) return 1;d//j+1 to yha ham i me pass kr rhe hai means i indirectly update ho rha hai yha pe
               //to bas ager dict me temp hai to fir true return hoga and then next part ke liye call hoga
            }
        }

        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }

        return solve(0,st,s);
    }
};



Time Complexity: O(2^m) in the worst case, where m is the length of the string s.
Space Complexity: O(m) due to the recursion stack.




2:dp with memo

class Solution {
public:
    bool solve(int i,set<string>&dict,string s,vector<int>&dp){
        if(i==s.length()){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];

        string temp;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
               if(solve(j+1,dict,s,dp)){//j+1 means it's value is passed in the i variable
                return 1;
               }
            }
        }

        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }

        return solve(0,st,s,dp);
    }
};

Time Complexity: O(m^2) where m is the length of the string s.
Space Complexity: O(m) where m is the length of the string s.

can also solve this ques directly using the vector but it takes more time as set operations take logn time

#include <bits/stdc++.h> 
#include <vector>
bool solve(int i, vector<string>& dict, string s, vector<int>& dp) {
    if (i == s.length()) {
        return 1;
    }
    if (dp[i] != -1) return dp[i];

    string temp;
    for (int j = i; j < s.length(); j++) {
        temp += s[j];
        if (find(dict.begin(), dict.end(), temp) != dict.end()) {
            if (solve(j + 1, dict, s, dp)) {
                return 1;
            }
        }
    }

    return dp[i] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
     vector<int>dp(target.length(),-1);
     return solve(0,arr,target,dp);
}
