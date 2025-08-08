1922. Count Good Numbers
Solved
Medium
Topics
premium lock icon
Companies
Hint
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015



brute force:  t.c:-O(10^n * n) and s.c:-O(n)


class Solution {
public:
    int mod=1e9+7;
    int power(int x,int n){
        long long ans=1;
        while(n>0){
            if(n&1){
                ans=(1LL*ans*x)%mod;
                n=n-1;
            }
            else{
                x=(1LL*x*x)%mod;
                n=n/2;
            }
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long total = power(10, n);
        int ans = 0;

        for (int i = 0; i < total; i++) {
            string s = to_string(i);
            while (s.length() < n) s = "0" + s; // pad with leading 0s

            bool isGood = true;
            for (int j = 0; j < s.size(); j++) {
                int digit = s[j] - '0';
                if (j % 2 == 0 && digit % 2 != 0) isGood = false;
                if (j % 2 == 1 && !(digit == 2 || digit == 3 || digit == 5 || digit == 7)) isGood = false;
            }

            if (isGood) ans = (ans + 1) % mod;
        }

        return ans;
    }
};


optimized:

t.c:-O(5^(n+1/2) * 4^(n/2)) and s.c:-O(1)

class Solution {
public:
    int mod=1e9+7;
    long long power(long long x,long long n){
        long long ans=1;
        while(n>0){
            if(n&1){
                ans=(ans*x)%mod;
                n=n-1;
            }
            else{
                x=(x*x)%mod;
                n=n/2;
            }
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
       long long evenpos=(n+1)/2;
       long long oddpos=(n)/2;
       long long a=power(5,evenpos)%mod;
       long long b=power(4,oddpos)%mod;
       long long ans=(a*b)%mod;
       return ans;
    }
};


because on even indices total even possible 0 2 4 6 8 -> 5 choices and for prime 2 3 5 7 -> 4 choices so if x even position and y odd position

total possible ans = 5^x * 4^y so we have calculated the power separately using loop as the ans can  be very long alright not wit pow function
