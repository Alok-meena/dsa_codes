Stream First Non-repeating
Difficulty: MediumAccuracy: 31.65%Submissions: 212K+Points: 4
Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every you need to consider the string from starting position till the ith position.
 

Examples:

Input: s = "aabc"
Output: "a#bb"
Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow- "a" - first non-repeating character is 'a' "aa" - no non-repeating character so '#' "aab" - first non-repeating character is 'b' "aabc" - there are two non repeating characters 'b' and 'c',  first non-repeating character is 'b' because 'b' comes before 'c' in the stream.
Input: s = "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow- "z" - first non-repeating character is 'z' "zz" - no non-repeating character so '#' 
Input: s = "bb"
Output: "b#"
Explanation: For every character first non repeating character is as follow- "b" - first non-repeating character is 'b' "bb" - no non-repeating character so '#'  
Constraints:
1 <= s.size()<= 105
'a' <= s[i] <= 'z'


class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        map<char,int>mp;
        queue<char>q;
        
        // for(auto i:s){
        //     mp[i]++;
        // }
        
        string ans;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            q.push(s[i]);
            
            while(!q.empty() and mp[q.front()]>1){
                q.pop();
            }
            
            if(q.size()>0){
                ans.push_back(q.front());
            }
            else ans.push_back('#');
        }
        
        return ans;
        
        
    }
};

simple sa code tha char add kor aor count bdao jab tk count>1 na ho push krte jaoo o/w pop and if queue size 0 then push #

t.c:-O(n) and s.c:-(n)
