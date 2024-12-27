



class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        stack<char>st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]=='}' || s[i]==']' || s[i]==')'){
                if(st.empty()) return false;
                
                char ch=st.top();
                if(ch=='(' and s[i]==')'){
                    st.pop();
                }
                else if(ch=='{' and s[i]=='}'){
                    st.pop();
                }
                else if(ch=='[' and s[i]==']'){
                    st.pop();
                }
                else return false;
            }
        }
        
        return st.empty();
        
        
        
    }
};
