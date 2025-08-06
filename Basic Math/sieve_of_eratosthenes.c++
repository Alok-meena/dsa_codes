Sieve of Eratosthenes
Difficulty: MediumAccuracy: 47.43%Submissions: 67K+Points: 4
Given a positive integer n, calculate and return all prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm.
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

Examples:

Input: n = 10
Output: [2, 3, 5, 7]
Explanation: Prime numbers less than equal to 10 are 2, 3, 5 and 7.
Input: n = 35
Output: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
Explanation: Prime numbers less than equal to 35 are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 and 31.
Constraints:
1 ≤ n ≤ 104



brute force:

t.c:-O(n*sqrt(n)) and s.c:-O(1)


class Solution {
  public:
    bool isprime(int n){
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if((n/i)!=i) cnt++;
            }
        }
        
        return cnt==2;
    }
    vector<int> sieve(int n) {
        // code here
        vector<int>ans;
        
        for(int i=2;i<=n;i++){
            if(isprime(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

optimized : use sieve algorithm

class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool>isprime(n+1,true);
        
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j=j+i){
                isprime[j]=false;
            }
        }
        
        vector<int>ans;
        
        for(int i=2;i<=n;i++){
            if(isprime[i]) ans.push_back(i);
        }
        
        
        return ans;
    }
};

t.c:-O(n*loglogn) and s.c-O(n)
