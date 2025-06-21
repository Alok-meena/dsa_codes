



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



bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>S;

    for(auto i:s){
        if(i=='(' or i=='{' or i=='['){
            S.push(i);
        }
        else{
            if(S.empty()) return false;
            char ch=S.top();
            if((i==')' and ch=='(') or (i=='}' and ch=='{') or (i==']' and ch=='[')){
                S.pop();
            }
            else return false;
        }
    }

    if(S.empty()) return true;
    return false;
}
