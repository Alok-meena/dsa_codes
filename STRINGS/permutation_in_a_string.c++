567. Permutation in String
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.







class Solution {
public:
    bool checkequal(vector<int>&a,vector<int>&b){
        int i=0;

        while(i<26){
            if(a[i]!=b[i]) return false;
            i++;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);

        for(int i=0;i<s1.length();i++){
            int ch=s1[i]-'a';
            count1[ch]++;
        }

        int windowsize=s1.length();
        int i=0;

        while(i<windowsize and i<s2.length()){
            int ch=s2[i]-'a';
            count2[ch]++;
            i++;
        }

        if(checkequal(count1,count2)) return 1;

        while(i<s2.length()){
            int idx1=s2[i]-'a';
            count2[idx1]++;

            int idx2=s2[i-windowsize]-'a';
            count2[idx2]--;

            if(checkequal(count1,count2)) return true;
            i++;
        }

        return false;
    }
};
