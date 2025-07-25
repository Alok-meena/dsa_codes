 Redundant Brackets
Easy
40/40
Average time to solve is 15m
280 upvotes
Asked in companies
Problem statement
Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

For Example :
((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
While (a + (b*c)) does not have any pair of redundant brackets. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50
3 <= |S| <= 10^4

Time Limit: 1 sec
Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes
Explanation of Sample Input 1 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 


In the second test case, the brackets around the alphabet ‘c’( index 8 and index 10) are redundant. Hence the output is “Yes”.
Sample Input 2 :
2
(a*b+(c/d))
((a/b))
Sample Output 2 :
No
Yes
Explanation of Sample Input 2 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 


In the second test case, the brackets around the subexpression “(a+b)” ( index 0 and index 6) are redundant. Hence the output is “Yes”.


simplest

#include <bits/stdc++.h> 

bool isoperator(char ch){
    return ch=='+' or ch=='-' or ch=='/' or ch=='*';
}
bool findRedundantBrackets(string &S)
{
    // Write your code here.
    stack<char>s;

    for(auto i:S){
        if(i=='(' or isoperator(i)){
            s.push(i);
        }
        else if(i==')'){
            if(isoperator(s.top())) s.pop();
            else return true;

            while(!s.empty() and s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }

    return false;
}

alright bs kya hai open h dal do operator h dal do closing h to top operator h no redundant and then pop the open bracket in stack also continue



#include <bits/stdc++.h> 


bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<int>st;

    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            char ch=st.top();
            bool isredundant=true;
            while(st.top()!='('){
               //to dekho (a) to ye redundant backet hai because brackets ki need hi nhi hai yha pe to okk 
             // but if open bracket se pahle ager koi bhi operator hua to ye redundant nhi hoga okk 
                if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                    isredundant=false;
                }
                st.pop();
            }
            if(isredundant){
                return true;
            }
            st.pop();
        }
        
    }

    return false;

    return !st.empty();
}


class Solution {
  public:
    bool isoperator(char i){
        if(i=='+' or i=='-' or i=='*' or i=='/') return true;
        return false;
    }
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        
        for(auto i:s){
            if(i=='('){
                st.push(i);
            }
            else if(isoperator(i)){
                st.push(i);
            }
            else if(i==')'){
                bool isop=false;
                
                while(!st.empty() and st.top()!='('){
                    if(isoperator(st.top())) isop=true;
                    st.pop();
                }
                
                st.pop();
                
                if(st.empty() and !isop){
                    return true;
                }
                
                if(!st.empty() and !isop){
                    return true;
                }
            }
        }
        
        return false;
    }
};
