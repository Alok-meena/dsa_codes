
User Accepted:15186
User Tried:15909
Total Accepted:15712
Total Submissions:19720
Difficulty:Easy
You are given a binary string s and an integer k.

A binary string satisfies the k-constraint if either of the following conditions holds:

The number of 0's in the string is at most k.
The number of 1's in the string is at most k.
Return an integer denoting the number of substrings of s that satisfy the k-constraint.

 

Example 1:

Input: s = "10101", k = 1

Output: 12

Explanation:

Every substring of s except the substrings "1010", "10101", and "0101" satisfies the k-constraint.

Example 2:

Input: s = "1010101", k = 2

Output: 25

Explanation:

Every substring of s except the substrings with a length greater than 5 satisfies the k-constraint.

Example 3:

Input: s = "11111", k = 1

Output: 15

Explanation:

All substrings of s satisfy the k-constraint.

 

Constraints:

1 <= s.length <= 50
1 <= k <= s.length
s[i] is either '0' or '1'.










class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        vector<string>str;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                str.push_back(s.substr(i,j-i+1));
            }
        }
        
        
        int count=0;
        
        for(auto i:str){
            int zero=0;
            int one=0;
            int j=0;
            while(j<i.length()){
                if(i[j]=='1') one++;
                else zero++;
                j++;
            }
            cout<<i<<" ";
            
            if(zero<=k || one<=k) count++;
        }
        
        return count;
    }
};
