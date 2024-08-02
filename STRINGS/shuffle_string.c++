You are given a string s and an integer array indices of the same length.
The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.



1: brute force


class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        for(int i=0;i<s.length();i++){
            string temp="";
            for(int j=0;j<indices.size();j++){
                if(i==indices[j]){
                    temp+=s[j];
                    break;
                }
            }
            ans+=temp;
        }

        return ans;

    }
};


t.c:-O(n^2) and s.c:-O(n)


2: O(nlogn) t.c and s.c:-O(n)

class Solution {
public:
    static bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second<b.second;
    }
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        
        vector<pair<char,int>>v;
        for(int i=0;i<indices.size();i++){
            v.push_back(make_pair(s[i],indices[i]));
        }

        sort(v.begin(),v.end(),cmp);

        for(auto i:v){
            ans+=i.first; //to jab i ne access kiya hoga to ek pair access kiya hoga 
        }

        return ans;

    }
};
