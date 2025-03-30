Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

Examples :

Input: str = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic substring is "aabbaa".
Input: str = "abc"
Output: a
Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.

brute force 

  // Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


    bool check(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string a=s.substr(i,j-i+1);
                if(check(a)){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }


int main() {
    // Write C++ code here
    string a="abcddc";
    cout<<longestPalindrome(a);
}

t.c:- O(n^3)

and in this only to return the string use this code

class Solution {
public:
    bool check(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        int maxlen=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string a=s.substr(i,j-i+1);
                if(check(a)){
                    if(maxlen<j-i+1){
                        ans=a;
                        maxlen=j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};


1st : using longest common substring in this

class Solution {
  public:
    string longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxlength=0;
        int endIndex=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>maxlength){
                        maxlength=dp[i][j];
                        endIndex=i;
                    }
                }
            }
        }
        
        string s=s1.substr(endIndex - maxlength, maxlength);//we did this as we are starting from index 1
        return s;
    }
    string longestPalin(string S) {
        // code here
        string s=S;
        reverse(s.begin(),s.end());
        
        return longestCommonSubstr(S,s);
        
    }
};

but this is givig error

  class Solution {
public:
    string longestPalin(string S) {
        int n = S.length();
        if (n == 0) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            // Check for odd-length palindromes
            int len1 = expandAroundCenter(S, i, i);
            // Check for even-length palindromes
            int len2 = expandAroundCenter(S, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2;
            }
        }

        return S.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // Length of the current palindromic substring
        return right - left - 1;
    }
};


we can also omit that formula of start by doing so



class Solution {
public:
    string longestPalin(string S) {
        int n = S.length();
        if (n == 0) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            // Check for odd-length palindromes
            pair<int,int>left= expandAroundCenter(S, i, i);
            // Check for even-length palindromes
            pair<int,int>right= expandAroundCenter(S, i, i + 1);
            
            int len1=left.first;
            int len2=right.first;

            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                if(len==len1){
                    start=left.second;
                }
                else{
                    start=right.second;
                }
            }
        }
        
        return S.substr(start, maxLength); //here start is the index and 2nd parameter is the length from that index to takeout
    }

private:
    pair<int,int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // Length of the current palindromic substring
        int len=right - left - 1;
        int start=left+1;
        return {len,start};
    }
};

Efficiency: This approach runs in O(n^2) time complexity and O(1) space complexity, making it efficient and straightforward for this problem.
