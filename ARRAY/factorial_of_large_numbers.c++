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


class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        int factorial=1;
        vector<int>ans;
        ans.push_back(1);
        int i=1;
        while(i<=n){
            int carry=0;
            for(int j=0;j<ans.size();j++){
                int val=ans[j]*i+carry;
                ans[j]=val%10;
                carry=val/10;
            }
            
            while(carry){
                ans.push_back(carry%10);
                carry/=10;
            }
            i++;
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};



we can use string also
#include <bits/stdc++.h>
using namespace std;

string solve(int n) {
    if (n == 0 || n == 1) return "1"; // Base case: 0! = 1! = 1
    
    // Initialize result as a string with "1" (1! = 1)
    string fact = "1";
    
    // Compute factorial
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        // Multiply current result with i
        for (int j = 0; j < fact.length(); j++) {
            int product = (fact[j] - '0') * i + carry; // Convert char to int, multiply, add carry
            fact[j] = (product % 10) + '0'; // Store the last digit of the product in fact
            carry = product / 10; // Update carry
        }
        
        // Handle remaining carry
        while (carry) {
            fact.push_back((carry % 10) + '0'); // Append the carry to the result
            carry /= 10;
        }
    }
    
    // Reverse the string to get the final result
    reverse(fact.begin(), fact.end());
    return fact;
}

string calculateFactorial(int n) {
    return solve(n);
}




