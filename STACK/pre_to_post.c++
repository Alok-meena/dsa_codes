// User function Template for C++

class Solution {
  public:
    string pretopost(string exp) {
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
                
                string ans=t1+t2+i;
                s.push(ans);
            }
        }
        
        return s.top();
    }
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(),pre_exp.end());
        return pretopost(pre_exp);
    }
};
