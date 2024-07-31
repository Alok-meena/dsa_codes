Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

Example:

Input: S = “geeksforgeeks”
Output:
e, count = 4
g, count = 2
k, count = 2
s, count = 2

Explanation: g occurs 2 times in the string, k occurs 2 times in the string, s occurs 2 times in the string while e occurs 4 times in the string rest of the characters have unique occurrences.


1: t.c:-O(n) and s.c:-O(n)


#include <bits/stdc++.h> 
#include <unordered_map>

vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.
    vector<pair<char,int>>ans;

    unordered_map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }

    for(auto i:mp){
        if(i.second>1){
            ans.push_back({i.first,i.second});
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}
