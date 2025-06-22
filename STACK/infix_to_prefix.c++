#include <bits/stdc++.h>
using namespace std;
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

    int main(){
        string a="a+b-c*(d-e)";
        reverse(a.begin(),a.end());
        for(auto &i:a){
            if(i=='(') i=')';
            else if(i==')') i='(';
        }
        string ans=infixToPostfix(a);
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
