
Code


Test Result
Testcase
Testcase
1358. Number of Substrings Containing All Three Characters
Attempted
Medium
Topics
premium lock icon
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.


brute: genearte all substring t.c:-O(n^2) and s.c:-O(3)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;

        int n=s.length();

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;

            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.find('a')!=mp.end() and mp.find('b')!=mp.end() and mp.find('c')!=mp.end()) count++;
            }
        }

        return count;
    }
};

optimized:


class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;

        int n=s.length();

        vector<int>lastseen(3,-1);

        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;

            if(lastseen[0]!=-1 and lastseen[1]!=-1 and lastseen[2]!=-1){
                count=count+(1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }
        }

        return count;
    }
};

t.c:-O(n) alright
