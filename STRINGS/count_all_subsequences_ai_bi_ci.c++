

Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7

 

Example 1:

Input:
S = "abbc"
Output: 3
Explanation: Subsequences are abc, abc and abbc.

Example 2:

Input:
S = "abcabc"
Output: 7
Explanation: Subsequences are abc, abc,
abbc, aabc abcc, abc and abc.


t.c:-O(n) and s.c:-O(1)






#define mod 1000000007
class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        long long int a=0;
        long long int b=0;
        long long int c=0;
        
        for(auto i:s){
            if(i=='a') a=(2*a+1)%mod;//to pahle ke a ke sath aor ya vo akela to 2a and current a akela ho skta hai that's why this formula
            else if(i=='b') b=(2*b+a)%mod;//and yha +a kiya taki pichle sabhi a me end me b jud skta hai and 2b kiya as new b ke sath combination bnege
            else if(i=='c') c=(2*c+b)%mod;//and yah bhi 2c +a kiya as c can only come after b so that's why 
        }
        
        return c%mod;
    }
};
