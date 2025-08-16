76. Minimum Window Substring
Attempted
Hard
Topics
premium lock icon
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


brute :

i tried

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";

        string ans=s;

        int n=s.length();

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(auto i:t) mp[i]++;
            string sub="";
            int cnt=0;
            for(int j=i;j<n;j++){
                sub+=s[j];
                if(mp[s[j]]>0) cnt++;
                mp[s[j]]--;
                if(cnt==t.length() and sub.length()<ans.length()){
                    ans=sub;
                }
                else if(cnt >t.length()) break;
            }
        }

        return ans;
    }
};


but this is correct:

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        int n=s.length(),m=t.length();

        string ans=s;

        int startidx=-1;

        int minlen=INT_MAX;


        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;

            for(auto i:t) mp[i]++;
            int cnt=0;
            for(int j=i;j<n;j++){
                if(mp[s[j]]>0) cnt++;
                mp[s[j]]--;
                if(cnt==m){
                    if((j-i+1)<minlen){
                        minlen=j-i+1;
                        startidx=i;
                        break;
                    }
                }
            }
        }
        
        if(startidx==-1) return "";
        return s.substr(startidx,minlen);
    }
};


optimized:

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        int n=s.length(),m=t.length();

        string ans=s;

        int startidx=-1;

        int minlen=INT_MAX;

        int l=0,r=0;

        unordered_map<char,int>mp;
        for(auto i:t) mp[i]++;
        int cnt=0;

        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            while(cnt==m){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    startidx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        if(startidx==-1) return "";
        return s.substr(startidx,minlen);
    }
};
