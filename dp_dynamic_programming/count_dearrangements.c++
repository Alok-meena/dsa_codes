A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. 
For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its 
initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 3000

Time limit: 1 sec
Sample Input 1:
2
2
3
Sample Output 1:
1
2
Explanation of Sample Output 1:
In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. 
Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements,
no element is present at its actual position.




1:recursion

int mod=1000000007;

long long int countDerangements(int n) {
    //base case
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    long long int ans=(((n-1)%mod)*((countDerangements(n-1)%mod)+(countDerangements(n-2)%mod)))%mod;
    return ans;
}

Time Complexity
O(2 ^ N), Where 'N' is the number of elements.

 

Since all possible permutations are found such that no element appears in its original position. Thus the time complexity is O(2 ^ N).

Space Complexity
O(N), Where 'N' is the number of elements.

 

Since recursive stack uses space of the order 'N'. Thus the space complexity will be O(N).


2nd:+memorization


#include <vector>
int mod=1000000007;

long long int solve(int n,vector<int>&dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=(((n-1)%mod)*((solve(n-1,dp)%mod)+(solve(n-2,dp)%mod)))%mod;
    return dp[n];
}

long long int countDerangements(int n) {
    //base case
    vector<int>dp(n+1,-1);
    long long int ans=solve(n,dp);
    return ans;
}

Time Complexity
O(N), Where 'N' is the number of elements.

 

Since an array of length 'N' is filled. Thus the time complexity will be O(N).

Space Complexity
O(N), Where 'N' is the number of elements.

 

Since an array of length 'N' is used. Thus the space complexity will be O(N).

3rd:tabulation


#include <vector>
int mod=1000000007;

long long int solve(int n){
    vector<int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        // dp[i] = ((i - 1) % MOD * (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD) % MOD;
        long long int first=dp[i-1]%mod;
        long long int second=dp[i-2]%mod;
        long long int sum=(first+second)%mod;

        long long int ans=((i-1)*sum)%mod;
        dp[i]=ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    
    return solve(n);
}


Time Complexity
O(N), Where 'N' is the number of elements.

 

Since an array of length 'N' is filled. Thus the time complexity will be O(N).

Space Complexity
O(N), Where 'N' is the number of elements.

 

Since an array of length 'N' is used. Thus the space complexity will be O(N).


4th: space optimised


#include <vector>
int mod=1000000007;

long long int solve(int n){
    if(n==1 || n==2){
        return n-1;
    }

    int prev1=0;
    int prev2=1;

    for(int i=3;i<=n;i++){
        long long int first=prev1%mod;
        long long int second=prev2%mod;
        long long int sum=(first+second)%mod;

        long long int curr=((i-1)*sum)%mod; 
        prev1=prev2;
        prev2=curr;
    }
    return prev2;
}

long long int countDerangements(int n) {
    
    return solve(n);
}



t.c:-O(N) and s.c:-O(1)


same code

long long int countDerangements(int n) {
    // Write your code here

    int a=0;
    int b=1;

    for(int i=3;i<=n;i++){
        int c=(((i-1)%mod)*((b%mod)+(a)%mod))%mod;  //bhai yha glti se i-1 ki jagah b use mt krna as we did a and b for dp[0] and dp[1] so replace with them only
        a=b;
        b=c;
    }
    return b;
}

