
Code
Test Result
Testcase
Testcase
139. Word Break
Solved
Medium
Topics
premium lock icon
Companies
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
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.




class Solution {
public:
    bool solve(int start,string &s,unordered_set<string>&dict,vector<int>&dp){
        if(start==s.length()) return true;

        if(dp[start]!=-1) return dp[start];
        for(int end=start;end<s.length();end++){
            string word=s.substr(start,end-start+1);
            if(dict.count(word)){
                if(solve(end+1,s,dict,dp)) return dp[start]=true;
            }
        }

        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,dict,dp);
    }
};

without dp t.c:-O(expo)
with memo t.c:-O(n^2) and s.c:-O(n)
