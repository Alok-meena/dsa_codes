// User function Template for C++

class Solution {
  public:
    string posttopre(string exp) {
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
                
                string ans=i+t2+t1;
                s.push(ans);
            }
        }
        
        return s.top();
    }
    string postToPre(string post_exp) {
        // Write your code here
        return posttopre(post_exp);
    }
};
