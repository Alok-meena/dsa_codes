402. Remove K Digits
Solved
Medium
Topics
premium lock icon
Companies
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.







class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>s;

        for(auto i:num){
            while(!s.empty() and k>0 and ((s.top()-'0')>(i-'0'))){
                s.pop();
                k--;
            }
            s.push(i);
        }

        while(!s.empty() and k>0){
            s.pop();
            k--;
        }

        if(s.empty()) return "0";

        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        while(!ans.empty() and ans.back()=='0'){
            ans.pop_back();
        }

        if(ans.empty()) return "0";
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

t.c:-O(N) and s.c:-O(n) explained in 2nd copy
