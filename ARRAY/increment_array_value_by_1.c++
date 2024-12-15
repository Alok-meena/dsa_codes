


way one 
#include <bits/stdc++.h>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        string s;
        for(auto i:digits){
            s.push_back('0'+i);
        }

        
        int digit=stoi(s);
        digit++;
        string new_string=to_string(digit);

        for(auto i:new_string){
            int val=i-'0';
            ans.push_back(val);
        }

        return ans;
    }
};

stoi is out of bound so not suitable for large input
t.c:-O(n) 



t.c:-O(n) 

better solution is 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int n=digits.size()-1;

        int carry=1;
        //initially carry 1 kiya for incrementing

        for(int i=n;i>=0;i--){
            int sum=digits[i]+carry;
            ans.push_back(sum%10);
            carry=sum/10;
        }

        //while loop necessary as the carry can be greater than 10 okk

        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }

        //just reverse the ans then
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
