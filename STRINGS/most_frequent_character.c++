Most Frequent Character
Difficulty: BasicAccuracy: 53.55%Submissions: 122K+Points: 1Average Time: 30m
Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

Examples:

Input: s = "testsample"
Output: 'e'
Explanation: e is the character which is having the highest frequency.
Input: s = "output"
Output: 't'
Explanation:  t and u are the characters with the same frequency, but t is lexicographically smaller.
Constraints:
1 ≤ |s| ≤ 100







class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        int maxi=INT_MIN;
        char ans='z';
        
        unordered_map<char,int>m;
        for(auto i:s) m[i]++;
        
        vector<char>ch;
        
        for(auto i:m){
            if(i.second>=maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        
        for(auto i:m){
            if(i.second==maxi){
                ch.push_back(i.first);
            }
        }
        
        sort(ch.begin(),ch.end());
        return ch[0];
    }
};
