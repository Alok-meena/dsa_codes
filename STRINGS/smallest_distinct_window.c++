Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"







1: brute force 

class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        set<char>s;
        
        for(auto i:str){
            s.insert(i);
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<str.length();i++){
            for(int len=1;len<=str.length();len++){
                set<char>s1(s.begin(),s.end());
                string S=str.substr(i,len);
                for(auto j:S){
                    if(s.find(j)!=s.end()){
                        s1.erase(j);
                    }
                }
                
                if(s1.empty()){
                    ans=min(ans,len);
                }
            }
        }
        
        return ans;
    }
};

t.c:-O(n^3) and s.c:-O(n)

2:optimal
