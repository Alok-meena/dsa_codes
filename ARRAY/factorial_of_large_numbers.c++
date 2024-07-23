Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

Example 1:

Input: N = 5
Output: [1,2,0]
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: [3,6,2,8,8,0,0]
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800






class Solution {
public:
    
    vector<int> solve(int n){
        vector<int>fact;
        fact.push_back(1);
        
        for(int i=2;i<=n;i++){
            int carry=0;
            for(int j=0;j<fact.size();j++){
                int product=fact[j]*i;
                product+=carry;
                carry=product/10;
                fact[j]=product%10;
            }
            
            if(carry){
                while(carry){
                    fact.push_back(carry%10);
                    carry/=10;
                }
            }
        }
        
        reverse(fact.begin(),fact.end());
        return fact;
    }
    vector<int> factorial(int N){
        // code here
        vector<int>ans;
        return solve(N);
    }
};



Time Complexity: O(N2) - The outer loop runs for N times, and for each iteration, there can be up to N multiplications.
Space Complexity: O(N) 
