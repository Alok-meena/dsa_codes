class Solution {
  public:
    int priority(char a){
        if(a=='^') return 3;
        if(a=='*' or a=='/') return 2;
        if(a=='+' or a=='-') return 1;
        return 0;
    }
    string infixToPostfix(string& s) {
        // code here
        string ans;
        stack<char>st;
        
        for(auto i:s){
            if(isalnum(i)){
                ans.push_back(i);
            }
            else if(i=='('){
                st.push(i);
            }
            else if(i==')'){
                while(!st.empty() and st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() and priority(i)<=priority(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(i);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};



dekho a+b*c-(d-e*e) isme baki sb shi ager s.top() ki priority jyada hai to pop krte rho jab tk km priority nhi milti aor km hai to push kr do bs and
ager close bracket aaya to sb khuch ans me dal do jb tk close brace nhi ata alright
