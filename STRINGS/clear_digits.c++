3174. Clear Digits
Solved
Easy
Topics
Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.



class Solution {
public:
    string clearDigits(string s) {
        stack<char>a;
        
        for(auto ch:s){
            if(isdigit(ch)){
                if(!a.empty()){
                    a.pop();
                }
            }
            else{
                a.push(ch);
            }
        }

        string ans;
        while(!a.empty()){
            ans.push_back(a.top());
            a.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};

t.c and s.c:-O(n)
