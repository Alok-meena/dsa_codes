Valid Substring
Difficulty: MediumAccuracy: 23.37%Submissions: 128K+Points: 4
Given a string s consisting only of opening and closing parentheses ( and ), find the length of the longest valid (well-formed) parentheses substring.

Note: The length of the smallest valid substring () is 2.

Examples:

Input: s = "(()("
Output: 2
Explanation: The longest valid substring is (). Its length is 2. 
Input: s = "()(())("
Output: 6
Explanation: The longest valid substring is ()(()). Its length is 6.
Input: s = "(()())"
Output: 6
Explanation: The longest valid substring is (()()). Its length is 6.
Constraints:
1 <= s.size() <= 105
s[i] = { '(' , ')' }










class Solution {
  public:
    int findMaxLen(string& s) {
        // code here
        int max_len=0;
        stack<int>st;
        
        st.push(-1); // -1 dala taki ager stack empty bhi ho to s.top() nikalne me error na aaye alright and rest u can check by dry run
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                
                if(st.empty()){
                    st.push(i);
                }
                else{
                    max_len=max(max_len,i-st.top());
                }
            }
        } 
        
        return max_len;
    }
};

t.c:-O(n) and s.c:-O(n)
