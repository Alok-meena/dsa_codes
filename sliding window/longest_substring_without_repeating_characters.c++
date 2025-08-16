3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.



brute force: t.c:-O(N^2) and s.c:-O(256)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=1;
        int n=s.length();

        if(n==0) return 0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            int j;
            for(j=i;j<n;j++){
                if(mp.find(s[j])==mp.end()){
                    mp[s[j]]++;
                }
                else{
                    break;
                }
            }

            len=max(len,j-i);
        }

        return len;
    }
};


optimizd: t.c:-O(2*n) and s.c:-O(256)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=1;
        int n=s.length();
        if(n==0) return 0;

        int l=0,r=0;
        unordered_map<char,int>freq;

        while(r<n){
            freq[s[r]]++;

            while(l<=r and freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }

            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};


more optimized : t.c:O(n) 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=1;
        int n=s.length();
        if(n==0) return 0;

        int l=0,r=0;
        unordered_map<char,int>hash;

        while(r<n){
            if(hash.find(s[r])!=hash.end()){
                l=max(l,hash[s[r]]+1); //because ex abba then for 2nd b l is already at 2 and if we do l=hash[s[r]]+1 then we are sending it back
                //which is wrong so do use max so that if it is anywhere ahead then remain there alright 
            }

            hash[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};

instead of storing count we can store index
