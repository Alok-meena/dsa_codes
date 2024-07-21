


Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25








class Solution {
private:
  
    double solve(double x,int n){
        double ans=1;

        while(n>0){
            if(n%2==1){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n=n>>1;
            }
        }
        return ans;
    }

public:
    double myPow(double x, int n) {
        // long long absN = abs(static_cast<long long>(n));
        // double result = solve(x, absN);
        // return (n < 0) ? 1.0 / result : result;
        if(x==0) return 0;
        if(n==0) return 1;

        if(n==INT_MIN){
            if(x==1) return 1;
            if(x==-1) return 1;
            return 0;
        }
        long long v=n;
        if(n<0){
            x=1/x;
            v=-v;
        }
        double ans=solve(x,v);
        return ans;
    }
};
