// User function Template for C++

class Solution {
  public:
    // User function Template for C++
    string preftoinfix(string exp) {
        // Write your code here
        stack<string>s;
        
        for(auto i:exp){
            if(isalnum(i)){
                s.push(string(1,i));
            }
            else{
                string t1=s.top();
                s.pop();
                string t2=s.top();
                s.pop();
                
                string ans='('+t1+i+t2+')';
                s.push(ans);
            }
        }
        
        return s.top();
    }

    string preToInfix(string pre_exp) {
        // Write your code here
        reverse(pre_exp.begin(),pre_exp.end());
        return preftoinfix(pre_exp);
    }
};
