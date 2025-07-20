LeetCode Logo
Problem List
Debugging...
Debugging...









0
0Streaks
Now or Never!
DCC Badge

avatar
Avatar
Alok kumar meena
Access all features with our Premium subscription!
myLists
My Lists
notebook
Notebook
submissions
Submissions
progress
Progress
points
Points
Try New Features
Orders
My Playgrounds
Settings
Appearance
Sign Out
Premium
Description
Editorial
Editorial
Solutions
Solutions
Submissions
Submissions


Code
Test Result
Test Result
Testcase
1048. Longest String Chain
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
477,932/768.6K
Acceptance Rate
62.2%
Topics
icon
Companies
Hint 1
Hint 2
Discussion (79)

Choose a type



Copyright © 2025 LeetCode. All rights reserved.

7.6K


79


56 Online
C++
Auto





293031323334353637383940414243
class Solution {
public:
    bool checkPossible(string a,string b){
        if(a.length()!=b.length()+1) return false;
        
        int i=0,j=0;
        while(i<a.length()){
            if(a[i]==b[j]){
                i++;j++;
            }

Saved
Case 1
Case 2
Case 3

words =
["a","b","ba","bca","bda","bdca"]
Search questions











class Solution {
public:
    bool checkPossible(string a,string b){
        if(a.length()!=b.length()+1) return false;
        
        int i=0,j=0;
        while(i<a.length()){
            if(a[i]==b[j]){
                i++;j++;
            }
            else i++;
        }

        return i==a.length() and j==b.length();
    }

    int longestStrChain(vector<string>& words) {
         int n=words.size();

         sort(words.begin(),words.end(),[](string a,string b){
            return a.length()<b.length();
         });


        vector<int>dp(n,1);

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(words[i],words[prev]) and dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }

            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }

        return maxi;
    }
};
