Word Break
Difficulty: MediumAccuracy: 40.86%Submissions: 161K+Points: 4
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :

Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".
Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: s can be breakdown as "i like gfg".
Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: s cannot be formed using dictionary[] words.
Constraints:
1 ≤ s.size() ≤ 3000
1 ≤ dictionary.size() ≤ 1000
1 ≤ dictionary[i].size() ≤ 100






class Solution {
  public:
    bool solve(int i,string s,unordered_set<string>&st,vector<int>&dp){
        if(i==s.length()) return true;
        
        if(dp[i]!=-1) return dp[i];
        
        string temp;
        
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(st.count(temp)){
                if(solve(j+1,s,st,dp)) return dp[i]=true;
            }
        }
        
        return dp[i]=false;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n=s.length();
        
        vector<int>dp(n+1,-1);
        
        unordered_set<string>st;
        for(auto i:dictionary){
            st.insert(i);
        }
        
        return solve(0,s,st,dp);
    }
};
