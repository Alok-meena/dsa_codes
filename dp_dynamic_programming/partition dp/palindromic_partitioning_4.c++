
Code
Test Result
Testcase
Testcase
1745. Palindrome Partitioning IV
Attempted
Hard
Topics
premium lock icon
Companies
Hint
Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.






class Solution {
public:
     bool ispalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }

    bool checkPartitioning(string s) {
       int n=s.length();

       for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(ispalindrome(0,i,s) and ispalindrome(i+1,j,s) and ispalindrome(j+1,n-1,s)) return true;
        }
       }
       return false;
    }
};


we have to try all possible substrings and check if any non empty 3 substrings exist or not
