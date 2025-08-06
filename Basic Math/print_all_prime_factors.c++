

Upgrade to Premium for Doubt Support across all your problems and courses.

Explore Premium
Redirection Icon
Prime Factors
Difficulty: EasyAccuracy: 30.47%Submissions: 67K+Points: 2Average Time: 15m
Given a number n. Find its unique prime factors in increasing order.

Examples :

Input: n = 100
Output: [2, 5]
Explanation: Unique prime factors of 100 are 2 and 5.
Input: n = 60
Output: [2, 3, 5]
Explanation: Prime factors of 60 are 2, 2, 3, 5. Unique prime factors are 2, 3 and 5.
Constraints:
1 ≤ n ≤ 106





class Solution {
  public:
    bool isprime(int n){
        int cnt=0;
        
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if((n/i)!=i){
                    cnt++;
                }
            }
        }
        
        return cnt==2;
    }
    vector<int> primeFac(int n) {
        // code here
        vector<int>divisors;
        
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                divisors.push_back(i);
                if((n/i)!=i) divisors.push_back((n/i));
            }
        }
        
        sort(divisors.begin(),divisors.end());
        
        vector<int>prime;
        
        for(auto i:divisors){
            if(isprime(i)) prime.push_back(i);
        }
        
        return prime;
    }
};

t.c:-O(sqrt(n) * sqrt(n)) = O(n)


optimized :--O(log(n)) t.c  but worst case when we have a large prime number O(n)


class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int>ans;
        
        for(int i=2;i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n=n/i;
                }
            }
        }
        
        return ans;
    }
};

more optimized

class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int>ans;
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n=n/i;
                }
            }
        }
        
        if(n!=1) ans.push_back(n);
        
        return ans;
    }
};

t.c:- O(root(n) * log(n)) and s.c-O(log(n)) alright
